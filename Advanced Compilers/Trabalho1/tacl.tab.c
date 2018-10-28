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
#line 1 "tacl.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include "compiler.h"

	extern int yylineno;
	int yylex(void);				
	void yyerror(const char *);		

#line 76 "tacl.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "tacl.tab.h".  */
#ifndef YY_YY_TACL_TAB_H_INCLUDED
# define YY_YY_TACL_TAB_H_INCLUDED
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
    INTEGER = 258,
    NAME = 259,
    ID = 260,
    PARRE = 261,
    PARRD = 262,
    PARE = 263,
    PARD = 264,
    COMMA = 265,
    SEMICOLON = 266,
    TWODOT = 267,
    DOT = 268,
    VAR = 269,
    LOCAL = 270,
    ARG = 271,
    FUN = 272,
    BODY = 273,
    CALL = 274,
    PRINT = 275,
    IF = 276,
    WHILE = 277,
    OR = 278,
    AND = 279,
    EQ = 280,
    NE = 281,
    LT = 282,
    LE = 283,
    GT = 284,
    GE = 285,
    PLUS = 286,
    MINUS = 287,
    TIMES = 288,
    DIV = 289,
    MOD = 290,
    NOT = 291,
    INV = 292,
    INT_LITERAL = 293,
    REAL_LITERAL = 294,
    TRUE = 295,
    FALSE = 296,
    TOREAL = 297,
    INT = 298,
    REAL = 299,
    BOOL = 300,
    ASSIGN = 301,
    NIL = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "tacl.y" /* yacc.c:355  */

	int integer;
    double real;
    char *name;
    char *id;
    struct Gdeclpar *gdeclpar;
    struct More_Gdecl *more_gdecl;
    struct Gdecl *gdecl;
    struct Var *var;
    struct Function *function;
    struct Body *body;
    struct Formal_Arg *formal_arg;
    struct More_Formal_Arg *more_formal_arg;
    struct OP *op;
    struct Statementpar *statementpar;
    struct Statement *statement;
    struct More_Statements *more_statements;
    struct Expression2 *expression2;
    struct Expression *expression;  
    struct Expression *expression1;  
    struct More_Expressions *more_expressions;
    struct More_Decl *more_decl;
    struct Declaration *declaration;
    struct Bool_Val *bool_val;
    struct Scope *scope;
    struct Type *type;
    


#line 194 "tacl.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TACL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 211 "tacl.tab.c" /* yacc.c:358  */

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   106,   106,   109,   110,   113,   116,   117,   120,   121,
     125,   128,   129,   130,   133,   136,   137,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   157,   158,   159,   162,   163,   164,   165,   166,
     169,   170,   173,   174,   177,   178,   181,   182,   183,   184,
     185,   186,   187,   188,   191,   192,   195,   196,   197,   200,
     201,   204,   205,   206,   209,   210,   211
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "NAME", "ID", "PARRE",
  "PARRD", "PARE", "PARD", "COMMA", "SEMICOLON", "TWODOT", "DOT", "VAR",
  "LOCAL", "ARG", "FUN", "BODY", "CALL", "PRINT", "IF", "WHILE", "OR",
  "AND", "EQ", "NE", "LT", "LE", "GT", "GE", "PLUS", "MINUS", "TIMES",
  "DIV", "MOD", "NOT", "INV", "INT_LITERAL", "REAL_LITERAL", "TRUE",
  "FALSE", "TOREAL", "INT", "REAL", "BOOL", "ASSIGN", "NIL", "$accept",
  "program", "gdeclpar", "more_gdecl", "gdecl", "var", "function", "body",
  "formal_arg", "more_formal_arg", "op", "statementpar", "statement",
  "more_statements", "expression2", "more_expressions", "expression",
  "more_decl", "declaration", "bool_val", "scope", "type", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF -83

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-83)))

