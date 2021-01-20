#define YY_parse_h_included
/*#define YY_USE_CLASS 
*/
/*  A Bison++ parser, made from p_sint.y  */

 /* with Bison++ version bison++ Version 1.21.9-1, adapted from GNU bison by coetmeur@icdc.fr
Maintained by Magnus Ekdahl <magnus@debian.org>
  */


#line 1 "/usr/share/bison++/bison.cc"
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Bob Corbett and Richard Stallman

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 1, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  

   As a special exception, when this file is copied by Bison++ into a
   Bison++ output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison, and has been in Bison++ since 1.21.9.  

*/

/* HEADER SECTION */
#if defined( _MSDOS ) || defined(MSDOS) || defined(__MSDOS__) 
 #define __MSDOS_AND_ALIKE
#endif

#if defined(_WINDOWS) && defined(_MSC_VER)
 #define __HAVE_NO_ALLOCA
 #define __MSDOS_AND_ALIKE
#endif

#ifndef alloca
 #if defined( __GNUC__)
  #define alloca __builtin_alloca

 #elif (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc)  || defined (__sgi)
  #include <alloca.h>

 #elif defined (__MSDOS_AND_ALIKE)
  #include <malloc.h>
  #ifndef __TURBOC__
   /* MS C runtime lib */
   #define alloca _alloca
  #endif

 #elif defined(_AIX)
  /* pragma must be put before any C/C++ instruction !! */
  #pragma alloca
  #include <malloc.h>

 #elif defined(__hpux)
  #ifdef __cplusplus
   extern "C" {
     void *alloca (unsigned int);
   };
  #else /* not __cplusplus */
   void *alloca ();
  #endif /* not __cplusplus */

 #endif /* not _AIX  not MSDOS, or __TURBOC__ or _AIX, not sparc.  */
#endif /* alloca not defined.  */

#ifdef c_plusplus
 #ifndef __cplusplus
  #define __cplusplus
 #endif
#endif

#ifdef __cplusplus
 #ifndef YY_USE_CLASS
/*#warning "For C++ its recomended to use bison++, otherwise classes won't be generated"*/
 #endif
#else
 #ifndef __STDC__
  #define const
 #endif
 #ifdef YY_USE_CLASS
  #error "This is a C++ header generated by bison++, please use a C++ compiler!"
 #endif
#endif

#include <stdio.h>
#define YYBISON 1  

 #line 88 "/usr/share/bison++/bison.cc"
#line 1 "p_sint.y"

    void yyerror (char *s);
    int yylex();
    #include <stdio.h>     /* C declarations used in actions */
    #include <stdlib.h>
    #include <ctype.h>
    int symbols[52];
    int symbolVal(char symbol);
    void updateSymbolVal(char symbol, int val);

    #define YYDEBUG 1

#line 14 "p_sint.y"
typedef union {int integer; float real; int boolean; char character; char* identifier;} yy_parse_stype;
#define YY_parse_STYPE yy_parse_stype
#ifndef YY_USE_CLASS
#define YYSTYPE yy_parse_stype
#endif

#line 88 "/usr/share/bison++/bison.cc"
/* %{ and %header{ and %union, during decl */
#define YY_parse_BISON 1

#ifndef YY_parse_COMPATIBILITY
 #ifndef YY_USE_CLASS
  #define  YY_parse_COMPATIBILITY 1
 #else
  #define  YY_parse_COMPATIBILITY 0
 #endif
#endif

#if YY_parse_COMPATIBILITY != 0
 /* backward compatibility */
 #ifdef YYLTYPE
  #ifndef YY_parse_LTYPE
   #define YY_parse_LTYPE YYLTYPE
  #endif
 #endif
/* Testing alternative bison solution
   /#ifdef YYSTYPE*/
#ifndef YY_parse_STYPE 
   #define YY_parse_STYPE YYSTYPE
#endif
/*#endif*/
 #ifdef YYDEBUG
  #ifndef YY_parse_DEBUG
   #define  YY_parse_DEBUG YYDEBUG
  #endif
 #endif
 
 /* use goto to be compatible */
 #ifndef YY_parse_USE_GOTO
  #define YY_parse_USE_GOTO 1
 #endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_parse_USE_GOTO
 #define YY_parse_USE_GOTO 0
#endif

#ifndef YY_parse_PURE

 #line 130 "/usr/share/bison++/bison.cc"

#line 130 "/usr/share/bison++/bison.cc"
/*  YY_parse_PURE */
#endif

