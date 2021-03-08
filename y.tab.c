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
    #include <stdbool.h>
    #include <string.h>
    #include <ctype.h>
    #include "tab.h"
    #include "lists.h"
    #include "codinterm.h"

    #include "aux.h"


    #define YYDEBUG 0          /* Se ligado, imprime mais informações */


    /* Forward declaration de funções do parser */
    void yyerror (char *s);
    void typeerror();
    void typeerror_msg(char* msg);
    int yylex();
    void tempTipo(int* tipo1, int* tipo2, intmdt_addr_t* s1, intmdt_addr_t* s3);
    bool isNumber(int tipo);
    bool isNumToReal(char* funct);
    
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

    /* Lista de Quádruplas geradas */
    intmdt_code_t *intermediate_code;

#line 112 "y.tab.c"

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
/* "%code requires" blocks.  */
#line 43 "yysint.y"

    #include "codinterm.h"
    #include <stdbool.h>

#line 160 "y.tab.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    RELOP = 258,
    MULOP = 259,
    AND = 260,
    ADDOP = 261,
    OR = 262,
    MINUS = 263,
    NOT = 264,
    ASSIGN = 265,
    INT_CONSTANT = 266,
    REAL_CONSTANT = 267,
    BOOL_CONSTANT = 268,
    TRUE_CST = 269,
    FALSE_CST = 270,
    IDENTIFIER = 271,
    IDENTIFIER_F = 272,
    CHAR_CONSTANT = 273,
    PROGRAM = 274,
    INTEGER = 275,
    REAL = 276,
    BOOLEAN = 277,
    CHAR = 278,
    BEGIN_STMT = 279,
    END = 280,
    IF = 281,
    THEN = 282,
    ELSE = 283,
    DO = 284,
    WHILE = 285,
    UNTIL = 286,
    READ = 287,
    WRITE = 288,
    GOTO = 289,
    SIN = 290,
    LOG = 291,
    COS = 292,
    ORD = 293,
    CHR = 294,
    ABS = 295,
    SQRT = 296,
    EXP = 297,
    EOF_TOKEN = 298,
    EOLN = 299
  };
#endif
/* Tokens.  */
#define RELOP 258
#define MULOP 259
#define AND 260
#define ADDOP 261
#define OR 262
#define MINUS 263
#define NOT 264
#define ASSIGN 265
#define INT_CONSTANT 266
#define REAL_CONSTANT 267
#define BOOL_CONSTANT 268
#define TRUE_CST 269
#define FALSE_CST 270
#define IDENTIFIER 271
#define IDENTIFIER_F 272
#define CHAR_CONSTANT 273
#define PROGRAM 274
#define INTEGER 275
#define REAL 276
#define BOOLEAN 277
#define CHAR 278
#define BEGIN_STMT 279
#define END 280
#define IF 281
#define THEN 282
#define ELSE 283
#define DO 284
#define WHILE 285
#define UNTIL 286
#define READ 287
#define WRITE 288
#define GOTO 289
#define SIN 290
#define LOG 291
#define COS 292
#define ORD 293
#define CHR 294
#define ABS 295
#define SQRT 296
#define EXP 297
#define EOF_TOKEN 298
#define EOLN 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 48 "yysint.y"

    int integer; 
    float real; 
    int boolean; 
    char character; 
    char* string; 
    char* lexeme_str; 
    intmdt_addr_t* intmdt_addr;


    /* Tipos de Não-terminais */
    struct stmt_t{
        list_head_t* next;
    } stmt_t;
    struct loop_aux_stmt_t{
        list_head_t* loop_main_next_list;
        list_head_t* next;
    } loop_aux_stmt_t;
    struct stmt_pref_t{
        bool hasPrefix;
        list_head_t* falselist;
        list_head_t* truelist;
    } stmt_pref_t;
    struct stmt_suff_t{
        bool hasSuffix;
        list_head_t* truelist;
        list_head_t* falselist;
    } stmt_suff_t;
    struct expr { 
        int type; 
        union value value;
    } expr;
    struct expr_lst_t { 
        list_head_t* list;
        int qtd_terms;
    } expr_lst_t;


#line 298 "y.tab.c"

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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   113

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

#define YYUNDEFTOK  2
#define YYMAXUTOK   299


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
      48,    49,     2,     2,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    45,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   148,   148,   156,   157,   159,   160,   161,   163,   164,
     165,   166,   169,   171,   177,   179,   236,   238,   240,   241,
     242,   243,   244,   245,   246,   248,   352,   354,   375,   394,
     401,   407,   478,   494,   499,   505,   512,   519,   533,   601,
     607,   616,   620,   672,   676,   709,   753,   781,   786,   852,
     897,  1015,  1041,  1066,  1072,  1115,  1119,  1123,  1130,  1176,
    1187,  1198,  1209,  1238
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RELOP", "MULOP", "AND", "ADDOP", "OR",
  "MINUS", "NOT", "ASSIGN", "INT_CONSTANT", "REAL_CONSTANT",
  "BOOL_CONSTANT", "TRUE_CST", "FALSE_CST", "IDENTIFIER", "IDENTIFIER_F",
  "CHAR_CONSTANT", "PROGRAM", "INTEGER", "REAL", "BOOLEAN", "CHAR",
  "BEGIN_STMT", "END", "IF", "THEN", "ELSE", "DO", "WHILE", "UNTIL",
  "READ", "WRITE", "GOTO", "SIN", "LOG", "COS", "ORD", "CHR", "ABS",
  "SQRT", "EXP", "EOF_TOKEN", "EOLN", "';'", "':'", "','", "'('", "')'",
  "$accept", "program", "decl_list", "decl", "ident_list", "type",
  "compound_stmt", "stmt_list", "stmt", "label", "unlabelled_stmt",
  "assign_stmt", "cond", "if_stmt", "M", "N", "loop_stmt", "stmt_prefix",
  "stmt_suffix", "read_stmt", "write_stmt", "goto_stmt", "expr_list",
  "expr", "simple_expr", "term", "function_ref", "factor_a", "factor",
  "constant", YY_NULLPTR
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
     295,   296,   297,   298,   299,    59,    58,    44,    40,    41
};
# endif

#define YYPACT_NINF (-82)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      17,    24,    43,    -1,   -82,    53,   -82,   -16,   -82,    18,
      29,    53,   -82,    61,    57,    49,    -2,    31,    48,    76,
     -82,    -7,   -82,   -82,   -82,   -82,   -82,    67,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,    -2,
       8,     8,   -82,   -82,   -82,   -82,   -82,    50,   -82,    -2,
      72,   -82,    64,    45,   -82,   -82,   -82,   -82,    53,    -2,
     -82,   -82,   -82,    55,   -82,   -82,   -82,   -82,   -82,    -2,
      51,   -82,    -2,    -2,   -82,    -2,    -2,   -82,    38,    39,
     -82,    29,    42,    -2,    73,    44,   -82,    29,    -3,    45,
      -2,    45,   -82,    -2,   -82,    -2,   -82,   -82,    49,   -82,
     -82,   -82,   -82,    75,    45,   -82,   -82,   -82,    29,   -82,
     -82,    59,   -82,   -82,    29,     3,   -82,   -82,    -2,   -82,
     -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     7,     0,     4,     0,
      29,     0,     2,     0,     0,    17,     0,     0,     0,     0,
      24,     0,    14,    29,    16,    18,    19,    33,    20,    21,
      22,    23,     3,     8,     9,    10,    11,     5,     6,     0,
       0,     0,    59,    60,    62,    63,    54,    51,    61,     0,
       0,    26,    41,    43,    57,    47,    53,    55,     0,     0,
      38,    12,    29,     0,    29,    29,    25,    52,    58,     0,
       0,    29,     0,     0,    29,     0,     0,    29,     0,     0,
      39,    29,    29,     0,     0,     0,    56,    29,    42,    44,
       0,    46,    48,     0,    36,     0,    37,    13,     0,    15,
      29,    29,    50,    29,    45,    49,    40,    32,    29,    30,
      27,    30,    29,    29,    29,     0,    28,    35,     0,    31,
      34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -82,   -82,   -82,    94,    52,   -82,    99,     0,   -54,   -82,
      25,   -82,   -81,   -82,   -23,     1,   -82,   -82,   -82,   -82,
     -82,   -82,    40,   -38,    41,   -43,   -82,   -41,    54,   -82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     8,     9,    37,    20,    21,    22,    23,
      24,    25,    50,    26,    27,   112,    28,    65,   119,    29,
      30,    31,    79,    51,    52,    53,    54,    55,    56,    57
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      63,    66,   100,    73,    74,    75,    40,    41,    10,    42,
      43,    70,    44,    45,    46,    47,    48,    41,    61,    42,
      43,    80,    44,    45,    46,    47,    48,    97,   117,    11,
      89,    80,    91,   103,   118,    92,     1,   120,    62,    81,
       3,    83,    84,     4,     5,    15,    49,   104,    87,    76,
      77,    90,   105,    10,    93,    16,    49,   106,    98,    39,
     116,    17,    18,    19,    13,    14,    10,    72,    16,     6,
      73,    74,    75,    38,    17,    18,    19,   107,   108,    58,
     110,    33,    34,    35,    36,    14,    95,    94,    96,   114,
     115,    95,    60,   102,    67,    68,    59,    64,    69,    71,
      86,    82,   101,   109,    62,    32,    12,    99,   111,    85,
      78,     0,   113,    88
};

