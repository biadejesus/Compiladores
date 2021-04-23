#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errormsg.h"
#include "absyn.h"
#include "prabsyn.h"
#include "parse.h"
#include "util.h"
#include "frame.h"
#include "semant.h"
#include "types.h"
#include "env.h"


void main(int argc, char **argv) {
  string fname = checked_malloc(50);
  A_exp absyn_tree_root;

  int opt;
  while ((opt = getopt(argc, argv, "p:a:i:c:h")) != -1) {
    switch (opt) {
			case 'p': // nome do programa de entrada
				strcpy(fname, optarg);
				break;

			case 'a': // imprime a arvore sintatica abstrata
				absyn_tree_root = parse(fname);
				if (absyn_tree_root)
					pr_exp(stdout, absyn_tree_root, 0);
				else {
					fprintf(stderr, "parsing failed!\n");
				}
				break;

			case 'i': // imprime a representação intermediária
				absyn_tree_root = parse(fname);
				if (absyn_tree_root) {
					F_fragList fl = SEM_transProg(absyn_tree_root, 1);
				} else {
					fprintf(stderr, "parsing failed!\n");
				}

				break;
    }
  }
}