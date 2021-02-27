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
#include "symbol.h"
#include "errormsg.h"
#include "absyn.h"

#define YYDEBUG 1

int yylex(void); /* function prototype */

A_exp absyn_root;

void yyerror(char *s)
{
  EM_error(EM_tokPos, "%s", s);
}


#line 91 "tiger.tab.c"

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

#include "tiger.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_COMMA = 6,                      /* COMMA  */
  YYSYMBOL_COLON = 7,                      /* COLON  */
  YYSYMBOL_SEMICOLON = 8,                  /* SEMICOLON  */
  YYSYMBOL_LPAREN = 9,                     /* LPAREN  */
  YYSYMBOL_RPAREN = 10,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 11,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 12,                    /* RBRACK  */
  YYSYMBOL_LBRACE = 13,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 14,                    /* RBRACE  */
  YYSYMBOL_DOT = 15,                       /* DOT  */
  YYSYMBOL_PLUS = 16,                      /* PLUS  */
  YYSYMBOL_MINUS = 17,                     /* MINUS  */
  YYSYMBOL_TIMES = 18,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 19,                    /* DIVIDE  */
  YYSYMBOL_EQ = 20,                        /* EQ  */
  YYSYMBOL_NEQ = 21,                       /* NEQ  */
  YYSYMBOL_LT = 22,                        /* LT  */
  YYSYMBOL_LE = 23,                        /* LE  */
  YYSYMBOL_GT = 24,                        /* GT  */
  YYSYMBOL_GE = 25,                        /* GE  */
  YYSYMBOL_AND = 26,                       /* AND  */
  YYSYMBOL_OR = 27,                        /* OR  */
  YYSYMBOL_ASSIGN = 28,                    /* ASSIGN  */
  YYSYMBOL_ARRAY = 29,                     /* ARRAY  */
  YYSYMBOL_IF = 30,                        /* IF  */
  YYSYMBOL_THEN = 31,                      /* THEN  */
  YYSYMBOL_ELSE = 32,                      /* ELSE  */
  YYSYMBOL_LET = 33,                       /* LET  */
  YYSYMBOL_IN = 34,                        /* IN  */
  YYSYMBOL_END = 35,                       /* END  */
  YYSYMBOL_OF = 36,                        /* OF  */
  YYSYMBOL_NIL = 37,                       /* NIL  */
  YYSYMBOL_FUNCTION = 38,                  /* FUNCTION  */
  YYSYMBOL_VAR = 39,                       /* VAR  */
  YYSYMBOL_TYPE = 40,                      /* TYPE  */
  YYSYMBOL_FUNC_RETURN = 41,               /* FUNC_RETURN  */
  YYSYMBOL_SWITCH = 42,                    /* SWITCH  */
  YYSYMBOL_CASE = 43,                      /* CASE  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_exp = 46,                       /* exp  */
  YYSYMBOL_exp_or = 47,                    /* exp_or  */
  YYSYMBOL_exp_or_rec = 48,                /* exp_or_rec  */
  YYSYMBOL_exp_and = 49,                   /* exp_and  */
  YYSYMBOL_exp_and_rec = 50,               /* exp_and_rec  */
  YYSYMBOL_exp_compa = 51,                 /* exp_compa  */
  YYSYMBOL_exp_add = 52,                   /* exp_add  */
  YYSYMBOL_exp_add_rec = 53,               /* exp_add_rec  */
  YYSYMBOL_exp_mul = 54,                   /* exp_mul  */
  YYSYMBOL_exp_mul_rec = 55,               /* exp_mul_rec  */
  YYSYMBOL_exp_nega = 56,                  /* exp_nega  */
  YYSYMBOL_exp_seq = 57,                   /* exp_seq  */
  YYSYMBOL_factor = 58,                    /* factor  */
  YYSYMBOL_expseq = 59,                    /* expseq  */
  YYSYMBOL_funcall = 60,                   /* funcall  */
  YYSYMBOL_argseq = 61,                    /* argseq  */
  YYSYMBOL_rec_creation = 62,              /* rec_creation  */
  YYSYMBOL_efield_seq = 63,                /* efield_seq  */
  YYSYMBOL_efield = 64,                    /* efield  */
  YYSYMBOL_decs = 65,                      /* decs  */
  YYSYMBOL_dec = 66,                       /* dec  */
  YYSYMBOL_tydec = 67,                     /* tydec  */
  YYSYMBOL_ty = 68,                        /* ty  */
  YYSYMBOL_func_ty = 69,                   /* func_ty  */
  YYSYMBOL_ty_param = 70,                  /* ty_param  */
  YYSYMBOL_ty_param_tail = 71,             /* ty_param_tail  */
  YYSYMBOL_tyfields = 72,                  /* tyfields  */
  YYSYMBOL_tail_tyfields = 73,             /* tail_tyfields  */
  YYSYMBOL_tyfield = 74,                   /* tyfield  */
  YYSYMBOL_vardec = 75,                    /* vardec  */
  YYSYMBOL_fundec = 76,                    /* fundec  */
  YYSYMBOL_lvalue = 77                     /* lvalue  */
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
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   159

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    67,    67,    68,    69,    75,    76,    77,    80,    81,
      82,    85,    86,    87,    88,    89,    90,    91,    95,    97,
      98,    99,   101,   103,   104,   105,   108,   109,   111,   112,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     125,   126,   128,   129,   131,   132,   134,   135,   137,   138,
     140,   143,   144,   146,   147,   148,   151,   153,   154,   155,
     156,   159,   160,   161,   162,   163,   164,   167,   170,   171,
     174,   175,   178,   179,   181,   184,   185,   188,   189,   192,
     193,   194,   195,   196
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "STRING", "INT",
  "COMMA", "COLON", "SEMICOLON", "LPAREN", "RPAREN", "LBRACK", "RBRACK",
  "LBRACE", "RBRACE", "DOT", "PLUS", "MINUS", "TIMES", "DIVIDE", "EQ",
  "NEQ", "LT", "LE", "GT", "GE", "AND", "OR", "ASSIGN", "ARRAY", "IF",
  "THEN", "ELSE", "LET", "IN", "END", "OF", "NIL", "FUNCTION", "VAR",
  "TYPE", "FUNC_RETURN", "SWITCH", "CASE", "$accept", "program", "exp",
  "exp_or", "exp_or_rec", "exp_and", "exp_and_rec", "exp_compa", "exp_add",
  "exp_add_rec", "exp_mul", "exp_mul_rec", "exp_nega", "exp_seq", "factor",
  "expseq", "funcall", "argseq", "rec_creation", "efield_seq", "efield",
  "decs", "dec", "tydec", "ty", "func_ty", "ty_param", "ty_param_tail",
  "tyfields", "tail_tyfields", "tyfield", "vardec", "fundec", "lvalue", YY_NULLPTR
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
     295,   296,   297,   298
};
#endif