#define YYTABLE_NINF -41

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,    38,    17,    23,   -83,    43,    21,    24,   -83,   -83,
     -83,    38,    58,    63,   -83,    61,    67,    64,   -83,    59,
      62,    72,   -21,    76,    73,    77,   -83,   -83,   -83,    78,
     -21,    64,    68,     0,   -83,   -83,    82,     8,   102,     8,
     -83,   -83,   -83,    81,     8,    86,    87,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,    89,    49,     8,    27,     8,   -83,    25,    90,
      91,   -83,    25,    20,    85,    92,    93,   -83,   -83,    94,
       8,   -83,   -83,   -83,    95,   101,     6,   -83,   -21,    97,
      84,    96,    98,    99,   100,    81,   -21,    12,    15,    20,
     104,     1,   105,   103,   -21,   -21,   -21,   -21,   106,   -83,
       7,   -83,    13,   109,   113,     8,    20,    20,   111,   114,
     -83,   -83,   -83,   -83,   108,   -21,   -83,   -83,   -83,   -83,
     -21,   -83,   -83,    15,   -83,   -83,    20,   -83,    12,    12,
     117,   -83,   -21,   -83,   -83,   133,   -83,    12,   -83,   139,
     -83,   138,   -83,    25,   -21,   137,    20,   -83
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     0,     0,     7,     6,
       1,     0,     0,     0,     3,     0,     0,    16,     5,     0,
       0,     0,     0,     0,     0,     0,    64,    66,    65,     0,
       0,    16,     0,     0,    14,    15,     0,     0,     0,     0,
       9,     8,    45,    55,    43,     0,     0,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,     0,     0,     0,     0,    53,    58,     0,
       0,    42,     0,     0,     0,     0,     0,    59,    60,     0,
       0,    62,    61,    63,     0,     0,     0,    44,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,    34,     0,     0,     0,     0,     0,     0,     0,     0,
      12,    10,    13,    11,     0,     0,    47,    48,    52,    49,
       0,    56,    57,     0,    41,    33,     0,    39,     0,     0,
       0,    32,     0,    51,    46,     0,    38,     0,    36,     0,
      50,    32,    37,     0,     0,     0,     0,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -83,   -83,   -83,   -83,    88,   -83,   -83,   -83,   -83,   118,
     -83,   -82,    18,    36,   -83,   -72,   -34,    55,   -83,   -83,
     -70,   -30
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     7,     8,     9,   100,    24,    21,
      66,   112,   119,   113,    70,    41,    42,    69,    84,    79,
      85,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    89,    88,    44,   101,    67,    37,    37,    38,    38,
      71,     1,    97,    37,    98,    38,    38,    10,    97,    97,
      98,   133,    26,    27,    28,    13,    37,   120,    38,   123,
      76,    11,    80,    14,   114,   115,   116,   117,   132,    81,
      82,    83,    39,    39,   138,   139,    94,    40,   122,    39,
      39,    12,     5,    99,   131,     6,   147,   148,   102,   111,
     111,   118,    39,    16,   146,   152,   110,    77,    78,    17,
      18,    19,    20,    22,   126,   127,   128,   129,    23,    25,
      30,   137,    31,   154,   157,    32,    36,    33,    43,    68,
      72,    73,    74,    75,    90,   143,   104,    86,    87,    15,
     144,    91,    92,    93,    95,    96,   103,    45,   105,   108,
     106,   107,   150,   121,   124,   125,   135,   136,   130,   140,
     142,    46,   149,   141,   155,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,   151,   153,    64,   -40,   156,    65,   134,    35,
     109,   145
};

