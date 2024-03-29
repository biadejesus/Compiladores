#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "errormsg.h"
#include "absyn.h"
#include "y.tab.h"



int yylex(void); 

string toknames[] = { 
"LOW", "FUNCTION", "TYPE", "ID", "LBRACK", "OF", "DO", "THEN",
"ELSE", "SEMICOLON", "ASSIGN", "OR", "AND", "GE", "GT", "LE",
"LT", "NEQ", "EQ", "MINUS", "PLUS", "DIVIDE", "TIMES", "UMINUS",
"STRING", "INT", "COMMA", "COLON", "LPAREN", "RPAREN", "RBRACK",
"LBRACE", "RBRACE", "DOT", "ARRAY", "IF", "WHILE", "FOR", "TO",
"LET", "IN", "END", "BREAK", "NIL", "VAR", "SWITCH", "CASE", "DEFAULT",
};


string tokname(int tok) {
  return tok<258 || tok>305 ? "BAD_TOKEN" : toknames[tok-258];
}

int main(int argc, char **argv) {
 string fname; int tok;
 if (argc!=2) {fprintf(stderr,"uso: a.out nomearquivo\n"); exit(1);}
 fname=argv[1];
 EM_reset(fname);
 for(;;) {
   
   tok=yylex();
   if (tok==0) break;
   switch(tok) {
   case ID: case STRING:
     printf("%10s %4d %s\n",tokname(tok),EM_tokPos,yylval.sval);
     break;
   case INT:
     printf("%10s %4d %d\n",tokname(tok),EM_tokPos,yylval.ival);
     break;
   default:
     printf("%10s %4d\n",tokname(tok),EM_tokPos);
   }
 }
 return 0;
}


