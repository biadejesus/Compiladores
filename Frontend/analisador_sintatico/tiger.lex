%{
#include <string.h>
#include "util.h"
#include "absyn.h"
#include "tiger.tab.h"
#include "errormsg.h"

int contador_comment=0;

const int TAM_STRING = 32;
int CAPACIDADE_STRING;
string str_buff;

static void buffer() {
  str_buff = checked_malloc(TAM_STRING);
  CAPACIDADE_STRING = TAM_STRING;
  str_buff[0] = '\0';
}

static void append(char c) {
  int new_length = strlen(str_buff) + 1;
  if(new_length >= CAPACIDADE_STRING) {
    char *tmp = str_buff;
    CAPACIDADE_STRING *= 2;
    str_buff = checked_malloc(CAPACIDADE_STRING);
    strcpy(str_buff, tmp);
  }
  str_buff[new_length-1] = c;
  str_buff[new_length] = '\0';
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
<INITIAL>[ \t\r]	{adjust(); continue;}
<INITIAL>\n       {adjust(); EM_newline(); continue;}
<INITIAL>","	  {adjust(); return COMMA;}
<INITIAL>":"    {adjust(); return COLON;}
<INITIAL>";"    {adjust(); return SEMICOLON;}
<INITIAL>"("    {adjust(); return LPAREN;}
<INITIAL>")"    {adjust(); return RPAREN;}
<INITIAL>"["    {adjust(); return LBRACK;}
<INITIAL>"]"    {adjust(); return RBRACK;}
<INITIAL>"{"    {adjust(); return LBRACE;}
<INITIAL>"}"    {adjust(); return RBRACE;}
<INITIAL>"."    {adjust(); return DOT;}
<INITIAL>"+"    {adjust(); return PLUS;}
<INITIAL>"-"    {adjust(); return MINUS;}
<INITIAL>"*"    {adjust(); return TIMES;}
<INITIAL>"/"    {adjust(); return DIVIDE;}
<INITIAL>"="    {adjust(); return EQ;}
<INITIAL>"<>"   {adjust(); return NEQ;}
<INITIAL>"<"    {adjust(); return LT;}
<INITIAL>"<="   {adjust(); return LE;}
<INITIAL>">"    {adjust(); return GT;}
<INITIAL>">="   {adjust(); return GE;}
<INITIAL>"&"    {adjust(); return AND;}
<INITIAL>"|"    {adjust(); return OR;}
<INITIAL>":="   {adjust(); return ASSIGN;}

<INITIAL>switch   {adjust(); return SWITCH;}
<INITIAL>case     {adjust(); return CASE;}
<INITIAL>default  {adjust(); return DEFAULT;}
<INITIAL>array    {adjust(); return ARRAY;}
<INITIAL>if       {adjust(); return IF;}
<INITIAL>then     {adjust(); return THEN;}
<INITIAL>else     {adjust(); return ELSE;}
<INITIAL>while    {adjust(); return WHILE;}
<INITIAL>for  	  {adjust(); return FOR;}
<INITIAL>to       {adjust(); return TO;}
<INITIAL>do       {adjust(); return DO;}
<INITIAL>let      {adjust(); return LET;}
<INITIAL>in       {adjust(); return IN;}
<INITIAL>end      {adjust(); return END;}
<INITIAL>of       {adjust(); return OF;}
<INITIAL>break    {adjust(); return BREAK;}
<INITIAL>nil      {adjust(); return NIL;}
<INITIAL>function {adjust(); return FUNCTION;}
<INITIAL>var      {adjust(); return VAR;}
<INITIAL>type     {adjust(); return TYPE;}

  /* id */
<INITIAL>[a-zA-Z][a-zA-Z0-9_]* {adjust(); yylval.sval=String(yytext); return ID;}

  /* string */
<INITIAL>\"   {adjust(); buffer(); BEGIN INSTRING;}
<INSTRING>\"  {adjust(); yylval.sval = String(str_buff); BEGIN 0; return STRING;}
<INSTRING>\n  {adjust(); EM_error(EM_tokPos,"unclose string: newline appear in string"); yyterminate();}
<INSTRING><<EOF>> {adjust(); EM_error(EM_tokPos,"unclose string"); yyterminate();}
<INSTRING>\\[0-9]{3} {adjust(); int tmp; sscanf(yytext+1, "%d", &tmp);
   if(tmp > 0xff) { EM_error(EM_tokPos,"ascii code out of range"); yyterminate(); }
   append(tmp);}
<INSTRING>\\[0-9]+ {adjust(); EM_error(EM_tokPos,"bad escape sequence"); yyterminate();}
<INSTRING>\\n {adjust(); append('\n');}
<INSTRING>\\t {adjust(); append('\t');}
<INSTRING>\\\\ {adjust(); append('\\');}
<INSTRING>\\\" {adjust(); append('\"');}
<INSTRING>\^[@A-Z\[\\\]\^_?] {adjust(); append(yytext[1]-'a');}
<INSTRING>\\[ \n\t\f]+\\ {adjust(); int i; for(i = 0; yytext[i]; ++i) if(yytext[i] == '\n') EM_newline(); continue;}
<INSTRING>[^\\\n\"]* {adjust(); char *tmp = yytext; while(*tmp) append(*tmp++);}

  /* integer */
<INITIAL>[0-9]+	 {adjust(); yylval.ival=atoi(yytext); return INT;}

  /* comment  */
"/*" {adjust(); contador_comment+=1; BEGIN COMMENT;}
<COMMENT>"*/" {adjust(); contador_comment-=1; if(contador_comment==0) BEGIN 0;}
<COMMENT><<EOF>> {adjust(); EM_error(EM_tokPos,"unclose comment"); yyterminate();}
<COMMENT>.    {adjust();}

  /* unknown input */
<INITIAL>.	 {adjust(); EM_error(EM_tokPos,"illegal token");}
