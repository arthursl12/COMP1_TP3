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
#line 1 "yysint.y"

    #include <stdio.h>    
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include "aux.h"
    #include "tab.h"

    #define YYDEBUG 0          /* Se ligado, imprime mais informações */

    /* Constantes para tipos */
    #define TYPE_INT    1
    #define TYPE_REAL   2
    #define TYPE_CHAR   3
    #define TYPE_BOOL   4

    /* Forward declaration de funções do Lex */
    void yyerror (char *s);
    void typeerror();
    int yylex();

    /* Globals da Tabela de Símbolos */
    extern int escopo[10];
    extern int nivel;      /* nível atual */
    extern int L;          /* índice do último elemento da tabela */
    extern int Raiz;   

    /* Funções Auxiliares da Tabela de Símbolos */
    void installIdentList(char* type);
    int novoVal = 1;       /* Global para testar o updateVal */
    void updateVal(char* id, char* value);
    int q = 0;              /* Tamanho do ident_list */
    char* id_list[20];      /* Lista de identificadores numa declaração */

#line 105 "y.tab.c"

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
    RELOP = 258,
    MULOP = 259,
    ADDOP = 260,
    MINUS = 261,
    NOT = 262,
    ASSIGN = 263,
    INT_CONSTANT = 264,
    REAL_CONSTANT = 265,
    BOOL_CONSTANT = 266,
    IDENTIFIER = 267,
    IDENTIFIER_F = 268,
    CHAR_CONSTANT = 269,
    PROGRAM = 270,
    INTEGER = 271,
    REAL = 272,
    BOOLEAN = 273,
    CHAR = 274,
    BEGIN_STMT = 275,
    END = 276,
    IF = 277,
    THEN = 278,
    ELSE = 279,
    DO = 280,
    WHILE = 281,
    UNTIL = 282,
    READ = 283,
    WRITE = 284,
    GOTO = 285,
    SIN = 286,
    LOG = 287,
    COS = 288,
    ORD = 289,
    CHR = 290,
    ABS = 291,
    SQRT = 292,
    EXP = 293,
    EOF_TOKEN = 294,
    EOLN = 295
  };
#endif
/* Tokens.  */
#define RELOP 258
#define MULOP 259
#define ADDOP 260
#define MINUS 261
#define NOT 262
#define ASSIGN 263
#define INT_CONSTANT 264
#define REAL_CONSTANT 265
#define BOOL_CONSTANT 266
#define IDENTIFIER 267
#define IDENTIFIER_F 268
#define CHAR_CONSTANT 269
#define PROGRAM 270
#define INTEGER 271
#define REAL 272
#define BOOLEAN 273
#define CHAR 274
#define BEGIN_STMT 275
#define END 276
#define IF 277
#define THEN 278
#define ELSE 279
#define DO 280
#define WHILE 281
#define UNTIL 282
#define READ 283
#define WRITE 284
#define GOTO 285
#define SIN 286
#define LOG 287
#define COS 288
#define ORD 289
#define CHR 290
#define ABS 291
#define SQRT 292
#define EXP 293
#define EOF_TOKEN 294
#define EOLN 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 36 "yysint.y"

    int integer; 
    float real; 
    int boolean; 
    char character; 
    char* string; 
    char* lexeme_str; 


    /* Tipos de Não-terminais */
    struct expr { 
        int type; 
        union value value;
    } expr; 

