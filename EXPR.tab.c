/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "EXPR.y" /* yacc.c:339  */


#include "EXPRc.h"

int yydebug=1; 

extern void yyerror(const char * s);
extern int yylex();


#line 77 "EXPR.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "EXPR.tab.h".  */
#ifndef YY_YY_EXPR_TAB_H_INCLUDED
# define YY_YY_EXPR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TEXSCI_BEGIN = 258,
    TEXSCI_END = 259,
    BLANKLINE = 260,
    MULT = 261,
    ID = 262,
    INT = 263,
    STRING = 264,
    IN = 265,
    INTEGER = 266,
    LOCAL = 267,
    PLUS = 268,
    MINUS = 269,
    IF = 270,
    EIF = 271,
    WHILE = 272,
    FOR = 273,
    TO = 274,
    TCC = 275,
    NON = 276,
    ET = 277,
    OU = 278,
    PLUSGRAND = 279,
    PLUSPETIT = 280,
    PLUSGRANDEG = 281,
    PLUSPETITEG = 282,
    NONEG = 283,
    LEFTARROW = 284,
    MBOX = 285,
    PRINT = 286,
    PRINTTEXT = 287,
    PRINTLN = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "EXPR.y" /* yacc.c:355  */

	int intval;
	name_t strval;
	char* stringval;
	struct {
		struct symbol * ptr;
		struct code * code;
		int index;
	} exprval;
	struct {
		struct code * code;
	} code;
  struct {
    struct code * true;
    struct code * false;
  } cond;

#line 169 "EXPR.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EXPR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 186 "EXPR.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   236

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  46
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    36,     2,     2,     2,
      42,    43,     2,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,    44,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    40,     2,    38,    39,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    58,    58,    59,    63,    74,    81,    86,    91,    96,
     101,   123,   124,   128,   140,   157,   190,   201,   215,   246,
     250,   255,   261,   266,   270,   279,   295,   314,   351,   356,
     367,   377,   387,   392,   402,   410,   411,   412,   413,   423,
     437,   445,   454,   463,   472,   481,   490
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TEXSCI_BEGIN", "TEXSCI_END",
  "BLANKLINE", "MULT", "ID", "INT", "STRING", "IN", "INTEGER", "LOCAL",
  "PLUS", "MINUS", "IF", "EIF", "WHILE", "FOR", "TO", "TCC", "NON", "ET",
  "OU", "PLUSGRAND", "PLUSPETIT", "PLUSGRANDEG", "PLUSPETITEG", "NONEG",
  "LEFTARROW", "MBOX", "PRINT", "PRINTTEXT", "PRINTLN", "'{'", "'}'",
  "'$'", "','", "'^'", "'_'", "'\\\\'", "';'", "'('", "')'", "'='",
  "$accept", "algorithm_list", "algorithm", "variables", "variabledef",
  "commandes", "identifiant", "commande", "expression", "conditions",
  "condition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   123,   125,    36,    44,    94,    95,
      92,    59,    40,    41,    61
};
# endif