static const yytype_int8 yycheck[] =
{
      23,    39,    83,     6,     7,     8,     8,     9,    24,    11,
      12,    49,    14,    15,    16,    17,    18,     9,    25,    11,
      12,    59,    14,    15,    16,    17,    18,    81,    25,    45,
      73,    69,    75,    87,    31,    76,    19,   118,    45,    62,
      16,    64,    65,     0,    45,    16,    48,    90,    71,     4,
       5,    74,    93,    24,    77,    26,    48,    95,    16,    10,
     114,    32,    33,    34,    46,    47,    24,     3,    26,    16,
       6,     7,     8,    16,    32,    33,    34,   100,   101,    48,
     103,    20,    21,    22,    23,    47,    47,    49,    49,   112,
     113,    47,    16,    49,    40,    41,    48,    30,    48,    27,
      49,    46,    29,    28,    45,    11,     7,    82,   108,    69,
      58,    -1,   111,    72
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    51,    16,     0,    45,    16,    52,    53,    54,
      24,    45,    56,    46,    47,    16,    26,    32,    33,    34,
      56,    57,    58,    59,    60,    61,    63,    64,    66,    69,
      70,    71,    53,    20,    21,    22,    23,    55,    16,    10,
       8,     9,    11,    12,    14,    15,    16,    17,    18,    48,
      62,    73,    74,    75,    76,    77,    78,    79,    48,    48,
      16,    25,    45,    64,    30,    67,    73,    78,    78,    48,
      73,    27,     3,     6,     7,     8,     4,     5,    54,    72,
      73,    64,    46,    64,    64,    72,    49,    64,    74,    75,
      64,    75,    77,    64,    49,    47,    49,    58,    16,    60,
      62,    29,    49,    58,    75,    77,    73,    64,    64,    28,
      64,    57,    65,    65,    64,    64,    58,    25,    31,    68,
      62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    54,    54,    55,    55,
      55,    55,    56,    57,    57,    58,    58,    59,    60,    60,
      60,    60,    60,    60,    60,    61,    62,    63,    63,    64,
      65,    66,    67,    67,    68,    68,    69,    70,    71,    72,
      72,    73,    73,    74,    74,    74,    74,    75,    75,    75,
      76,    76,    77,    77,    78,    78,    78,    78,    78,    79,
      79,    79,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     1,     3,     3,     1,     1,     1,
       1,     1,     3,     4,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     6,     9,     0,
       0,     9,     4,     0,     2,     1,     4,     4,     2,     1,
       3,     1,     3,     1,     3,     4,     3,     1,     3,     4,
       4,     1,     2,     1,     1,     1,     3,     1,     2,     1,
       1,     1,     1,     1
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
#line 149 "yysint.y"
    {
        // Quádrupla para finalizar: é útil quando comandos de controle são
        // os últimos ou só há um comando no programa. Não possui ação prática.
        gen(intermediate_code, "end", NULL, NULL, NULL);
        backpatch((yyvsp[0].stmt_t).next, intermediate_code->code[intermediate_code->n - 1]);
        
    }
#line 1565 "y.tab.c"
    break;

  case 3:
#line 156 "yysint.y"
                                                            { q = 0; }
#line 1571 "y.tab.c"
    break;

  case 4:
#line 157 "yysint.y"
                                                            { q = 0; }
#line 1577 "y.tab.c"
    break;

  case 5:
#line 159 "yysint.y"
                                                            { installIdentList((yyvsp[0].string)); (yyval.string) = (yyvsp[-2].string); }
#line 1583 "y.tab.c"
    break;

  case 6:
#line 160 "yysint.y"
                                                            { id_list[q] = (yyvsp[0].string); q++; }
#line 1589 "y.tab.c"
    break;

  case 7:
#line 161 "yysint.y"
                                                            { id_list[q] = (yyvsp[0].string); q++; }
#line 1595 "y.tab.c"
    break;

  case 12:
#line 169 "yysint.y"
                                                     { (yyval.stmt_t).next = (yyvsp[-1].stmt_t).next; }
#line 1601 "y.tab.c"
    break;

  case 13:
#line 172 "yysint.y"
    {
        // Remenda o próximo do stmt_list para o primeiro do stmt
        backpatch((yyvsp[-3].stmt_t).next, intermediate_code->code[(yyvsp[-1].integer)]);
        (yyval.stmt_t).next = (yyvsp[0].stmt_t).next;
    }
#line 1611 "y.tab.c"
    break;

  case 14:
#line 177 "yysint.y"
                                 { (yyval.stmt_t).next = (yyvsp[0].stmt_t).next; }
#line 1617 "y.tab.c"
    break;

  case 15:
#line 180 "yysint.y"
    {
        // Coloca um '_' ao final do label
        // Para diferenciar de identificadores comuns, por exemplo
        char* label = strdup((yyvsp[-3].string));
        strncat(label, "_ _", 1);
        
        // Procura label na TS
        int res_niv;
        int res_i;
        Get_Entry(label, &res_niv, &res_i);

        if (res_i == -1){
            // Label não está na TS
            // Instalar o label na TS
            union value dest;
            int tipo_cst = TYPE_LABEL;
            int cls = CLS_LABEL;
            boolean_list_t *blist = NULL;

            // Já instala com a quádrupla de destino (quádrupla atual)
            dest.instr_ptr = intermediate_code->code[(yyvsp[-2].integer)];
            Instala(label, tipo_cst, cls, dest, blist);
        }else if(res_i != -1 
            && TabelaS[res_i].value.instr_ptr != NULL 
            && TabelaS[res_i].value.instr_ptr->result != NULL){
            quadruple_t* quad = TabelaS[res_i].value.instr_ptr;
            // Label está na TS e já possui um destino definido
            // Temos que acusar um erro
            
            printf("Label %s já declarado e já definido\n", (yyvsp[-3].string));
            printf("Destino atual: ");
            printQuad(quad, quad->n);
            yyerror(" ");
            YYABORT;
        }else{
            // Label está na TS mas não possui um destino definido
            // Vamos definir seu destino (quádrupla atual)

            // Cria estrutura para quádrupla de destino
            intmdt_addr_t *dest = malloc(sizeof(intmdt_addr_t));
            if (dest == NULL) {
                fprintf(stderr, "failed to malloc intmdt_addr_t in goto_stmt\n");
                YYABORT;
            }
            quadruple_t* quad = intermediate_code->code[(yyvsp[-2].integer)];
            dest->type = TYPE_LABEL;
            dest->value.instr_ptr = quad;

            // Altera o campo do label na TS
            quadruple_t* quad1 = TabelaS[res_i].value.instr_ptr;
            quad1->result = dest;
        }
        
        // Passa o next para cima o não-terminal da esquerda
        (yyval.stmt_t).next = (yyvsp[0].stmt_t).next;
    }
#line 1678 "y.tab.c"
    break;

  case 16:
#line 236 "yysint.y"
                                            { (yyval.stmt_t).next = (yyvsp[0].stmt_t).next; }
#line 1684 "y.tab.c"
    break;

  case 18:
#line 240 "yysint.y"
                                        { (yyval.stmt_t).next = (yyvsp[0].stmt_t).next; }
#line 1690 "y.tab.c"
    break;

  case 19:
#line 241 "yysint.y"
                                    { (yyval.stmt_t).next = (yyvsp[0].stmt_t).next; }
#line 1696 "y.tab.c"
    break;

  case 20:
#line 242 "yysint.y"
                                        { (yyval.stmt_t).next = (yyvsp[0].stmt_t).next; }
#line 1702 "y.tab.c"
    break;

  case 21:
#line 243 "yysint.y"
                                        { (yyval.stmt_t).next = NULL; }
#line 1708 "y.tab.c"
    break;

  case 22:
#line 244 "yysint.y"
                                        { (yyval.stmt_t).next = NULL; }
#line 1714 "y.tab.c"
    break;

  case 23:
#line 245 "yysint.y"
                                        { (yyval.stmt_t).next = (yyvsp[0].stmt_t).next; }
#line 1720 "y.tab.c"
    break;

  case 24:
#line 246 "yysint.y"
                                            { (yyval.stmt_t).next = (yyvsp[0].stmt_t).next; }
#line 1726 "y.tab.c"
    break;

  case 25:
#line 249 "yysint.y"
    { 
        // Pesquisa a entrada na tabela de símbolos
        int res_niv;
        int res_i;
        Get_Entry((yyvsp[-2].string), &res_niv, &res_i);
        if (res_niv == -1){
            // Não encontrou na tabela
            yyerror("Identifier não encontrado\n");
            YYABORT;
        }

        // Tipo dos operandos (para verificação de tipos)
        int tipo1 = TabelaS[res_i].type;
        int tipo2 = (yyvsp[0].intmdt_addr)->type;

        // Se for temporário, procure na Tabela de Símbolos seu tipo de verdade
        if (tipo1 == TS_ENTRY ){
            int idx = TabelaS[res_i].value.TS_idx;
            tipo1 = TabelaS[idx].type;
        }
        if (tipo2 == TS_ENTRY){
            int idx = (yyvsp[0].intmdt_addr)->value.TS_idx;
            tipo2 = TabelaS[idx].type;
        }

        // Verificação de Tipos
        if (tipo1 == TYPE_REAL && tipo2 == TYPE_INT){
            // Pode colocar int em real, nada a ser feito
        }else if (tipo1 != tipo2){
            // Tentando colocar real em int, acusar erro
            typeerror_msg("Tipos incompatíveis na atribuição\n");
            YYABORT;
        }

        // Geração da Quádrupla
        if (tipo1 != TYPE_BOOL){
            // Variáveis do tipo inteiro, real e char
            // Guarde o resultado da expressão na entrada do identificador na TS
            intmdt_addr_t *dest = malloc (sizeof(intmdt_code_t));
            if (dest == NULL) {
                yyerror("Error: malloc in ASSIGN");
                YYABORT;
            }
            dest->type = TS_ENTRY;
            dest->value.TS_idx = res_i;
            gen(intermediate_code, ":=", (yyvsp[0].intmdt_addr), NULL, dest);
            (yyval.stmt_t).next = NULL;
        }else{
            // Variáveis do tipo booleano:

            // Guarde o resultado da expressão na entrada do identificador na TS
            // Mas tem um porém quanto ao resultado da expressão!
            intmdt_addr_t *dest = malloc (sizeof(intmdt_code_t));
            if (dest == NULL) {
                yyerror("Error: malloc in ASSIGN");
                YYABORT;
            }
            dest->type = TS_ENTRY;
            dest->value.TS_idx = res_i;

            // Existe um "if escondido" nessa atribuição:
            //      if (expr)
            //          id = true
            //      else
            //          id = false
            // As quádruplas geradas a seguir são para simular isso

            // Gerar um temporário 'true'
            // Ele será atribuído ao id se expr for verdadeiro
            intmdt_addr_t *temp1 = newtemp(TYPE_BOOL);
            TabelaS[temp1->value.TS_idx].class = CLS_VARIABLE;
            TabelaS[temp1->value.TS_idx].value.boolean = 1;

            // Quádrupla para atribuir verdadeiro ao identifier
            gen(intermediate_code, ":=", temp1, NULL, dest);

            // Remendo: caso a expressão passada seja true, atribuamos true
            // i.e. a truelist deve ir para o atribuir true 
            backpatch((yyvsp[0].intmdt_addr)->list->truelist, 
                      intermediate_code->code[intermediate_code->n-1]);

            // Após atribuir verdadeiro, pule o atribuir falso
            gen(intermediate_code, "gotoAB", NULL, NULL, NULL);
            (yyval.stmt_t).next = list_makelist(intermediate_code->code[intermediate_code->n - 1]);

            // Gerar um temporário 'false'
            // Ele será atribuído ao id se expr for falso
            intmdt_addr_t *temp2 = newtemp(TYPE_BOOL);
            TabelaS[temp2->value.TS_idx].class = CLS_VARIABLE;
            TabelaS[temp2->value.TS_idx].value.boolean = 0;
            
            // Quádrupla para atribuir falso ao identifier
            gen(intermediate_code, ":=", temp2, NULL, dest);

            // Remendo: caso a expressão passada seja false, atribuamos false
            // i.e. a falselist deve ir para o atribuir false 
            backpatch((yyvsp[0].intmdt_addr)->list->falselist, 
                      intermediate_code->code[intermediate_code->n-1]);

            // Não precisamos pular quádruplas agora, basta seguir a execução
        }
    }
#line 1833 "y.tab.c"
    break;

  case 27:
#line 355 "yysint.y"
    {
        // Se cond é verdadeiro, devemos ir para o stmt
        // i.e. remende a truelist de cond para ir para o stmt
       	backpatch((yyvsp[-4].intmdt_addr)->list->truelist, intermediate_code->code[(yyvsp[-2].integer)]);

        // Se cond é falso, devemos ir para depois do stmt
        // i.e. devemos ir para a quádrupla seguinte ao stmt
        // Após o comando if, devemos ir para lá também,
        // por isso a atribuição a $$.next
       	(yyval.stmt_t).next = list_merge((yyvsp[-4].intmdt_addr)->list->falselist, (yyvsp[-1].stmt_t).next);
        // Essa falselist será remendada quando o $$.next for remendado,
        // por exemplo no stmt_list

        // Se conhecemos a quádrupla seguinte ao stmt,
        // podemos fazer o remendo dela para seguir após o if_stmt
        if ((yyvsp[-1].stmt_t).next != NULL){
            backpatch((yyvsp[-1].stmt_t).next, intermediate_code->code[(yyvsp[0].integer)]);
            printf("Done!\n");
        }
    }
#line 1858 "y.tab.c"
    break;

  case 28:
#line 376 "yysint.y"
    {
        // Se cond é verdadeiro, devemos ir para o stmt
        // i.e. remende a truelist de cond para ir para o stmt
        backpatch((yyvsp[-7].intmdt_addr)->list->truelist, intermediate_code->code[(yyvsp[-5].integer)]);

        // Se cond é falso, devemos ir para o stmt do else
        // i.e. remende a falselist de cond para ir para o stmt
        backpatch((yyvsp[-7].intmdt_addr)->list->falselist, intermediate_code->code[(yyvsp[-1].integer)]);

        // temp = merge(S1.nextlist, N.nextlist);
        
        // Após o stmt (do then), o stmt (do else) e o N vamos para a quádrupla
        // após o if_stmt
        list_head_t* temp = list_merge((yyvsp[-4].stmt_t).next, (yyvsp[-2].stmt_t).next);
        (yyval.stmt_t).next = list_merge(temp, (yyvsp[0].stmt_t).next);
    }
#line 1879 "y.tab.c"
    break;

  case 29:
#line 394 "yysint.y"
    {
        // Agora já sabemos o número da próxima quádrupla
        // Ele está em 'intermediate_code->n'
        (yyval.integer) = intermediate_code->n;
    }
#line 1889 "y.tab.c"
    break;

  case 30:
#line 401 "yysint.y"
    {
        // Cria-se o goto para saltar um trecho de código à frente
        // Saberemos o destino posteriormente e o remendaremos
       	gen(intermediate_code, "gotoN", NULL, NULL, NULL);
		(yyval.stmt_t).next = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
    }
#line 1900 "y.tab.c"
    break;

  case 31:
#line 408 "yysint.y"
    {
        printf(">Estamos num loop\n");
        if (!(yyvsp[-7].stmt_pref_t).hasPrefix && !(yyvsp[0].stmt_suff_t).hasSuffix){
            printf(">> Num loop infinito!\n");

            // Ao fim do corpo, faça o loop infinito
            backpatch((yyvsp[-2].stmt_t).next, intermediate_code->code[(yyvsp[-8].integer)]); 
            (yyval.stmt_t).next = NULL;   
        }else{
            // // Tratamento do While
            // if ($1 == $3){
            //     // Não possui while
            // }else{
            //     // Possui while
            //     backpatch($6.next, intermediate_code->code[$1]);    // Fazer o loop
            // }

            backpatch((yyvsp[-3].stmt_t).next, (yyvsp[-2].stmt_t).next->list->value);    // Fazer o loop


            printf(">> Temos WHILE?\n");
            list_head_t* falseWhile = NULL;
            // Tratamento do While
            if ((yyvsp[-7].stmt_pref_t).hasPrefix == true){
                printf(">>> Sim\n");
                printf(">>> Lista de Falso do WHILE: \n");
                printList((yyvsp[-7].stmt_pref_t).falselist);
                falseWhile = (yyvsp[-7].stmt_pref_t).falselist;     // Para fazer o loop
                printf(">>> Backpatching para ficar no WHILE se verdadeiro: \n");
                backpatch((yyvsp[-2].stmt_t).next, intermediate_code->code[(yyvsp[-8].integer)]);    // Ao fim do corpo, faça o loop
                printf(">>> Backpatching para entrar no loop \n");
                backpatch((yyvsp[-7].stmt_pref_t).truelist, intermediate_code->code[(yyvsp[-4].integer)]);
            }else{
                printf(">>> Não\n");
                // ignore
            }
            
            
            //Tratamento do Until
            printf(">> Temos UNTIL?\n");
            if ((yyvsp[0].stmt_suff_t).hasSuffix == true){
                printf(">>> Sim\n");
                backpatch((yyvsp[0].stmt_suff_t).falselist, intermediate_code->code[(yyvsp[-8].integer)]);   // Se cond falso, volte para o loop
                (yyval.stmt_t).next = list_merge((yyvsp[0].stmt_suff_t).truelist, (yyvsp[-7].stmt_pref_t).falselist);        // Senão, pode sair
                backpatch((yyvsp[-2].stmt_t).next, intermediate_code->code[(yyvsp[-1].integer)]);    // Ao fim do corpo, faça o loop
                printf(">>> Lista do Next\n");
                printList((yyval.stmt_t).next);
            }else{
                printf(">>> Não\n");
                (yyval.stmt_t).next = (yyvsp[-7].stmt_pref_t).falselist;
                printf(">>> Lista do Next\n");
                printList((yyval.stmt_t).next);
            }
        }
        
        


        // // Tratamento do Until
        // if ($7.loop_main_next_list == NULL){
        //     // Não possui UNTIL
        //     $$.next = list_merge($7.next, $2.loop_main_next_list);
        // }else{
        //     // UNTIL está presente
        //     $$.next = list_merge($7.loop_main_next_list, $2.loop_main_next_list);
        //     backpatch($7->list->falselist, intermediate_code->code[$$.loop_idx]);

        // }
    }
#line 1974 "y.tab.c"
    break;

  case 32:
#line 479 "yysint.y"
    {
        // WHILE m '(' bool ')' m stmt 
        printf("> Avaliando o WHILE\n");

        (yyval.stmt_pref_t).hasPrefix = true;
        (yyval.stmt_pref_t).falselist = (yyvsp[-1].intmdt_addr)->list->falselist;
        (yyval.stmt_pref_t).truelist = (yyvsp[-1].intmdt_addr)->list->truelist;

        // // Goto para voltar ao início e testar as condições novamente
        // intmdt_addr_t *temp = malloc(sizeof(intmdt_addr_t));
        // temp->type = TYPE_LABEL;
        // temp->value.instr_ptr = intermediate_code->code[$2];
        // gen(intermediate_code, "gotoW", NULL, NULL, temp);
    }
#line 1993 "y.tab.c"
    break;

  case 33:
#line 494 "yysint.y"
    {
        (yyval.stmt_pref_t).hasPrefix = false;
        (yyval.stmt_pref_t).falselist = NULL;
    }
#line 2002 "y.tab.c"
    break;

  case 34:
#line 500 "yysint.y"
    {
        (yyval.stmt_suff_t).truelist = (yyvsp[0].intmdt_addr)->list->truelist;
        (yyval.stmt_suff_t).falselist = (yyvsp[0].intmdt_addr)->list->falselist;
        (yyval.stmt_suff_t).hasSuffix = true;
    }
#line 2012 "y.tab.c"
    break;

  case 35:
#line 506 "yysint.y"
    {
        (yyval.stmt_suff_t).truelist = NULL;
        (yyval.stmt_suff_t).falselist = NULL;
        (yyval.stmt_suff_t).hasSuffix = false;
    }
#line 2022 "y.tab.c"
    break;

  case 36:
#line 513 "yysint.y"
    {
        // TODO: necessário ident_list
        gen(intermediate_code, "TODO:read", NULL, NULL, NULL);

    }
#line 2032 "y.tab.c"
    break;

  case 37:
#line 520 "yysint.y"
    {
        // Iterar por toda a lista gerando um print para cada expr
        printListIntmt((yyvsp[-1].expr_lst_t).list);
        
        list_entry_t* current = (yyvsp[-1].expr_lst_t).list->list;

        while(current != NULL) {
            gen(intermediate_code, "print", current->value, NULL, NULL);
            current = current->next;
        }
        (yyval.stmt_t).next = NULL;
    }
#line 2049 "y.tab.c"
    break;

  case 38:
#line 534 "yysint.y"
    {
        // Coloca um '_' ao final, para diferenciar de identificadores comuns
        printf("GOTO_stmt: %s\n",(yyvsp[0].string));
        char* label = strdup((yyvsp[0].string));
        strncat(label, "_ _", 1);
        
        // Procurar na TS
        int res_niv;
        int res_i;
        Get_Entry(label, &res_niv, &res_i);

        if (res_i != -1 
            && TabelaS[res_i].value.instr_ptr != NULL 
            && TabelaS[res_i].value.instr_ptr->result != NULL){            // Label está na TS
            // Destino é um label definido, basta gerar código para lá
            printf("Label %s já na tabela e definido\n", (yyvsp[0].string));
            
            // Pega o destino da TS
            intmdt_addr_t *dest = malloc(sizeof(intmdt_addr_t));
            if (dest == NULL) {
                fprintf(stderr, "failed to malloc intmdt_addr_t in goto_stmt\n");
                YYABORT;
            }

            quadruple_t* quad = TabelaS[res_i].value.instr_ptr;

            printQuad(quad, quad->n);
            // intmdt_addr_print(((quadruple_t*)current->value)->result);
            
            dest->type = TYPE_LABEL;
            dest->value.instr_ptr = quad;
            
            gen(intermediate_code, "goto", NULL, NULL, dest);
        }else{
            printf("Label %s ou não definido ou não está na tabela\n", (yyvsp[0].string));

            if (res_i == -1){
                // Instala o label na TS
                union value dest;
                int tipo_cst = TYPE_LABEL;
                int cls = CLS_LABEL;
                boolean_list_t *blist = NULL;

                // Gera quádrupla para ser remendada depois
                gen(intermediate_code, "gotoV1", NULL, NULL, NULL);
                dest.instr_ptr = intermediate_code->code[intermediate_code->n-1];
                Instala(label, tipo_cst, cls, dest, blist);
                printf("Label %s instalado agora\n", (yyvsp[0].string));
            }else{
                printf("Label %s: colocando label vazio\n", (yyvsp[0].string));
                
                // Coloca um goto vazio para ser remendado depois
                intmdt_addr_t *dest = malloc(sizeof(intmdt_addr_t));
                if (dest == NULL) {
                    fprintf(stderr, "failed to malloc intmdt_addr_t in goto_stmt\n");
                    YYABORT;
                }
                
                gen(intermediate_code, "gotoV2", NULL, NULL, NULL);
                TabelaS[res_i].value.instr_ptr = intermediate_code->code[intermediate_code->n-1];
            }
        }
        // $$.next = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
        (yyval.stmt_t).next = NULL;
    }
#line 2119 "y.tab.c"
    break;

  case 39:
#line 602 "yysint.y"
    {
        printf("expr_list -> expr\n");
        (yyval.expr_lst_t).list = list_makelist_intmt((yyvsp[0].intmdt_addr));
        (yyval.expr_lst_t).qtd_terms = 1;
    }
#line 2129 "y.tab.c"
    break;

  case 40:
#line 608 "yysint.y"
    {
        printf("expr_list -> expr_list , expr\n");
        list_head_t* templist = list_makelist_intmt((yyvsp[0].intmdt_addr));
        (yyval.expr_lst_t).list = list_merge((yyvsp[-2].expr_lst_t).list, templist);
        (yyval.expr_lst_t).qtd_terms = (yyvsp[-2].expr_lst_t).qtd_terms + 1;
        printf("Total de termos: %i\n",(yyval.expr_lst_t).qtd_terms);
    }
#line 2141 "y.tab.c"
    break;

  case 41:
#line 617 "yysint.y"
    { 
        (yyval.intmdt_addr) = (yyvsp[0].intmdt_addr); 
    }
#line 2149 "y.tab.c"
    break;

  case 42:
#line 621 "yysint.y"
    {
        // Se algum for temporário, procure na tabela seu tipo de verdade
        int tipo1 = (yyvsp[-2].intmdt_addr)->type;
        int tipo2 = (yyvsp[0].intmdt_addr)->type;
        tempTipo(&tipo1, &tipo2, (yyvsp[-2].intmdt_addr), (yyvsp[0].intmdt_addr));
        
        // Verificação de Tipos
        if (strcmp((yyvsp[-1].lexeme_str),"=") == 0 || strcmp((yyvsp[-1].lexeme_str),"!=") == 0){
            // Não importa os tipos dos operandos
            printf("simple_expr RELOP (%s) simple_expr\n", (yyvsp[-1].lexeme_str));
            intmdt_addr_t *temp = newtemp(TYPE_BOOL);
            temp->list = malloc(sizeof(boolean_list_t));
            if (temp->list == NULL) {
                fprintf(stderr, "Malloc of boolean_list_t failed! (RELOP)\n");
                YYABORT;
            }
            gen(intermediate_code, (yyvsp[-1].lexeme_str), (yyvsp[-2].intmdt_addr), (yyvsp[0].intmdt_addr), temp);
            temp->list->truelist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            gen(intermediate_code, "gotoRE", NULL, NULL, NULL);
            temp->list->falselist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            (yyval.intmdt_addr) = temp;
            // TODO: criar quádrupla para calcular valor
            // $$->value = $1->value; 
        }else if (strcmp((yyvsp[-1].lexeme_str),"<") == 0 || strcmp((yyvsp[-1].lexeme_str),"<=") == 0 
               || strcmp((yyvsp[-1].lexeme_str),">") == 0 || strcmp((yyvsp[-1].lexeme_str),">=") == 0){
            if (!isNumber(tipo1) && !isNumber(tipo2)){
                typeerror();
                YYABORT;
            }

            // $$->type = TYPE_BOOL; 
            printf("simple_expr RELOP (%s) simple_expr\n", (yyvsp[-1].lexeme_str));
            intmdt_addr_t *temp = newtemp(TYPE_BOOL);
            temp->list = malloc(sizeof(boolean_list_t));
            if (temp->list == NULL) {
                fprintf(stderr, "Malloc of boolean_list_t failed! (RELOP)\n");
                YYABORT;
            }
            gen(intermediate_code, (yyvsp[-1].lexeme_str), (yyvsp[-2].intmdt_addr), (yyvsp[0].intmdt_addr), temp);
            temp->list->truelist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            gen(intermediate_code, "gotoRG", NULL, NULL, NULL);
            temp->list->falselist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            (yyval.intmdt_addr) = temp;
            // TODO: criar quádrupla para calcular valor
            // $$->value = $1->value; 
        }else{
            printf("Lexema RELOP não encontrado\n");
            YYABORT;
        }
    }
#line 2204 "y.tab.c"
    break;

  case 43:
#line 673 "yysint.y"
    { 
        (yyval.intmdt_addr) = (yyvsp[0].intmdt_addr);
    }
#line 2212 "y.tab.c"
    break;

  case 44:
#line 677 "yysint.y"
    {
        if (strcmp((yyvsp[-1].lexeme_str),"+") == 0){
            // Se algum for temporário, procure na tabela seu tipo de verdade
            int tipo1 = (yyvsp[-2].intmdt_addr)->type;
            int tipo2 = (yyvsp[0].intmdt_addr)->type;
            tempTipo(&tipo1, &tipo2, (yyvsp[-2].intmdt_addr), (yyvsp[0].intmdt_addr));
            
            // Verificação de Tipos + Geração da Quádrupla
            if (isNumber(tipo1) && isNumber(tipo2)){
                if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
                    // Dois inteiros
                    printf("simple_expr -> simple_expr + term (int,int)\n");
       	     		intmdt_addr_t *temp = newtemp(TYPE_INT);
                    gen(intermediate_code, "+", (yyvsp[-2].intmdt_addr), (yyvsp[0].intmdt_addr), temp);
                    (yyval.intmdt_addr) = temp;
                }else{
                    // Pelo menos um real
                    printf("simple_expr -> simple_expr + term (real)\n");
       	     		intmdt_addr_t *temp = newtemp(TYPE_REAL);
                    gen(intermediate_code, "+", (yyvsp[-2].intmdt_addr), (yyvsp[0].intmdt_addr), temp);
                    (yyval.intmdt_addr) = temp;
                }
            }else{
                typeerror();
                YYABORT;
            }
        }else{
            printf("Lexema ADDOP não encontrado: %s\n", (yyvsp[-1].lexeme_str));
            yyerror("");
            YYABORT;
        }
    }
