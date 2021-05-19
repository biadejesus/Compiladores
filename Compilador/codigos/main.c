#include "absyn.h"
#include "errormsg.h"
#include "parse.h"
#include "prabsyn.h"
#include "symbol.h"
#include "util.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int printar_abs = 0, printar_ir = 0;

int main(int argc, char *argv[])
{
  int parametros;
  string fname = checked_malloc(50);
  FILE *out = stdout;
  A_exp abs_tree_root;

  char *input_file = NULL;
  char *output_file = NULL;

  int opt;
  while ((opt = getopt(argc, argv, "aho:p:isc")) != -1)
  {
    switch (opt)
    {
    case 'p': // nome do programa de entrada
      input_file = (char *)malloc(strlen(optarg));
      strcpy(input_file, optarg);
      break;

    case 'a': // imprime a arvore sintatica abstrata
      printar_abs = 1;
      break;
    
    case 'h': // help
      printf("-------- help ---------");
      printf("\n flag -h mostra o menu de ajuda");
      printf("\n -p para colocar o nome do programa de entrada");
      printf("\n -a para printar a arvore abstrata");

    default:
      printf("\n uso: ./tc -p nome do arquivo\n");
      printf("\n -h para ajuda");
      break;
    }
  }
  abs_tree_root = parse(input_file);

  if (printar_abs)
  {
    if (abs_tree_root)
    {
      fprintf(out, "------------------ ARVORE ABSTRATA  ------------------\n");
      pr_exp(stdout, abs_tree_root, 0);

      fprintf(out, "\n\n\n");
    }
    else
    {
      fprintf(stderr, "print da arvore abstrata falhou\n");
    }
  }
  return 0;
}