/* section apres lecture def, avant lecture grammaire S2 */

 #line 134 "/usr/share/bison++/bison.cc"

#line 134 "/usr/share/bison++/bison.cc"
/* prefix */
#ifndef YY_parse_DEBUG

 #line 136 "/usr/share/bison++/bison.cc"

#line 136 "/usr/share/bison++/bison.cc"
/* YY_parse_DEBUG */
#endif


#ifndef YY_parse_LSP_NEEDED

 #line 141 "/usr/share/bison++/bison.cc"

#line 141 "/usr/share/bison++/bison.cc"
 /* YY_parse_LSP_NEEDED*/
#endif



/* DEFAULT LTYPE*/
#ifdef YY_parse_LSP_NEEDED
#ifndef YY_parse_LTYPE
#ifndef BISON_YYLTYPE_ISDECLARED
#define BISON_YYLTYPE_ISDECLARED
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#endif
#define YY_parse_LTYPE yyltype
#endif
#endif
/* DEFAULT STYPE*/
      /* We used to use `unsigned long' as YY_parse_STYPE on MSDOS,
	 but it seems better to be consistent.
	 Most programs should declare their own type anyway.  */

#ifndef YY_parse_STYPE
#define YY_parse_STYPE int
#endif
/* DEFAULT MISCELANEOUS */
#ifndef YY_parse_PARSE
#define YY_parse_PARSE yyparse
#endif
#ifndef YY_parse_LEX
#define YY_parse_LEX yylex
#endif
#ifndef YY_parse_LVAL
#define YY_parse_LVAL yylval
#endif
#ifndef YY_parse_LLOC
#define YY_parse_LLOC yylloc
#endif
#ifndef YY_parse_CHAR
#define YY_parse_CHAR yychar
#endif
#ifndef YY_parse_NERRS
#define YY_parse_NERRS yynerrs
#endif
#ifndef YY_parse_DEBUG_FLAG
#define YY_parse_DEBUG_FLAG yydebug
#endif
#ifndef YY_parse_ERROR
#define YY_parse_ERROR yyerror
#endif

#ifndef YY_parse_PARSE_PARAM
 #ifndef YY_USE_CLASS
  #ifdef YYPARSE_PARAM
   #define YY_parse_PARSE_PARAM void* YYPARSE_PARAM 
  #else
   #ifndef __STDC__
    #ifndef __cplusplus
     #define YY_parse_PARSE_PARAM
    #endif
   #endif
  #endif
 #endif
 #ifndef YY_parse_PARSE_PARAM
  #define YY_parse_PARSE_PARAM void
 #endif
#endif

#if YY_parse_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YY_parse_LTYPE
#ifndef YYLTYPE
#define YYLTYPE YY_parse_LTYPE
#else
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
#endif
#endif

/* Removed due to bison compabilityproblems
/#ifndef YYSTYPE
/#define YYSTYPE YY_parse_STYPE
/#else*/
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
/*#endif*/

#ifdef YY_parse_PURE
#  ifndef YYPURE
#    define YYPURE YY_parse_PURE
#  endif
#endif

#ifdef YY_parse_DEBUG
#  ifndef YYDEBUG
#    define YYDEBUG YY_parse_DEBUG 
#  endif
#endif

#ifndef YY_parse_ERROR_VERBOSE
 #ifdef YYERROR_VERBOSE
  #define YY_parse_ERROR_VERBOSE YYERROR_VERBOSE
 #endif
#endif

#ifndef YY_parse_LSP_NEEDED
#  ifdef YYLSP_NEEDED
#    define YY_parse_LSP_NEEDED YYLSP_NEEDED
#  endif
#endif

#endif

#ifndef YY_USE_CLASS
/* TOKEN C */

 #line 263 "/usr/share/bison++/bison.cc"
#define	print	258
#define	exit_command	259
#define	ADDOP	260
#define	RELOP	261
#define	MULOP	262
#define	NOT	263
#define	ASSIGN	264
#define	INT_CONSTANT	265
#define	REAL_CONSTANT	266
#define	BOOL_CONSTANT	267
#define	IDENTIFIER	268
#define	CHAR_CONSTANT	269
#define	PROGRAM	270
#define	INTEGER	271
#define	REAL	272
#define	BOOLEAN	273
#define	CHAR	274
#define	BEGIN_STMT	275
#define	END	276
#define	IF	277
#define	THEN	278
#define	ELSE	279
#define	DO	280
#define	WHILE	281
#define	UNTIL	282
#define	READ	283
#define	WRITE	284
#define	GOTO	285
#define	UMINUS	286
#define	IDX	287