#line 2249 "y.tab.c"
    break;

  case 45:
#line 710 "yysint.y"
    {
        if (strcmp((yyvsp[-2].lexeme_str),"or") == 0){
            // Se algum for temporário, procure na tabela seu tipo de verdade
            int tipo1 = (yyvsp[-3].intmdt_addr)->type;
            int tipo2 = (yyvsp[0].intmdt_addr)->type;
            tempTipo(&tipo1, &tipo2, (yyvsp[-3].intmdt_addr), (yyvsp[0].intmdt_addr));
            
            // Verificação de Tipos + Geração da Quádrupla
            if (tipo1 == TYPE_BOOL && tipo2 == TYPE_BOOL){
                // printf("simple_expr -> simple_expr or term\n");
                // intmdt_addr_t *temp = newtemp(TYPE_BOOL);
                // printf("TODO: truelist e falselist\n");
                // gen(intermediate_code, "or", $1, $4, temp);
                // $$ = temp;
                printf("simple_expr -> simple_expr or term\n");

                // Remendo do primeiro do false com o valor do M
                backpatch((yyvsp[-3].intmdt_addr)->list->falselist, intermediate_code->code[(yyvsp[-1].integer)]);
                intmdt_addr_t *temp = newtemp(TYPE_BOOL);
                // gen(intermediate_code, "or", $1, $4, temp);

                // E.falselist = E2.falselist
                temp->list = malloc(sizeof(boolean_list_t));
                if (temp->list == NULL) {
                    fprintf(stderr, "Malloc of boolean_list_t failed! (OR)\n");
                    YYABORT;
                }
                temp->list->falselist = (yyvsp[0].intmdt_addr)->list->falselist;

                // E.truelist = merge(E1.truelist, E2.truelist)
                temp->list->truelist = list_merge((yyvsp[-3].intmdt_addr)->list->truelist,
                                                  (yyvsp[0].intmdt_addr)->list->truelist);
                (yyval.intmdt_addr) = temp;
            }else{
                typeerror();
                YYABORT;
            }
        }else{
            printf("Lexema OR não encontrado: %s\n", (yyvsp[-2].lexeme_str));
            yyerror("");
            YYABORT;
        }
    }
