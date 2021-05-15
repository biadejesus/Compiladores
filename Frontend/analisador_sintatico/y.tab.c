/* A Bison parser, made by GNU Bison 3.7.3.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "tiger.y"

#include <stdio.h>
#include "util.h"
#include "errormsg.h"
#include "absyn.h"
#include "symbol.h"

int yylex(void);

void yyerror(char *s) {
  EM_error(EM_tokPos, "%s", s);
}

A_exp absyn_root;


#line 88 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    LOW = 258,                     /* LOW  */
    UMINUS = 259,                  /* UMINUS  */
    ID = 260,                      /* ID  */
    STRING = 261,                  /* STRING  */
    INT = 262,                     /* INT  */
    COMMA = 263,                   /* COMMA  */
    COLON = 264,                   /* COLON  */
    SEMICOLON = 265,               /* SEMICOLON  */
    LPAREN = 266,                  /* LPAREN  */
    RPAREN = 267,                  /* RPAREN  */
    LBRACK = 268,                  /* LBRACK  */
    RBRACK = 269,                  /* RBRACK  */
    LBRACE = 270,                  /* LBRACE  */
    RBRACE = 271,                  /* RBRACE  */
    DOT = 272,                     /* DOT  */
    PLUS = 273,                    /* PLUS  */
    MINUS = 274,                   /* MINUS  */
    TIMES = 275,                   /* TIMES  */
    DIVIDE = 276,                  /* DIVIDE  */
    EQ = 277,                      /* EQ  */
    NEQ = 278,                     /* NEQ  */
    LT = 279,                      /* LT  */
    LE = 280,                      /* LE  */
    GT = 281,                      /* GT  */
    GE = 282,                      /* GE  */
    AND = 283,                     /* AND  */
    OR = 284,                      /* OR  */
    ASSIGN = 285,                  /* ASSIGN  */
    ARRAY = 286,                   /* ARRAY  */
    IF = 287,                      /* IF  */
    THEN = 288,                    /* THEN  */
    ELSE = 289,                    /* ELSE  */
    WHILE = 290,                   /* WHILE  */
    FOR = 291,                     /* FOR  */
    TO = 292,                      /* TO  */
    DO = 293,                      /* DO  */
    LET = 294,                     /* LET  */
    IN = 295,                      /* IN  */
    END = 296,                     /* END  */
    OF = 297,                      /* OF  */
    BREAK = 298,                   /* BREAK  */
    NIL = 299,                     /* NIL  */
    FUNCTION = 300,                /* FUNCTION  */
    VAR = 301,                     /* VAR  */
    TYPE = 302,                    /* TYPE  */
    SWITCH = 303,                  /* SWITCH  */
    CASE = 304,                    /* CASE  */
    DEFAULT = 305                  /* DEFAULT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define LOW 258
#define UMINUS 259
#define ID 260
#define STRING 261
#define INT 262
#define COMMA 263
#define COLON 264
#define SEMICOLON 265
#define LPAREN 266
#define RPAREN 267
#define LBRACK 268
#define RBRACK 269
#define LBRACE 270
#define RBRACE 271
#define DOT 272
#define PLUS 273
#define MINUS 274
#define TIMES 275
#define DIVIDE 276
#define EQ 277
#define NEQ 278
#define LT 279
#define LE 280
#define GT 281
#define GE 282
#define AND 283
#define OR 284
#define ASSIGN 285
#define ARRAY 286
#define IF 287
#define THEN 288
#define ELSE 289
#define WHILE 290
#define FOR 291
#define TO 292
#define DO 293
#define LET 294
#define IN 295
#define END 296
#define OF 297
#define BREAK 298
#define NIL 299
#define FUNCTION 300
#define VAR 301
#define TYPE 302
#define SWITCH 303
#define CASE 304
#define DEFAULT 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "tiger.y"

	int pos;
	int ival;
	string sval;
  A_var var;
  A_exp exp;
  A_dec dec;
  A_ty ty;
  A_decList declist;
  A_expList explist;
  A_field field;
  A_fieldList fieldlist;
  A_fundec fundec;
  A_fundecList fundeclist;
  A_namety namety;
  A_nametyList nametylist;
  A_efield efield;
  A_efieldList efieldlist;
  

#line 261 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LOW = 3,                        /* LOW  */
  YYSYMBOL_UMINUS = 4,                     /* UMINUS  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_COMMA = 8,                      /* COMMA  */
  YYSYMBOL_COLON = 9,                      /* COLON  */
  YYSYMBOL_SEMICOLON = 10,                 /* SEMICOLON  */
  YYSYMBOL_LPAREN = 11,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 12,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 13,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 14,                    /* RBRACK  */
  YYSYMBOL_LBRACE = 15,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 16,                    /* RBRACE  */
  YYSYMBOL_DOT = 17,                       /* DOT  */
  YYSYMBOL_PLUS = 18,                      /* PLUS  */
  YYSYMBOL_MINUS = 19,                     /* MINUS  */
  YYSYMBOL_TIMES = 20,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 21,                    /* DIVIDE  */
  YYSYMBOL_EQ = 22,                        /* EQ  */
  YYSYMBOL_NEQ = 23,                       /* NEQ  */
  YYSYMBOL_LT = 24,                        /* LT  */
  YYSYMBOL_LE = 25,                        /* LE  */
  YYSYMBOL_GT = 26,                        /* GT  */
  YYSYMBOL_GE = 27,                        /* GE  */
  YYSYMBOL_AND = 28,                       /* AND  */
  YYSYMBOL_OR = 29,                        /* OR  */
  YYSYMBOL_ASSIGN = 30,                    /* ASSIGN  */
  YYSYMBOL_ARRAY = 31,                     /* ARRAY  */
  YYSYMBOL_IF = 32,                        /* IF  */
  YYSYMBOL_THEN = 33,                      /* THEN  */
  YYSYMBOL_ELSE = 34,                      /* ELSE  */
  YYSYMBOL_WHILE = 35,                     /* WHILE  */
  YYSYMBOL_FOR = 36,                       /* FOR  */
  YYSYMBOL_TO = 37,                        /* TO  */
  YYSYMBOL_DO = 38,                        /* DO  */
  YYSYMBOL_LET = 39,                       /* LET  */
  YYSYMBOL_IN = 40,                        /* IN  */
  YYSYMBOL_END = 41,                       /* END  */
  YYSYMBOL_OF = 42,                        /* OF  */
  YYSYMBOL_BREAK = 43,                     /* BREAK  */
  YYSYMBOL_NIL = 44,                       /* NIL  */
  YYSYMBOL_FUNCTION = 45,                  /* FUNCTION  */
  YYSYMBOL_VAR = 46,                       /* VAR  */
  YYSYMBOL_TYPE = 47,                      /* TYPE  */
  YYSYMBOL_SWITCH = 48,                    /* SWITCH  */
  YYSYMBOL_CASE = 49,                      /* CASE  */
  YYSYMBOL_DEFAULT = 50,                   /* DEFAULT  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_program = 52,                   /* program  */
  YYSYMBOL_exp = 53,                       /* exp  */
  YYSYMBOL_switch_exp = 54,                /* switch_exp  */
  YYSYMBOL_case_list = 55,                 /* case_list  */
  YYSYMBOL_case = 56,                      /* case  */
  YYSYMBOL_cond_exp = 57,                  /* cond_exp  */
  YYSYMBOL_loop_exp = 58,                  /* loop_exp  */
  YYSYMBOL_lvalue = 59,                    /* lvalue  */
  YYSYMBOL_func_call = 60,                 /* func_call  */
  YYSYMBOL_explist = 61,                   /* explist  */
  YYSYMBOL_explist_nonempty = 62,          /* explist_nonempty  */
  YYSYMBOL_arith_exp = 63,                 /* arith_exp  */
  YYSYMBOL_cmp_exp = 64,                   /* cmp_exp  */
  YYSYMBOL_bool_exp = 65,                  /* bool_exp  */
  YYSYMBOL_record_create = 66,             /* record_create  */
  YYSYMBOL_record_create_list = 67,        /* record_create_list  */
  YYSYMBOL_record_create_list_nonempty = 68, /* record_create_list_nonempty  */
  YYSYMBOL_record_create_field = 69,       /* record_create_field  */
  YYSYMBOL_array_create = 70,              /* array_create  */
  YYSYMBOL_decs = 71,                      /* decs  */
  YYSYMBOL_dec = 72,                       /* dec  */
  YYSYMBOL_tydeclist = 73,                 /* tydeclist  */
  YYSYMBOL_tydec = 74,                     /* tydec  */
  YYSYMBOL_ty = 75,                        /* ty  */
  YYSYMBOL_tyfields = 76,                  /* tyfields  */
  YYSYMBOL_tyfields_nonempty = 77,         /* tyfields_nonempty  */
  YYSYMBOL_tyfield = 78,                   /* tyfield  */
  YYSYMBOL_vardec = 79,                    /* vardec  */
  YYSYMBOL_fundeclist = 80,                /* fundeclist  */
  YYSYMBOL_fundec = 81,                    /* fundec  */
  YYSYMBOL_expseq = 82                     /* expseq  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   350

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    85,    85,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   108,   110,   111,   113,   114,   116,   117,   119,
     120,   122,   123,   124,   125,   127,   129,   130,   132,   133,
     135,   136,   137,   138,   140,   141,   142,   143,   144,   145,
     147,   148,   150,   152,   153,   155,   156,   158,   160,   162,
     163,   165,   166,   167,   169,   170,   172,   174,   175,   176,
     178,   179,   181,   182,   184,   186,   187,   189,   190,   192,
     193,   195,   196,   197
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LOW", "UMINUS", "ID",
  "STRING", "INT", "COMMA", "COLON", "SEMICOLON", "LPAREN", "RPAREN",
  "LBRACK", "RBRACK", "LBRACE", "RBRACE", "DOT", "PLUS", "MINUS", "TIMES",
  "DIVIDE", "EQ", "NEQ", "LT", "LE", "GT", "GE", "AND", "OR", "ASSIGN",
  "ARRAY", "IF", "THEN", "ELSE", "WHILE", "FOR", "TO", "DO", "LET", "IN",
  "END", "OF", "BREAK", "NIL", "FUNCTION", "VAR", "TYPE", "SWITCH", "CASE",
  "DEFAULT", "$accept", "program", "exp", "switch_exp", "case_list",
  "case", "cond_exp", "loop_exp", "lvalue", "func_call", "explist",
  "explist_nonempty", "arith_exp", "cmp_exp", "bool_exp", "record_create",
  "record_create_list", "record_create_list_nonempty",
  "record_create_field", "array_create", "decs", "dec", "tydeclist",
  "tydec", "ty", "tyfields", "tyfields_nonempty", "tyfield", "vardec",
  "fundeclist", "fundec", "expseq", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
#endif

#define YYPACT_NINF (-60)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      58,     2,   -60,   -60,    -3,    58,    58,    58,    23,   -23,
     -60,   -60,    25,    43,   300,   -60,   -60,   -60,    54,   -60,
     -60,   -60,   -60,   -60,   -60,    58,    58,    42,   -60,   191,
      49,   -60,   240,   149,    36,    63,    65,    67,    45,   -23,
     -60,    35,   -60,   -60,    31,    73,    29,   -60,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    82,    58,   109,    76,   -60,   256,    69,    79,   -60,
      81,    58,   -60,    58,    58,    58,    85,     1,    70,    58,
     -60,   -60,   -60,    58,   -31,    18,    18,   -60,   -60,    60,
      60,    60,    60,    60,    60,   323,   312,   272,   -60,   300,
      58,   -60,    56,    58,   -60,    42,   -60,   223,   300,   203,
      94,    99,    58,     6,    64,   288,   100,   101,   -15,   -60,
     -60,   -60,    58,   300,   -60,    58,    58,   102,    96,   -60,
     105,    84,   300,   -60,    94,    74,   -60,   -60,   -60,   106,
      58,   -60,   -60,   300,   300,   170,   104,     5,    94,    58,
     103,   113,    58,   300,    58,   -60,   115,    58,   -60,   300,
     -60,   -60,   300,   300,   117,   300,    58,   300
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    31,     7,     6,     0,     0,     0,     0,     0,    59,
      18,     4,     0,     0,     2,    21,    16,    17,     3,     9,
      10,    11,    12,    13,    14,    36,     0,    53,     5,    82,
       0,     8,     0,     0,     0,     0,     0,     0,     0,    59,
      61,    64,    62,    63,    77,    31,     0,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,    37,     0,     0,     0,    54,
      55,    81,    20,     0,     0,     0,     0,     0,     0,    81,
      60,    65,    78,     0,     0,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,     0,    34,    15,
       0,    35,    32,     0,    52,     0,    83,    28,    29,     0,
      70,     0,     0,     0,     0,     0,     0,     0,     0,    23,
      33,    39,     0,    57,    56,     0,     0,     0,     0,    71,
      72,     0,    75,    67,    70,     0,    66,    19,    32,     0,
       0,    22,    24,    58,    27,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    74,     0,     0,    73,    76,
      68,    69,    25,    30,     0,    79,     0,    80
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,   -60,     0,   -60,   -60,     3,   -60,   -60,   111,   -60,
     -60,    24,   -60,   -60,   -60,   -60,   -60,    37,   -60,   -60,
     107,   -60,   110,   -60,   -60,     7,    -5,   -60,   -60,   112,
     -60,   -59
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    29,    15,   118,   119,    16,    17,    18,    19,
      64,    65,    20,    21,    22,    23,    68,    69,    70,    24,
      38,    39,    40,    41,   136,   128,   129,   130,    42,    43,
      44,    30
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      14,   141,     1,     2,     3,    31,    32,    33,     4,    28,
     111,   133,   106,    25,   156,    26,     5,    27,   116,   117,
     114,   134,    35,    36,    37,    63,    66,   157,    34,     6,
      45,   112,     7,     8,   116,   117,     9,   135,    50,    51,
      10,    11,    60,    47,    84,    12,    61,    67,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    72,    99,     1,     2,     3,    75,    60,    76,     4,
      77,    61,    78,   107,   108,   109,    35,     5,    48,    49,
      50,    51,    37,   115,    62,    79,    83,    98,   101,   105,
       6,   103,   113,     7,     8,   104,   110,     9,   122,   127,
      63,    10,    11,   123,   131,   137,    12,   139,   147,   155,
     140,   146,   132,   148,   149,   152,   151,   100,   161,   160,
     164,   142,   143,    46,   121,   144,   145,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,   166,
     153,   150,   124,   158,     0,     0,    80,     0,     0,   159,
       0,    81,   162,     0,   163,     0,    82,   165,     0,     0,
       0,     0,     0,     0,     0,     0,   167,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,    71,     0,     0,     0,     0,     0,     0,   154,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,     0,     0,     0,     0,     0,
     126,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,     0,     0,   125,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
     102,     0,     0,    73,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,   120,     0,     0,     0,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,   138,     0,     0,     0,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57
};

static const yytype_int16 yycheck[] =
{
       0,    16,     5,     6,     7,     5,     6,     7,    11,    12,
       9,     5,    71,    11,     9,    13,    19,    15,    49,    50,
      79,    15,    45,    46,    47,    25,    26,    22,     5,    32,
       5,    30,    35,    36,    49,    50,    39,    31,    20,    21,
      43,    44,    13,     0,    15,    48,    17,     5,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    12,    62,     5,     6,     7,    30,    13,     5,    11,
       5,    17,     5,    73,    74,    75,    45,    19,    18,    19,
      20,    21,    47,    83,    30,    40,    13,     5,    12,     8,
      32,    22,    22,    35,    36,    16,    11,    39,    42,     5,
     100,    43,    44,   103,     5,    41,    48,     7,    12,     5,
       9,     9,   112,     8,    30,     9,    42,     8,     5,    16,
       5,   118,   122,    12,   100,   125,   126,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    22,
     140,   134,   105,   148,    -1,    -1,    39,    -1,    -1,   149,
      -1,    41,   152,    -1,   154,    -1,    44,   157,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   166,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    38,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    34,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      14,    -1,    -1,    33,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    14,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    14,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     7,    11,    19,    32,    35,    36,    39,
      43,    44,    48,    52,    53,    54,    57,    58,    59,    60,
      63,    64,    65,    66,    70,    11,    13,    15,    12,    53,
      82,    53,    53,    53,     5,    45,    46,    47,    71,    72,
      73,    74,    79,    80,    81,     5,    59,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      13,    17,    30,    53,    61,    62,    53,     5,    67,    68,
      69,    10,    12,    33,    38,    30,     5,     5,     5,    40,
      71,    73,    80,    13,    15,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,     5,    53,
       8,    12,    14,    22,    16,     8,    82,    53,    53,    53,
      11,     9,    30,    22,    82,    53,    49,    50,    55,    56,
      14,    62,    42,    53,    68,    34,    37,     5,    76,    77,
      78,     5,    53,     5,    15,    31,    75,    41,    14,     7,
       9,    16,    56,    53,    53,    53,     9,    12,     8,    30,
      76,    42,     9,    53,    38,     5,     9,    22,    77,    53,
      16,     5,    53,    53,     5,    53,    22,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    59,    59,    60,    61,    61,    62,    62,
      63,    63,    63,    63,    64,    64,    64,    64,    64,    64,
      65,    65,    66,    67,    67,    68,    68,    69,    70,    71,
      71,    72,    72,    72,    73,    73,    74,    75,    75,    75,
      76,    76,    77,    77,    78,    79,    79,    80,    80,    81,
      81,    82,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     5,
       3,     1,     5,     1,     2,     4,     3,     6,     4,     4,
       8,     1,     4,     4,     3,     4,     0,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     0,     1,     1,     3,     3,     6,     0,
       2,     1,     1,     1,     1,     2,     4,     1,     3,     3,
       0,     1,     1,     3,     3,     4,     6,     1,     2,     7,
       9,     0,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: exp  */
