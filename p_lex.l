%{
    #include "tokens.h"
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


letter [A-Za-z] 
id {letter}({letter}| {digit})* 
number {digit}+(\.{digit}+)?(E[+-]?{digit}+)?

%%

{ws}                ;
{uint}              { printf("[%4d] Integer: \t%s\n", yylineno, yytext); return INT_CONSTANT; }
{ureal}             { printf("[%4d] Real: \t%s\n", yylineno, yytext); return REAL_CONSTANT; }
{char}              { printf("[%4d] Char: \t%s\n", yylineno, yytext); return CHAR_CONSTANT; }
:                   { printf("[%4d] COLON: \t%s\n", yylineno, yytext); return COLON; }
"db_type"           return TYPE;
"db_name"           return NAME;
"db_table_prefix"   return TABLE_PREFIX;
"db_port"           return PORT;

[a-zA-z][_a-zA-Z0-9]*       return IDENTIFIER;
[1-9][0-9]*                 return INTEGER;

.                           printf("Unexpected character\n");


%%
/* Funções auxiliares no 'scanner.c' */