#line 2297 "y.tab.c"
    break;

  case 46:
#line 754 "yysint.y"
    {
        // Se algum for temporário, procure na tabela seu tipo de verdade
        int tipo1 = (yyvsp[-2].intmdt_addr)->type;
        int tipo2 = (yyvsp[0].intmdt_addr)->type;
        tempTipo(&tipo1, &tipo2, (yyvsp[-2].intmdt_addr), (yyvsp[0].intmdt_addr));
        
        // Verificação de Tipos + Geração da Quádrupla
        if (isNumber(tipo1) && isNumber(tipo2)){
            if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
                // Dois inteiros
                printf("simple_expr -> simple_expr - term (int,int)\n");
                intmdt_addr_t *temp = newtemp(TYPE_INT);
                gen(intermediate_code, "-", (yyvsp[-2].intmdt_addr), (yyvsp[0].intmdt_addr), temp);
                (yyval.intmdt_addr) = temp;
            }else{
                // Pelo menos um real
                printf("simple_expr -> simple_expr - term (real)\n");
                intmdt_addr_t *temp = newtemp(TYPE_REAL);
                gen(intermediate_code, "-", (yyvsp[-2].intmdt_addr), (yyvsp[0].intmdt_addr), temp);
                (yyval.intmdt_addr) = temp;
            }
        }else{
            typeerror();
            YYABORT;
        }
    }
