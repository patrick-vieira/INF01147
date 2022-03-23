/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <stdio.h>
    #include "hash.h"
    #include "ast.h"

    void yyerror(const char *s);  
    int getLineNumber(void); 
    AST* getRootNode(void); 
    
    int yylex(void); 

    AST *rootNode;


#line 85 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

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

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SYMBOL_VARIABLE = 258,
    SYMBOL_FUNCTION = 259,
    SYMBOL_VECTOR = 260,
    KW_CHAR = 261,
    KW_INT = 262,
    KW_FLOAT = 263,
    KW_IF = 264,
    KW_THEN = 265,
    KW_ELSE = 266,
    KW_WHILE = 267,
    KW_GOTO = 268,
    KW_READ = 269,
    KW_PRINT = 270,
    KW_RETURN = 271,
    OPERATOR_ADD = 272,
    OPERATOR_SUB = 273,
    OPERATOR_MULT = 274,
    OPERATOR_DIV = 275,
    OPERATOR_LTE = 276,
    OPERATOR_LT = 277,
    OPERATOR_GTE = 278,
    OPERATOR_GT = 279,
    OPERATOR_EQ = 280,
    OPERATOR_DIF = 281,
    TK_IDENTIFIER = 282,
    LIT_INTEGER = 283,
    LIT_CHAR = 284,
    LIT_STRING = 285,
    TOKEN_ERROR = 286
  };
#endif
/* Tokens.  */
#define SYMBOL_VARIABLE 258
#define SYMBOL_FUNCTION 259
#define SYMBOL_VECTOR 260
#define KW_CHAR 261
#define KW_INT 262
#define KW_FLOAT 263
#define KW_IF 264
#define KW_THEN 265
#define KW_ELSE 266
#define KW_WHILE 267
#define KW_GOTO 268
#define KW_READ 269
#define KW_PRINT 270
#define KW_RETURN 271
#define OPERATOR_ADD 272
#define OPERATOR_SUB 273
#define OPERATOR_MULT 274
#define OPERATOR_DIV 275
#define OPERATOR_LTE 276
#define OPERATOR_LT 277
#define OPERATOR_GTE 278
#define OPERATOR_GT 279
#define OPERATOR_EQ 280
#define OPERATOR_DIF 281
#define TK_IDENTIFIER 282
#define LIT_INTEGER 283
#define LIT_CHAR 284
#define LIT_STRING 285
#define TOKEN_ERROR 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "parser.y"

    HASH_NODE *symbol;
    AST *ast;

#line 204 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   259

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

#define YYUNDEFTOK  2
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      36,    37,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    32,    33,
       2,    41,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   107,   107,   110,   111,   114,   115,   126,   127,   128,
     132,   133,   134,   137,   138,   139,   142,   143,   147,   148,
     149,   150,   158,   159,   160,   163,   164,   167,   168,   169,
     170,   171,   172,   175,   178,   181,   182,   185,   186,   193,
     194,   195,   196,   197,   198,   201,   204,   205,   206,   210,
     211,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     225,   226,   227,   228,   229,   230,   232,   233,   236,   239,
     242,   243,   244,   245,   248,   257,   258,   259,   260,   263,
     266
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SYMBOL_VARIABLE", "SYMBOL_FUNCTION",
  "SYMBOL_VECTOR", "KW_CHAR", "KW_INT", "KW_FLOAT", "KW_IF", "KW_THEN",
  "KW_ELSE", "KW_WHILE", "KW_GOTO", "KW_READ", "KW_PRINT", "KW_RETURN",
  "OPERATOR_ADD", "OPERATOR_SUB", "OPERATOR_MULT", "OPERATOR_DIV",
  "OPERATOR_LTE", "OPERATOR_LT", "OPERATOR_GTE", "OPERATOR_GT",
  "OPERATOR_EQ", "OPERATOR_DIF", "TK_IDENTIFIER", "LIT_INTEGER",
  "LIT_CHAR", "LIT_STRING", "TOKEN_ERROR", "':'", "';'", "'['", "']'",
  "'('", "')'", "','", "'{'", "'}'", "'='", "$accept", "program",
  "declaration_list", "declaration", "declaration_global",
  "declaration_global_int", "declaration_global_char",
  "declaration_global_float", "array_val", "declaration_function",
  "declaration_function_args_or_empty", "declaration_function_args",
  "declaration_function_body", "function_call",
  "function_call_args_or_empty", "function_call_args", "command",
  "command_block", "command_list", "attribution", "expression",
  "array_element", "print", "print_rest", "return", "flux_control",
  "label", "go_to", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    58,    59,    91,    93,    40,    41,    44,   123,
     125,    61
};
# endif