#line 253 "y.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   138

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


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
      44,    45,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,    41,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   104,   104,   105,   106,   108,   109,   110,   112,   113,
     114,   115,   118,   120,   121,   123,   124,   126,   128,   129,
     130,   131,   132,   133,   134,   136,   164,   166,   167,   169,
     171,   172,   174,   175,   177,   179,   181,   184,   185,   187,
     192,   218,   223,   262,   287,   292,   349,   358,   367,   377,
     392,   403,   414,   427,   440,   453,   467,   479,   485,   499,
     504,   509,   516,   528,   534,   540,   546
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RELOP", "MULOP", "ADDOP", "MINUS",
  "NOT", "ASSIGN", "INT_CONSTANT", "REAL_CONSTANT", "BOOL_CONSTANT",
  "IDENTIFIER", "IDENTIFIER_F", "CHAR_CONSTANT", "PROGRAM", "INTEGER",
  "REAL", "BOOLEAN", "CHAR", "BEGIN_STMT", "END", "IF", "THEN", "ELSE",
  "DO", "WHILE", "UNTIL", "READ", "WRITE", "GOTO", "SIN", "LOG", "COS",
  "ORD", "CHR", "ABS", "SQRT", "EXP", "EOF_TOKEN", "EOLN", "';'", "':'",
  "','", "'('", "')'", "$accept", "program", "decl_list", "decl",
  "ident_list", "type", "compound_stmt", "stmt_list", "stmt", "label",
  "unlabelled_stmt", "assign_stmt", "cond", "if_stmt", "loop_stmt",
  "stmt_prefix", "stmt_suffix", "read_stmt", "write_stmt", "goto_stmt",
  "expr_list", "expr", "simple_expr", "term", "function_ref", "factor_a",
  "factor", "constant", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    59,    58,    44,    40,    41
};
# endif

#define YYPACT_NINF (-70)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -11,     1,    17,   -20,   -70,    15,   -70,   -18,   -70,    -5,
      87,    15,   -70,    -9,    23,    55,    22,    22,    27,    31,
      64,   -70,   -15,   -70,    35,   -70,   -70,   -70,   -70,    53,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
      22,    58,    58,   -70,   -70,   -70,   -70,   -70,    36,    37,
      38,    39,    40,    41,    42,    43,    56,    57,    22,    65,
     -70,     9,    99,   -70,   -70,   -70,   -70,   -70,    15,    22,
     -70,   -70,    87,    98,    87,   -70,   -70,   -70,    22,    22,
      22,    22,    22,    22,    22,    22,    22,    22,    60,    87,
      22,    22,    22,    22,   -27,   -21,   -70,   -70,    55,   -70,
     -16,    61,    63,    66,    67,    69,    74,    76,    77,    78,
      80,   -70,   105,    44,    99,    99,   -70,   -70,    22,   -70,
     -70,    22,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,    87,   -70,   -70,   -70
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     7,     0,     4,     0,
      31,     0,     2,     0,     0,    17,     0,     0,     0,     0,
       0,    24,     0,    14,     0,    16,    18,    19,    20,     0,
      21,    22,    23,     3,     8,     9,    10,    11,     5,     6,
       0,     0,     0,    63,    64,    66,    58,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,    39,    41,    61,    44,    57,    59,    30,     0,     0,
      36,    12,    31,    31,    31,    25,    56,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,    37,    13,     0,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    60,    27,    40,    42,    43,    45,    34,     0,    35,
      33,     0,    29,    46,    48,    47,    52,    53,    49,    50,
      51,    55,    54,    31,    38,    32,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -70,   -70,   -70,   119,    68,   -70,   124,    59,   -69,   -70,
      62,   -70,   -17,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -39,    47,   -40,   -70,    45,    32,   -70
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     8,     9,    38,    21,    22,    23,    24,
      25,    26,    59,    27,    28,    29,   122,    30,    31,    32,
      95,    60,    61,    62,    63,    64,    65,    66
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      67,    75,    10,    97,     1,   120,    71,    34,    35,    36,
      37,   121,    90,     3,    91,    92,    14,     4,   117,    88,
     112,     5,   118,    11,   119,    72,    72,     6,    41,    42,
      96,    43,    44,    45,    46,    39,    47,    13,    14,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    91,
      92,   114,   115,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    40,   136,    42,    58,    43,    44,    45,
      46,    68,    47,    76,    77,    69,    70,    73,    74,   134,
      78,    79,    80,    81,    82,    83,    84,    85,    89,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    15,
      86,    87,    58,    93,   135,   111,   123,    10,   124,    16,
      98,   125,   126,    17,   127,    18,    19,    20,    10,   128,
      16,   129,   130,   131,    17,   132,    18,    19,    20,   133,
      33,    12,     0,   100,     0,    99,    94,   113,   116
};