#line 2328 "y.tab.c"
    break;

  case 47:
#line 782 "yysint.y"
    { 
        printf("term -> factor_a\n");
        (yyval.intmdt_addr) = (yyvsp[0].intmdt_addr); 
    }
#line 2337 "y.tab.c"
    break;

  case 48:
#line 787 "yysint.y"
    {
        // Se algum for temporário, procure na tabela seu tipo de verdade
        int tipo1 = (yyvsp[-2].intmdt_addr)->type;
        int tipo2 = (yyvsp[0].intmdt_addr)->type;
        tempTipo(&tipo1, &tipo2, (yyvsp[-2].intmdt_addr), (yyvsp[0].intmdt_addr));
            
        if (strcmp((yyvsp[-1].lexeme_str),"*") == 0){
            // Verificação de Tipos + Geração da Quádrupla
            if (isNumber(tipo1) && isNumber(tipo2)){
                if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
                    // Dois inteiros
                    printf("term -> term * factor_a (int,int)\n");
                    intmdt_addr_t *temp = newtemp(TYPE_INT);
                    gen(intermediate_code, "*", (yyvsp[-2].intmdt_addr), (yyvsp[0].intmdt_addr), temp);
                    (yyval.intmdt_addr) = temp;
                }else{
                    // Pelo menos um real
                    printf("term -> term * factor_a (real)\n");
                    intmdt_addr_t *temp = newtemp(TYPE_REAL);
                    gen(intermediate_code, "*", (yyvsp[-2].intmdt_addr), (yyvsp[0].intmdt_addr), temp);
                    (yyval.intmdt_addr) = temp;
                }
            }else{
                typeerror();
                YYABORT;
            }
        }else if(strcmp((yyvsp[-1].lexeme_str),"/") == 0){
            // Verificação de Tipos + Geração da Quádrupla
            if (isNumber(tipo1) && isNumber(tipo2)){
                printf("term -> term / factor_a (real)\n");
                intmdt_addr_t *temp = newtemp(TYPE_REAL);
                gen(intermediate_code, "/", (yyvsp[-2].intmdt_addr), (yyvsp[0].intmdt_addr), temp);
                (yyval.intmdt_addr) = temp;
            }else{
                typeerror();
                YYABORT;
            }
        }else if (strcmp((yyvsp[-1].lexeme_str),"div") == 0){
            // Verificação de Tipos + Geração da Quádrupla
            if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
                printf("term -> term div factor_a (int,int)\n");
                intmdt_addr_t *temp = newtemp(TYPE_INT);
                gen(intermediate_code, "div", (yyvsp[-2].intmdt_addr), (yyvsp[0].intmdt_addr), temp);
                (yyval.intmdt_addr) = temp;
            }else{
                typeerror();
                YYABORT;
            }
        }else if (strcmp((yyvsp[-1].lexeme_str),"mod") == 0){
            // Verificação de Tipos + Geração da Quádrupla
            if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
                printf("term -> term mod factor_a (int,int)\n");
                intmdt_addr_t *temp = newtemp(TYPE_INT);
                gen(intermediate_code, "mod", (yyvsp[-2].intmdt_addr), (yyvsp[0].intmdt_addr), temp);
                (yyval.intmdt_addr) = temp;
            }else{
                typeerror();
                YYABORT;
            }
        }else{
            printf("Lexema MULOP não encontrado: %s\n", (yyvsp[-1].lexeme_str));
            yyerror("");
            YYABORT;
        }
    }
