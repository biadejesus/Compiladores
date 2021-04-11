%{
#include <string.h>
#include "util.h"
#include "absyn.h"
#include "y.tab.h"
#include "errormsg.h"

int count_comment=0;

const int TAM_STRING = 32;
int CAPACIDADE_STRING;
string string_buffer;

static void init_string_buffer() {
  string_buffer = checked_malloc(TAM_STRING);
  CAPACIDADE_STRING = TAM_STRING;
  string_buffer[0] = '\0';
}

static void append_to_buffer(char c) {
  int new_length = strlen(string_buffer) + 1;
  if(new_length >= CAPACIDADE_STRING) {
    char *tmp = string_buffer;
    CAPACIDADE_STRING *= 2;
    string_buffer = checked_malloc(CAPACIDADE_STRING);
    strcpy(string_buffer, tmp);
  }
  string_buffer[new_length-1] = c;
  string_buffer[new_length] = '\0';
}

int charPos=1;

int yywrap(void) {
  charPos=1;
  return 1;
}

void adjust(void) {
  EM_tokPos=charPos;
  charPos+=yyleng; 
}

%}

%START COMMENT INSTRING
%%
<INITIAL>
/* ignore characters */
[ \t\r]	{adjust(); continue;}

  /* newline */
\n       {adjust(); EM_newline(); continue;}

  /* punctuation symbols */
","	  {adjust(); return COMMA;}
":"    {adjust(); return COLON;}
";"    {adjust(); return SEMICOLON;}
"("    {adjust(); return LPAREN;}
")"    {adjust(); return RPAREN;}
"["    {adjust(); return LBRACK;}
"]"    {adjust(); return RBRACK;}
"{"    {adjust(); return LBRACE;}
"}"    {adjust(); return RBRACE;}
"."    {adjust(); return DOT;}
"+"    {adjust(); return PLUS;}
"-"    {adjust(); return MINUS;}
"*"    {adjust(); return TIMES;}
"/"    {adjust(); return DIVIDE;}
"="    {adjust(); return EQ;}
"<>"   {adjust(); return NEQ;}
"<"    {adjust(); return LT;}
"<="   {adjust(); return LE;}
">"    {adjust(); return GT;}
">="   {adjust(); return GE;}
"&"    {adjust(); return AND;}
"|"    {adjust(); return OR;}
":="   {adjust(); return ASSIGN;}

  /* reserved words */
array    {adjust(); return ARRAY;}
if       {adjust(); return IF;}
then     {adjust(); return THEN;}
else     {adjust(); return ELSE;}
while    {adjust(); return WHILE;}
for  	  {adjust(); return FOR;}
to       {adjust(); return TO;}
do       {adjust(); return DO;}
let      {adjust(); return LET;}
in       {adjust(); return IN;}
end      {adjust(); return END;}
of       {adjust(); return OF;}
break    {adjust(); return BREAK;}
nil      {adjust(); return NIL;}
function {adjust(); return FUNCTION;}
var      {adjust(); return VAR;}
type     {adjust(); return TYPE;}

  /* identifier */
[a-zA-Z][a-zA-Z0-9_]* {adjust(); yylval.sval=String(yytext); return ID;}

  /* string literal */
\"   {adjust(); init_string_buffer(); BEGIN INSTRING;}
<INSTRING>\"  {adjust(); yylval.sval = String(string_buffer); BEGIN 0; return STRING;}
<INSTRING>\n  {adjust(); EM_error(EM_tokPos,"unclose string: newline appear in string"); yyterminate();}
<INSTRING><<EOF>> {adjust(); EM_error(EM_tokPos,"unclose string"); yyterminate();}
<INSTRING>\\[0-9]{3} {adjust(); int tmp; sscanf(yytext+1, "%d", &tmp);
                      if(tmp > 0xff) { EM_error(EM_tokPos,"ascii code out of range"); yyterminate(); }
                      append_to_buffer(tmp);
                      }
<INSTRING>\\[0-9]+ {adjust(); EM_error(EM_tokPos,"bad escape sequence"); yyterminate();}
<INSTRING>\\n {adjust(); append_to_buffer('\n');}
<INSTRING>\\t {adjust(); append_to_buffer('\t');}
<INSTRING>\\\\ {adjust(); append_to_buffer('\\');}
<INSTRING>\\\" {adjust(); append_to_buffer('\"');}
<INSTRING>\^[@A-Z\[\\\]\^_?] {adjust(); append_to_buffer(yytext[1]-'a');}
<INSTRING>\\[ \n\t\f]+\\ {adjust(); int i; for(i = 0; yytext[i]; ++i) if(yytext[i] == '\n') EM_newline(); continue;}
<INSTRING>[^\\\n\"]* {adjust(); char *tmp = yytext; while(*tmp) append_to_buffer(*tmp++);}

  /* integer literal */
[0-9]+	 {adjust(); yylval.ival=atoi(yytext); return INT;}

  /* comment part */
"/*" {adjust(); count_comment+=1; BEGIN COMMENT;}
<COMMENT>"*/" {adjust(); count_comment-=1; if(count_comment==0) BEGIN 0;}
<COMMENT><<EOF>> {adjust(); EM_error(EM_tokPos,"unclose comment"); yyterminate();}
<COMMENT>.    {adjust();}

  /* unknown input */
.	 {adjust(); EM_error(EM_tokPos,"illegal token");}
