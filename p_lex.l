%{
    // #include "tokens.h"
    #include "aux.h"
    #include "y.tab.h"
    #include <stdlib.h>
    #include <stdbool.h>
    void yyerror (char *s);
%}
/* Para usar o 'yylineno' (número da linha) */
%option nounput yylineno   

/* DEFINIÇÕES REGULARES */ 
/* Espaços */
delim [ \t\n] 
ws {delim}+ 

/* Números e Constantes */
digit           [0-9]
uint            {digit}{digit}*
sign            [+-]?
scale_factor    E{sign}{uint}
ureal           {uint}(\.{digit}*)?({scale_factor})?
char            \'[\x00-\x7F]\'

/* Identificadores */
letter          [A-Za-z] 
id              {letter}({letter}|{digit})* 

%%
    /* Delimitadores e Espaços */
{ws}                ;
    /* Constantes */
{uint}              { printToken("Integer"); yylval.integer = atoi(yytext); return INT_CONSTANT; }
{ureal}             { printf("[%4d] Real: \t%s\n", yylineno, yytext); yylval.real = atof(yytext); return REAL_CONSTANT; }
{char}              { printf("[%4d] Char: \t%s\n", yylineno, yytext); yylval.character = *yytext; return CHAR_CONSTANT; }
    /* Constantes Booleanas */
"true"              { printf("[%4d] Bool: \t%s\n", yylineno, yytext); yylval.boolean = 1; return BOOL_CONSTANT; }
"false"             { printf("[%4d] Bool: \t%s\n", yylineno, yytext); yylval.boolean = 0; return BOOL_CONSTANT; }

    /* RELOP */ 
">"                 { printf("[%4d] Relop: \t%s\n", yylineno, yytext); return RELOP; }
">="                { printf("[%4d] Relop: \t%s\n", yylineno, yytext); return RELOP; }
"<"                 { printf("[%4d] Relop: \t%s\n", yylineno, yytext); return RELOP; }
"<="                { printf("[%4d] Relop: \t%s\n", yylineno, yytext); return RELOP; }
"="                 { printf("[%4d] Relop: \t%s\n", yylineno, yytext); return RELOP; }
"!="                { printf("[%4d] Relop: \t%s\n", yylineno, yytext); return RELOP; }
"NOT"               { printf("[%4d] Relop: \t%s\n", yylineno, yytext); return RELOP; }
    /* ADDOP */
"+"                 { printf("[%4d] Addop: \t%s\n", yylineno, yytext); return ADDOP; }
"-"                 { printf("[%4d] Addop: \t%s\n", yylineno, yytext); return ADDOP; }
"or"                { printf("[%4d] Addop: \t%s\n", yylineno, yytext); return ADDOP; }
    /* MULOP */
"*"                 { printf("[%4d] Mulop: \t%s\n", yylineno, yytext); return MULOP; }
"/"                 { printf("[%4d] Mulop: \t%s\n", yylineno, yytext); return MULOP; }
"div"               { printf("[%4d] Mulop: \t%s\n", yylineno, yytext); return MULOP; }
"mod"               { printf("[%4d] Mulop: \t%s\n", yylineno, yytext); return MULOP; }
"and"               { printf("[%4d] Mulop: \t%s\n", yylineno, yytext); return MULOP; }

{id}                { return tokenId(); }

","                 { return *yytext; }
.                   printf("Unexpected character\n");


%%
/* Funções auxiliares no 'scanner.c' */