#line 263 "/usr/share/bison++/bison.cc"
 /* #defines tokens */
#else
/* CLASS */
#ifndef YY_parse_CLASS
#define YY_parse_CLASS parse
#endif
#ifndef YY_parse_INHERIT
#define YY_parse_INHERIT
#endif
#ifndef YY_parse_MEMBERS
#define YY_parse_MEMBERS 
#endif
#ifndef YY_parse_LEX_BODY
#define YY_parse_LEX_BODY  
#endif
#ifndef YY_parse_ERROR_BODY
#define YY_parse_ERROR_BODY  
#endif
#ifndef YY_parse_CONSTRUCTOR_PARAM
#define YY_parse_CONSTRUCTOR_PARAM
#endif
#ifndef YY_parse_CONSTRUCTOR_CODE
#define YY_parse_CONSTRUCTOR_CODE
#endif
#ifndef YY_parse_CONSTRUCTOR_INIT
#define YY_parse_CONSTRUCTOR_INIT
#endif
/* choose between enum and const */
#ifndef YY_parse_USE_CONST_TOKEN
#define YY_parse_USE_CONST_TOKEN 0
/* yes enum is more compatible with flex,  */
/* so by default we use it */ 
#endif
#if YY_parse_USE_CONST_TOKEN != 0
#ifndef YY_parse_ENUM_TOKEN
#define YY_parse_ENUM_TOKEN yy_parse_enum_token
#endif
#endif

class YY_parse_CLASS YY_parse_INHERIT
{
public: 
#if YY_parse_USE_CONST_TOKEN != 0
/* static const int token ... */

 #line 307 "/usr/share/bison++/bison.cc"
static const int print;
static const int exit_command;
static const int ADDOP;
static const int RELOP;
static const int MULOP;
static const int NOT;
static const int ASSIGN;
static const int INT_CONSTANT;
static const int REAL_CONSTANT;
static const int BOOL_CONSTANT;
static const int IDENTIFIER;
static const int CHAR_CONSTANT;
static const int PROGRAM;
static const int INTEGER;
static const int REAL;
static const int BOOLEAN;
static const int CHAR;
static const int BEGIN_STMT;
static const int END;
static const int IF;
static const int THEN;
static const int ELSE;
static const int DO;
static const int WHILE;
static const int UNTIL;
static const int READ;
static const int WRITE;
static const int GOTO;
static const int UMINUS;
static const int IDX;


#line 307 "/usr/share/bison++/bison.cc"
 /* decl const */
#else
enum YY_parse_ENUM_TOKEN { YY_parse_NULL_TOKEN=0

 #line 310 "/usr/share/bison++/bison.cc"
	,print=258
	,exit_command=259
	,ADDOP=260
	,RELOP=261
	,MULOP=262
	,NOT=263
	,ASSIGN=264
	,INT_CONSTANT=265
	,REAL_CONSTANT=266
	,BOOL_CONSTANT=267
	,IDENTIFIER=268
	,CHAR_CONSTANT=269
	,PROGRAM=270
	,INTEGER=271
	,REAL=272
	,BOOLEAN=273
	,CHAR=274
	,BEGIN_STMT=275
	,END=276
	,IF=277
	,THEN=278
	,ELSE=279
	,DO=280
	,WHILE=281
	,UNTIL=282
	,READ=283
	,WRITE=284
	,GOTO=285
	,UMINUS=286
	,IDX=287


#line 310 "/usr/share/bison++/bison.cc"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_parse_PARSE (YY_parse_PARSE_PARAM);
 virtual void YY_parse_ERROR(char *msg) YY_parse_ERROR_BODY;
#ifdef YY_parse_PURE
#ifdef YY_parse_LSP_NEEDED
 virtual int  YY_parse_LEX (YY_parse_STYPE *YY_parse_LVAL,YY_parse_LTYPE *YY_parse_LLOC) YY_parse_LEX_BODY;
#else
 virtual int  YY_parse_LEX (YY_parse_STYPE *YY_parse_LVAL) YY_parse_LEX_BODY;
#endif
#else
 virtual int YY_parse_LEX() YY_parse_LEX_BODY;
 YY_parse_STYPE YY_parse_LVAL;
#ifdef YY_parse_LSP_NEEDED
 YY_parse_LTYPE YY_parse_LLOC;
#endif
 int   YY_parse_NERRS;
 int    YY_parse_CHAR;
#endif
#if YY_parse_DEBUG != 0
 int YY_parse_DEBUG_FLAG;   /*  nonzero means print parse trace     */
#endif
public:
 YY_parse_CLASS(YY_parse_CONSTRUCTOR_PARAM);
public:
 YY_parse_MEMBERS 
};
/* other declare folow */
#if YY_parse_USE_CONST_TOKEN != 0