#define YYPACT_NINF -33

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-33)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,    -3,    55,   -33,    28,   -33,   -33,     5,   -33,    24,
     139,    25,    31,    40,    41,    44,    46,   -33,    27,    85,
      56,   139,    45,    74,    84,    87,    90,    -4,    32,   100,
     -33,    58,   -33,   123,    80,    65,    65,    65,   140,   129,
      80,   118,   137,   -33,   148,   -18,   -33,    80,    80,   -33,
      63,    65,    65,    38,    70,   -33,   102,   141,   131,   105,
      80,   132,   134,   138,   154,   146,   166,   -33,    54,    80,
      80,    80,   -33,    80,   -33,    -1,   -13,    80,    80,    80,
      80,    80,    80,    65,    65,   149,   150,   151,    80,   -33,
      96,   152,   153,   144,   145,   -33,   180,   -33,   -33,   -33,
     -33,    77,   -33,   165,   165,   165,   165,   165,   165,   -33,
     -33,   157,   158,   159,   115,   167,    80,    80,   185,   160,
     163,   187,   -33,   139,   139,   139,   164,    80,   147,   126,
     168,   169,   192,   -33,   171,   172,   173,   175,   130,   174,
     170,   176,   161,    -2,   -33,   177,   -33,   139,   -33,    80,
     179,   181,   182,   194,   -33,   139,   183,   136,   184,   186,
     -33,   189,   190,   -33,   -33,   188,   191,   -33,   -33,   193,
     195,   -33,   -33
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     0,     1,     2,     0,     6,     0,
      12,     0,    16,     0,     0,     0,     0,    23,     0,     0,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     0,    28,     0,     0,    29,
       0,     0,     0,    40,     0,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     0,    17,     0,    37,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
       0,     0,     0,     0,     7,     5,     0,    34,    33,    30,
      31,     0,    36,    43,    44,    45,    46,    42,    41,    38,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    12,    12,    12,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,     0,    26,    12,    14,     0,
       0,     0,     0,     0,     9,    12,     0,     0,     0,     0,
      22,     0,     0,    27,    15,     0,     0,    10,    25,     0,
       0,    20,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -33,   -33,   208,   -33,   -33,   -20,   -10,   -33,   -32,   -30,
     -33
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     9,    45,    19,    49,    21,    53,    54,
      55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      20,    32,    50,    12,   153,    69,    56,    57,    59,    83,
      84,    20,    70,    71,     1,    67,    68,    39,    65,    66,
      75,    74,    76,    77,    78,    79,    80,    81,    90,    10,
     102,     4,    38,   154,    28,     7,    11,    98,    99,   100,
       8,   101,    97,    82,    69,   103,   104,   105,   106,   107,
     108,    70,    71,   109,   110,     5,   114,    29,     1,    22,
      69,    40,    77,    78,    79,    80,    81,    70,    71,    69,
      23,    41,    12,    46,    24,    25,    70,    71,    26,    47,
      27,    33,    82,    69,   128,   129,    51,    12,    46,    30,
      70,    71,    83,    84,    47,   138,    31,    97,    72,    43,
      73,    38,    69,   134,   135,   136,    85,    52,    34,    70,
      71,    69,   122,    20,    20,    20,    38,   157,    70,    71,
      35,    69,    48,    36,    83,    84,    37,   156,    70,    71,
      44,   115,    69,   116,    42,   162,    69,    20,    86,    70,
      71,    89,    69,    70,    71,    20,    12,    28,    58,    70,
      71,   126,    60,    69,    13,    14,    15,    16,    64,    17,
      70,    71,   140,    83,    84,    94,   148,    88,    61,    62,
      63,    69,   164,    96,    91,    18,    92,    87,    70,    71,
      93,    95,   139,   120,   111,   112,   113,   119,   117,   118,
     121,   123,   124,   125,   130,   131,   127,   132,   133,   137,
     143,   152,   161,   149,   141,   142,   144,   145,   146,   147,
       6,   155,     0,   150,   158,     0,   159,     0,   163,   151,
     165,     0,   166,   160,   167,   168,     0,     0,   169,     0,
       0,   170,     0,     0,   171,     0,   172
};

