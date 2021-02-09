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
    ADDOP = 258,
    RELOP = 259,
    MULOP = 260,
    NOT = 261,
    ASSIGN = 262,
    INT_CONSTANT = 263,
    REAL_CONSTANT = 264,
    BOOL_CONSTANT = 265,
    IDENTIFIER = 266,
    IDENTIFIER_F = 267,
    CHAR_CONSTANT = 268,
    PROGRAM = 269,
    INTEGER = 270,
    REAL = 271,
    BOOLEAN = 272,
    CHAR = 273,
    BEGIN_STMT = 274,
    END = 275,
    IF = 276,
    THEN = 277,
    ELSE = 278,
    DO = 279,
    WHILE = 280,
    UNTIL = 281,
    READ = 282,
    WRITE = 283,
    GOTO = 284,
    SIN = 285,
    LOG = 286,
    COS = 287,
    ORD = 288,
    CHR = 289,
    ABS = 290,
    SQRT = 291,
    EXP = 292,
    EOF_TOKEN = 293,
    EOLN = 294
  };
#endif
/* Tokens.  */
#define ADDOP 258
#define RELOP 259
#define MULOP 260
#define NOT 261
#define ASSIGN 262
#define INT_CONSTANT 263
#define REAL_CONSTANT 264
#define BOOL_CONSTANT 265
#define IDENTIFIER 266
#define IDENTIFIER_F 267
#define CHAR_CONSTANT 268
#define PROGRAM 269
#define INTEGER 270
#define REAL 271
#define BOOLEAN 272
#define CHAR 273
#define BEGIN_STMT 274
#define END 275
#define IF 276
#define THEN 277
#define ELSE 278
#define DO 279
#define WHILE 280
#define UNTIL 281
#define READ 282
#define WRITE 283
#define GOTO 284
#define SIN 285
#define LOG 286
#define COS 287
#define ORD 288
#define CHR 289
#define ABS 290
#define SQRT 291
#define EXP 292
#define EOF_TOKEN 293
#define EOLN 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "yysint.y"

    int integer; 
    float real; 
    int boolean; 
    char character; 
    char* string; 

#line 143 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