 #line 341 "/usr/share/bison++/bison.cc"
const int YY_parse_CLASS::print=258;
const int YY_parse_CLASS::exit_command=259;
const int YY_parse_CLASS::ADDOP=260;
const int YY_parse_CLASS::RELOP=261;
const int YY_parse_CLASS::MULOP=262;
const int YY_parse_CLASS::NOT=263;
const int YY_parse_CLASS::ASSIGN=264;
const int YY_parse_CLASS::INT_CONSTANT=265;
const int YY_parse_CLASS::REAL_CONSTANT=266;
const int YY_parse_CLASS::BOOL_CONSTANT=267;
const int YY_parse_CLASS::IDENTIFIER=268;
const int YY_parse_CLASS::CHAR_CONSTANT=269;
const int YY_parse_CLASS::PROGRAM=270;
const int YY_parse_CLASS::INTEGER=271;
const int YY_parse_CLASS::REAL=272;
const int YY_parse_CLASS::BOOLEAN=273;
const int YY_parse_CLASS::CHAR=274;
const int YY_parse_CLASS::BEGIN_STMT=275;
const int YY_parse_CLASS::END=276;
const int YY_parse_CLASS::IF=277;
const int YY_parse_CLASS::THEN=278;
const int YY_parse_CLASS::ELSE=279;
const int YY_parse_CLASS::DO=280;
const int YY_parse_CLASS::WHILE=281;
const int YY_parse_CLASS::UNTIL=282;
const int YY_parse_CLASS::READ=283;
const int YY_parse_CLASS::WRITE=284;
const int YY_parse_CLASS::GOTO=285;
const int YY_parse_CLASS::UMINUS=286;
const int YY_parse_CLASS::IDX=287;


#line 341 "/usr/share/bison++/bison.cc"
 /* const YY_parse_CLASS::token */
#endif
/*apres const  */
YY_parse_CLASS::YY_parse_CLASS(YY_parse_CONSTRUCTOR_PARAM) YY_parse_CONSTRUCTOR_INIT
{
#if YY_parse_DEBUG != 0
YY_parse_DEBUG_FLAG=0;
#endif
YY_parse_CONSTRUCTOR_CODE;
};
#endif

 #line 352 "/usr/share/bison++/bison.cc"


#define	YYFINAL		62
#define	YYFLAG		-32768
#define	YYNTBASE	39

#define YYTRANSLATE(x) ((unsigned)(x) <= 287 ? yytranslate[x] : 58)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
    38,     2,     2,    35,    36,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    34,    33,     2,
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
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32
};

#if YY_parse_DEBUG != 0
static const short yyprhs[] = {     0,
     0,     4,     8,    10,    14,    16,    18,    20,    22,    24,
    26,    30,    35,    42,    44,    48,    50,    54,    56,    60,
    64,    66,    70,    72,    77,    79,    81,    83,    86,    88,
    90,    92,    96,    98,   101,   103,   105,   107
};

static const short yyrhs[] = {    20,
    40,    21,     0,    40,    33,    41,     0,    41,     0,    42,
    34,    43,     0,    43,     0,    13,     0,    45,     0,    46,
     0,    39,     0,    48,     0,    13,     9,    48,     0,    22,
    44,    23,    41,     0,    22,    44,    23,    41,    24,    41,
     0,    48,     0,    47,    35,    48,     0,    49,     0,    49,
     6,    49,     0,    50,     0,    49,     5,    50,     0,    49,
    36,    50,     0,    55,     0,    50,     7,    55,     0,    52,
     0,    53,    37,    47,    38,     0,    54,     0,    52,     0,
    13,     0,    36,    56,     0,    56,     0,    13,     0,    57,
     0,    37,    48,    38,     0,    51,     0,     8,    56,     0,
    10,     0,    11,     0,    14,     0,    12,     0
};

#endif

#if (YY_parse_DEBUG != 0) || defined(YY_parse_ERROR_VERBOSE) 
static const short yyrline[] = { 0,
    57,    59,    60,    62,    63,    65,    67,    68,    69,    71,
    73,    75,    76,    78,    79,    81,    82,    84,    85,    86,
    88,    89,    91,    93,    95,    96,    98,   100,   101,   103,
   104,   105,   106,   107,   109,   110,   111,   112
};