#line 85 "tiger.y"
             { absyn_root = (yyvsp[0].exp); }
#line 1470 "y.tab.c"
    break;

  case 3: /* exp: lvalue  */
#line 87 "tiger.y"
            { (yyval.exp) = A_VarExp(EM_tokPos, (yyvsp[0].var)); }
#line 1476 "y.tab.c"
    break;

  case 4: /* exp: NIL  */
#line 88 "tiger.y"
            { (yyval.exp) = A_NilExp(EM_tokPos); }
#line 1482 "y.tab.c"
    break;

  case 5: /* exp: LPAREN RPAREN  */
#line 89 "tiger.y"
                   { (yyval.exp) = A_SeqExp(EM_tokPos, NULL); }
#line 1488 "y.tab.c"
    break;

  case 6: /* exp: INT  */
#line 90 "tiger.y"
                   { (yyval.exp) = A_IntExp(EM_tokPos, (yyvsp[0].ival)); }
#line 1494 "y.tab.c"
    break;

  case 7: /* exp: STRING  */
#line 91 "tiger.y"
                   { (yyval.exp) = A_StringExp(EM_tokPos, (yyvsp[0].sval)); }
#line 1500 "y.tab.c"
    break;

  case 8: /* exp: MINUS exp  */
#line 92 "tiger.y"
                            { (yyval.exp) = A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), (yyvsp[0].exp)); }
