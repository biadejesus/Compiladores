#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "errormsg.h"
#include "parse.h"
#include "absyn.h"
#include "symbol.h"
#include "semant.h"

int main(int argc, char **argv) {
  if (argc!=2) {fprintf(stderr,"uso: a./tc filename\n"); exit(1);}
  A_exp absyn_tree_root = parse(argv[1]);
  if(absyn_tree_root) {
    SEM_transProg(absyn_tree_root, 0);
  } else {
    fprintf(stderr, "parsing falhou!\n");
    return 1;
  }
  return 0;
}