static const yytype_uint8 yycheck[] =
{
      30,    73,    72,    37,    86,    39,     6,     6,     8,     8,
      44,     8,     6,     6,     8,     8,     8,     0,     6,     6,
       8,     8,    43,    44,    45,     4,     6,    99,     8,   101,
      64,     8,    66,     9,    19,    20,    21,    22,   110,    14,
      15,    16,    42,    42,   116,   117,    80,    47,    47,    42,
      42,     8,    14,    47,    47,    17,   138,   139,    88,    47,
      47,    46,    42,     5,   136,   147,    96,    40,    41,     6,
       9,     4,     8,    14,   104,   105,   106,   107,    16,     7,
       4,   115,     9,   153,   156,     8,    18,     9,     6,     8,
       4,     4,     3,    44,     9,   125,    12,     7,     7,    11,
     130,     9,     9,     9,     9,     4,     9,     5,    12,     9,
      12,    12,   142,     9,     9,    12,     7,     4,    12,     8,
      12,    19,     5,     9,   154,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     9,     4,    42,     7,     9,    45,   112,    31,
      95,   133
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    49,    50,    51,    14,    17,    52,    53,    54,
       0,     8,     8,     4,     9,    52,     5,     6,     9,     4,
       8,    57,    14,    16,    56,     7,    43,    44,    45,    69,
       4,     9,     8,     9,    69,    57,    18,     6,     8,    42,
      47,    63,    64,     6,    64,     5,    19,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    42,    45,    58,    64,     8,    65,
      62,    64,     4,     4,     3,    44,    64,    40,    41,    67,
      64,    14,    15,    16,    66,    68,     7,     7,    68,    63,
       9,     9,     9,     9,    64,     9,     4,     6,     8,    47,
      55,    59,    69,     9,    12,    12,    12,    12,     9,    65,
      69,    47,    59,    61,    19,    20,    21,    22,    46,    60,
      63,     9,    47,    63,     9,    12,    69,    69,    69,    69,
      12,    47,    63,     8,    61,     7,     4,    64,    63,    63,
       8,     9,    12,    69,    69,    60,    63,    59,    59,     5,
      69,     9,    59,     4,    68,    69,     9,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    52,    52,    53,    53,
      54,    55,    55,    55,    56,    57,    57,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    59,    59,    59,    60,    60,    60,    60,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    65,    65,    66,    66,    66,    67,
      67,    68,    68,    68,    69,    69,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     1,     4,     1,     1,     8,     8,
      12,     2,     2,     2,     3,     4,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     8,     3,     4,     3,     2,
       4,     2,     1,     0,     4,     1,     7,     6,     6,     6,
       8,     7,     6,     2,     4,     0,     4,     4,     0,     1,
       1,     1,     1,     1,     1,     1,     1
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
        case 2:
#line 106 "tacl.y" /* yacc.c:1646  */
    {root((yyvsp[0].gdeclpar));}
#line 1390 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 109 "tacl.y" /* yacc.c:1646  */
    {(yyval.gdeclpar) = newGdeclpar(pare_gdecl, (yyvsp[-1].gdecl), NULL);}
#line 1396 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 110 "tacl.y" /* yacc.c:1646  */
    {(yyval.gdeclpar) = newGdeclpar(more_gdecl_, NULL, (yyvsp[0].more_gdecl));}
#line 1402 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 113 "tacl.y" /* yacc.c:1646  */
    {(yyval.more_gdecl) = newMore_Gdecl((yyvsp[-3].gdeclpar), (yyvsp[-1].gdecl));}
#line 1408 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 116 "tacl.y" /* yacc.c:1646  */
    {(yyval.gdecl) = newGdecl(function, (yyvsp[0].function), NULL);}
#line 1414 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 117 "tacl.y" /* yacc.c:1646  */
    {(yyval.gdecl) = newGdecl(var, NULL, (yyvsp[0].var));}
#line 1420 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 120 "tacl.y" /* yacc.c:1646  */
    {(yyval.var) = newVar(var_exp, (yyvsp[-4].name), (yyvsp[-2].type), (yyvsp[0].more_expressions));}
#line 1426 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 121 "tacl.y" /* yacc.c:1646  */
    {(yyval.var) = newVar(var_nil, (yyvsp[-4].name), (yyvsp[-2].type), NULL);}
#line 1432 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 125 "tacl.y" /* yacc.c:1646  */
    {(yyval.function) = newFunction((yyvsp[-10].name), (yyvsp[-8].more_formal_arg), (yyvsp[-3].more_decl), (yyvsp[-1].body));}
#line 1438 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 128 "tacl.y" /* yacc.c:1646  */
    {(yyval.body) = newBody(statement_expression, (yyvsp[-1].statementpar), (yyvsp[0].more_expressions));}
#line 1444 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 129 "tacl.y" /* yacc.c:1646  */
    {(yyval.body) = newBody(nil_expression, NULL, (yyvsp[0].more_expressions));}
#line 1450 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 130 "tacl.y" /* yacc.c:1646  */
    {(yyval.body) = newBody(statement_nil, (yyvsp[-1].statementpar), NULL);}
#line 1456 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 133 "tacl.y" /* yacc.c:1646  */
    {(yyval.formal_arg) = newFormalArg((yyvsp[-1].name), (yyvsp[0].type));}
#line 1462 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 136 "tacl.y" /* yacc.c:1646  */
    {(yyval.more_formal_arg) = newMoreFormalArg(formal_more_formal, (yyvsp[-2].formal_arg), (yyvsp[0].more_formal_arg));}
#line 1468 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 137 "tacl.y" /* yacc.c:1646  */
    {(yyval.more_formal_arg) = newMoreFormalArg(empty_more_decl, NULL, NULL);}
#line 1474 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 140 "tacl.y" /* yacc.c:1646  */
    {(yyval.op) = newOP(or_);}
#line 1480 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 141 "tacl.y" /* yacc.c:1646  */
    {(yyval.op) = newOP(and_);}
#line 1486 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 142 "tacl.y" /* yacc.c:1646  */
    {(yyval.op) = newOP(eq_);}
#line 1492 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 143 "tacl.y" /* yacc.c:1646  */
    {(yyval.op) = newOP(ne_);}
#line 1498 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 144 "tacl.y" /* yacc.c:1646  */
    {(yyval.op) = newOP(lt_);}
#line 1504 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 145 "tacl.y" /* yacc.c:1646  */
    {(yyval.op) = newOP(le_);}
#line 1510 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 146 "tacl.y" /* yacc.c:1646  */
    {(yyval.op) = newOP(gt_);}
#line 1516 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 147 "tacl.y" /* yacc.c:1646  */
    {(yyval.op) = newOP(ge_);}
#line 1522 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 148 "tacl.y" /* yacc.c:1646  */
    {(yyval.op) = newOP(plus_);}
#line 1528 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 149 "tacl.y" /* yacc.c:1646  */
    {(yyval.op) = newOP(minus_);}
#line 1534 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 150 "tacl.y" /* yacc.c:1646  */
    {(yyval.op) = newOP(times_);}
#line 1540 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 151 "tacl.y" /* yacc.c:1646  */
    {(yyval.op) = newOP(div_);}
#line 1546 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 152 "tacl.y" /* yacc.c:1646  */
    {(yyval.op) = newOP(mod_);}
#line 1552 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 153 "tacl.y" /* yacc.c:1646  */
    {(yyval.op) = newOP(not_);}
#line 1558 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 154 "tacl.y" /* yacc.c:1646  */
    {(yyval.op) = newOP(inv_);}
#line 1564 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 157 "tacl.y" /* yacc.c:1646  */
    {(yyval.statementpar) = newStatementPar(par_statement, (yyvsp[-1].statement), NULL );}
#line 1570 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 158 "tacl.y" /* yacc.c:1646  */
    {(yyval.statementpar) = newStatementPar(more_statement, NULL, (yyvsp[-1].more_statements) );}
#line 1576 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 159 "tacl.y" /* yacc.c:1646  */
    {(yyval.statementpar) = newStatementPar(nil, NULL, NULL );}
#line 1582 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 162 "tacl.y" /* yacc.c:1646  */
    {(yyval.statement) = newStatement(assign, (yyvsp[-3].scope), (yyvsp[0].more_expressions), NULL, NULL, (yyvsp[-4].name), NULL, (yyvsp[-2].type));}
#line 1588 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 163 "tacl.y" /* yacc.c:1646  */
    {(yyval.statement) = newStatement(while_, NULL, (yyvsp[-1].more_expressions), (yyvsp[0].statementpar), NULL, NULL, NULL, NULL);}
#line 1594 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 164 "tacl.y" /* yacc.c:1646  */
    {(yyval.statement) = newStatement(if_, NULL, (yyvsp[-2].more_expressions), (yyvsp[-1].statementpar), (yyvsp[0].statementpar), NULL, NULL, NULL);}
#line 1600 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 165 "tacl.y" /* yacc.c:1646  */
    {(yyval.statement) = newStatement(call_proc, NULL, (yyvsp[0].more_expressions), NULL, NULL, (yyvsp[-1].name), NULL, NULL);}
#line 1606 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 166 "tacl.y" /* yacc.c:1646  */
    {(yyval.statement) = newStatement(print, NULL, NULL, NULL, NULL, NULL, (yyvsp[0].expression), NULL);}
#line 1612 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 169 "tacl.y" /* yacc.c:1646  */
    {(yyval.more_statements) = newMoreStatements(statement_statement, (yyvsp[-3].statementpar), (yyvsp[-1].statement),NULL);}
#line 1618 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 170 "tacl.y" /* yacc.c:1646  */
    {(yyval.more_statements) = newMoreStatements(statement_more_statement, (yyvsp[-1].statementpar), NULL, (yyvsp[0].more_statements));}
#line 1624 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 173 "tacl.y" /* yacc.c:1646  */
    {(yyval.expression2) = newExpression2(exp_, (yyvsp[0].expression));}
#line 1630 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 174 "tacl.y" /* yacc.c:1646  */
    {(yyval.expression2) = newExpression2(empty_exp2, NULL);}
#line 1636 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 177 "tacl.y" /* yacc.c:1646  */
    {(yyval.more_expressions) = newMoreExpressions(exp_exp, (yyvsp[-2].expression), (yyvsp[-1].expression2));}
#line 1642 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 178 "tacl.y" /* yacc.c:1646  */
    {(yyval.more_expressions) = newMoreExpressions(m_exp, (yyvsp[0].expression), NULL);}
#line 1648 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 181 "tacl.y" /* yacc.c:1646  */
    {(yyval.expression) = newExpression(op, (yyvsp[-5].op), (yyvsp[-4].expression), NULL, (yyvsp[0].type), NULL, 0, 0.0, NULL, NULL, NULL, NULL, (yyvsp[-3].expression));}
#line 1654 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 182 "tacl.y" /* yacc.c:1646  */
    {(yyval.expression) = newExpression(int_literal, NULL, NULL, NULL, (yyvsp[0].type), NULL, (yyvsp[-3].integer), 0.0, NULL, NULL, NULL, NULL, NULL);}
#line 1660 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 183 "tacl.y" /* yacc.c:1646  */
    {(yyval.expression) = newExpression(real_literal, NULL, NULL, NULL, (yyvsp[0].type), NULL, 0, (yyvsp[-3].real), NULL, NULL, NULL, NULL, NULL);}
#line 1666 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 184 "tacl.y" /* yacc.c:1646  */
    {(yyval.expression) = newExpression(bool_exp, NULL, NULL, NULL, (yyvsp[0].type), NULL, 0, 0.0, (yyvsp[-3].bool_val), NULL, NULL, NULL, NULL);}
#line 1672 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 185 "tacl.y" /* yacc.c:1646  */
    {(yyval.expression) = newExpression(id, NULL, NULL, NULL, (yyvsp[-3].type), (yyvsp[0].type), 0, 0.0, NULL, (yyvsp[-4].scope), NULL, (yyvsp[-5].name), NULL);}
#line 1678 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 186 "tacl.y" /* yacc.c:1646  */
    {(yyval.expression) = newExpression(call_func, NULL, NULL, NULL, (yyvsp[0].type), NULL, 0, 0.0, NULL, NULL, (yyvsp[-3].more_expressions), (yyvsp[-4].name), NULL);}
#line 1684 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 187 "tacl.y" /* yacc.c:1646  */
    {(yyval.expression) = newExpression(toreal, NULL, (yyvsp[-3].expression), NULL, (yyvsp[0].type), NULL, 0, 0.0, NULL, NULL, NULL, NULL, NULL);}
#line 1690 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 188 "tacl.y" /* yacc.c:1646  */
    {(yyval.expression) = newExpression(toreal, NULL, (yyvsp[0].expression), NULL, NULL, NULL, 0, 0.0, NULL, NULL, NULL, NULL, NULL);}
#line 1696 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 191 "tacl.y" /* yacc.c:1646  */
    {(yyval.more_decl) = newMoreDecl(more_gdecl, (yyvsp[-2].declaration), (yyvsp[0].more_decl));}
#line 1702 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 192 "tacl.y" /* yacc.c:1646  */
    {(yyval.more_decl) = newMoreDecl(empty_more_decl, NULL, NULL);}
#line 1708 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 195 "tacl.y" /* yacc.c:1646  */
    {(yyval.declaration) = newDeclaration(decl_nil, (yyvsp[-3].scope), (yyvsp[-2].name), (yyvsp[-1].type), NULL);}
#line 1714 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 196 "tacl.y" /* yacc.c:1646  */
    {(yyval.declaration) = newDeclaration(decl_more_expressions, (yyvsp[-3].scope), (yyvsp[-2].name), (yyvsp[-1].type), (yyvsp[0].more_expressions));}
#line 1720 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 197 "tacl.y" /* yacc.c:1646  */
    {(yyval.declaration) = newDeclaration(empty_decl, NULL, NULL, NULL, NULL);}
#line 1726 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 200 "tacl.y" /* yacc.c:1646  */
    {(yyval.bool_val) = newBoolVal(true_);}
#line 1732 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 201 "tacl.y" /* yacc.c:1646  */
    {(yyval.bool_val) = newBoolVal(false_);}
#line 1738 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 204 "tacl.y" /* yacc.c:1646  */
    {(yyval.scope) = newScope(local_scope);}
#line 1744 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 205 "tacl.y" /* yacc.c:1646  */
    {(yyval.scope) = newScope(var_scope);}
#line 1750 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 206 "tacl.y" /* yacc.c:1646  */
    {(yyval.scope) = newScope(arg_scope);}
#line 1756 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 209 "tacl.y" /* yacc.c:1646  */
    {(yyval.type) = newType(int_type);}
#line 1762 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 210 "tacl.y" /* yacc.c:1646  */
    {(yyval.type) = newType(bool_type);}
#line 1768 "tacl.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 211 "tacl.y" /* yacc.c:1646  */
    {(yyval.type) = newType(real_type);}
#line 1774 "tacl.tab.c" /* yacc.c:1646  */
    break;


#line 1778 "tacl.tab.c" /* yacc.c:1646  */
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
#line 214 "tacl.y" /* yacc.c:1906  */


void yyerror(const char *msg){
	fprintf(stderr, "error: %s\n", msg);
}


int main(){
	return yyparse();
}