static const yytype_int16 yycheck[] =
{
      10,    21,    34,     7,     6,     6,    36,    37,    40,    22,
      23,    21,    13,    14,     3,    47,    48,    27,    36,    37,
      52,    51,    52,    24,    25,    26,    27,    28,    60,     5,
      43,    34,    36,    35,     7,     7,    12,    69,    70,    71,
      35,    73,    43,    44,     6,    77,    78,    79,    80,    81,
      82,    13,    14,    83,    84,     0,    88,    30,     3,    34,
       6,    29,    24,    25,    26,    27,    28,    13,    14,     6,
      39,    39,     7,     8,    34,    34,    13,    14,    34,    14,
      34,    36,    44,     6,   116,   117,    21,     7,     8,     4,
      13,    14,    22,    23,    14,   127,    40,    43,    35,    41,
      37,    36,     6,   123,   124,   125,    36,    42,    34,    13,
      14,     6,    35,   123,   124,   125,    36,   149,    13,    14,
      36,     6,    42,    36,    22,    23,    36,   147,    13,    14,
       7,    35,     6,    37,    34,   155,     6,   147,    36,    13,
      14,    36,     6,    13,    14,   155,     7,     7,    19,    13,
      14,    36,    34,     6,    15,    16,    17,    18,    10,    20,
      13,    14,    36,    22,    23,    11,    36,    36,    31,    32,
      33,     6,    36,     7,    42,    36,    42,    36,    13,    14,
      42,    35,    35,    38,    35,    35,    35,    43,    36,    36,
      10,    34,    34,    34,     9,    35,    29,    34,    11,    35,
       8,    40,     8,    29,    36,    36,    35,    35,    35,    34,
       2,    34,    -1,    43,    35,    -1,    35,    -1,    35,    43,
      36,    -1,    36,    41,    35,    35,    -1,    -1,    40,    -1,
      -1,    40,    -1,    -1,    41,    -1,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    46,    47,    34,     0,    47,     7,    35,    48,
       5,    12,     7,    15,    16,    17,    18,    20,    36,    50,
      51,    52,    34,    39,    34,    34,    34,    34,     7,    30,
       4,    40,    50,    36,    34,    36,    36,    36,    36,    51,
      29,    39,    34,    41,     7,    49,     8,    14,    42,    51,
      53,    21,    42,    53,    54,    55,    54,    54,    19,    53,
      34,    31,    32,    33,    10,    36,    37,    53,    53,     6,
      13,    14,    35,    37,    54,    53,    54,    24,    25,    26,
      27,    28,    44,    22,    23,    36,    36,    36,    36,    36,
      53,    42,    42,    42,    11,    35,     7,    43,    53,    53,
      53,    53,    43,    53,    53,    53,    53,    53,    53,    54,
      54,    35,    35,    35,    53,    35,    37,    36,    36,    43,
      38,    10,    35,    34,    34,    34,    36,    29,    53,    53,
       9,    35,    34,    11,    50,    50,    50,    35,    53,    35,
      36,    36,    36,     8,    35,    35,    35,    34,    36,    29,
      43,    43,    40,     6,    35,    34,    50,    53,    35,    35,
      41,     8,    50,    35,    36,    36,    36,    35,    35,    40,
      40,    41,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    47,    48,    48,    49,    49,    49,
      49,    50,    50,    51,    51,    51,    51,    51,    51,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
      53,    53,    53,    53,    53,    54,    54,    54,    54,    54,
      55,    55,    55,    55,    55,    55,    55
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     8,     7,     0,     3,     5,     7,
       9,     2,     0,     5,     9,    11,     1,     5,     7,     3,
      13,    13,    10,     1,     9,    12,     9,    11,     1,     1,
       3,     3,     2,     3,     3,     1,     3,     2,     3,     3,
       1,     3,     3,     3,     3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 4:
#line 64 "EXPR.y" /* yacc.c:1646  */
    {
			fprintf(stderr, "[texcc] info: algorithm \"%s\" parsed\n", (yyvsp[-5].strval));
			//free($3);
			CODE=concat_code((yyvsp[-3].code).code, (yyvsp[-1].code).code);
			code_free((yyvsp[-3].code).code);
			code_free((yyvsp[-1].code).code);
		}
#line 1382 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 75 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.code).code = concat_code((yyvsp[-6].code).code, (yyvsp[-2].code).code);
			code_free((yyvsp[-6].code).code);
			code_free((yyvsp[-2].code).code);
		}
#line 1392 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 81 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.code).code = code_new();
		}
#line 1400 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 87 "EXPR.y" /* yacc.c:1646  */
    {
	  		(yyval.code).code = code_new();
	  		struct symbol * id = symtable_put(SYMTAB,(yyvsp[-2].strval));
	  	}
#line 1409 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 92 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.code).code = (yyvsp[-4].code).code;
			struct symbol * id = symtable_put(SYMTAB,(yyvsp[-2].strval));
		}
#line 1418 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 97 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.code).code = code_new();
			struct symbol * id = symtable_put_list(SYMTAB,(yyvsp[-6].strval), (yyvsp[-1].intval), "INT");
		}