#line 1506 "y.tab.c"
    break;

  case 9: /* exp: func_call  */
#line 93 "tiger.y"
                   { (yyval.exp) = (yyvsp[0].exp); }
#line 1512 "y.tab.c"
    break;

  case 10: /* exp: arith_exp  */
#line 94 "tiger.y"
                   { (yyval.exp) = (yyvsp[0].exp); }
#line 1518 "y.tab.c"
    break;

  case 11: /* exp: cmp_exp  */
#line 95 "tiger.y"
                   { (yyval.exp) = (yyvsp[0].exp); }
#line 1524 "y.tab.c"
    break;

  case 12: /* exp: bool_exp  */
#line 96 "tiger.y"
                   { (yyval.exp) = (yyvsp[0].exp); }
#line 1530 "y.tab.c"
    break;

  case 13: /* exp: record_create  */
#line 97 "tiger.y"
                   { (yyval.exp) = (yyvsp[0].exp); }
#line 1536 "y.tab.c"
    break;

  case 14: /* exp: array_create  */
#line 98 "tiger.y"
                   { (yyval.exp) = (yyvsp[0].exp); }
#line 1542 "y.tab.c"
    break;

  case 15: /* exp: lvalue ASSIGN exp  */
#line 99 "tiger.y"
                       { (yyval.exp) = A_AssignExp(EM_tokPos, (yyvsp[-2].var), (yyvsp[0].exp)); }
