#include <stdio.h>
#include "util.h"
#include "absyn.h"
#include "errormsg.h"
#include "parse.h"

extern int yyparse(void);
extern A_exp absyn_root;

A_exp parse(string fname) 
{
  EM_reset(fname);
  if (yyparse() == 0) { 
    return absyn_root;
  }
  else return NULL;
}