static const char * const yytname[] = {   "$","error","$illegal.","print","exit_command",
"ADDOP","RELOP","MULOP","NOT","ASSIGN","INT_CONSTANT","REAL_CONSTANT","BOOL_CONSTANT",
"IDENTIFIER","CHAR_CONSTANT","PROGRAM","INTEGER","REAL","BOOLEAN","CHAR","BEGIN_STMT",
"END","IF","THEN","ELSE","DO","WHILE","UNTIL","READ","WRITE","GOTO","UMINUS",
"IDX","';'","':'","','","'-'","'('","')'","compound_stmt","stmt_list","stmt",
"label","unlabelled_stmt","cond","assign_stmt","if_stmt","expr_list","expr",
"simple_expr","term","function_ref","function_ref_par","variable","simple_variable_or_proc",
"factor_a","factor","constant",""
};
#endif

static const short yyr1[] = {     0,
    39,    40,    40,    41,    41,    42,    43,    43,    43,    44,
    45,    46,    46,    47,    47,    48,    48,    49,    49,    49,
    50,    50,    51,    52,    53,    53,    54,    55,    55,    56,
    56,    56,    56,    56,    57,    57,    57,    57
};

static const short yyr2[] = {     0,
     3,     3,     1,     3,     1,     1,     1,     1,     1,     1,
     3,     4,     6,     1,     3,     1,     3,     1,     3,     3,
     1,     3,     1,     4,     1,     1,     1,     2,     1,     1,
     1,     3,     1,     2,     1,     1,     1,     1
};

static const short yydefact[] = {     0,
     0,     6,     0,     9,     0,     3,     0,     5,     7,     8,
     0,     0,    35,    36,    38,    30,    37,     0,     0,     0,
    10,    16,    18,    33,    23,     0,    25,    21,    29,    31,
     1,     0,     0,    11,    34,    28,     0,     0,     0,     0,
     0,     0,     0,     2,     0,     4,    32,    12,    19,    17,
    20,    22,     0,    14,     0,     0,    24,    13,    15,     0,
     0,     0
};

static const short yydefgoto[] = {     4,
     5,     6,     7,     8,    20,     9,    10,    53,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    30
};

static const short yypact[] = {     6,
    14,    -4,     1,-32768,   -15,-32768,    -5,-32768,-32768,-32768,
     1,     9,-32768,-32768,-32768,    -7,-32768,     9,     1,     8,
-32768,    -3,    35,-32768,     7,    11,-32768,-32768,-32768,-32768,
-32768,    14,    27,-32768,-32768,-32768,     5,    14,     1,     1,
     1,     1,     1,-32768,    -4,-32768,-32768,    26,    35,    -1,
    35,-32768,   -10,-32768,    14,     1,-32768,-32768,-32768,    51,
    52,-32768
};

static const short yypgoto[] = {    53,
-32768,   -31,-32768,    21,-32768,-32768,-32768,-32768,   -11,    15,
     0,-32768,-32768,-32768,-32768,    16,    -2,-32768
};


#define	YYLAST		58


static const short yytable[] = {    34,
    44,    39,    40,    39,    11,    31,    48,    37,    12,    35,
    13,    14,    15,    16,    17,    36,    12,    32,    13,    14,
    15,    16,    17,    58,    56,     1,     2,    57,    33,   -27,
    38,    54,    41,     1,    41,     3,    18,    19,    49,    45,
    51,    42,    47,   -26,    59,    19,     1,    43,     3,    55,
    61,    62,    60,    46,    50,     0,     0,    52
};

static const short yycheck[] = {    11,
    32,     5,     6,     5,     9,    21,    38,    19,     8,    12,
    10,    11,    12,    13,    14,    18,     8,    33,    10,    11,
    12,    13,    14,    55,    35,    20,    13,    38,    34,    37,
    23,    43,    36,    20,    36,    22,    36,    37,    39,    13,
    41,     7,    38,    37,    56,    37,    20,    37,    22,    24,
     0,     0,     0,    33,    40,    -1,    -1,    42
};

#line 352 "/usr/share/bison++/bison.cc"
 /* fattrs + tables */

/* parser code folow  */


/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: dollar marks section change
   the next  is replaced by the list of actions, each action
   as one case of the switch.  */ 