#line 1427 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 102 "EXPR.y" /* yacc.c:1646  */
    {
			char *str = malloc((strlen((yyvsp[-8].strval))+10)*sizeof(char));

			(yyval.code).code = code_new();
			symtable_put_list(SYMTAB,(yyvsp[-8].strval), (yyvsp[-3].intval)*(yyvsp[-1].intval), "INT");

			strcpy(str, (yyvsp[-8].strval));
			strcat(str, "_h");
			struct symbol * id = symtable_put_list_dim(SYMTAB,str);
			gencode((yyval.code).code,COPY,id,symtable_const(SYMTAB,(yyvsp[-3].intval)),NULL);

			strcpy(str, (yyvsp[-8].strval));
			strcat(str, "_w");
			id = symtable_put_list_dim(SYMTAB,str);
			gencode((yyval.code).code,COPY,id,symtable_const(SYMTAB,(yyvsp[-1].intval)),NULL);

			free(str);
		}
#line 1450 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 123 "EXPR.y" /* yacc.c:1646  */
    { (yyval.code).code = concat_code((yyvsp[-1].code).code,(yyvsp[0].code).code);code_free((yyvsp[-1].code).code);code_free((yyvsp[0].code).code); }
#line 1456 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 124 "EXPR.y" /* yacc.c:1646  */
    { (yyval.code).code=code_new(); }
#line 1462 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 129 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.exprval).code = (yyvsp[-1].exprval).code;
			struct symbol * id = symtable_get(SYMTAB,(yyvsp[-3].strval));
			if ( id == NULL )
			{
				fprintf(stderr,"::error::Name '%s' undeclared\n",(yyvsp[-3].strval));
				exit(3);
			}
			gencode((yyval.exprval).code,COPY,id,(yyvsp[-1].exprval).ptr,NULL);
			(yyval.exprval).ptr = id;
		}
#line 1478 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 141 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.exprval).code = concat_code((yyvsp[-4].exprval).code, (yyvsp[-1].exprval).code);
			code_free((yyvsp[-4].exprval).code);
			code_free((yyvsp[-1].exprval).code);

			struct symbol * list = symtable_get(SYMTAB,(yyvsp[-7].strval));
			if ( list == NULL )
			{
				fprintf(stderr,"::error::Name '%s' undeclared\n",(yyvsp[-7].strval));
				exit(3);
			}
			gencode((yyval.exprval).code,LIST_SET,list,symtable_const(SYMTAB,(yyvsp[-4].exprval).ptr->u.value),(yyvsp[-1].exprval).ptr);
			
			(yyval.exprval).ptr = list;
			(yyval.exprval).index = (yyvsp[-4].exprval).ptr->u.value;
		}
#line 1499 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 158 "EXPR.y" /* yacc.c:1646  */
    {
			char *str = malloc((strlen((yyvsp[-9].strval))+10)*sizeof(char));
			struct symbol *tmp = newtemp(SYMTAB);

			(yyval.exprval).code = concat_code((yyvsp[-6].exprval).code, (yyvsp[-4].exprval).code);
			code_free((yyvsp[-6].exprval).code);
			code_free((yyvsp[-4].exprval).code);

			struct code * tmp_code =(yyval.exprval).code;
			(yyval.exprval).code = concat_code((yyval.exprval).code, (yyvsp[-1].exprval).code);
			code_free(tmp_code);
			code_free((yyvsp[-1].exprval).code);

			struct symbol * list = symtable_get(SYMTAB,(yyvsp[-9].strval));
			if ( list == NULL )
			{
				fprintf(stderr,"::error::Name '%s' undeclared\n",(yyvsp[-9].strval));
				exit(1);
			}

			strcpy(str, (yyvsp[-9].strval));
			strcat(str, "_h");

			struct symbol * height = symtable_get(SYMTAB,str);
			gencode((yyval.exprval).code,BOP_MULT,tmp,(yyvsp[-6].exprval).ptr,height);
			gencode((yyval.exprval).code,BOP_PLUS,tmp,tmp,(yyvsp[-4].exprval).ptr);
			gencode((yyval.exprval).code,LIST_SET,list,tmp,(yyvsp[-1].exprval).ptr);
			
			(yyval.exprval).ptr = list;
			(yyval.exprval).index = tmp->u.value;
			free(str);
		}