#line 2407 "y.tab.c"
    break;

  case 49:
#line 853 "yysint.y"
    {
        if (strcmp((yyvsp[-2].lexeme_str),"and") == 0){
            // Se algum for temporário, procure na tabela seu tipo de verdade
            int tipo1 = (yyvsp[-3].intmdt_addr)->type;
            int tipo2 = (yyvsp[0].intmdt_addr)->type;
            tempTipo(&tipo1, &tipo2, (yyvsp[-3].intmdt_addr), (yyvsp[0].intmdt_addr));
            
            // Verificação de Tipos + Geração da Quádrupla
            if (tipo1 == TYPE_BOOL && tipo2 == TYPE_BOOL){
                // printf("term -> term and factor_a\n");
                // intmdt_addr_t *temp = newtemp(TYPE_BOOL);
                // printf("TODO: truelist e falselist\n");
                // gen(intermediate_code, "and", $1, $3, temp);
                // $$ = temp;

                printf("term -> term and factor_a\n");

                // Remendo do primeiro do true com o valor do M
                backpatch((yyvsp[-3].intmdt_addr)->list->truelist, intermediate_code->code[(yyvsp[-1].integer)]);
                intmdt_addr_t *temp = newtemp(TYPE_BOOL);
                // gen(intermediate_code, "&&", $1, $4, temp);

                // E.truelist = E2.truelist
                temp->list = malloc(sizeof(boolean_list_t));
                if (temp->list == NULL) {
                    fprintf(stderr, "Malloc of boolean_list_t failed! (AND)\n");
                    YYABORT;
                }
                temp->list->truelist = (yyvsp[0].intmdt_addr)->list->truelist;

                // E.falselist = merge(E1.falselist, E2.falselist)
                temp->list->falselist = list_merge((yyvsp[-3].intmdt_addr)->list->falselist,
                                                   (yyvsp[0].intmdt_addr)->list->falselist);
                (yyval.intmdt_addr) = temp;
            }else{
                typeerror();
                YYABORT;
            }
        }else{
            printf("Lexema MULOP não encontrado: %s\n", (yyvsp[-2].lexeme_str));
            yyerror("");
            YYABORT;
        }
    }
#line 2456 "y.tab.c"
    break;

  case 50:
#line 898 "yysint.y"
    {
        // Tratamento Quantidade de Argumentos
        printf("Tratando Argumentos\n");
        int args = (yyvsp[-1].expr_lst_t).qtd_terms;
        char buf[50];
        if (args > 1){
            // Nenhuma função tem mais de um argumento
            sprintf(buf, "Muitos argumentos para %s\n", (yyvsp[-3].string));
            yyerror(buf);
            YYABORT;
        }else if(args == 0 && 
            !(
                (strcmp((yyvsp[-3].string),"eoln") == 0)
                && (strcmp((yyvsp[-3].string),"eof") == 0)
            )){
            // Só Eof e Eoln devem ser invocadas sem argumento
            sprintf(buf, "Poucos argumentos para %s\n", (yyvsp[-3].string));
            yyerror(buf);
            YYABORT;
        }else if(args == 1 && 
            (
                (strcmp((yyvsp[-3].string),"eoln") == 0)
                && (strcmp((yyvsp[-3].string),"eof") == 0)
            )){
            // Eof e Eoln devem ser invocadas sem argumento
            sprintf(buf, "Muitos argumentos para %s\n", (yyvsp[-3].string));
            yyerror(buf);
            YYABORT;
        }
        
        printf("Tratando Temporários\n");
        intmdt_addr_t* arg;
        int tipo1;
        if (args == 1){
            // Argumento passado
            arg = (yyvsp[-1].expr_lst_t).list->list->value;

            // Se ele for temporário, pegue o tipo verdadeiro na TS
            tipo1 = arg->type;
            if (tipo1 == TS_ENTRY){
                int idx = arg->value.TS_idx;
                tipo1 = TabelaS[idx].type;
            }
        }

        printf("Gerando Código\n");
        // Verificação de Tipos + Geração da Quádrupla
        if (isNumToReal((yyvsp[-3].string))){
            if (tipo1 != TYPE_REAL && tipo1 != TYPE_INT){
                typeerror_msg((yyvsp[-3].string));
                YYABORT;
            }
            intmdt_addr_t *temp = newtemp(TYPE_REAL);
            gen(intermediate_code, (yyvsp[-3].string), arg, NULL, temp);
            (yyval.intmdt_addr) = temp;

        }else if (strcmp((yyvsp[-3].string),"abs") == 0){
            intmdt_addr_t *temp;
            if (tipo1 == TYPE_REAL){
                temp = newtemp(TYPE_REAL);
            }else if(tipo1 == TYPE_INT){
                temp = newtemp(TYPE_INT);
            }else{
                typeerror_msg((yyvsp[-3].string));
                YYABORT;
            }
            gen(intermediate_code, "abs", arg, NULL, temp);
            (yyval.intmdt_addr) = temp;

        }else if (strcmp((yyvsp[-3].string),"ord") == 0){
            // Retorna o inteiro do parâmetro
            // É um "casting" de inteiro

            if (tipo1 == TYPE_REAL){
                typeerror_msg((yyvsp[-3].string));
                YYABORT;
            }
            intmdt_addr_t *temp = newtemp(TYPE_INT);
            gen(intermediate_code, "ord", arg, NULL, temp);
            (yyval.intmdt_addr) = temp;

        }else if (strcmp((yyvsp[-3].string),"chr") == 0){
            // Retorna equivalente char do parâmetro
            // É um "casting" de char

            if (tipo1 == TYPE_REAL || tipo1 == TYPE_BOOL){
                typeerror();
                YYABORT;
            }
            intmdt_addr_t *temp = newtemp(TYPE_CHAR);
            gen(intermediate_code, "chr", arg, NULL, temp);
            (yyval.intmdt_addr) = temp;

        }else if (strcmp((yyvsp[-3].string),"eoln") == 0 || strcmp((yyvsp[-3].string),"eof") == 0){
            // Verifica EOLn na entrada padrão
            // Não há tipos a verificar

            // Temporário para resultado + gerência de truelist/falselist
            intmdt_addr_t *temp = newtemp(TYPE_BOOL);
            temp->list = malloc(sizeof(boolean_list_t));
            if (temp->list == NULL) {
                fprintf(stderr, "Malloc of boolean_list_t failed! (funct)\n");
                YYABORT;
            }

            gen(intermediate_code, (yyvsp[-3].string) , NULL, NULL, temp);
            temp->list->truelist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            gen(intermediate_code, "gotoF", NULL, NULL, NULL);
            temp->list->falselist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            (yyval.intmdt_addr) = temp;

        }else{
            printf("Função não encontrada: %s\n", (yyvsp[-3].string));
            yyerror("");
            YYABORT;
        }
    }
#line 2578 "y.tab.c"
    break;

  case 51:
#line 1016 "yysint.y"
    {
        if (strcmp((yyvsp[0].string),"eoln") == 0 || strcmp((yyvsp[0].string),"eof") == 0){
            // Verifica EOLn na entrada padrão
            // Não há tipos a verificar

            // Temporário para resultado + gerência de truelist/falselist
            intmdt_addr_t *temp = newtemp(TYPE_BOOL);
            temp->list = malloc(sizeof(boolean_list_t));
            if (temp->list == NULL) {
                fprintf(stderr, "Malloc of boolean_list_t failed! (funct)\n");
                YYABORT;
            }

            gen(intermediate_code, (yyvsp[0].string) , NULL, NULL, temp);
            temp->list->truelist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            gen(intermediate_code, "gotoF", NULL, NULL, NULL);
            temp->list->falselist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            (yyval.intmdt_addr) = temp;
        }else{
            printf("Função não encontrada: %s\n", (yyvsp[0].string));
            yyerror("");
            YYABORT;
        }
    }
#line 2607 "y.tab.c"
    break;

  case 52:
#line 1042 "yysint.y"
    { 
        // Se algum for temporário, procure na tabela seu tipo de verdade
        int tipo1 = (yyvsp[0].intmdt_addr)->type;
        if (tipo1 == TS_ENTRY){
            int idx = (yyvsp[0].intmdt_addr)->value.TS_idx;
            tipo1 = TabelaS[idx].type;
        }
        
        // Verificação de Tipos
        printf("factor_a -> - factor \n");
        intmdt_addr_t *temp;
        if (tipo1 == TYPE_INT){
            temp = newtemp(TYPE_INT);
        }else if (tipo1 == TYPE_REAL){
            temp = newtemp(TYPE_INT);
        }else{
            typeerror();
            YYABORT;
        }

        // Geração da Quádrupla
        gen(intermediate_code, "1-", (yyvsp[0].intmdt_addr), NULL, temp);
        (yyval.intmdt_addr) = temp;
    }
#line 2636 "y.tab.c"
    break;

  case 53:
#line 1067 "yysint.y"
    { 
        printf("factor_a -> factor\n");
        (yyval.intmdt_addr) = (yyvsp[0].intmdt_addr);
    }
#line 2645 "y.tab.c"
    break;

  case 54:
#line 1073 "yysint.y"
    { 
        printf("factor -> id(1)\n");
        // Pesquisa a entrada na tabela de símbolos
        int res_niv;
        int res_i;
        Get_Entry((yyvsp[0].string), &res_niv, &res_i);
        if (res_niv == -1){
            // Não encontrou na tabela
            exit(1);
        }

        printf("factor -> id(2)\n");
        intmdt_addr_t *dest = malloc (sizeof(intmdt_code_t));
        if (dest == NULL) {
            fprintf(stderr,"Error: could not malloc dest in 'factor -> identifier'");
            YYABORT;
        }
        printf("factor -> id(3)\n");
        dest->type = TS_ENTRY;
        dest->value.TS_idx = res_i;

        printf("factor -> id(4)\n");
        TabelaS[res_i].class = CLS_VARIABLE;
        boolean_list_t *list = NULL;
        if (TabelaS[res_i].type == TYPE_BOOL){
            printf("factor -> id(5)\n");
            intmdt_addr_t *temp = newtemp(TYPE_BOOL);
            temp->list = malloc(sizeof(boolean_list_t));
            if (temp->list == NULL) {
                fprintf(stderr, "Malloc of boolean_list_t failed! (factor -> id)\n");
                exit(1);
            }
            gen(intermediate_code, "boolV", dest, NULL, temp);    // if id goto __
            temp->list->truelist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            gen(intermediate_code, "gotoB", NULL, NULL, NULL);   // else goto ___
            temp->list->falselist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            (yyval.intmdt_addr) = temp;
        }else{
            printf("factor -> id\n");
            (yyval.intmdt_addr) = dest;
        }
    }
#line 2692 "y.tab.c"
    break;

  case 55:
#line 1116 "yysint.y"
                            { 
                                (yyval.intmdt_addr) = (yyvsp[0].intmdt_addr); 
                            }
#line 2700 "y.tab.c"
    break;

  case 56:
#line 1120 "yysint.y"
                            { 
                                (yyval.intmdt_addr) = (yyvsp[-1].intmdt_addr); 
                            }
#line 2708 "y.tab.c"
    break;

  case 57:
#line 1124 "yysint.y"
                            { 
                                // TODO: tipo função 
                                //       + verificação tipos parâmtros
                                //       + verificaçaõ tipo retorno
                                (yyval.intmdt_addr) = (yyvsp[0].intmdt_addr);
                            }
#line 2719 "y.tab.c"
    break;

  case 58:
#line 1131 "yysint.y"
    { 
        // Basta inverter as listas
        printf("factor -> NOT factor\n");
        intmdt_addr_t *temp = newtemp(TYPE_BOOL);
        temp->list = malloc(sizeof(boolean_list_t));
        if (temp->list == NULL) {
            fprintf(stderr, "Malloc of boolean_list_t failed! (NOT)\n");
            YYABORT;
        }

        int tipo1 = (yyvsp[0].intmdt_addr)->type;
        if (tipo1 == TS_ENTRY){
            int idx = (yyvsp[0].intmdt_addr)->value.TS_idx;
            tipo1 = TabelaS[idx].type;
        }

        if (tipo1 != TYPE_BOOL){
            typeerror();
            YYABORT;
        }
        temp->list->truelist = (yyvsp[0].intmdt_addr)->list->falselist;
        temp->list->falselist = (yyvsp[0].intmdt_addr)->list->truelist;
        (yyval.intmdt_addr) = temp;
      
        // // Se algum for temporário, procure na tabela seu tipo de verdade
        // int tipo1 = $2->type;
        // if (tipo1 == TS_ENTRY){
        //     int idx = $2->value.TS_idx;
        //     tipo1 = TabelaS[idx].type;
        // }
        
        // // Verificação de Tipos                         
        // if (tipo1 != TYPE_BOOL){
        //     typeerror();
        //     YYABORT;
        // }

        // // Geração da Quádrupla
        // printf("factor -> NOT factor\n");
        // intmdt_addr_t *temp = newtemp(TYPE_BOOL);
        // printf("TODO: truelist e falselist\n");
        // gen(intermediate_code, "NOT", $2, NULL, temp);
        // $$ = temp;
    }
#line 2768 "y.tab.c"
    break;

  case 59:
#line 1177 "yysint.y"
                            {
                                intmdt_addr_t *temp = newtemp(TYPE_INT);
                                TabelaS[temp->value.TS_idx].class = CLS_CST;
                                TabelaS[temp->value.TS_idx].value.integer = (yyvsp[0].integer);
                                (yyval.intmdt_addr) = temp;
                                (yyval.intmdt_addr)->list = NULL;
                                
                                intmdt_addr_print((yyval.intmdt_addr));
                                printf("\n");
                            }
#line 2783 "y.tab.c"
    break;

  case 60:
#line 1188 "yysint.y"
                            { 
                                intmdt_addr_t *temp = newtemp(TYPE_REAL);
                                TabelaS[temp->value.TS_idx].class = CLS_CST;
                                TabelaS[temp->value.TS_idx].value.real = (yyvsp[0].real);
                                (yyval.intmdt_addr) = temp;
                                (yyval.intmdt_addr)->list = NULL;
                                
                                intmdt_addr_print((yyval.intmdt_addr));
                                printf("\n");
                            }
#line 2798 "y.tab.c"
    break;

  case 61:
#line 1199 "yysint.y"
                            { 
                                intmdt_addr_t *temp = newtemp(TYPE_CHAR);
                                TabelaS[temp->value.TS_idx].class = CLS_CST;
                                TabelaS[temp->value.TS_idx].value.character = (yyvsp[0].character);
                                (yyval.intmdt_addr) = temp;
                                (yyval.intmdt_addr)->list = NULL;

                                intmdt_addr_print((yyval.intmdt_addr));
                                printf("\n");
                            }
#line 2813 "y.tab.c"
    break;

  case 62:
#line 1210 "yysint.y"
    { 
        intmdt_addr_t *temp = newtemp(TYPE_BOOL);
        TabelaS[temp->value.TS_idx].class = CLS_CST;
        TabelaS[temp->value.TS_idx].value.boolean = (yyvsp[0].boolean);
        // $$ = temp;

        printf("constant -> true\n");
        temp->list = malloc(sizeof(boolean_list_t));
        if (temp->list == NULL) {
            fprintf(stderr, "Malloc of boolean_list_t failed!\n");
            YYABORT;
        }
        /* Generate a goto statement with no destination,
            then pass it into a list for backpatching. */

        gen(intermediate_code, "gotoT", NULL, NULL, NULL);
        quadruple_t* quad = intermediate_code->code[intermediate_code->n - 1];
        printQuad(quad, quad->n);
        temp->list->truelist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);

        temp->list->falselist = NULL;

        (yyval.intmdt_addr) = temp;
        printf("constant -> true 3\n");


        intmdt_addr_print((yyval.intmdt_addr));
        printf("\n");
    }
#line 2847 "y.tab.c"
    break;

  case 63:
#line 1239 "yysint.y"
    { 
        intmdt_addr_t *temp = newtemp(TYPE_BOOL);
        TabelaS[temp->value.TS_idx].class = CLS_CST;
        TabelaS[temp->value.TS_idx].value.boolean = (yyvsp[0].boolean);
        // $$ = temp;
        
        printf("constant -> false\n");
        boolean_list_t *list = malloc(sizeof(boolean_list_t));
        if (list == NULL) {
            fprintf(stderr, "Malloc of boolean_list_t failed!\n");
            YYABORT;
        }
        /* Generate a goto statement with no destination,
            then pass it into a list for backpatching. */
        gen(intermediate_code, "gotoF", NULL, NULL, NULL);
        list->truelist = NULL;
        list->falselist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
        (yyval.intmdt_addr)->list = list;

        intmdt_addr_print((yyval.intmdt_addr));
        printf("\n");
    }
#line 2874 "y.tab.c"
    break;


#line 2878 "y.tab.c"

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
#line 1264 "yysint.y"
                     

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
        int cls = -1;
        boolean_list_t *blist = NULL;
        if (strcmp(type, "integer") == 0){
            tipo_cst = TYPE_INT;
            cls = CLS_VARIABLE;
        }else if (strcmp(type, "real") == 0){
            tipo_cst = TYPE_REAL;
            cls = CLS_VARIABLE;
        }else if (strcmp(type, "boolean") == 0){
            cls = CLS_VARIABLE;
            tipo_cst = TYPE_BOOL;
            blist = malloc(sizeof(boolean_list_t));
            if (blist == NULL) {
                fprintf(stderr, "Malloc of boolean_list_t failed!\n");
                exit(1);
            }
        }else if (strcmp(type, "char") == 0){
            cls = CLS_VARIABLE;
            tipo_cst = TYPE_CHAR;
        }
        Instala(id_list[i], tipo_cst, cls, placeholder, blist);
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
    // strcpy(TabelaS[res_i]->value, value);

    // Ainda não avaliamos expressões para conseguir calcular o value
    // mas podemos testar o updateVal, colocando o contador 'novoVal' na tabela
    char num[200];
    sprintf(num, "%d", novoVal);
    /* strcpy(TabelaS[res_i]->value, num); */
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

    /* Inicialização da lista de quádruplas */
    intermediate_code = init_code();

    /* Parsing */
    printf("Parsing...\n");
    if (yyparse() == 0){
        printf("Parse sucessful\n\n");
        /* printf("Tabela de Simbolos Final:"); */
        /* imprimir();     // Imprime a tabela de símbolos ao final */
        print_intmdt_code(intermediate_code);
        free_intmdt_code(intermediate_code);
        return 0;
    }else{
        free_intmdt_code(intermediate_code);
        return 1;
    }
}

/* 
Se algum tipo for temporário (apontar para a tabela de símbolos) busca na 
tabela de símbolos o tipo verdadeiro
*/
void tempTipo(int* tipo1, int* tipo2, intmdt_addr_t* s1, intmdt_addr_t* s3){
    if (*tipo1 == TS_ENTRY){
        int idx = s1->value.TS_idx;
        *tipo1 = TabelaS[idx].type;
    }
    if (*tipo2 == TS_ENTRY){
        int idx = s3->value.TS_idx;
        *tipo2 = TabelaS[idx].type;
    }
}

/* Verifica se o tipo passado é um número (inteiro ou real) */
bool isNumber(int tipo){
    return (tipo == TYPE_INT || tipo == TYPE_REAL);
}

/* 
Verifica se função é simples "número->real"
Estão nesse conjunto: sin, cos, log, exp, sqrt 
Isso facilita verificação de tipos
*/
bool isNumToReal(char* funct){
    if (
        strcmp(funct, "sqrt") == 0
        ||  strcmp(funct, "sin") == 0
        ||  strcmp(funct, "cos") == 0
        ||  strcmp(funct, "log") == 0
        ||  strcmp(funct, "exp") == 0
        ||  strcmp(funct, "exp") == 0
    ){
        return true;
    }else{
        return false;
    }
}

void yyerror (char *s) {
    fprintf(stderr, "%s\n", s);
    fprintf(stderr,"At line %d\n",yylineno);
}

void typeerror(){
    yyerror("Type-error!");
}
void typeerror_msg(char* msg){
    printf("Type-error: %s \n ", msg);
    yyerror("");
}