#define YYPACT_NINF (-130)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      59,    24,  -130,  -130,    59,    59,    59,   -23,  -130,     5,
    -130,  -130,   -20,     8,    80,    57,    60,  -130,  -130,  -130,
    -130,     3,    50,    59,     7,    22,  -130,    17,  -130,    46,
      39,    45,    72,    74,    52,   -23,  -130,  -130,  -130,  -130,
      59,  -130,    59,  -130,    59,    59,    59,    59,    59,    59,
      59,    59,  -130,    59,    59,  -130,    59,    85,    59,  -130,
      91,    81,    86,    87,  -130,    92,   102,  -130,  -130,    59,
     100,     2,   101,    59,  -130,   -20,     8,  -130,  -130,  -130,
    -130,  -130,  -130,    57,    57,    60,    60,    99,  -130,  -130,
      59,  -130,    76,    59,  -130,   117,    90,   120,   121,    59,
      -1,    93,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
      59,  -130,  -130,    59,   118,   116,   123,   103,  -130,    89,
      10,   120,    97,  -130,  -130,  -130,  -130,  -130,   124,     4,
     120,  -130,    59,    23,   128,    94,   126,   125,   134,  -130,
     135,    59,   123,  -130,    89,  -130,   137,  -130,    62,   104,
    -130,  -130,   122,  -130,  -130,   128,    89,  -130,    63,    59,
    -130,    89,  -130,  -130
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    79,    32,    31,    41,     0,     0,    52,    30,     0,
       2,     4,     7,    10,    17,    21,    25,    27,    29,    38,
      39,    37,     0,     0,     0,     0,    40,     0,    26,    37,
       0,     0,     0,     0,     0,    52,    53,    54,    55,     1,
       0,     5,     0,     8,     0,     0,     0,     0,     0,     0,
       0,     0,    18,     0,     0,    22,     0,     0,     0,    42,
      45,     0,     0,     0,    46,     0,    49,    80,    28,     0,
       0,     0,     0,    41,    51,     7,    10,    11,    12,    15,
      16,    13,    14,    21,    21,    25,    25,     0,    81,     3,
       0,    43,    82,     0,    47,     0,    36,    71,     0,     0,
       0,     0,     6,     9,    19,    20,    23,    24,    83,    44,
       0,    50,    48,     0,     0,     0,    73,     0,    75,    57,
       0,    71,     0,    56,    60,    33,    34,    35,     0,     0,
       0,    70,     0,     0,    69,     0,     0,     0,     0,    74,
       0,     0,    73,    76,    63,    66,     0,    67,     0,     0,
      58,    59,     0,    77,    72,    69,    62,    65,     0,     0,
      68,    61,    64,    78
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,     0,  -130,    68,   106,    71,   107,    70,     1,
      31,     9,    -2,  -130,  -130,    75,  -130,    54,  -130,    55,
    -130,   119,  -130,  -130,  -130,  -129,  -130,    -3,    30,    11,
      25,  -130,  -130,    -4
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    26,    11,    41,    12,    43,    13,    14,    52,
      15,    55,    16,    17,    18,    27,    19,    61,    20,    65,
      66,    34,    35,    36,   123,   124,   136,   147,   115,   131,
     116,    37,    38,    21
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      10,    29,   119,    28,   145,    39,    30,    40,   120,    98,
      63,   140,   121,   134,    56,    31,    32,    33,    57,   157,
     135,    64,    60,    62,   141,    67,   144,    68,   122,   162,
      99,    58,   120,    22,    42,    23,    29,    24,    29,    25,
      29,    29,    29,    29,    29,    29,    29,    29,    70,    29,
      29,    85,    86,     1,     2,     3,    87,    56,    89,     4,
      59,    57,     1,     2,     3,   156,   161,     5,     4,    96,
      69,   120,   120,    50,    51,    71,     5,    72,    53,    54,
       6,    83,    84,     7,   104,   105,    73,     8,    88,     6,
      60,    91,     7,   111,   106,   107,     8,    90,    92,   118,
      44,    45,    46,    47,    48,    49,    94,    93,    95,    97,
     126,   108,   110,   127,    77,    78,    79,    80,    81,    82,
      63,   100,   113,   114,   117,   128,   129,   139,   125,   130,
     133,   132,   143,   138,   146,   148,   149,   151,   152,   150,
     155,   153,   159,   102,   109,   158,    75,   103,   101,    76,
     112,   137,   160,   154,    74,   142,     0,     0,     0,   163
};