#line 1536 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 191 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.exprval).code = code_new();
			struct symbol * id = symtable_get(SYMTAB,(yyvsp[0].strval));
			if ( id == NULL )
			{
				fprintf(stderr,"::error::Name '%s' undeclared\n",(yyvsp[0].strval));
				exit(3);
			}
			(yyval.exprval).ptr = id;
		}
#line 1551 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 202 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.exprval).code = (yyvsp[-1].exprval).code;

			struct symbol * list = symtable_get(SYMTAB,(yyvsp[-4].strval));
			if ( list == NULL )
			{
				fprintf(stderr,"::error::Name '%s' undeclared\n",(yyvsp[-4].strval));
				exit(3);
			}
			
			(yyval.exprval).ptr = list;
			(yyval.exprval).index = (yyvsp[-1].exprval).ptr->u.value;
		}
#line 1569 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 216 "EXPR.y" /* yacc.c:1646  */
    {
			char *str = malloc((strlen((yyvsp[-6].strval))+10)*sizeof(char));
			struct symbol *tmp = newtemp(SYMTAB);

			(yyval.exprval).code = concat_code((yyvsp[-3].exprval).code, (yyvsp[-1].exprval).code);
			code_free((yyvsp[-3].exprval).code);
			code_free((yyvsp[-1].exprval).code);

			struct symbol * list = symtable_get(SYMTAB,(yyvsp[-6].strval));
			if ( list == NULL )
			{
				fprintf(stderr,"::error::Name '%s' undeclared\n",(yyvsp[-6].strval));
				exit(1);
			}

			strcpy(str, (yyvsp[-6].strval));
			strcat(str, "_h");

			struct symbol * height = symtable_get(SYMTAB,str);
			gencode((yyval.exprval).code,BOP_MULT,tmp,(yyvsp[-3].exprval).ptr,height);
			gencode((yyval.exprval).code,BOP_PLUS,tmp,tmp,(yyvsp[-1].exprval).ptr);
			
			(yyval.exprval).ptr = list;
			(yyval.exprval).index = tmp->u.value;

			free(str);
		}
#line 1601 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 247 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.code).code = (yyvsp[-2].exprval).code;
		}
#line 1609 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 251 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.code).code = (yyvsp[-6].exprval).code;
			gencode((yyval.code).code,CALL_PRINT,(yyvsp[-6].exprval).ptr,NULL,NULL);
		}
#line 1618 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 256 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.code).code = code_new();
			struct symbol * id = symtable_put_string(SYMTAB,(yyvsp[-6].stringval));
			gencode((yyval.code).code,CALL_PRINT_STRING,id,NULL,NULL);
		}
#line 1628 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 262 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.code).code = code_new();
			gencode((yyval.code).code,CALL_PRINT_LN,NULL,NULL,NULL);
		}
#line 1637 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 267 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.code).code = code_new();
		}
#line 1645 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 271 "EXPR.y" /* yacc.c:1646  */
    {
			struct symbol * out = newlabel(SYMTAB);
			code_replace_unknow_label((yyvsp[-5].cond).true,out);
			(yyval.code).code = concat_code((yyvsp[-5].cond).true,(yyvsp[-1].code).code);
			gencode((yyval.code).code,SET_LABEL,out,NULL,NULL);
			code_free((yyvsp[-5].cond).true);code_free((yyvsp[-5].cond).false);
			code_free((yyvsp[-1].code).code);
		}
#line 1658 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 280 "EXPR.y" /* yacc.c:1646  */
    {
			struct symbol *label_else = newlabel(SYMTAB);
			struct symbol *out = newlabel(SYMTAB);

			gencode((yyvsp[-4].code).code,GOTO,out,NULL,NULL);
			gencode((yyvsp[-4].code).code,SET_LABEL,label_else,NULL,NULL);
			code_replace_unknow_label((yyvsp[-8].cond).true,label_else);

			(yyval.code).code = concat_code((yyvsp[-8].cond).true,(yyvsp[-4].code).code);
			struct code * tmp_code =(yyval.code).code;
			(yyval.code).code = concat_code((yyval.code).code, (yyvsp[-1].code).code);
			code_free(tmp_code);
			gencode((yyval.code).code,SET_LABEL,out,NULL,NULL);
			code_free((yyvsp[-8].cond).true);code_free((yyvsp[-8].cond).false);
		}