#if YY_parse_USE_GOTO != 0
/* 
 SUPRESSION OF GOTO : on some C++ compiler (sun c++)
  the goto is strictly forbidden if any constructor/destructor
  is used in the whole function (very stupid isn't it ?)
 so goto are to be replaced with a 'while/switch/case construct'
 here are the macro to keep some apparent compatibility
*/
#define YYGOTO(lb) {yy_gotostate=lb;continue;}
#define YYBEGINGOTO  enum yy_labels yy_gotostate=yygotostart; \
                     for(;;) switch(yy_gotostate) { case yygotostart: {
#define YYLABEL(lb) } case lb: {
#define YYENDGOTO } } 
#define YYBEGINDECLARELABEL enum yy_labels {yygotostart
#define YYDECLARELABEL(lb) ,lb
#define YYENDDECLARELABEL  };
#else
/* macro to keep goto */
#define YYGOTO(lb) goto lb
#define YYBEGINGOTO 
#define YYLABEL(lb) lb:
#define YYENDGOTO
#define YYBEGINDECLARELABEL 
#define YYDECLARELABEL(lb)
#define YYENDDECLARELABEL 
#endif
/* LABEL DECLARATION */
YYBEGINDECLARELABEL
  YYDECLARELABEL(yynewstate)
  YYDECLARELABEL(yybackup)
/* YYDECLARELABEL(yyresume) */
  YYDECLARELABEL(yydefault)
  YYDECLARELABEL(yyreduce)
  YYDECLARELABEL(yyerrlab)   /* here on detecting error */
  YYDECLARELABEL(yyerrlab1)   /* here on error raised explicitly by an action */
  YYDECLARELABEL(yyerrdefault)  /* current state does not do anything special for the error token. */
  YYDECLARELABEL(yyerrpop)   /* pop the current state because it cannot handle the error token */
  YYDECLARELABEL(yyerrhandle)  
YYENDDECLARELABEL
/* ALLOCA SIMULATION */
/* __HAVE_NO_ALLOCA */
#ifdef __HAVE_NO_ALLOCA
int __alloca_free_ptr(char *ptr,char *ref)
{if(ptr!=ref) free(ptr);
 return 0;}

#define __ALLOCA_alloca(size) malloc(size)
#define __ALLOCA_free(ptr,ref) __alloca_free_ptr((char *)ptr,(char *)ref)

#ifdef YY_parse_LSP_NEEDED
#define __ALLOCA_return(num) \
            do { return( __ALLOCA_free(yyss,yyssa)+\
		    __ALLOCA_free(yyvs,yyvsa)+\
		    __ALLOCA_free(yyls,yylsa)+\
		   (num)); } while(0)
#else
#define __ALLOCA_return(num) \
            do { return( __ALLOCA_free(yyss,yyssa)+\
		    __ALLOCA_free(yyvs,yyvsa)+\
		   (num)); } while(0)
#endif
#else
#define __ALLOCA_return(num) do { return(num); } while(0)
#define __ALLOCA_alloca(size) alloca(size)
#define __ALLOCA_free(ptr,ref) 
#endif

/* ENDALLOCA SIMULATION */

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (YY_parse_CHAR = YYEMPTY)
#define YYEMPTY         -2
#define YYEOF           0
#define YYACCEPT        __ALLOCA_return(0)
#define YYABORT         __ALLOCA_return(1)
#define YYERROR         YYGOTO(yyerrlab1)
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL          YYGOTO(yyerrlab)
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do                                                              \
  if (YY_parse_CHAR == YYEMPTY && yylen == 1)                               \
    { YY_parse_CHAR = (token), YY_parse_LVAL = (value);                 \
      yychar1 = YYTRANSLATE (YY_parse_CHAR);                                \
      YYPOPSTACK;                                               \
      YYGOTO(yybackup);                                            \
    }                                                           \
  else                                                          \
    { YY_parse_ERROR ("syntax error: cannot back up"); YYERROR; }   \
while (0)

#define YYTERROR        1
#define YYERRCODE       256

#ifndef YY_parse_PURE
/* UNPURE */
#define YYLEX           YY_parse_LEX()
#ifndef YY_USE_CLASS
/* If nonreentrant, and not class , generate the variables here */
int     YY_parse_CHAR;                      /*  the lookahead symbol        */
YY_parse_STYPE      YY_parse_LVAL;              /*  the semantic value of the */
				/*  lookahead symbol    */
int YY_parse_NERRS;                 /*  number of parse errors so far */
#ifdef YY_parse_LSP_NEEDED
YY_parse_LTYPE YY_parse_LLOC;   /*  location data for the lookahead     */
			/*  symbol                              */
#endif
#endif


#else
/* PURE */
#ifdef YY_parse_LSP_NEEDED
#define YYLEX           YY_parse_LEX(&YY_parse_LVAL, &YY_parse_LLOC)
#else
#define YYLEX           YY_parse_LEX(&YY_parse_LVAL)
#endif
#endif
#ifndef YY_USE_CLASS
#if YY_parse_DEBUG != 0
int YY_parse_DEBUG_FLAG;                    /*  nonzero means print parse trace     */
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif
#endif



/*  YYINITDEPTH indicates the initial size of the parser's stacks       */

#ifndef YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif


#if __GNUC__ > 1                /* GNU C and GNU C++ define this.  */
#define __yy_bcopy(FROM,TO,COUNT)       __builtin_memcpy(TO,FROM,COUNT)
#else                           /* not GNU C or C++ */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */

#ifdef __cplusplus
static void __yy_bcopy (char *from, char *to, int count)
#else
#ifdef __STDC__
static void __yy_bcopy (char *from, char *to, int count)
#else
static void __yy_bcopy (from, to, count)
     char *from;
     char *to;
     int count;
#endif
#endif
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}
#endif


int
#ifdef YY_USE_CLASS
 YY_parse_CLASS::
#endif
     YY_parse_PARSE(YY_parse_PARSE_PARAM)
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
/* parameter definition without protypes */
YY_parse_PARSE_PARAM_DEF
#endif
#endif
#endif
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YY_parse_STYPE *yyvsp;
  int yyerrstatus;      /*  number of tokens to shift before error messages enabled */
  int yychar1=0;          /*  lookahead token as an internal (translated) token number */

  short yyssa[YYINITDEPTH];     /*  the state stack                     */
  YY_parse_STYPE yyvsa[YYINITDEPTH];        /*  the semantic value stack            */

  short *yyss = yyssa;          /*  refer to the stacks thru separate pointers */
  YY_parse_STYPE *yyvs = yyvsa;     /*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YY_parse_LSP_NEEDED
  YY_parse_LTYPE yylsa[YYINITDEPTH];        /*  the location stack                  */
  YY_parse_LTYPE *yyls = yylsa;
  YY_parse_LTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YY_parse_PURE
  int YY_parse_CHAR;
  YY_parse_STYPE YY_parse_LVAL;
  int YY_parse_NERRS;
#ifdef YY_parse_LSP_NEEDED
  YY_parse_LTYPE YY_parse_LLOC;
#endif
#endif

  YY_parse_STYPE yyval;             /*  the variable used to return         */
				/*  semantic values from the action     */
				/*  routines                            */

  int yylen;
/* start loop, in which YYGOTO may be used. */
YYBEGINGOTO

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    fprintf(stderr, "Starting parse\n");
#endif
  yystate = 0;
  yyerrstatus = 0;
  YY_parse_NERRS = 0;
  YY_parse_CHAR = YYEMPTY;          /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YY_parse_LSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
YYLABEL(yynewstate)

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YY_parse_STYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YY_parse_LSP_NEEDED
      YY_parse_LTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YY_parse_LSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YY_parse_LSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  YY_parse_ERROR("parser stack overflow");
	  __ALLOCA_return(2);
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) __ALLOCA_alloca (yystacksize * sizeof (*yyssp));
      __yy_bcopy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      __ALLOCA_free(yyss1,yyssa);
      yyvs = (YY_parse_STYPE *) __ALLOCA_alloca (yystacksize * sizeof (*yyvsp));
      __yy_bcopy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
      __ALLOCA_free(yyvs1,yyvsa);
