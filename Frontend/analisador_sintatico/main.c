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
    printStmList(out, stm_l);
  }

  if (printar_ass) {
    instr_l = F_codegen(frame, stm_l);
    AS_printInstrList(out, instr_l, F_tempMap());
  }
}

int main(int argc, char *argv[]) {
  int parametros;
  string fname = checked_malloc(50);
  FILE *out = stdout;
  A_exp abs_tree_root;
  F_fragList frags;

  //   if (argc != 2) {
  //     fprintf(stderr, "uso: tc no nome do arquivo\n");
  //     return 1;
  //   }

  abs_tree_root = parse(fname);

  Esc_findEscape(abs_tree_root);

  frags = SEM_transProg(abs_tree_root);

  //   fprintf(out, "------------------ CODIGO EM ASSEMBLY
  //   ------------------\n"); for (F_fragList f = frags; f; f = f->tail) {
  //     if (f->head->kind == F_procFrag) {
  //       do_proc(out, f->head->u.proc.frame, f->head->u.proc.body);
  //     }
  //   }
  //   /* string */
  //   for (F_fragList f = frags; f; f = f->tail) {
  //     if (f->head->kind == F_stringFrag) {
  //       do_string(out, f->head->u.proc.frame, f->head->u.proc.body);
  //     }
  //   }
  //   fprintf(out, "\n------------------ FIM ------------------\n\n");

  char *input_file = NULL;
  char *output_file = NULL;
  int bosta = 0;

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
      bosta = 1;
      break;

    case 'i': // imprime a representação intermediária
      if (abs_tree_root) {
        fprintf(out, "------------------ IR ------------------\n");
        F_fragList fl = SEM_transProg(abs_tree_root);
        fprintf(out, "\n------------------ FIM ------------------\n\n");
        fprintf(out, "\n\n\n");
      } else {
        fprintf(stderr, "parsing falhou!\n");
      }
      break;

    default:
      printf("aaaaaa");
      break;
      // case 'c': //imprime a representação intermediária após a geração de
      // árvores canônicas.

      // case 's': //imprime o código Assembly (antes da alocação de
      // registradores) case 'S': //imprime o código assembly (após da alocação
      // de registradores) case 'h': //help
    }
  }
  if (bosta) {
    if (abs_tree_root) {
      fprintf(out, "------------------ ARVORE ABSTRATA  ------------------\n");
      pr_exp(out, abs_tree_root, 0);
      fprintf(out, "\n------------------ FIM ------------------\n\n");
      fprintf(out, "\n\n\n");
    } else {
      fprintf(stderr, "print da arvore abstrata falhou\n");
    }
  }
  return 0;
}