#line 1678 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 296 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.code).code = code_new();
			struct symbol *label_while = newlabel(SYMTAB);
			gencode((yyval.code).code,SET_LABEL,label_while,NULL,NULL);

			struct symbol * out = newlabel(SYMTAB);
			code_replace_unknow_label((yyvsp[-5].cond).true,out);
			gencode((yyvsp[-1].code).code,GOTO,label_while,NULL,NULL);
			struct code * tmp_code =(yyval.code).code;
			(yyval.code).code = concat_code((yyval.code).code,(yyvsp[-5].cond).true);
			code_free(tmp_code);
			tmp_code =(yyval.code).code;
			(yyval.code).code = concat_code((yyval.code).code,(yyvsp[-1].code).code);
			code_free(tmp_code);
			gencode((yyval.code).code,SET_LABEL,out,NULL,NULL);
			code_free((yyvsp[-5].cond).true);code_free((yyvsp[-5].cond).false);
			code_free((yyvsp[-1].code).code);
		}
#line 1701 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 315 "EXPR.y" /* yacc.c:1646  */
    {
			struct symbol *tmp;
			struct symbol *label_for = newlabel(SYMTAB);
			struct symbol *label_out = newlabel(SYMTAB);

			if((yyvsp[-8].exprval).ptr->kind == LIST) {
				tmp = newtemp(SYMTAB);
			}

			(yyval.code).code = (yyvsp[-8].exprval).code;
			gencode((yyval.code).code,SET_LABEL,label_for,NULL,NULL);

			if((yyvsp[-8].exprval).ptr->kind == LIST) {
				gencode((yyvsp[-1].code).code,LIST_GET,tmp,(yyvsp[-8].exprval).ptr,symtable_const(SYMTAB,(yyvsp[-8].exprval).index));
				// Egalité
				gencode((yyvsp[-1].code).code, TEST_EGALITE, label_out, tmp, (yyvsp[-5].exprval).ptr);
				// Affection
				gencode((yyvsp[-1].code).code, BOP_PLUS, tmp, tmp, symtable_const(SYMTAB, 1));
				gencode((yyvsp[-1].code).code,LIST_SET,(yyvsp[-8].exprval).ptr,symtable_const(SYMTAB,(yyvsp[-8].exprval).index),tmp);
			}
			else {
				// Egalité
				gencode((yyvsp[-1].code).code, TEST_EGALITE, label_out, (yyvsp[-8].exprval).ptr, (yyvsp[-5].exprval).ptr);
				// Affection
				gencode((yyvsp[-1].code).code, BOP_PLUS, (yyvsp[-8].exprval).ptr, (yyvsp[-8].exprval).ptr, symtable_const(SYMTAB, 1));
			}

			gencode((yyvsp[-1].code).code,GOTO,label_for,NULL,NULL);
			gencode((yyvsp[-1].code).code,SET_LABEL,label_out,NULL,NULL);
			struct code * tmp_code =(yyval.code).code;
			(yyval.code).code = concat_code((yyval.code).code, (yyvsp[-1].code).code);
			code_free((yyvsp[-1].code).code);code_free(tmp_code);
		}
#line 1739 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 352 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.exprval).ptr = symtable_const(SYMTAB,(yyvsp[0].intval));
			(yyval.exprval).code = code_new();
		}
#line 1748 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 357 "EXPR.y" /* yacc.c:1646  */
    {
			if((yyval.exprval).ptr->kind == LIST) {
				(yyval.exprval).ptr = newtemp(SYMTAB);
				gencode((yyval.exprval).code,LIST_GET,(yyval.exprval).ptr,(yyvsp[0].exprval).ptr,symtable_const(SYMTAB,(yyvsp[0].exprval).index));
			}
			else
				(yyval.exprval).ptr = (yyvsp[0].exprval).ptr;

			(yyval.exprval).code = (yyvsp[0].exprval).code;
		}