#define YYPACT_NINF (-132)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-49)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      94,    18,    24,    27,    56,  -132,    94,  -132,  -132,  -132,
    -132,  -132,    23,    55,    63,  -132,  -132,    57,    45,   102,
      57,    51,   102,    62,    64,   102,  -132,   -24,  -132,  -132,
      57,  -132,   189,  -132,    30,    69,    84,    89,    83,  -132,
     206,   109,   114,   132,   118,   141,    57,    57,   149,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,  -132,
      10,   116,   138,   142,    -8,  -132,    35,    -8,   151,   148,
      -8,   170,   145,  -132,   117,  -132,   130,   130,  -132,  -132,
      87,    87,    87,    87,    87,    87,    54,  -132,   102,   102,
     102,    57,    57,   156,    33,    57,   -13,    37,  -132,  -132,
    -132,  -132,   143,  -132,  -132,  -132,  -132,    54,  -132,  -132,
     152,  -132,  -132,  -132,  -132,    57,    54,    54,   164,  -132,
    -132,  -132,   223,   106,  -132,   160,   139,  -132,   233,    57,
     -14,   166,   161,    37,    57,   167,  -132,  -132,  -132,  -132,
    -132,    -8,  -132,    33,    33,   233,  -132,    37,  -132,  -132,
     233,  -132,   191,  -132,  -132,  -132,    -8,  -132
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     0,     0,     2,     4,     6,     7,     8,
       9,     5,     0,     0,     0,     1,     3,     0,     0,    26,
       0,     0,    26,     0,     0,    26,    54,    53,    51,    52,
       0,    67,     0,    55,     0,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
       0,    31,    30,    32,    44,    10,     0,    44,     0,     0,
      44,     0,     0,    35,    37,    66,    56,    57,    58,    59,
      61,    60,    63,    62,    64,    65,     0,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,    23,    33,
      43,    39,     0,    41,    42,    40,    78,     0,    11,    22,
       0,    17,    24,    68,    34,     0,    19,    21,     0,    28,
      27,    29,     0,    44,    80,    70,    72,    69,    74,     0,
       0,     0,     0,    44,     0,     0,    16,    38,    18,    20,
      15,    44,    77,     0,     0,    49,    79,    44,    45,    47,
      50,    12,    75,    71,    73,    46,    44,    76
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,   197,  -132,  -132,  -132,  -132,  -132,   -92,  -132,
     -16,    58,   -44,  -132,  -132,   101,   -75,  -132,  -131,  -132,
     -17,   -53,  -132,   -30,  -132,  -132,  -132,  -132
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,     9,    10,   118,    11,
      38,    39,    98,    31,    72,    73,    99,   100,   132,   101,
     126,    33,   103,   127,   104,   105,   133,   106
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    91,   149,    40,    92,    93,    42,    94,    95,    45,
      46,   102,    47,    48,   102,   135,   155,   102,   146,    96,
      46,    46,   131,   109,   138,   139,   112,   129,   129,    71,
      74,    97,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,   102,    12,    91,    26,   142,    92,
      93,    13,    94,    95,    14,    17,    15,    18,   131,    19,
      27,    28,    29,   125,   130,    60,   152,   107,   108,    30,
     102,    26,   131,    34,   122,   123,    97,   -48,   128,    41,
     102,   157,   116,   117,    27,    28,    29,    20,   102,    21,
      43,    22,    44,    30,   102,    23,    61,    24,    74,    25,
       1,     2,     3,   102,    49,    50,    51,    52,    35,    36,
      37,    62,   145,   153,   154,    91,    63,   150,    92,    93,
      64,    94,    95,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    96,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    66,    97,   119,   120,   121,    51,
      52,    67,    68,    69,    88,   115,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    89,   144,    70,   110,
      90,   111,   114,   124,   134,   136,    75,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,   140,   143,   147,
     151,   148,   156,    16,     0,   113,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,   137,     0,     0,     0,
       0,     0,    59,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,   141,     0,     0,     0,     0,     0,    65,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58
};