#line 1548 "y.tab.c"
    break;

  case 16: /* exp: cond_exp  */
#line 100 "tiger.y"
                  { (yyval.exp) = (yyvsp[0].exp); }
#line 1554 "y.tab.c"
    break;

  case 17: /* exp: loop_exp  */
#line 101 "tiger.y"
                  { (yyval.exp) = (yyvsp[0].exp); }
#line 1560 "y.tab.c"
    break;

  case 18: /* exp: BREAK  */
#line 102 "tiger.y"
           { (yyval.exp) = A_BreakExp(EM_tokPos); }
#line 1566 "y.tab.c"
    break;

  case 19: /* exp: LET decs IN expseq END  */
#line 103 "tiger.y"
                            { (yyval.exp) = A_LetExp(EM_tokPos, (yyvsp[-3].declist), A_SeqExp(EM_tokPos, (yyvsp[-1].explist))); }
#line 1572 "y.tab.c"
    break;

  case 20: /* exp: LPAREN expseq RPAREN  */
#line 104 "tiger.y"
                          { (yyval.exp) = A_SeqExp(EM_tokPos, (yyvsp[-1].explist)); }
#line 1578 "y.tab.c"
    break;

  case 21: /* exp: switch_exp  */
#line 105 "tiger.y"
                 { (yyval.exp) = (yyvsp[0].exp); }
