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

#line 153 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