#ifdef YY_parse_LSP_NEEDED
      yyls = (YY_parse_LTYPE *) __ALLOCA_alloca (yystacksize * sizeof (*yylsp));
      __yy_bcopy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
      __ALLOCA_free(yyls1,yylsa);
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YY_parse_LSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YY_parse_DEBUG != 0
      if (YY_parse_DEBUG_FLAG)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  YYGOTO(yybackup);
YYLABEL(yybackup)

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* YYLABEL(yyresume) */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    YYGOTO(yydefault);

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (YY_parse_CHAR == YYEMPTY)
    {
#if YY_parse_DEBUG != 0
      if (YY_parse_DEBUG_FLAG)
	fprintf(stderr, "Reading a token: ");
#endif
      YY_parse_CHAR = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (YY_parse_CHAR <= 0)           /* This means end of input. */
    {
      yychar1 = 0;
      YY_parse_CHAR = YYEOF;                /* Don't call YYLEX any more */

#if YY_parse_DEBUG != 0
      if (YY_parse_DEBUG_FLAG)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(YY_parse_CHAR);

#if YY_parse_DEBUG != 0
      if (YY_parse_DEBUG_FLAG)
	{
	  fprintf (stderr, "Next token is %d (%s", YY_parse_CHAR, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, YY_parse_CHAR, YY_parse_LVAL);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    YYGOTO(yydefault);

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	YYGOTO(yyerrlab);
      yyn = -yyn;
      YYGOTO(yyreduce);
    }
  else if (yyn == 0)
    YYGOTO(yyerrlab);

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    fprintf(stderr, "Shifting token %d (%s), ", YY_parse_CHAR, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (YY_parse_CHAR != YYEOF)
    YY_parse_CHAR = YYEMPTY;

  *++yyvsp = YY_parse_LVAL;
#ifdef YY_parse_LSP_NEEDED
  *++yylsp = YY_parse_LLOC;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  YYGOTO(yynewstate);

/* Do the default action for the current state.  */
YYLABEL(yydefault)

  yyn = yydefact[yystate];
  if (yyn == 0)
    YYGOTO(yyerrlab);

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
YYLABEL(yyreduce)
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


 #line 839 "/usr/share/bison++/bison.cc"

  switch (yyn) {

}

#line 839 "/usr/share/bison++/bison.cc"
   /* the action file gets copied in in place of this dollarsign  */
  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YY_parse_LSP_NEEDED
  yylsp -= yylen;
#endif

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YY_parse_LSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = YY_parse_LLOC.first_line;
      yylsp->first_column = YY_parse_LLOC.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  YYGOTO(yynewstate);

YYLABEL(yyerrlab)   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++YY_parse_NERRS;

#ifdef YY_parse_ERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      YY_parse_ERROR(msg);
	      free(msg);
	    }
	  else
	    YY_parse_ERROR ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YY_parse_ERROR_VERBOSE */
	YY_parse_ERROR("parse error");
    }

  YYGOTO(yyerrlab1);
YYLABEL(yyerrlab1)   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (YY_parse_CHAR == YYEOF)
	YYABORT;

#if YY_parse_DEBUG != 0
      if (YY_parse_DEBUG_FLAG)
	fprintf(stderr, "Discarding token %d (%s).\n", YY_parse_CHAR, yytname[yychar1]);
#endif

      YY_parse_CHAR = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;              /* Each real token shifted decrements this */

  YYGOTO(yyerrhandle);

YYLABEL(yyerrdefault)  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) YYGOTO(yydefault);
#endif