#line 1584 "y.tab.c"
    break;

  case 22: /* switch_exp: SWITCH lvalue LBRACE case_list RBRACE  */
#line 108 "tiger.y"
                                                   { (yyval.exp) = A_Switch(EM_tokPos, (yyvsp[-3].var), (yyvsp[-1].exp)); }
#line 1590 "y.tab.c"
    break;

  case 23: /* case_list: case  */
#line 110 "tiger.y"
                  { (yyval.exp) = (yyvsp[0].exp); }
#line 1596 "y.tab.c"
    break;

  case 24: /* case_list: case_list case  */
#line 111 "tiger.y"
                              { (yyval.exp) = A_CaseList(EM_tokPos, (yyvsp[-1].exp), (yyvsp[0].exp));}
#line 1602 "y.tab.c"
    break;

  case 25: /* case: CASE INT COLON exp  */
#line 113 "tiger.y"
                             { (yyval.exp) = A_Case(EM_tokPos, (yyvsp[0].exp));}
#line 1608 "y.tab.c"
    break;

  case 26: /* case: DEFAULT COLON exp  */
#line 114 "tiger.y"
                          { (yyval.exp) = A_Default(EM_tokPos, (yyvsp[0].exp));}
#line 1614 "y.tab.c"
    break;

  case 27: /* cond_exp: IF exp THEN exp ELSE exp  */