#line 1763 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 368 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.exprval).ptr = newtemp(SYMTAB);

			(yyval.exprval).code = concat_code((yyvsp[-2].exprval).code,(yyvsp[0].exprval).code);
			code_free((yyvsp[-2].exprval).code);
			code_free((yyvsp[0].exprval).code); 

			gencode((yyval.exprval).code,BOP_PLUS,(yyval.exprval).ptr,(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);
		}
#line 1777 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 378 "EXPR.y" /* yacc.c:1646  */
    { 
			(yyval.exprval).ptr = newtemp(SYMTAB);

			(yyval.exprval).code = concat_code((yyvsp[-2].exprval).code,(yyvsp[0].exprval).code);
			code_free((yyvsp[-2].exprval).code);
			code_free((yyvsp[0].exprval).code); 

			gencode((yyval.exprval).code,BOP_MINUS,(yyval.exprval).ptr,(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);
		}
#line 1791 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 388 "EXPR.y" /* yacc.c:1646  */
    { 
			(yyval.exprval).ptr = symtable_const(SYMTAB,-1 * (yyvsp[0].exprval).ptr->u.value);
			(yyval.exprval).code = (yyvsp[0].exprval).code;
		}
#line 1800 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 393 "EXPR.y" /* yacc.c:1646  */
    { 
			(yyval.exprval).ptr = newtemp(SYMTAB);

			(yyval.exprval).code = concat_code((yyvsp[-2].exprval).code,(yyvsp[0].exprval).code);
			code_free((yyvsp[-2].exprval).code);
			code_free((yyvsp[0].exprval).code); 

			gencode((yyval.exprval).code,BOP_MULT,(yyval.exprval).ptr,(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);
		}
#line 1814 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 403 "EXPR.y" /* yacc.c:1646  */
    { 
			(yyval.exprval).ptr = (yyvsp[-1].exprval).ptr;
			(yyval.exprval).code = (yyvsp[-1].exprval).code;
		}
#line 1823 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 410 "EXPR.y" /* yacc.c:1646  */
    { (yyval.cond).true = (yyvsp[0].cond).true;(yyval.cond).false = (yyvsp[0].cond).false; }
#line 1829 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 411 "EXPR.y" /* yacc.c:1646  */
    { (yyval.cond).true = (yyvsp[-1].cond).true;(yyval.cond).false = (yyvsp[-1].cond).false; }
#line 1835 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 412 "EXPR.y" /* yacc.c:1646  */
    { (yyval.cond).true = (yyvsp[0].cond).false;(yyval.cond).false = (yyvsp[0].cond).true; }
#line 1841 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 414 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.cond).true = concat_code((yyvsp[-2].cond).true,(yyvsp[0].cond).true);
			struct symbol * out = newlabel(SYMTAB);
			(yyval.cond).false = concat_code((yyvsp[-2].cond).true,(yyvsp[0].cond).false);
			code_replace_unknow_label((yyvsp[-2].cond).true,out);
			gencode((yyval.cond).false,SET_LABEL,out,NULL,NULL);
			code_free((yyvsp[0].cond).true);code_free((yyvsp[0].cond).false);
			code_free((yyvsp[-2].cond).true);code_free((yyvsp[-2].cond).false);
		}
#line 1855 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 424 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.cond).false = concat_code((yyvsp[-2].cond).false,(yyvsp[0].cond).false);
			struct symbol * out = newlabel(SYMTAB);
			code_replace_unknow_label((yyvsp[-2].cond).false,out);
			(yyval.cond).true = concat_code((yyvsp[-2].cond).false,(yyvsp[0].cond).true);
			gencode((yyval.cond).true,SET_LABEL,out,NULL,NULL);
			code_free((yyvsp[0].cond).true);code_free((yyvsp[0].cond).false);
			code_free((yyvsp[-2].cond).true);code_free((yyvsp[-2].cond).false);
		}
