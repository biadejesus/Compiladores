#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "errormsg.h"
#include "parse.h"
#include "absyn.h"
#include "symbol.h"
#include "semant.h"
#include "frame.h"

int main(int argc, char **argv) {
  if (argc!=2) {fprintf(stderr,"usage: a.out filename\n"); exit(1);}
  A_exp absyn_tree_root = parse(argv[1]);
  if(absyn_tree_root) {
    F_fragList fl = SEM_transProg(absyn_tree_root, 1);
  } else {
    fprintf(stderr, "parsing falhou!\n");
    return 1;
  }
  return 0;
}
