/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 53 "y.tab.h"

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


#line 191 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
