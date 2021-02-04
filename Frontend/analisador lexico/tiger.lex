%{
#include <string.h>
#include "util.h"
#include "tokens.h"
#include "errormsg.h"

int charPos=1;
static int contadorComentario = 0;

int yywrap(void)
{
 charPos=1;
 return 1;
}


void adjust(void)
{
 EM_tokPos=charPos;
 charPos+=yyleng;
}

char *getstr(const char *str)
{
    char *result = (char *)malloc(yyleng + 1);
    size_t cur = 1, len = 0;
    while(str[cur] != '"') {
        if (str[cur] == '\\' ) {
            switch(str[++cur]) {
                case 'n': result[len++] = '\n'; break;
                case 't': result[len++] = '\t'; break;
                case '\\': result[len++] = '\\'; break;
                default: break;
            }
            ++cur;
        }
        else {
            result[len++] = str[cur++];
        }
    }
    if (len == 0) {
        free(result);
        return NULL;
    }
    result[len] = '\0';
    return result;
}


%}

%x COMMENT

%%
<INITIAL>
" "	 {adjust(); continue;}
[ \t\r]	{adjust(); continue;}
\n	 {adjust(); EM_newline(); continue;}
","	 {adjust(); return COMMA;}
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
"%"  { adjust(); return MOD           ; }
"=="    {adjust(); return EQ;}
"!=" { adjust(); return NEQUAL        ; }
"<>"   {adjust(); return NEQ;}
"<"    {adjust(); return LT;}
"<="   {adjust(); return LE;}
">"    {adjust(); return GT;}
">="   {adjust(); return GE;}
"&&"    {adjust(); return AND;}
"||"    {adjust(); return OR;}
"!"  { adjust(); return NOT           ; }
"="   {adjust(); return ASSIGN;}
"+=" { adjust(); return ASSIGN_PLUS   ; }
"-=" { adjust(); return ASSIGN_MINUS  ; }
"*=" { adjust(); return ASSIGN_TIMES  ; }
"/=" { adjust(); return ASSIGN_DIVIDE ; }
"%=" { adjust(); return ASSIGN_MOD    ; }
"?"  { adjust(); return IF_TERNARIO   ; }

"while" {adjust(); return WHILE;}
"for"   {adjust(); return FOR;}
"to"	{adjust(); return TO;}
"break" {adjust(); return BREAK;}
"let"	 {adjust(); return LET;}
"in"  {adjust(); return IN;}
"end"   {adjust(); return END;}
"function" {adjust(); return FUNCTION;}
"var"   {adjust(); return VAR;}
"type"  {adjust(); return TYPE;}
"array" {adjust(); return ARRAY;}
"if"	  {adjust(); return IF;}
"then"  {adjust(); return THEN;}
"else"  {adjust(); return ELSE;}
"do"	  {adjust(); return DO;}
"of"	  {adjust(); return OF;}
"nil"	  {adjust(); return NIL;}
"return"    { adjust(); return RETURN    ; }

[0-9]+	 {adjust(); yylval.ival=atoi(yytext); return INT;}
"bool"      { adjust(); yylval.sval = "bool";     return T_BOOL    ; }
"int"       { adjust(); yylval.sval = "int";      return T_INT     ; }
"read"      { adjust(); yylval.sval = "read";     return READ      ; }
"write"     { adjust(); yylval.sval = "write";    return WRITE     ; }
"false"     { adjust(); yylval.ival = 0;          return FALSE     ; }
"true"     { adjust(); yylval.ival = 1;          return TRUE      ; }


\"[\-\+\*\/\.\\a-zA-Z0-9\ \t]*\" { adjust(); yylval.sval = getstr(yytext); return STRING; }
[0-9]* { adjust(); yylval.ival = atoi(yytext); return INT; }
[_a-zA-Z][_0-9a-zA-Z]* { adjust(); yylval.sval = String(yytext); return ID; }


"/*" { adjust(), ++contadorComentario; BEGIN COMMENT; }
<COMMENT>\n { adjust(); EM_newline(); }
<COMMENT>[^\*\/]* { adjust(); }
<COMMENT>"*" { adjust(); }
<COMMENT>"/" { adjust(); }
<COMMENT>"*/" {
    adjust();
    --contadorComentario;
    if (contadorComentario == 0) BEGIN 0;
    else if (contadorComentario < 0) {
        contadorComentario = 0;
        REJECT;
    }
}

<<EOF>> { adjust(); yyterminate(); }
.	 {adjust(); EM_error(EM_tokPos,"illegal token");}