static const yytype_int16 yycheck[] =
{
      17,     9,   133,    20,    12,    13,    22,    15,    16,    25,
      34,    64,    36,    30,    67,   107,   147,    70,    32,    27,
      34,    34,    97,    67,   116,   117,    70,    41,    41,    46,
      47,    39,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    32,    33,    97,    27,     9,    14,   123,    12,
      13,    27,    15,    16,    27,    32,     0,    34,   133,    36,
      27,    28,    29,    30,    27,    35,   141,    32,    33,    36,
     123,    14,   147,    28,    91,    92,    39,    40,    95,    28,
     133,   156,    28,    29,    27,    28,    29,    32,   141,    34,
      28,    36,    28,    36,   147,    32,    27,    34,   115,    36,
       6,     7,     8,   156,    17,    18,    19,    20,     6,     7,
       8,    27,   129,   143,   144,     9,    27,   134,    12,    13,
      37,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    35,    39,    88,    89,    90,    19,
      20,    37,    20,    35,    38,    38,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    38,    38,    37,    28,
      38,    33,    37,    27,    41,    33,    37,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    33,    38,    33,
      33,    40,    11,     6,    -1,    35,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   115,    -1,    -1,    -1,
      -1,    -1,    33,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    10,    -1,    -1,    -1,    -1,    -1,    33,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,    43,    44,    45,    46,    47,    48,
      49,    51,    27,    27,    27,     0,    44,    32,    34,    36,
      32,    34,    36,    32,    34,    36,    14,    27,    28,    29,
      36,    55,    62,    63,    28,     6,     7,     8,    52,    53,
      62,    28,    52,    28,    28,    52,    34,    36,    62,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    33,
      35,    27,    27,    27,    37,    33,    35,    37,    20,    35,
      37,    62,    56,    57,    62,    37,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    32,    33,    38,    38,
      38,     9,    12,    13,    15,    16,    27,    39,    54,    58,
      59,    61,    63,    64,    66,    67,    69,    32,    33,    54,
      28,    33,    54,    35,    37,    38,    28,    29,    50,    53,
      53,    53,    62,    62,    27,    30,    62,    65,    62,    41,
      27,    58,    60,    68,    41,    50,    33,    57,    50,    50,
      33,    10,    58,    38,    38,    62,    32,    33,    40,    60,
      62,    33,    58,    65,    65,    60,    11,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    46,    46,    46,
      47,    47,    47,    48,    48,    48,    49,    49,    50,    50,
      50,    50,    51,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    54,    55,    56,    56,    57,    57,    58,
      58,    58,    58,    58,    58,    59,    60,    60,    60,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    63,    64,
      65,    65,    65,    65,    66,    67,    67,    67,    67,    68,
      69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       5,     6,     8,     5,     6,     8,     7,     6,     2,     1,
       2,     1,     6,     6,     6,     1,     0,     4,     4,     4,
       2,     2,     2,     1,     4,     1,     0,     1,     3,     1,
       1,     1,     1,     1,     0,     3,     3,     2,     0,     3,
       3,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     4,     2,
       1,     3,     1,     3,     2,     4,     6,     3,     1,     2,
       2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
# undef YYSTACK_RELOCATE
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
  case 2:
#line 107 "parser.y"
                                       { (yyval.ast) = astCreate(AST_PROGRAM, 0, (yyvsp[0].ast),0,0,0); rootNode = (yyval.ast); }
#line 1511 "y.tab.c"
    break;

  case 3:
#line 110 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_DECLARATION_LIST, 0, (yyvsp[-1].ast),(yyvsp[0].ast),0,0); }
#line 1517 "y.tab.c"
    break;

  case 4:
#line 111 "parser.y"
                                                    { (yyval.ast) = 0; }
#line 1523 "y.tab.c"
    break;

  case 5:
#line 114 "parser.y"
                                            {(yyval.ast)=(yyvsp[0].ast);}
#line 1529 "y.tab.c"
    break;

  case 6:
#line 115 "parser.y"
                                            {(yyval.ast)=(yyvsp[0].ast);}
#line 1535 "y.tab.c"
    break;

  case 7:
#line 126 "parser.y"
                                              {(yyval.ast)=(yyvsp[0].ast);}
#line 1541 "y.tab.c"
    break;

  case 8:
#line 127 "parser.y"
                                              {(yyval.ast)=(yyvsp[0].ast);}
#line 1547 "y.tab.c"
    break;

  case 9:
#line 128 "parser.y"
                                              {(yyval.ast)=(yyvsp[0].ast);}
#line 1553 "y.tab.c"
    break;

  case 10:
#line 132 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_DECLARATION_GLOBAL_INT, (yyvsp[-3].symbol), (yyvsp[-1].ast),0,0,0); }
#line 1559 "y.tab.c"
    break;

  case 11:
#line 133 "parser.y"
                                                                        { AST* lit_arr_size = astCreate(AST_SYMBOL, (yyvsp[-2].symbol), 0,0,0,0); (yyval.ast) = astCreate(AST_DECLARATION_GLOBAL_ARRAY_INT, (yyvsp[-4].symbol), lit_arr_size,0,0,0); }
#line 1565 "y.tab.c"
    break;

  case 12:
#line 134 "parser.y"
                                                                        { AST* lit_arr_size = astCreate(AST_SYMBOL, (yyvsp[-4].symbol), 0,0,0,0); (yyval.ast) = astCreate(AST_DECLARATION_GLOBAL_ARRAY_INT, (yyvsp[-6].symbol), lit_arr_size,(yyvsp[-1].ast),0,0); }
#line 1571 "y.tab.c"
    break;

  case 13:
#line 137 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_DECLARATION_GLOBAL_CHAR, (yyvsp[-3].symbol), (yyvsp[-1].ast),0,0,0); }
#line 1577 "y.tab.c"
    break;

  case 14:
#line 138 "parser.y"
                                                                        { AST* lit_arr_size = astCreate(AST_SYMBOL, (yyvsp[-2].symbol), 0,0,0,0); (yyval.ast) = astCreate(AST_DECLARATION_GLOBAL_ARRAY_CHAR, (yyvsp[-4].symbol), lit_arr_size,0,0,0); }
#line 1583 "y.tab.c"
    break;

  case 15:
#line 139 "parser.y"
                                                                        { AST* lit_arr_size = astCreate(AST_SYMBOL, (yyvsp[-4].symbol), 0,0,0,0); (yyval.ast) = astCreate(AST_DECLARATION_GLOBAL_ARRAY_CHAR, (yyvsp[-6].symbol), lit_arr_size,(yyvsp[-1].ast),0,0); }
#line 1589 "y.tab.c"
    break;

  case 16:
#line 142 "parser.y"
                                                                                                 { AST* lit1 = astCreate(AST_SYMBOL, (yyvsp[-3].symbol), 0,0,0,0); AST* lit2 = astCreate(AST_SYMBOL, (yyvsp[-1].symbol), 0,0,0,0); (yyval.ast) = astCreate(AST_DECLARATION_GLOBAL_FLOAT, (yyvsp[-5].symbol), lit1,lit2,0,0); }
#line 1595 "y.tab.c"
    break;

  case 17:
#line 143 "parser.y"
                                                                                        { AST* lit_arr_size = astCreate(AST_SYMBOL, (yyvsp[-2].symbol), 0,0,0,0); (yyval.ast) = astCreate(AST_DECLARATION_GLOBAL_ARRAY_FLOAT, (yyvsp[-4].symbol), lit_arr_size,0,0,0); }
#line 1601 "y.tab.c"
    break;

  case 18:
#line 147 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_ARRAY_VAL, (yyvsp[-1].symbol), (yyvsp[0].ast),0,0,0); }
#line 1607 "y.tab.c"
    break;

  case 19:
#line 148 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_ARRAY_VAL, (yyvsp[0].symbol), 0,0,0,0); }
#line 1613 "y.tab.c"
    break;

  case 20:
#line 149 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_ARRAY_VAL, (yyvsp[-1].symbol), (yyvsp[0].ast),0,0,0); }
#line 1619 "y.tab.c"
    break;

  case 21:
#line 150 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_ARRAY_VAL, (yyvsp[0].symbol), 0,0,0,0); }
#line 1625 "y.tab.c"
    break;

  case 22:
#line 158 "parser.y"
                                                                                                                    { (yyval.ast) = astCreate(AST_DECLARATION_FUNCTION_INT, (yyvsp[-4].symbol), (yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1631 "y.tab.c"
    break;

  case 23:
#line 159 "parser.y"
                                                                                                                    { (yyval.ast) = astCreate(AST_DECLARATION_FUNCTION_CHAR, (yyvsp[-4].symbol), (yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1637 "y.tab.c"
    break;

  case 24:
#line 160 "parser.y"
                                                                                                                    { (yyval.ast) = astCreate(AST_DECLARATION_FUNCTION_FLOAT, (yyvsp[-4].symbol), (yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1643 "y.tab.c"
    break;

  case 25:
#line 163 "parser.y"
                                                                                                                    { (yyval.ast) = astCreate(AST_DECLARATION_FUNCTION_ARGS_OR_EMPTY, 0, (yyvsp[0].ast),0,0,0); }
#line 1649 "y.tab.c"
    break;

  case 26:
#line 164 "parser.y"
                                                                                                                    { (yyval.ast) = 0; }
#line 1655 "y.tab.c"
    break;

  case 27:
#line 167 "parser.y"
                                                                                    { (yyval.ast) = astCreate(AST_DECLARATION_FUNCTION_ARGS_INT,   (yyvsp[-2].symbol), (yyvsp[0].ast),0,0,0); }
#line 1661 "y.tab.c"
    break;

  case 28:
#line 168 "parser.y"
                                                                                    { (yyval.ast) = astCreate(AST_DECLARATION_FUNCTION_ARGS_CHAR,  (yyvsp[-2].symbol), (yyvsp[0].ast),0,0,0); }
#line 1667 "y.tab.c"
    break;

  case 29:
#line 169 "parser.y"
                                                                                    { (yyval.ast) = astCreate(AST_DECLARATION_FUNCTION_ARGS_FLOAT, (yyvsp[-2].symbol), (yyvsp[0].ast),0,0,0); }
#line 1673 "y.tab.c"
    break;

  case 30:
#line 170 "parser.y"
                                                                                    { (yyval.ast) = astCreate(AST_DECLARATION_FUNCTION_ARGS_INT,   (yyvsp[0].symbol), 0,0,0,0); }
#line 1679 "y.tab.c"
    break;

  case 31:
#line 171 "parser.y"
                                                                                    { (yyval.ast) = astCreate(AST_DECLARATION_FUNCTION_ARGS_CHAR,  (yyvsp[0].symbol), 0,0,0,0); }
#line 1685 "y.tab.c"
    break;

  case 32:
#line 172 "parser.y"
                                                                                    { (yyval.ast) = astCreate(AST_DECLARATION_FUNCTION_ARGS_FLOAT, (yyvsp[0].symbol), 0,0,0,0); }
#line 1691 "y.tab.c"
    break;

  case 33:
#line 175 "parser.y"
                                        { (yyval.ast) = astCreate(AST_DECLARATION_FUNCTION_BODY, 0, (yyvsp[0].ast),0,0,0);  }
#line 1697 "y.tab.c"
    break;

  case 34:
#line 178 "parser.y"
                                                                     { (yyval.ast) = astCreate(AST_FUNCTION_CALL, (yyvsp[-3].symbol), (yyvsp[-1].ast),0,0,0);  }
#line 1703 "y.tab.c"
    break;

  case 35:
#line 181 "parser.y"
                                                    { (yyval.ast) = (yyvsp[0].ast); }
#line 1709 "y.tab.c"
    break;

  case 36:
#line 182 "parser.y"
                                                    { (yyval.ast) = 0; }
#line 1715 "y.tab.c"
    break;

  case 37:
#line 185 "parser.y"
                                                     { (yyval.ast) = astCreate(AST_FUNCTION_CALL_ARGS, 0, (yyvsp[0].ast),0,0,0);  }
#line 1721 "y.tab.c"
    break;

  case 38:
#line 186 "parser.y"
                                                     { (yyval.ast) = astCreate(AST_FUNCTION_CALL_ARGS, 0, (yyvsp[-2].ast),(yyvsp[0].ast),0,0);  }
#line 1727 "y.tab.c"
    break;

  case 39:
#line 193 "parser.y"
                                                { (yyval.ast)=(yyvsp[0].ast);}
#line 1733 "y.tab.c"
    break;

  case 40:
#line 194 "parser.y"
                                                { (yyval.ast)=(yyvsp[0].ast);}
#line 1739 "y.tab.c"
    break;

  case 41:
#line 195 "parser.y"
                                                { (yyval.ast)=(yyvsp[0].ast);}
#line 1745 "y.tab.c"
    break;

  case 42:
#line 196 "parser.y"
                                                { (yyval.ast)=(yyvsp[0].ast);}
#line 1751 "y.tab.c"
    break;

  case 43:
#line 197 "parser.y"
                                                { (yyval.ast)=(yyvsp[0].ast);}
#line 1757 "y.tab.c"
    break;

  case 44:
#line 198 "parser.y"
                                                { (yyval.ast)=0; }
#line 1763 "y.tab.c"
    break;

  case 45:
#line 201 "parser.y"
                                                { (yyval.ast) = astCreate(AST_COMMAND_BLOCK, 0, (yyvsp[-1].ast),0,0,0); }
#line 1769 "y.tab.c"
    break;

  case 46:
#line 204 "parser.y"
                                                { (yyval.ast) = astCreate(AST_COMMAND_LIST, 0, (yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1775 "y.tab.c"
    break;

  case 47:
#line 205 "parser.y"
                                                { (yyval.ast) = astCreate(AST_COMMAND_LIST, 0, (yyvsp[-1].ast),(yyvsp[0].ast),0,0); }
#line 1781 "y.tab.c"
    break;

  case 48:
#line 206 "parser.y"
                                                { (yyval.ast) = 0;}
#line 1787 "y.tab.c"
    break;

  case 49:
#line 210 "parser.y"
                                                {  (yyval.ast) = astCreate(AST_ATTRIBUITION, (yyvsp[-2].symbol), (yyvsp[0].ast),0,0,0); }
#line 1793 "y.tab.c"
    break;

  case 50:
#line 211 "parser.y"
                                                {  (yyval.ast) = astCreate(AST_ARRAY_ATTRIBUITION, 0, (yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1799 "y.tab.c"
    break;

  case 51:
#line 215 "parser.y"
                                                { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0,0,0,0); }
#line 1805 "y.tab.c"
    break;

  case 52:
#line 216 "parser.y"
                                                { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0,0,0,0); }
#line 1811 "y.tab.c"
    break;

  case 53:
#line 217 "parser.y"
                                                { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0,0,0,0); }
#line 1817 "y.tab.c"
    break;

  case 54:
#line 218 "parser.y"
                                                { (yyval.ast) = astCreate(AST_READ, 0, 0,0,0,0); }
#line 1823 "y.tab.c"
    break;

  case 55:
#line 219 "parser.y"
                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1829 "y.tab.c"
    break;

  case 56:
#line 220 "parser.y"
                                                { (yyval.ast) = astCreate(AST_EXPRESSION_BINARY_ARITHMETIC, (yyvsp[-1].symbol), (yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1835 "y.tab.c"
    break;

  case 57:
#line 221 "parser.y"
                                                { (yyval.ast) = astCreate(AST_EXPRESSION_BINARY_ARITHMETIC, (yyvsp[-1].symbol), (yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1841 "y.tab.c"
    break;

  case 58:
#line 222 "parser.y"
                                                { (yyval.ast) = astCreate(AST_EXPRESSION_BINARY_ARITHMETIC, (yyvsp[-1].symbol), (yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1847 "y.tab.c"
    break;

  case 59:
#line 223 "parser.y"
                                                { (yyval.ast) = astCreate(AST_EXPRESSION_BINARY_ARITHMETIC, (yyvsp[-1].symbol), (yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1853 "y.tab.c"
    break;

  case 60:
#line 225 "parser.y"
                                                { (yyval.ast) = astCreate(AST_EXPRESSION_BINARY_BOOLEAN, (yyvsp[-1].symbol), (yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1859 "y.tab.c"
    break;

  case 61:
#line 226 "parser.y"
                                                { (yyval.ast) = astCreate(AST_EXPRESSION_BINARY_BOOLEAN, (yyvsp[-1].symbol), (yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1865 "y.tab.c"
    break;

  case 62:
#line 227 "parser.y"
                                                { (yyval.ast) = astCreate(AST_EXPRESSION_BINARY_BOOLEAN, (yyvsp[-1].symbol), (yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1871 "y.tab.c"
    break;

  case 63:
#line 228 "parser.y"
                                                { (yyval.ast) = astCreate(AST_EXPRESSION_BINARY_BOOLEAN, (yyvsp[-1].symbol), (yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1877 "y.tab.c"
    break;

  case 64:
#line 229 "parser.y"
                                                { (yyval.ast) = astCreate(AST_EXPRESSION_BINARY_BOOLEAN, (yyvsp[-1].symbol), (yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1883 "y.tab.c"
    break;

  case 65:
#line 230 "parser.y"
                                                { (yyval.ast) = astCreate(AST_EXPRESSION_BINARY_BOOLEAN, (yyvsp[-1].symbol), (yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1889 "y.tab.c"
    break;

  case 66:
#line 232 "parser.y"
                                                { (yyval.ast) = astCreate(AST_EXPRESSION_BLOCK, 0, (yyvsp[-1].ast),0,0,0); }
#line 1895 "y.tab.c"
    break;

  case 67:
#line 233 "parser.y"
                                                { (yyval.ast) = (yyvsp[0].ast);}
#line 1901 "y.tab.c"
    break;

  case 68:
#line 236 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_ARRAY_ELEMENT, (yyvsp[-3].symbol), (yyvsp[-1].ast),0,0,0); }
#line 1907 "y.tab.c"
    break;

  case 69:
#line 239 "parser.y"
                                        { (yyval.ast) = astCreate(AST_PRINT, 0, (yyvsp[0].ast),0,0,0); }
#line 1913 "y.tab.c"
    break;

  case 70:
#line 242 "parser.y"
                                        { AST* lit = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0,0,0,0); (yyval.ast) = astCreate(AST_PRINT_REST, 0, lit,0,0,0); }
#line 1919 "y.tab.c"
    break;

  case 71:
#line 243 "parser.y"
                                        { AST* lit = astCreate(AST_SYMBOL, (yyvsp[-2].symbol), 0,0,0,0); (yyval.ast) = astCreate(AST_PRINT_REST, 0, lit,(yyvsp[0].ast),0,0); }
#line 1925 "y.tab.c"
    break;

  case 72:
#line 244 "parser.y"
                                        { (yyval.ast) = (yyvsp[0].ast); }
#line 1931 "y.tab.c"
    break;

  case 73:
#line 245 "parser.y"
                                        { (yyval.ast) = astCreate(AST_PRINT_REST, 0, (yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1937 "y.tab.c"
    break;

  case 74:
#line 248 "parser.y"
                                    { (yyval.ast) = astCreate(AST_RETURN, 0, (yyvsp[0].ast),0,0,0); }
#line 1943 "y.tab.c"
    break;

  case 75:
#line 257 "parser.y"
                                                            { (yyval.ast) = astCreate(AST_FLUX_CONTROLL_IF,   0, (yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1949 "y.tab.c"
    break;

  case 76:
#line 258 "parser.y"
                                                            { (yyval.ast) = astCreate(AST_FLUX_CONTROLL_IF,   0, (yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[0].ast),0); }
#line 1955 "y.tab.c"
    break;

  case 77:
#line 259 "parser.y"
                                                            { (yyval.ast) = astCreate(AST_FLUX_CONTROLL_WHILE,   0, (yyvsp[-1].ast),(yyvsp[0].ast),0,0); }
#line 1961 "y.tab.c"
    break;

  case 78:
#line 260 "parser.y"
                                                            { (yyval.ast) = (yyvsp[0].ast); }
#line 1967 "y.tab.c"
    break;

  case 79:
#line 263 "parser.y"
                                { (yyval.ast) = astCreate(AST_LABEL,   (yyvsp[-1].symbol), 0,0,0,0); }
#line 1973 "y.tab.c"
    break;

  case 80:
#line 266 "parser.y"
                                { (yyval.ast) = astCreate(AST_FLUX_CONTROLL_GOTO,   (yyvsp[0].symbol), 0,0,0,0); }
#line 1979 "y.tab.c"
    break;


#line 1983 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 270 "parser.y"


AST* getRootNode() {
    //astPrint(rootNode, 0);
    return rootNode;
}


void yyerror(const char *s) {
    fprintf(stderr, "%s at line %d.\n", s, getLineNumber());
    exit(3);
}