static const yytype_int16 yycheck[] =
{
       0,     5,     3,     5,   133,     0,     6,    27,     9,     7,
       3,     7,    13,     3,    11,    38,    39,    40,    15,   148,
      10,    14,    22,    23,    20,     3,     3,    10,    29,   158,
      28,    28,     9,     9,    26,    11,    40,    13,    42,    15,
      44,    45,    46,    47,    48,    49,    50,    51,     3,    53,
      54,    53,    54,     3,     4,     5,    56,    11,    58,     9,
      10,    15,     3,     4,     5,     3,     3,    17,     9,    69,
      31,     9,     9,    16,    17,     3,    17,     3,    18,    19,
      30,    50,    51,    33,    83,    84,    34,    37,     3,    30,
      90,    10,    33,    93,    85,    86,    37,     6,    12,    99,
      20,    21,    22,    23,    24,    25,    14,    20,     6,     9,
     110,    12,    36,   113,    44,    45,    46,    47,    48,    49,
       3,    20,    32,     3,     3,     7,    10,     3,    35,     6,
      41,    28,   132,    36,     6,    41,    10,     3,     3,    14,
       3,   141,    20,    75,    90,    41,    40,    76,    73,    42,
      95,   121,   155,   142,    35,   130,    -1,    -1,    -1,   159
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     9,    17,    30,    33,    37,    45,
      46,    47,    49,    51,    52,    54,    56,    57,    58,    60,
      62,    77,     9,    11,    13,    15,    46,    59,    56,    77,
      46,    38,    39,    40,    65,    66,    67,    75,    76,     0,
      27,    48,    26,    50,    20,    21,    22,    23,    24,    25,
      16,    17,    53,    18,    19,    55,    11,    15,    28,    10,
      46,    61,    46,     3,    14,    63,    64,     3,    10,    31,
       3,     3,     3,    34,    65,    49,    51,    52,    52,    52,
      52,    52,    52,    54,    54,    56,    56,    46,     3,    46,
       6,    10,    12,    20,    14,     6,    46,     9,     7,    28,
      20,    59,    48,    50,    53,    53,    55,    55,    12,    61,
      36,    46,    63,    32,     3,    72,    74,     3,    46,     3,
       9,    13,    29,    68,    69,    35,    46,    46,     7,    10,
       6,    73,    28,    41,     3,    10,    70,    72,    36,     3,
       7,    20,    74,    46,     3,    69,     6,    71,    41,    10,
      14,     3,     3,    46,    73,     3,     3,    69,    41,    20,
      71,     3,    69,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    48,    48,    49,    50,
      50,    51,    51,    51,    51,    51,    51,    51,    52,    53,
      53,    53,    54,    55,    55,    55,    56,    56,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    59,    60,    60,    61,    61,    62,    62,    63,    63,
      64,    65,    65,    66,    66,    66,    67,    68,    68,    68,
      68,    69,    69,    69,    69,    69,    69,    70,    71,    71,
      72,    72,    73,    73,    74,    75,    75,    76,    76,    77,
      77,    77,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     2,     3,     0,     2,     3,
       0,     3,     3,     3,     3,     3,     3,     1,     2,     3,
       3,     0,     2,     3,     3,     0,     2,     1,     3,     1,
       1,     1,     1,     5,     6,     6,     4,     1,     1,     1,
       1,     0,     3,     4,     3,     1,     3,     4,     3,     1,
       3,     2,     0,     1,     1,     1,     4,     1,     3,     3,
       1,     5,     4,     3,     5,     4,     3,     2,     3,     0,
       2,     0,     3,     0,     3,     4,     6,     7,     9,     1,
       3,     3,     4,     4
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
#line 67 "tiger.y"
                                        { absyn_root = (yyvsp[0].exp); }
#line 1261 "tiger.tab.c"
    break;

  case 3: /* exp: lvalue ASSIGN exp  */
#line 68 "tiger.y"
                                        {(yyval.exp) = A_AssignExp(EM_tokPos, (yyvsp[-2].var), (yyvsp[0].exp)); }
#line 1267 "tiger.tab.c"
    break;

  case 4: /* exp: exp_or  */
#line 69 "tiger.y"
                                        {(yyval.exp) = (yyvsp[0].exp);}
#line 1273 "tiger.tab.c"
    break;

  case 5: /* exp_or: exp_and exp_or_rec  */
#line 75 "tiger.y"
                                        {(yyval.exp) = A_ExpExp((yyvsp[-1].exp), (yyvsp[0].exp));}
#line 1279 "tiger.tab.c"
    break;

  case 6: /* exp_or_rec: OR exp_and exp_or_rec  */
#line 76 "tiger.y"
                                        {(yyval.exp) = A_IfExp2(EM_tokPos, (yyvsp[-3].exp), A_IntExp(EM_tokPos, 1), (yyvsp[-1].exp), (yyvsp[0].exp));}
#line 1285 "tiger.tab.c"
    break;

  case 7: /* exp_or_rec: %empty  */
#line 77 "tiger.y"
                                        {(yyval.exp) = NULL;}
#line 1291 "tiger.tab.c"
    break;

  case 8: /* exp_and: exp_compa exp_and_rec  */
#line 80 "tiger.y"
                                        {(yyval.exp) = A_ExpExp((yyvsp[-1].exp), (yyvsp[0].exp));}
#line 1297 "tiger.tab.c"
    break;

  case 9: /* exp_and_rec: AND exp_compa exp_and_rec  */
#line 81 "tiger.y"
                                        {(yyval.exp) = A_IfExp2(EM_tokPos, (yyvsp[-3].exp), A_IntExp(EM_tokPos, 0), (yyvsp[-1].exp), (yyvsp[0].exp));}
#line 1303 "tiger.tab.c"
    break;

  case 10: /* exp_and_rec: %empty  */
#line 82 "tiger.y"
                                        {(yyval.exp) = NULL;}
#line 1309 "tiger.tab.c"
    break;

  case 11: /* exp_compa: exp_add EQ exp_add  */
#line 85 "tiger.y"
                                        {(yyval.exp) = A_OpExp(EM_tokPos, A_eqOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1315 "tiger.tab.c"
    break;

  case 12: /* exp_compa: exp_add NEQ exp_add  */
#line 86 "tiger.y"
                                        {(yyval.exp) = A_OpExp(EM_tokPos, A_neqOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1321 "tiger.tab.c"
    break;

  case 13: /* exp_compa: exp_add GT exp_add  */
#line 87 "tiger.y"
                                        {(yyval.exp) = A_OpExp(EM_tokPos, A_gtOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1327 "tiger.tab.c"
    break;

  case 14: /* exp_compa: exp_add GE exp_add  */
#line 88 "tiger.y"
                                        {(yyval.exp) = A_OpExp(EM_tokPos, A_geOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1333 "tiger.tab.c"
    break;

  case 15: /* exp_compa: exp_add LT exp_add  */
#line 89 "tiger.y"
                                        {(yyval.exp) = A_OpExp(EM_tokPos, A_ltOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1339 "tiger.tab.c"
    break;

  case 16: /* exp_compa: exp_add LE exp_add  */
#line 90 "tiger.y"
                                        {(yyval.exp) = A_OpExp(EM_tokPos, A_leOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1345 "tiger.tab.c"
    break;

  case 17: /* exp_compa: exp_add  */
#line 91 "tiger.y"
                                        {(yyval.exp) = (yyvsp[0].exp);}
#line 1351 "tiger.tab.c"
    break;

  case 18: /* exp_add: exp_mul exp_add_rec  */
#line 95 "tiger.y"
                                          {(yyval.exp) = A_ExpExp((yyvsp[-1].exp), (yyvsp[0].exp));}
#line 1357 "tiger.tab.c"
    break;

  case 19: /* exp_add_rec: PLUS exp_mul exp_add_rec  */
#line 97 "tiger.y"
                                          {(yyval.exp) = A_OpExp2(EM_tokPos, A_plusOp, (yyvsp[-3].exp), (yyvsp[-1].exp), (yyvsp[0].exp));}
#line 1363 "tiger.tab.c"
    break;

  case 20: /* exp_add_rec: MINUS exp_mul exp_add_rec  */
#line 98 "tiger.y"
                                          {(yyval.exp) = A_OpExp2(EM_tokPos, A_minusOp, (yyvsp[-3].exp), (yyvsp[-1].exp), (yyvsp[0].exp));}
#line 1369 "tiger.tab.c"
    break;

  case 21: /* exp_add_rec: %empty  */
#line 99 "tiger.y"
                                          {(yyval.exp) = NULL;}
#line 1375 "tiger.tab.c"
    break;

  case 22: /* exp_mul: exp_nega exp_mul_rec  */
#line 101 "tiger.y"
                                          {(yyval.exp) = A_ExpExp((yyvsp[-1].exp), (yyvsp[0].exp));}
#line 1381 "tiger.tab.c"
    break;

  case 23: /* exp_mul_rec: TIMES exp_nega exp_mul_rec  */
#line 103 "tiger.y"
                                          { (yyval.exp) = A_OpExp2(EM_tokPos, A_timesOp, (yyvsp[-3].exp), (yyvsp[-1].exp), (yyvsp[0].exp)); }
#line 1387 "tiger.tab.c"
    break;

  case 24: /* exp_mul_rec: DIVIDE exp_nega exp_mul_rec  */
#line 104 "tiger.y"
                                          { (yyval.exp) = A_OpExp2(EM_tokPos, A_divideOp, (yyvsp[-3].exp), (yyvsp[-1].exp), (yyvsp[0].exp)); }
#line 1393 "tiger.tab.c"
    break;

  case 25: /* exp_mul_rec: %empty  */
#line 105 "tiger.y"
                                          {(yyval.exp) = NULL;}
#line 1399 "tiger.tab.c"
    break;

  case 26: /* exp_nega: MINUS exp_nega  */
#line 108 "tiger.y"
                                           {(yyval.exp) = A_OpExp(EM_tokPos, A_minusOp, A_IntExp(0, 0), (yyvsp[0].exp));}
#line 1405 "tiger.tab.c"
    break;

  case 27: /* exp_nega: exp_seq  */
#line 109 "tiger.y"
                                          {(yyval.exp) = (yyvsp[0].exp);}
#line 1411 "tiger.tab.c"
    break;

  case 28: /* exp_seq: LPAREN expseq RPAREN  */
#line 111 "tiger.y"
                                          {(yyval.exp) = A_SeqExp(EM_tokPos, (yyvsp[-1].expList));}
#line 1417 "tiger.tab.c"
    break;

  case 29: /* exp_seq: factor  */
#line 112 "tiger.y"
                                          {(yyval.exp) = (yyvsp[0].exp);}
#line 1423 "tiger.tab.c"
    break;

  case 30: /* factor: NIL  */
#line 114 "tiger.y"
                                          { (yyval.exp) = A_NilExp(EM_tokPos); }
#line 1429 "tiger.tab.c"
    break;

  case 31: /* factor: INT  */
#line 115 "tiger.y"
                                          { (yyval.exp) = A_IntExp(EM_tokPos, yylval.ival); }
#line 1435 "tiger.tab.c"
    break;

  case 32: /* factor: STRING  */
#line 116 "tiger.y"
                                          { (yyval.exp) = A_StringExp(EM_tokPos, yylval.sval); }
#line 1441 "tiger.tab.c"
    break;

  case 33: /* factor: LET decs IN expseq END  */
#line 117 "tiger.y"
                                          { (yyval.exp) = A_LetExp(EM_tokPos, (yyvsp[-3].decList), (yyvsp[-1].expList)); }
#line 1447 "tiger.tab.c"
    break;

  case 34: /* factor: ID LBRACK exp RBRACK OF exp  */
#line 118 "tiger.y"
                                          { (yyval.exp) = A_ArrayExp(EM_tokPos, S_Symbol((yyvsp[-5].sval)), (yyvsp[-3].exp), (yyvsp[0].exp)); }
#line 1453 "tiger.tab.c"
    break;

  case 35: /* factor: IF exp THEN exp ELSE exp  */
#line 119 "tiger.y"
                                          { (yyval.exp) = A_IfExp(EM_tokPos, (yyvsp[-4].exp), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1459 "tiger.tab.c"
    break;

  case 36: /* factor: IF exp THEN exp  */
#line 120 "tiger.y"
                                          { (yyval.exp) = A_IfExp(EM_tokPos, (yyvsp[-2].exp), (yyvsp[0].exp), NULL); }
#line 1465 "tiger.tab.c"
    break;

  case 37: /* factor: lvalue  */
#line 121 "tiger.y"
                                          { (yyval.exp) = A_VarExp(EM_tokPos, (yyvsp[0].var)); }
#line 1471 "tiger.tab.c"
    break;

  case 38: /* factor: funcall  */
#line 122 "tiger.y"
                                          {(yyval.exp) = (yyvsp[0].exp);}
#line 1477 "tiger.tab.c"
    break;

  case 39: /* factor: rec_creation  */
#line 123 "tiger.y"
                                          {(yyval.exp) = (yyvsp[0].exp);}
#line 1483 "tiger.tab.c"
    break;

  case 40: /* expseq: exp  */
#line 125 "tiger.y"
                              { (yyval.expList) = A_ExpList((yyvsp[0].exp), NULL); }
#line 1489 "tiger.tab.c"
    break;

  case 41: /* expseq: %empty  */
#line 126 "tiger.y"
                              { (yyval.expList) = NULL; }
#line 1495 "tiger.tab.c"
    break;

  case 42: /* funcall: ID LPAREN RPAREN  */
#line 128 "tiger.y"
                                    { (yyval.exp) = A_CallExp(EM_tokPos, S_Symbol((yyvsp[-2].sval)), NULL); }
#line 1501 "tiger.tab.c"
    break;

  case 43: /* funcall: ID LPAREN argseq RPAREN  */
#line 129 "tiger.y"
                                    { (yyval.exp) = A_CallExp(EM_tokPos, S_Symbol((yyvsp[-3].sval)), (yyvsp[-1].expList)); }
#line 1507 "tiger.tab.c"
    break;

  case 44: /* argseq: exp COMMA argseq  */
#line 131 "tiger.y"
                          { (yyval.expList) = A_ExpList((yyvsp[-2].exp), (yyvsp[0].expList)); }
#line 1513 "tiger.tab.c"
    break;

  case 45: /* argseq: exp  */
#line 132 "tiger.y"
                          { (yyval.expList) = A_ExpList((yyvsp[0].exp), NULL); }
#line 1519 "tiger.tab.c"
    break;

  case 46: /* rec_creation: ID LBRACE RBRACE  */
#line 134 "tiger.y"
                                          { (yyval.exp) = A_RecordExp(EM_tokPos, S_Symbol((yyvsp[-2].sval)), NULL); }
#line 1525 "tiger.tab.c"
    break;

  case 47: /* rec_creation: ID LBRACE efield_seq RBRACE  */
#line 135 "tiger.y"
                                          { (yyval.exp) = A_RecordExp(EM_tokPos, S_Symbol((yyvsp[-3].sval)), (yyvsp[-1].efieldList)); }
#line 1531 "tiger.tab.c"
    break;

  case 48: /* efield_seq: efield COMMA efield_seq  */
#line 137 "tiger.y"
                                    { (yyval.efieldList) = A_EfieldList((yyvsp[-2].efield), (yyvsp[0].efieldList)); }
#line 1537 "tiger.tab.c"
    break;

  case 49: /* efield_seq: efield  */
#line 138 "tiger.y"
                                    { (yyval.efieldList) = A_EfieldList((yyvsp[0].efield), NULL); }
#line 1543 "tiger.tab.c"
    break;

  case 50: /* efield: ID EQ exp  */
#line 140 "tiger.y"
                    { (yyval.efield) = A_Efield(S_Symbol((yyvsp[-2].sval)), (yyvsp[0].exp)); }
#line 1549 "tiger.tab.c"
    break;

  case 51: /* decs: dec decs  */
#line 143 "tiger.y"
                { (yyval.decList) = A_DecList((yyvsp[-1].dec), (yyvsp[0].decList)); }
#line 1555 "tiger.tab.c"
    break;

  case 52: /* decs: %empty  */
#line 144 "tiger.y"
                { (yyval.decList) = NULL; }
#line 1561 "tiger.tab.c"
    break;

  case 53: /* dec: tydec  */
#line 146 "tiger.y"
              { (yyval.dec) = (yyvsp[0].dec); }
#line 1567 "tiger.tab.c"
    break;

  case 54: /* dec: vardec  */
#line 147 "tiger.y"
              { (yyval.dec) = (yyvsp[0].dec); }
#line 1573 "tiger.tab.c"
    break;

  case 55: /* dec: fundec  */
#line 148 "tiger.y"
              { (yyval.dec) = (yyvsp[0].dec); }
#line 1579 "tiger.tab.c"
    break;

  case 56: /* tydec: TYPE ID EQ ty  */
#line 151 "tiger.y"
                      { (yyval.dec) = A_TypeDec(EM_tokPos, S_Symbol((yyvsp[-2].sval)), (yyvsp[0].ty)); }
#line 1585 "tiger.tab.c"
    break;

  case 57: /* ty: ID  */
#line 153 "tiger.y"
                            { (yyval.ty) = A_NameTy(S_Symbol((yyvsp[0].sval))); }
#line 1591 "tiger.tab.c"
    break;

  case 58: /* ty: LBRACE tyfields RBRACE  */
#line 154 "tiger.y"
                            { (yyval.ty) = A_RecordTy((yyvsp[-1].fieldList)); }
#line 1597 "tiger.tab.c"
    break;

  case 59: /* ty: ARRAY OF ID  */
#line 155 "tiger.y"
                            { (yyval.ty) = A_ArrayTy(S_Symbol((yyvsp[0].sval))); }
#line 1603 "tiger.tab.c"
    break;

  case 60: /* ty: func_ty  */
#line 156 "tiger.y"
                            { (yyval.ty) = (yyvsp[0].ty); }
#line 1609 "tiger.tab.c"
    break;

  case 61: /* func_ty: LPAREN ty_param RPAREN FUNC_RETURN ID  */
#line 159 "tiger.y"
                                                         { (yyval.ty) = A_FuncTySimpleTypeReturn((yyvsp[-3].paramList),A_ParameterList(EM_tokPos, S_Symbol((yyvsp[0].sval)), NULL)); }
#line 1615 "tiger.tab.c"
    break;

  case 62: /* func_ty: LPAREN RPAREN FUNC_RETURN ID  */
#line 160 "tiger.y"
                                                         { (yyval.ty) = A_FuncTySimpleTypeReturn(NULL, A_ParameterList(EM_tokPos, S_Symbol((yyvsp[0].sval)), NULL)); }
#line 1621 "tiger.tab.c"
    break;

  case 63: /* func_ty: ID FUNC_RETURN ID  */
#line 161 "tiger.y"
                                                         { (yyval.ty) = A_FuncTySimpleTypeReturn(A_ParameterList(EM_tokPos, S_Symbol((yyvsp[-2].sval)), NULL), A_ParameterList(EM_tokPos, S_Symbol((yyvsp[0].sval)), NULL)); }
#line 1627 "tiger.tab.c"
    break;

  case 64: /* func_ty: LPAREN ty_param RPAREN FUNC_RETURN func_ty  */
#line 162 "tiger.y"
                                                         { (yyval.ty) = A_FuncTyFuncReturn((yyvsp[-3].paramList),(yyvsp[0].ty)); }
#line 1633 "tiger.tab.c"
    break;

  case 65: /* func_ty: LPAREN RPAREN FUNC_RETURN func_ty  */
#line 163 "tiger.y"
                                                         { (yyval.ty) = A_FuncTyFuncReturn(NULL,(yyvsp[0].ty)); }
#line 1639 "tiger.tab.c"
    break;

  case 66: /* func_ty: ID FUNC_RETURN func_ty  */
#line 164 "tiger.y"
                                                         { (yyval.ty) = A_FuncTyFuncReturn(A_ParameterList(EM_tokPos, S_Symbol((yyvsp[-2].sval)), NULL), (yyvsp[0].ty)); }
#line 1645 "tiger.tab.c"
    break;

  case 67: /* ty_param: ID ty_param_tail  */
#line 167 "tiger.y"
                            { (yyval.paramList) = A_ParameterList(EM_tokPos, S_Symbol((yyvsp[-1].sval)), (yyvsp[0].paramList)); }
#line 1651 "tiger.tab.c"
    break;

  case 68: /* ty_param_tail: COMMA ID ty_param_tail  */
#line 170 "tiger.y"
                                      { (yyval.paramList) = A_ParameterList(EM_tokPos, S_Symbol((yyvsp[-1].sval)), (yyvsp[0].paramList)); }
#line 1657 "tiger.tab.c"
    break;

  case 69: /* ty_param_tail: %empty  */
#line 171 "tiger.y"
                                      { (yyval.paramList) = NULL; }
#line 1663 "tiger.tab.c"
    break;

  case 70: /* tyfields: tyfield tail_tyfields  */
#line 174 "tiger.y"
                                { (yyval.fieldList) = A_FieldList((yyvsp[-1].field), (yyvsp[0].fieldList)); }
#line 1669 "tiger.tab.c"
    break;

  case 71: /* tyfields: %empty  */
#line 175 "tiger.y"
                                { (yyval.fieldList) = NULL; }
#line 1675 "tiger.tab.c"
    break;

  case 72: /* tail_tyfields: COMMA tyfield tail_tyfields  */
#line 178 "tiger.y"
                                            { (yyval.fieldList) = A_FieldList((yyvsp[-1].field), (yyvsp[0].fieldList)); }
#line 1681 "tiger.tab.c"
    break;

  case 73: /* tail_tyfields: %empty  */
#line 179 "tiger.y"
                                            { (yyval.fieldList) = NULL; }
#line 1687 "tiger.tab.c"
    break;

  case 74: /* tyfield: ID COLON ID  */
#line 181 "tiger.y"
                      { (yyval.field) = A_Field(EM_tokPos, S_Symbol((yyvsp[-2].sval)), S_Symbol((yyvsp[0].sval))); }
#line 1693 "tiger.tab.c"
    break;

  case 75: /* vardec: VAR ID ASSIGN exp  */
#line 184 "tiger.y"
                                    { (yyval.dec) = A_VarDec(EM_tokPos, S_Symbol((yyvsp[-2].sval)), NULL, (yyvsp[0].exp)); }
#line 1699 "tiger.tab.c"
    break;

  case 76: /* vardec: VAR ID COLON ID ASSIGN exp  */
#line 185 "tiger.y"
                                    { (yyval.dec) = A_VarDec(EM_tokPos, S_Symbol((yyvsp[-4].sval)), S_Symbol((yyvsp[-2].sval)), (yyvsp[0].exp)); }
#line 1705 "tiger.tab.c"
    break;

  case 77: /* fundec: FUNCTION ID LPAREN tyfields RPAREN EQ exp  */
#line 188 "tiger.y"
                                                            {(yyval.dec) = A_Fundec(EM_tokPos, S_Symbol((yyvsp[-5].sval)), (yyvsp[-3].fieldList), NULL, (yyvsp[0].exp)); }
#line 1711 "tiger.tab.c"
    break;

  case 78: /* fundec: FUNCTION ID LPAREN tyfields RPAREN COLON ID EQ exp  */
#line 189 "tiger.y"
                                                            {(yyval.dec) = A_Fundec(EM_tokPos, S_Symbol((yyvsp[-7].sval)), (yyvsp[-5].fieldList), S_Symbol((yyvsp[-2].sval)), (yyvsp[0].exp)); }
#line 1717 "tiger.tab.c"
    break;

  case 79: /* lvalue: ID  */
#line 192 "tiger.y"
                      { (yyval.var) = A_SimpleVar(EM_tokPos, S_Symbol((yyvsp[0].sval))); }
#line 1723 "tiger.tab.c"
    break;

  case 80: /* lvalue: ID DOT ID  */
#line 193 "tiger.y"
                      { (yyval.var) = A_FieldVar(EM_tokPos, A_SimpleVar(EM_tokPos, S_Symbol((yyvsp[-2].sval))), S_Symbol((yyvsp[0].sval))); }
#line 1729 "tiger.tab.c"
    break;

  case 81: /* lvalue: lvalue DOT ID  */
#line 194 "tiger.y"
                      { (yyval.var) = A_FieldVar(EM_tokPos, (yyvsp[-2].var), S_Symbol((yyvsp[0].sval))); }
#line 1735 "tiger.tab.c"
    break;

  case 82: /* lvalue: ID LBRACK exp RBRACK  */
#line 195 "tiger.y"
                                  { (yyval.var) = A_SubscriptVar(EM_tokPos, A_SimpleVar(EM_tokPos, S_Symbol((yyvsp[-3].sval))), (yyvsp[-1].exp)); }
#line 1741 "tiger.tab.c"
    break;

  case 83: /* lvalue: lvalue LBRACK exp RBRACK  */
#line 196 "tiger.y"
                                  { (yyval.var) = A_SubscriptVar(EM_tokPos, (yyvsp[-3].var), (yyvsp[-1].exp)); }
#line 1747 "tiger.tab.c"
    break;


#line 1751 "tiger.tab.c"

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

