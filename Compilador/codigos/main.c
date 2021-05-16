#include "absyn.h"
#include "assem.h"
#include "canon.h"
#include "codegen.h"
#include "errormsg.h"
#include "escape.h"
#include "frame.h"
#include "parse.h"
#include "prabsyn.h"
#include "printtree.h"
#include "semant.h"
#include "symbol.h"
#include "temp.h"
#include "tree.h"
#include "util.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int printar_abs = 0, printar_ir = 0, printar_can = 0, printar_ass = 0;

static void do_proc(FILE *out, F_frame frame, T_stm body) {
  AS_instrList instr_l = NULL;
  T_stmList stm_l = NULL;

  stm_l = C_linearize(body);
  stm_l = C_traceSchedule(C_basicBlocks(stm_l));
  if (printar_can) {
    fprintf(out, "------------------ CANONICA  ------------------\n");
    printStmList(out, stm_l);
  }

  if (printar_ass) {
    fprintf(out, "------------------ ASSEMBLY ------------------\n");
    instr_l = F_codegen(frame, stm_l);
    AS_printInstrList(out, instr_l, F_tempMap());
  }
}
static void do_string(FILE *out, F_frame frame, T_stm body) {}

int main(int argc, char *argv[]) {
  int parametros;
  string fname = checked_malloc(50);
  FILE *out = stdout;
  A_exp abs_tree_root;

  char *input_file = NULL;
  char *output_file = NULL;

  int opt;
  while ((opt = getopt(argc, argv, "aho:p:isc")) != -1) {
    switch (opt) {
    case 'p': // nome do programa de entrada
      input_file = (char *)malloc(strlen(optarg));
      strcpy(input_file, optarg);
      break;

    case 'o':
      output_file = (char *)malloc(strlen(optarg));
      strcpy(output_file, optarg);
      break;

    case 'a': // imprime a arvore sintatica abstrata
      printar_abs = 1;
      break;

    case 'i': // imprime a representação intermediária
      fprintf(out, "------------------ IR ------------------\n");
      printar_ir = 1;
      break;

    case 'c': // imprime a representação intermediária após a geração de árvores
              // canônicas.
      printar_can = 1;
      break;

    case 's': // imprime o código Assembly (antes da alocação de registradores)
      printar_ass = 1;
      break;
    case 'h': // help
      printf("-------- help ---------");
      printf("\n flag -h mostra o menu de ajuda");
      printf("\n -p para colocar o nome do programa de entrada");
      printf("\n -o para colocar o nome do arquivo de saida");
      printf("\n -a para printar a arvore abstrata");
      printf("\n -i para printar a representação intermediária");
      printf("\n -c para printar a arvore canonica");
      printf("\n -s para printar o código assembly");

    default:
      printf("\n uso: ./tc -p nome do arquivo\n");
      printf("\n -h para ajuda");
      break;
    }
  }
  abs_tree_root = parse(input_file);
  F_fragList frags = SEM_transProg(abs_tree_root, printar_ir);

  if (printar_abs) {
    if (abs_tree_root) {
      fprintf(out, "------------------ ARVORE ABSTRATA  ------------------\n");
      pr_exp(stdout, abs_tree_root, 0);

      fprintf(out, "\n\n\n");
    } else {
      fprintf(stderr, "print da arvore abstrata falhou\n");
    }
  }
  if (printar_can || printar_ass) {

    if (abs_tree_root) {
      for (F_fragList f = frags; f; f = f->tail) {
        if (f->head->kind == F_procFrag) {
          do_proc(out, f->head->u.proc.frame, f->head->u.proc.body);
        }
      }
    } else {
      printf("Falhou!");
    }
  }
  return 0;
}
