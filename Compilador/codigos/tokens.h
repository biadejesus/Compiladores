typedef union  {
	int pos;
	int ival;
	string sval;
	} YYSTYPE;
extern YYSTYPE yylval;

# define ID 257
# define STRING 258
# define INT 259
# define COMMA 260
# define COLON 261
# define SEMICOLON 262
# define LPAREN 263
# define RPAREN 264
# define LBRACK 265
# define RBRACK 266
# define LBRACE 267
# define RBRACE 268
# define DOT 269
# define PLUS 270
# define MINUS 271
# define TIMES 272
# define DIVIDE 273
# define EQ 274
# define NEQ 275
# define LT 276
# define LE 277
# define GT 278
# define GE 279
# define AND 280
# define OR 281
# define ASSIGN 282
# define ARRAY 283
# define IF 284
# define THEN 285
# define ELSE 286
# define WHILE 287
# define FOR 288
# define TO 289
# define DO 290
# define LET 291
# define IN 292
# define END 293
# define OF 294
# define BREAK 295
# define NIL 296
# define FUNCTION 297
# define VAR 298
# define TYPE 299
# define MOD 300
# define NEQUAL 301
# define NOT 302
# define ASSIGN_PLUS 303
# define ASSIGN_MINUS 304
# define ASSIGN_TIMES 305
# define ASSIGN_DIVIDE 306
# define ASSIGN_MOD 307
# define IF_TERNARIO 308
# define RETURN 309
# define T_BOOL 310
# define T_INT 311
# define READ 312
# define WRITE 313
# define SWITCH 314
# define CASE 315
# define DEFAULT 316