#line 116 "tiger.y"
                                     { (yyval.exp) = A_IfExp(EM_tokPos, (yyvsp[-4].exp), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1620 "y.tab.c"
    break;

  case 28: /* cond_exp: IF exp THEN exp  */
#line 117 "tiger.y"
                        { (yyval.exp) = A_IfExp(EM_tokPos, (yyvsp[-2].exp), (yyvsp[0].exp), NULL); }
#line 1626 "y.tab.c"
    break;

  case 29: /* loop_exp: WHILE exp DO exp  */
#line 119 "tiger.y"
                            { (yyval.exp) = A_WhileExp(EM_tokPos, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1632 "y.tab.c"
    break;

  case 30: /* loop_exp: FOR ID ASSIGN exp TO exp DO exp  */
#line 120 "tiger.y"
                                        { (yyval.exp) = A_ForExp(EM_tokPos, S_Symbol((yyvsp[-6].sval)), (yyvsp[-4].exp), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1638 "y.tab.c"
    break;

  case 31: /* lvalue: ID  */
#line 122 "tiger.y"
                                 { (yyval.var) = A_SimpleVar(EM_tokPos, S_Symbol((yyvsp[0].sval))); }
#line 1644 "y.tab.c"
    break;

  case 32: /* lvalue: ID LBRACK exp RBRACK  */
#line 123 "tiger.y"
                                 { (yyval.var) = A_SubscriptVar(EM_tokPos, A_SimpleVar(EM_tokPos, S_Symbol((yyvsp[-3].sval))), (yyvsp[-1].exp)); }
#line 1650 "y.tab.c"
    break;

  case 33: /* lvalue: lvalue LBRACK exp RBRACK  */
#line 124 "tiger.y"
                                 { (yyval.var) = A_SubscriptVar(EM_tokPos, (yyvsp[-3].var), (yyvsp[-1].exp)); }
#line 1656 "y.tab.c"
    break;

  case 34: /* lvalue: lvalue DOT ID  */
#line 125 "tiger.y"
                                 { (yyval.var) = A_FieldVar(EM_tokPos, (yyvsp[-2].var), S_Symbol((yyvsp[0].sval))); }
#line 1662 "y.tab.c"
    break;

  case 35: /* func_call: ID LPAREN explist RPAREN  */
#line 127 "tiger.y"
                                    { (yyval.exp) = A_CallExp(EM_tokPos, S_Symbol((yyvsp[-3].sval)), (yyvsp[-1].explist)); }
#line 1668 "y.tab.c"
    break;

  case 36: /* explist: %empty  */
#line 129 "tiger.y"
                          { (yyval.explist) = NULL; }
#line 1674 "y.tab.c"
    break;

  case 37: /* explist: explist_nonempty  */
#line 130 "tiger.y"
                          { (yyval.explist) = (yyvsp[0].explist); }
#line 1680 "y.tab.c"
    break;

  case 38: /* explist_nonempty: exp  */
#line 132 "tiger.y"
                                             { (yyval.explist) = A_ExpList((yyvsp[0].exp), NULL); }
#line 1686 "y.tab.c"
    break;

  case 39: /* explist_nonempty: exp COMMA explist_nonempty  */
#line 133 "tiger.y"
                                             { (yyval.explist) = A_ExpList((yyvsp[-2].exp), (yyvsp[0].explist)); }
#line 1692 "y.tab.c"
    break;

  case 40: /* arith_exp: exp PLUS exp  */
#line 135 "tiger.y"
                          { (yyval.exp) = A_OpExp(EM_tokPos, A_plusOp, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1698 "y.tab.c"
    break;

  case 41: /* arith_exp: exp MINUS exp  */
#line 136 "tiger.y"
                          { (yyval.exp) = A_OpExp(EM_tokPos, A_minusOp, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1704 "y.tab.c"
    break;

  case 42: /* arith_exp: exp TIMES exp  */
#line 137 "tiger.y"
                          { (yyval.exp) = A_OpExp(EM_tokPos, A_timesOp, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1710 "y.tab.c"
    break;

  case 43: /* arith_exp: exp DIVIDE exp  */
#line 138 "tiger.y"
                          { (yyval.exp) = A_OpExp(EM_tokPos, A_divideOp, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1716 "y.tab.c"
    break;

  case 44: /* cmp_exp: exp EQ exp  */
#line 140 "tiger.y"
                     { (yyval.exp) = A_OpExp(EM_tokPos, A_eqOp, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1722 "y.tab.c"
    break;

  case 45: /* cmp_exp: exp NEQ exp  */
#line 141 "tiger.y"
                     { (yyval.exp) = A_OpExp(EM_tokPos, A_neqOp, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1728 "y.tab.c"
    break;

  case 46: /* cmp_exp: exp LT exp  */
#line 142 "tiger.y"
                     { (yyval.exp) = A_OpExp(EM_tokPos, A_ltOp, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1734 "y.tab.c"
    break;

  case 47: /* cmp_exp: exp LE exp  */
#line 143 "tiger.y"
                     { (yyval.exp) = A_OpExp(EM_tokPos, A_leOp, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1740 "y.tab.c"
    break;

  case 48: /* cmp_exp: exp GT exp  */
#line 144 "tiger.y"
                     { (yyval.exp) = A_OpExp(EM_tokPos, A_gtOp, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1746 "y.tab.c"
    break;

  case 49: /* cmp_exp: exp GE exp  */
#line 145 "tiger.y"
                     { (yyval.exp) = A_OpExp(EM_tokPos, A_geOp, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1752 "y.tab.c"
    break;

  case 50: /* bool_exp: exp AND exp  */
#line 147 "tiger.y"
                      { (yyval.exp) = A_IfExp(EM_tokPos, (yyvsp[-2].exp), (yyvsp[0].exp), A_IntExp(EM_tokPos, 0)); }
#line 1758 "y.tab.c"
    break;

  case 51: /* bool_exp: exp OR exp  */
#line 148 "tiger.y"
                      { (yyval.exp) = A_IfExp(EM_tokPos, (yyvsp[-2].exp), A_IntExp(EM_tokPos, 1), (yyvsp[0].exp)); }
#line 1764 "y.tab.c"
    break;

  case 52: /* record_create: ID LBRACE record_create_list RBRACE  */
#line 150 "tiger.y"
                                                   { (yyval.exp) = A_RecordExp(EM_tokPos, S_Symbol((yyvsp[-3].sval)), (yyvsp[-1].efieldlist)); }
#line 1770 "y.tab.c"
    break;

  case 53: /* record_create_list: %empty  */
#line 152 "tiger.y"
                    { (yyval.efieldlist) = NULL; }
#line 1776 "y.tab.c"
    break;

  case 54: /* record_create_list: record_create_list_nonempty  */
#line 153 "tiger.y"
                                                { (yyval.efieldlist) = (yyvsp[0].efieldlist); }
#line 1782 "y.tab.c"
    break;

  case 55: /* record_create_list_nonempty: record_create_field  */
#line 155 "tiger.y"
                                                 { (yyval.efieldlist) = A_EfieldList((yyvsp[0].efield), NULL); }
#line 1788 "y.tab.c"
    break;

  case 56: /* record_create_list_nonempty: record_create_field COMMA record_create_list_nonempty  */
#line 156 "tiger.y"
                                                                                   { (yyval.efieldlist) = A_EfieldList((yyvsp[-2].efield), (yyvsp[0].efieldlist)); }
#line 1794 "y.tab.c"
    break;

  case 57: /* record_create_field: ID EQ exp  */
#line 158 "tiger.y"
                               { (yyval.efield) = A_Efield(S_Symbol((yyvsp[-2].sval)), (yyvsp[0].exp)); }
#line 1800 "y.tab.c"
    break;

  case 58: /* array_create: ID LBRACK exp RBRACK OF exp  */
#line 160 "tiger.y"
                                          { (yyval.exp) = A_ArrayExp(EM_tokPos, S_Symbol((yyvsp[-5].sval)), (yyvsp[-3].exp), (yyvsp[0].exp)); }
#line 1806 "y.tab.c"
    break;

  case 59: /* decs: %empty  */
#line 162 "tiger.y"
               { (yyval.declist) = NULL; }
#line 1812 "y.tab.c"
    break;

  case 60: /* decs: dec decs  */
#line 163 "tiger.y"
               { (yyval.declist) = A_DecList((yyvsp[-1].dec), (yyvsp[0].declist)); }
#line 1818 "y.tab.c"
    break;

  case 61: /* dec: tydeclist  */
#line 165 "tiger.y"
                { (yyval.dec) = (yyvsp[0].dec); }
#line 1824 "y.tab.c"
    break;

  case 62: /* dec: vardec  */
#line 166 "tiger.y"
                { (yyval.dec) = (yyvsp[0].dec); }
#line 1830 "y.tab.c"
    break;

  case 63: /* dec: fundeclist  */
#line 167 "tiger.y"
                { (yyval.dec) = (yyvsp[0].dec); }
#line 1836 "y.tab.c"
    break;

  case 64: /* tydeclist: tydec  */
#line 169 "tiger.y"
                           { (yyval.dec) = A_TypeDec(EM_tokPos, A_NametyList((yyvsp[0].namety), NULL)); }
#line 1842 "y.tab.c"
    break;

  case 65: /* tydeclist: tydec tydeclist  */
#line 170 "tiger.y"
                           { (yyval.dec) = A_TypeDec(EM_tokPos, A_NametyList((yyvsp[-1].namety), (yyvsp[0].dec)->u.type)); }
#line 1848 "y.tab.c"
    break;

  case 66: /* tydec: TYPE ID EQ ty  */
#line 172 "tiger.y"
                           { (yyval.namety) = A_Namety(S_Symbol((yyvsp[-2].sval)), (yyvsp[0].ty)); }
#line 1854 "y.tab.c"
    break;

  case 67: /* ty: ID  */
#line 174 "tiger.y"
                           { (yyval.ty) = A_NameTy(EM_tokPos, S_Symbol((yyvsp[0].sval))); }
#line 1860 "y.tab.c"
    break;

  case 68: /* ty: LBRACE tyfields RBRACE  */
#line 175 "tiger.y"
                           { (yyval.ty) = A_RecordTy(EM_tokPos, (yyvsp[-1].fieldlist)); }
#line 1866 "y.tab.c"
    break;

  case 69: /* ty: ARRAY OF ID  */
#line 176 "tiger.y"
                           { (yyval.ty) = A_ArrayTy(EM_tokPos, S_Symbol((yyvsp[0].sval))); }
#line 1872 "y.tab.c"
    break;

  case 70: /* tyfields: %empty  */
#line 178 "tiger.y"
                            { (yyval.fieldlist) = NULL; }
#line 1878 "y.tab.c"
    break;

  case 71: /* tyfields: tyfields_nonempty  */
#line 179 "tiger.y"
                            { (yyval.fieldlist) = (yyvsp[0].fieldlist); }
#line 1884 "y.tab.c"
    break;

  case 72: /* tyfields_nonempty: tyfield  */
#line 181 "tiger.y"
                                                   { (yyval.fieldlist) = A_FieldList((yyvsp[0].field), NULL); }
#line 1890 "y.tab.c"
    break;

  case 73: /* tyfields_nonempty: tyfield COMMA tyfields_nonempty  */
#line 182 "tiger.y"
                                                   { (yyval.fieldlist) = A_FieldList((yyvsp[-2].field), (yyvsp[0].fieldlist)); }
#line 1896 "y.tab.c"
    break;

  case 74: /* tyfield: ID COLON ID  */
#line 184 "tiger.y"
                     { (yyval.field) = A_Field(EM_tokPos, S_Symbol((yyvsp[-2].sval)), S_Symbol((yyvsp[0].sval))); }
#line 1902 "y.tab.c"
    break;

  case 75: /* vardec: VAR ID ASSIGN exp  */
#line 186 "tiger.y"
                                   { (yyval.dec) = A_VarDec(EM_tokPos, S_Symbol((yyvsp[-2].sval)), NULL, (yyvsp[0].exp)); }
#line 1908 "y.tab.c"
    break;

  case 76: /* vardec: VAR ID COLON ID ASSIGN exp  */
#line 187 "tiger.y"
                                   { (yyval.dec) = A_VarDec(EM_tokPos, S_Symbol((yyvsp[-4].sval)), S_Symbol((yyvsp[-2].sval)), (yyvsp[0].exp)); }
#line 1914 "y.tab.c"
    break;

  case 77: /* fundeclist: fundec  */
#line 189 "tiger.y"
                              { (yyval.dec) = A_FunctionDec(EM_tokPos, A_FundecList((yyvsp[0].fundec), NULL)); }
#line 1920 "y.tab.c"
    break;

  case 78: /* fundeclist: fundec fundeclist  */
#line 190 "tiger.y"
                              { (yyval.dec) = A_FunctionDec(EM_tokPos, A_FundecList((yyvsp[-1].fundec), (yyvsp[0].dec)->u.function)); }
#line 1926 "y.tab.c"
    break;

  case 79: /* fundec: FUNCTION ID LPAREN tyfields RPAREN EQ exp  */
#line 192 "tiger.y"
                                                           { (yyval.fundec) = A_Fundec(EM_tokPos, S_Symbol((yyvsp[-5].sval)), (yyvsp[-3].fieldlist), NULL, (yyvsp[0].exp)); }
#line 1932 "y.tab.c"
    break;

  case 80: /* fundec: FUNCTION ID LPAREN tyfields RPAREN COLON ID EQ exp  */
#line 193 "tiger.y"
                                                           { (yyval.fundec) = A_Fundec(EM_tokPos, S_Symbol((yyvsp[-7].sval)), (yyvsp[-5].fieldlist), S_Symbol((yyvsp[-2].sval)), (yyvsp[0].exp)); }
#line 1938 "y.tab.c"
    break;

  case 81: /* expseq: %empty  */
#line 195 "tiger.y"
                              {(yyval.explist)=NULL;}
#line 1944 "y.tab.c"
    break;

  case 82: /* expseq: exp  */
#line 196 "tiger.y"
                             { (yyval.explist) = A_ExpList((yyvsp[0].exp), NULL); }
#line 1950 "y.tab.c"
    break;

  case 83: /* expseq: exp SEMICOLON expseq  */
#line 197 "tiger.y"
                             { (yyval.explist) = A_ExpList((yyvsp[-2].exp), (yyvsp[0].explist)); }
#line 1956 "y.tab.c"
    break;


#line 1960 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