YYLABEL(yyerrpop)   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YY_parse_LSP_NEEDED
  yylsp--;
#endif

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

YYLABEL(yyerrhandle)

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    YYGOTO(yyerrdefault);

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    YYGOTO(yyerrdefault);

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	YYGOTO(yyerrpop);
      yyn = -yyn;
      YYGOTO(yyreduce);
    }
  else if (yyn == 0)
    YYGOTO(yyerrpop);

  if (yyn == YYFINAL)
    YYACCEPT;

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = YY_parse_LVAL;
#ifdef YY_parse_LSP_NEEDED
  *++yylsp = YY_parse_LLOC;
#endif

  yystate = yyn;
  YYGOTO(yynewstate);
/* end loop, in which YYGOTO may be used. */
  YYENDGOTO
}

/* END */

 #line 1038 "/usr/share/bison++/bison.cc"
#line 116 "p_sint.y"
                     /* C code */

int computeSymbolIndex(char token)
{
	int idx = -1;
	if(islower(token)) {
		idx = token - 'a' + 26;
	} else if(isupper(token)) {
		idx = token - 'A';
	}
	return idx;
} 

/* returns the value of a given symbol */
int symbolVal(char symbol)
{
	int bucket = computeSymbolIndex(symbol);
	return symbols[bucket];
}

/* updates the value of a given symbol */
void updateSymbolVal(char symbol, int val)
{
	int bucket = computeSymbolIndex(symbol);
	symbols[bucket] = val;
}

int main (void) {
    #if YYDEBUG
        yydebug = 1;     
    #endif 
	/* init symbol table */
	int i;
	for(i=0; i<52; i++) {
		symbols[i] = 0;
	}

    if (yyparse() == 0){
        printf("Parse sucessful\n");
        return 0;
    }else{
        return 1;
    }
	
}

void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 