#line 1869 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 438 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.cond).false = code_new();
			(yyval.cond).false = concat_code((yyval.cond).false,(yyvsp[0].exprval).code);
			gencode((yyval.cond).false,TEST_VAR,label_unknown(),(yyvsp[0].exprval).ptr,NULL);
			(yyval.cond).true =(yyvsp[0].exprval).code;
			gencode((yyval.cond).true,TEST_NON_VAR,label_unknown(),(yyvsp[0].exprval).ptr,NULL);
		}
#line 1881 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 446 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.cond).true = concat_code((yyvsp[-2].exprval).code,(yyvsp[0].exprval).code);
			gencode((yyval.cond).true,TEST_NON_EGALITE,label_unknown(),(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);
			(yyval.cond).false = concat_code((yyvsp[-2].exprval).code,(yyvsp[0].exprval).code);
			gencode((yyval.cond).false,TEST_EGALITE,label_unknown(),(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);
			code_free((yyvsp[-2].exprval).code);
			code_free((yyvsp[0].exprval).code);
		}
#line 1894 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 455 "EXPR.y" /* yacc.c:1646  */
    {
      (yyval.cond).true = concat_code((yyvsp[-2].exprval).code,(yyvsp[0].exprval).code);
      gencode((yyval.cond).true,TEST_EGALITE,label_unknown(),(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);
      (yyval.cond).false = concat_code((yyvsp[-2].exprval).code,(yyvsp[0].exprval).code);
      gencode((yyval.cond).false,TEST_NON_EGALITE,label_unknown(),(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);
      code_free((yyvsp[-2].exprval).code);
      code_free((yyvsp[0].exprval).code);
    }
#line 1907 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 464 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.cond).true = concat_code((yyvsp[-2].exprval).code,(yyvsp[0].exprval).code);
			gencode((yyval.cond).true,TEST_LESS_OR_EQ,label_unknown(),(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);
			(yyval.cond).false = concat_code((yyvsp[-2].exprval).code,(yyvsp[0].exprval).code);
			gencode((yyval.cond).false,TEST_GREATER,label_unknown(),(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);
			code_free((yyvsp[-2].exprval).code);
			code_free((yyvsp[0].exprval).code);
		}
#line 1920 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 473 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.cond).true = concat_code((yyvsp[-2].exprval).code,(yyvsp[0].exprval).code);
			gencode((yyval.cond).true,TEST_GREATER_OR_EQ,label_unknown(),(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);
			(yyval.cond).false = concat_code((yyvsp[-2].exprval).code,(yyvsp[0].exprval).code);
			gencode((yyval.cond).false,TEST_LESS,label_unknown(),(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);
			code_free((yyvsp[-2].exprval).code);
			code_free((yyvsp[0].exprval).code);
		}
#line 1933 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 482 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.cond).true = concat_code((yyvsp[-2].exprval).code,(yyvsp[0].exprval).code);
			gencode((yyval.cond).true,TEST_LESS,label_unknown(),(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);
			(yyval.cond).false = concat_code((yyvsp[-2].exprval).code,(yyvsp[0].exprval).code);
			gencode((yyval.cond).false,TEST_GREATER_OR_EQ,label_unknown(),(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);
			code_free((yyvsp[-2].exprval).code);
			code_free((yyvsp[0].exprval).code);
		}
#line 1946 "EXPR.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 491 "EXPR.y" /* yacc.c:1646  */
    {
			(yyval.cond).true = concat_code((yyvsp[-2].exprval).code,(yyvsp[0].exprval).code);
			gencode((yyval.cond).true,TEST_GREATER,label_unknown(),(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);
			(yyval.cond).false = concat_code((yyvsp[-2].exprval).code,(yyvsp[0].exprval).code);
			gencode((yyval.cond).false,TEST_LESS_OR_EQ,label_unknown(),(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);
			code_free((yyvsp[-2].exprval).code);
			code_free((yyvsp[0].exprval).code);
		}
#line 1959 "EXPR.tab.c" /* yacc.c:1646  */
    break;


#line 1963 "EXPR.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 501 "EXPR.y" /* yacc.c:1906  */


void yyerror(const char * s)
{
	fprintf(stderr,"erreur de syntaxe:%s\n",s);exit(2);
}