static const yytype_int16 yycheck[] =
{
      17,    40,    20,    72,    15,    21,    21,    16,    17,    18,
      19,    27,     3,    12,     5,     6,    43,     0,    45,    58,
      89,    41,    43,    41,    45,    41,    41,    12,     6,     7,
      69,     9,    10,    11,    12,    12,    14,    42,    43,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     5,
       6,    91,    92,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     8,   133,     7,    44,     9,    10,    11,
      12,    44,    14,    41,    42,    44,    12,    42,    25,   118,
      44,    44,    44,    44,    44,    44,    44,    44,    23,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    12,
      44,    44,    44,     4,   121,    45,    45,    20,    45,    22,
      12,    45,    45,    26,    45,    28,    29,    30,    20,    45,
      22,    45,    45,    45,    26,    45,    28,    29,    30,    24,
      11,     7,    -1,    74,    -1,    73,    68,    90,    93
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    47,    12,     0,    41,    12,    48,    49,    50,
      20,    41,    52,    42,    43,    12,    22,    26,    28,    29,
      30,    52,    53,    54,    55,    56,    57,    59,    60,    61,
      63,    64,    65,    49,    16,    17,    18,    19,    51,    12,
       8,     6,     7,     9,    10,    11,    12,    14,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    44,    58,
      67,    68,    69,    70,    71,    72,    73,    58,    44,    44,
      12,    21,    41,    42,    25,    67,    72,    72,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    67,    23,
       3,     5,     6,     4,    50,    66,    67,    54,    12,    56,
      53,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    45,    54,    68,    69,    69,    71,    45,    43,    45,
      21,    27,    62,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    24,    67,    58,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    50,    50,    51,    51,
      51,    51,    52,    53,    53,    54,    54,    55,    56,    56,
      56,    56,    56,    56,    56,    57,    58,    59,    59,    60,
      61,    61,    62,    62,    63,    64,    65,    66,    66,    67,
      67,    68,    68,    68,    69,    69,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    71,    71,    72,    72,
      72,    72,    72,    73,    73,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     1,     3,     3,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     4,     6,     4,
       2,     0,     2,     1,     4,     4,     2,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     2,     1,     1,     1,
       3,     1,     2,     1,     1,     1,     1
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
  case 3:
#line 105 "yysint.y"
                                                            { q = 0; }
#line 1520 "y.tab.c"
    break;

  case 4:
#line 106 "yysint.y"
                                                            { q = 0; }
#line 1526 "y.tab.c"
    break;

  case 5:
#line 108 "yysint.y"
                                                            { installIdentList((yyvsp[0].string)); (yyval.string) = (yyvsp[-2].string); }
#line 1532 "y.tab.c"
    break;

  case 6:
#line 109 "yysint.y"
                                                            { id_list[q] = (yyvsp[0].string); q++; }
#line 1538 "y.tab.c"
    break;

  case 7:
#line 110 "yysint.y"
                                                            { id_list[q] = (yyvsp[0].string); q++; }
#line 1544 "y.tab.c"
    break;

  case 25:
#line 137 "yysint.y"
                            { 
                                // Pesquisa a entrada na tabela de símbolos
                                int res_niv;
                                int res_i;
                                Get_Entry((yyvsp[-2].string), &res_niv, &res_i);

                                if (res_niv == -1){
                                    // Não encontrou na tabela
                                    exit(1);
                                }

                                if (TabelaS[res_i].type == TYPE_REAL 
                                    &&
                                    (yyvsp[0].expr).type == TYPE_INT){
                                    // Pode colocar int em real
                                    TabelaS[res_i].value = (yyvsp[0].expr).value;
                                }else if (TabelaS[res_i].type != (yyvsp[0].expr).type){
                                    printf("IDType: %i\n", TabelaS[res_i].type);
                                    printf("ExprType: %i\n", (yyvsp[0].expr).type);
                                    typeerror();
                                }else{
                                    TabelaS[res_i].value = (yyvsp[0].expr).value;
                                }
                                // updateVal($1,"updt"); 

                            }
#line 1575 "y.tab.c"
    break;

  case 39:
#line 188 "yysint.y"
    { 
        (yyval.expr).type = (yyvsp[0].expr).type; 
        (yyval.expr).value = (yyvsp[0].expr).value; 
    }
#line 1584 "y.tab.c"
    break;

  case 40:
#line 193 "yysint.y"
    {
        // Verificação de Tipos
        if (strcmp((yyvsp[-1].lexeme_str),"==") == 0 || strcmp((yyvsp[-1].lexeme_str),"!=") == 0){
            // Não importa os tipos dos operandos
            (yyval.expr).type = TYPE_BOOL; 
            
            // TODO: criar quádrupla para calcular valor
            // $$.value = $1.value; 
        }else if (strcmp((yyvsp[-1].lexeme_str),"<") == 0 || strcmp((yyvsp[-1].lexeme_str),"<=") == 0 
               || strcmp((yyvsp[-1].lexeme_str),">") == 0 || strcmp((yyvsp[-1].lexeme_str),">=") == 0){
            if ((yyvsp[-2].expr).type != TYPE_INT && (yyvsp[-2].expr).type != TYPE_REAL)
                typeerror();
            else if ((yyvsp[0].expr).type != TYPE_INT && (yyvsp[0].expr).type != TYPE_REAL)
                typeerror();
            
            (yyval.expr).type = TYPE_BOOL; 

            // TODO: criar quádrupla para calcular valor
            // $$.value = $1.value; 
        }else{
            printf("Lexema RELOP não encontrado\n");
            exit(1);
        }
    }
#line 1613 "y.tab.c"
    break;

  case 41:
#line 219 "yysint.y"
    { 
        (yyval.expr).type = (yyvsp[0].expr).type; 
        (yyval.expr).value = (yyvsp[0].expr).value; 
    }
#line 1622 "y.tab.c"
    break;

  case 42:
#line 224 "yysint.y"
    {
        if (strcmp((yyvsp[-1].lexeme_str),"+") == 0){
            
            if (((yyvsp[-2].expr).type == TYPE_INT || (yyvsp[-2].expr).type == TYPE_REAL)
                &&
                ((yyvsp[0].expr).type == TYPE_INT || (yyvsp[0].expr).type == TYPE_REAL))
            {
                // Estamos operando com números

                if ((yyvsp[-2].expr).type == TYPE_INT 
                && (yyvsp[0].expr).type == TYPE_INT)
                {
                    // Dois inteiros
                    (yyval.expr).type = TYPE_INT;
                    // TODO: criar quádrupla para calcular valor
                    // $$.value = $1.value; 
                }else{
                    // Pelo menos um real
                    (yyval.expr).type = TYPE_REAL;
                    // TODO: criar quádrupla para calcular valor
                    // $$.value = $1.value; 
                }
            }else
                typeerror();
        }else if (strcmp((yyvsp[-1].lexeme_str),"or") == 0){
            if ((yyvsp[-2].expr).type == TYPE_BOOL 
                && (yyvsp[0].expr).type == TYPE_BOOL){
                
                (yyval.expr).type = TYPE_BOOL;
                // TODO: criar quádrupla para calcular valor
                // $$.value = $1.value; 
            }else
                typeerror();
        }else{
            printf("Lexema ADDOP não encontrado\n");
            exit(1);
        }
    }
#line 1665 "y.tab.c"
    break;

  case 43:
#line 263 "yysint.y"
    {
        if (((yyvsp[-2].expr).type == TYPE_INT || (yyvsp[-2].expr).type == TYPE_REAL)
            &&
            ((yyvsp[0].expr).type == TYPE_INT || (yyvsp[0].expr).type == TYPE_REAL))
        {
            // Estamos operando com números

            if ((yyvsp[-2].expr).type == TYPE_INT 
            && (yyvsp[0].expr).type == TYPE_INT)
            {
                // Dois inteiros
                (yyval.expr).type = TYPE_INT;
                // TODO: criar quádrupla para calcular valor
                // $$.value = $1.value; 
            }else{
                // Pelo menos um real
                (yyval.expr).type = TYPE_REAL;
                // TODO: criar quádrupla para calcular valor
                // $$.value = $1.value; 
            }
        }else
            typeerror();
    }
#line 1693 "y.tab.c"
    break;

  case 44:
#line 288 "yysint.y"
    { 
        (yyval.expr).type = (yyvsp[0].expr).type; 
        (yyval.expr).value = (yyvsp[0].expr).value; 
    }
#line 1702 "y.tab.c"
    break;

  case 45:
#line 293 "yysint.y"
    {
        if (strcmp((yyvsp[-1].lexeme_str),"*") == 0){
            if (((yyvsp[-2].expr).type == TYPE_INT || (yyvsp[-2].expr).type == TYPE_REAL)
                &&
                ((yyvsp[0].expr).type == TYPE_INT || (yyvsp[0].expr).type == TYPE_REAL))
            {
                // Estamos operando com números
                if ((yyvsp[-2].expr).type == TYPE_INT 
                && (yyvsp[0].expr).type == TYPE_INT)
                {
                    // Dois inteiros
                    (yyval.expr).type = TYPE_INT;
                    // TODO: criar quádrupla para calcular valor
                    // $$.value = $1.value; 
                }else{
                    // Pelo menos um real
                    (yyval.expr).type = TYPE_REAL;
                    // TODO: criar quádrupla para calcular valor
                    // $$.value = $1.value; 
                }
            }else
                typeerror();
        }else if(strcmp((yyvsp[-1].lexeme_str),"/") == 0){
            if (((yyvsp[-2].expr).type == TYPE_INT || (yyvsp[-2].expr).type == TYPE_REAL)
                &&
                ((yyvsp[0].expr).type == TYPE_INT || (yyvsp[0].expr).type == TYPE_REAL))
            {
                (yyval.expr).type = TYPE_REAL;
                // TODO: criar quádrupla para calcular valor
                // $$.value = $1.value; 
            }else
                typeerror();
        }else if (strcmp((yyvsp[-1].lexeme_str),"div") == 0 || strcmp((yyvsp[-1].lexeme_str),"mod") == 0){
            if ((yyvsp[-2].expr).type == TYPE_INT
                && (yyvsp[0].expr).type == TYPE_INT)
            {
                (yyval.expr).type = TYPE_INT;
                // TODO: criar quádrupla para calcular valor
                // $$.value = $1.value; 
            }else
                typeerror();
        }else if (strcmp((yyvsp[-1].lexeme_str),"and") == 0){
            if ((yyvsp[-2].expr).type == TYPE_BOOL 
                && (yyvsp[0].expr).type == TYPE_BOOL){
                
                (yyval.expr).type = TYPE_BOOL;
                // TODO: criar quádrupla para calcular valor
                // $$.value = $1.value; 
            }else
                typeerror();
        }else {
            printf("Lexema MULOP não encontrado\n");
            exit(1);
        }
    }
#line 1762 "y.tab.c"
    break;

  case 46:
#line 350 "yysint.y"
                            {
                                if ((yyvsp[-1].expr).type != TYPE_REAL){
                                    typeerror();
                                }
                                (yyval.expr).type = TYPE_REAL;
                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
#line 1775 "y.tab.c"
    break;

  case 47:
#line 359 "yysint.y"
                            {
                                if ((yyvsp[-1].expr).type != TYPE_REAL){
                                    typeerror();
                                }
                                (yyval.expr).type = TYPE_REAL;
                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
#line 1788 "y.tab.c"
    break;

  case 48:
#line 368 "yysint.y"
                            {
                                // Assumindo logaritmo natural (base e)
                                if ((yyvsp[-1].expr).type != TYPE_REAL){
                                    typeerror();
                                }
                                (yyval.expr).type = TYPE_REAL;
                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
#line 1802 "y.tab.c"
    break;

  case 49:
#line 378 "yysint.y"
                            {
                                if ((yyvsp[-1].expr).type == TYPE_REAL){
                                    (yyval.expr).type = TYPE_REAL;

                                }else if((yyvsp[-1].expr).type == TYPE_INT){
                                    (yyval.expr).type = TYPE_INT;

                                }else{
                                    typeerror();
                                }

                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
#line 1821 "y.tab.c"
    break;

  case 50:
#line 393 "yysint.y"
                            {
                                if ((yyvsp[-1].expr).type != TYPE_REAL){
                                    typeerror();
                                }
                                (yyval.expr).type = TYPE_REAL;

                                // Se for negativo, gerará erro de execução
                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
#line 1836 "y.tab.c"
    break;

  case 51:
#line 404 "yysint.y"
                            {
                                // Retorna e^x, sendo x o parâmetro
                                if ((yyvsp[-1].expr).type != TYPE_REAL){
                                    typeerror();
                                }
                                (yyval.expr).type = TYPE_REAL;

                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
#line 1851 "y.tab.c"
    break;

  case 52:
#line 415 "yysint.y"
                            {
                                // Retorna o inteiro do parâmetro
                                // É um "casting" de inteiro

                                if ((yyvsp[-1].expr).type == TYPE_REAL){
                                    typeerror();
                                }
                                (yyval.expr).type = TYPE_INT;

                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
#line 1868 "y.tab.c"
    break;

  case 53:
#line 428 "yysint.y"
                            {
                                // Retorna equivalente char do parâmetro
                                // É um "casting" de char

                                if ((yyvsp[-1].expr).type == TYPE_REAL){
                                    typeerror();
                                }
                                (yyval.expr).type = TYPE_CHAR;

                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
#line 1885 "y.tab.c"
    break;

  case 54:
#line 441 "yysint.y"
                            {
                                // Verifica EOLn do arquivo nomeado pelo parâmetro

                                if ((yyvsp[-1].expr).type != TYPE_CHAR){
                                    printf("EOLn: %i", (yyvsp[-1].expr).type);
                                    typeerror();
                                }
                                (yyval.expr).type = TYPE_BOOL;

                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
#line 1902 "y.tab.c"
    break;

  case 55:
#line 454 "yysint.y"
                            {
                                // Verifica EOF do arquivo nomeado pelo parâmetro

                                if ((yyvsp[-1].expr).type != TYPE_CHAR){
                                    printf("EOF: %i", (yyvsp[-1].expr).type);
                                    typeerror();
                                }
                                (yyval.expr).type = TYPE_BOOL;

                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
#line 1919 "y.tab.c"
    break;

  case 56:
#line 468 "yysint.y"
                            { 
                                if ((yyvsp[0].expr).type == TYPE_INT){
                                    (yyval.expr).type = TYPE_INT;
                                }else if ((yyvsp[0].expr).type == TYPE_REAL){
                                    (yyval.expr).type = TYPE_REAL;
                                }else
                                    typeerror();
                                
                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
#line 1935 "y.tab.c"
    break;

  case 57:
#line 480 "yysint.y"
                            { 
                                (yyval.expr).type = (yyvsp[0].expr).type; 
                                (yyval.expr).value = (yyvsp[0].expr).value; 
                            }
#line 1944 "y.tab.c"
    break;

  case 58:
#line 486 "yysint.y"
                            { 
                                // Pesquisa a entrada na tabela de símbolos
                                int res_niv;
                                int res_i;
                                Get_Entry((yyvsp[0].string), &res_niv, &res_i);

                                if (res_niv == -1){
                                    // Não encontrou na tabela
                                    exit(1);
                                }
                                (yyval.expr).type = TabelaS[res_i].type;
                                (yyval.expr).value = TabelaS[res_i].value;
                            }
#line 1962 "y.tab.c"
    break;

  case 59:
#line 500 "yysint.y"
                            { 
                                (yyval.expr).type = (yyvsp[0].expr).type; 
                                (yyval.expr).value = (yyvsp[0].expr).value; 
                            }
#line 1971 "y.tab.c"
    break;

  case 60:
#line 505 "yysint.y"
                            { 
                                (yyval.expr).type = (yyvsp[-1].expr).type; 
                                (yyval.expr).value = (yyvsp[-1].expr).value; 
                            }
#line 1980 "y.tab.c"
    break;

  case 61:
#line 510 "yysint.y"
                            { 
                                // TODO: tipo função 
                                //       + verificação tipos parâmtros
                                //       + verificaçaõ tipo retorno
                                (yyval.expr).type = (yyvsp[0].expr).type;
                            }
#line 1991 "y.tab.c"
    break;

  case 62:
#line 517 "yysint.y"
                            { 
                                if ((yyvsp[0].expr).type != TYPE_BOOL){
                                    typeerror();
                                }else{
                                    (yyval.expr).type = TYPE_BOOL;
                                }

                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
#line 2006 "y.tab.c"
    break;

  case 63:
#line 529 "yysint.y"
                            { 
                                (yyval.expr).type = TYPE_INT; 
                                (yyval.expr).value.integer = (yyvsp[0].integer); 
                                printf("Valor [integer]: %d\n", (yyvsp[0].integer));
                            }
#line 2016 "y.tab.c"
    break;

  case 64:
#line 535 "yysint.y"
                            { 
                                (yyval.expr).type = TYPE_REAL; 
                                (yyval.expr).value.real = (yyvsp[0].real); 
                                printf("Valor [real]: %f\n", (yyvsp[0].real));
                            }
#line 2026 "y.tab.c"
    break;

  case 65:
#line 541 "yysint.y"
                            { 
                                (yyval.expr).type = TYPE_CHAR; 
                                (yyval.expr).value.character = (yyvsp[0].character); 
                                printf("Valor [character]: %c\n", (yyvsp[0].character));
                            }
#line 2036 "y.tab.c"
    break;

  case 66:
#line 547 "yysint.y"
                            { 
                                (yyval.expr).type = TYPE_BOOL; 
                                (yyval.expr).value.boolean = (yyvsp[0].boolean); 
                                printf("Valor [boolean]: %i\n", (yyvsp[0].boolean));
                            }
#line 2046 "y.tab.c"
    break;


#line 2050 "y.tab.c"

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
#line 555 "yysint.y"
                     

/*
Instala a lista de identificadores 'id_list' (global) de tipo 'type' na 
tabela de símbolos
*/
void installIdentList(char* type){
    //   Obs.: o tamanho do array 'id_list' está na variável global 'q'
    int i = 0;
    // printf("%i declaracoes do tipo %s\n", q, type);

    for (i = 0; i < q; i++){
        // printf("Instalando %s, do tipo %s\n", id_list[i], type);
        union value placeholder;
        int tipo_cst = -1;
        if (strcmp(type, "integer") == 0){
            tipo_cst = TYPE_INT;
        }else if (strcmp(type, "real") == 0){
            tipo_cst = TYPE_REAL;
        }else if (strcmp(type, "boolean") == 0){
            tipo_cst = TYPE_BOOL;
        }else if (strcmp(type, "char") == 0){
            tipo_cst = TYPE_CHAR;
        }
        Instala(id_list[i], tipo_cst, placeholder);

    }
}

/*
Atualiza o atributo 'value' da entrada 'id' da tabela de símbolos
*/
void updateVal(char* id, char* value){
    int res_niv;
    int res_i;
    Get_Entry(id, &res_niv, &res_i);

    // O correto seria:
    // strcpy(TabelaS[res_i].value, value);

    // Ainda não avaliamos expressões para conseguir calcular o value
    // mas podemos testar o updateVal, colocando o contador 'novoVal' na tabela
    char num[200];
    sprintf(num, "%d", novoVal);
    /* strcpy(TabelaS[res_i].value, num); */
    TabelaS[res_i].value.integer = atoi(num);

    novoVal++;
}

int main (void) {
    #if YYDEBUG
        yydebug = 1;     
    #endif 


    /* Inicialização da Tabela de Símbolos */
    /* Primeira posição da tabela é 1. L é o final da árvore */
    L = 1;             
    /* Primeiro nível é 1 */     
    nivel = 1;              
    /* escopo[1] contém o indice do primeiro elemento */
    escopo[nivel] = 0;      

    /* Parsing */
    printf("Parsing...\n");
    if (yyparse() == 0){
        printf("Parse sucessful\n\n");
        printf("Tabela de Simbolos Final:");
        imprimir();     // Imprime a tabela de símbolos ao final
        return 0;
    }else{
        return 1;
    }
	
}

void yyerror (char *s) {
    fprintf (stderr, "%s\n", s);
}

void typeerror(){
    printf("Type-error\n");
    exit(1);
}
