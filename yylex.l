%{
    #include "tokens.h"
    #include "aux.h"
    #include <stdlib.h>
    #include <stdbool.h>
    void yyerror (char *s);
%}
/* Para usar o 'yylineno' (número da linha) */
%option nounput yylineno   

/* DEFINIÇÕES VIA EXPRESSÕES REGULARES */ 
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
{uint}              { printToken("Integer"); return INT_CONSTANT; }
{ureal}             { printf("[%4d] Real: \t%s\n", yylineno, yytext); return REAL_CONSTANT; }
{char}              { printf("[%4d] Char: \t%s\n", yylineno, yytext); return CHAR_CONSTANT; }
    /* Constantes Booleanas */
"true"              { printf("[%4d] Bool: \t%s\n", yylineno, yytext); return BOOL_CONSTANT; }
"false"             { printf("[%4d] Bool: \t%s\n", yylineno, yytext); return BOOL_CONSTANT; }

    /* RELOP */ 
">"                 { printf("[%4d] Relop: \t%s\n", yylineno, yytext); return RELOP; }
">="                { printf("[%4d] Relop: \t%s\n", yylineno, yytext); return RELOP; }
"<"                 { printf("[%4d] Relop: \t%s\n", yylineno, yytext); return RELOP; }
"<="                { printf("[%4d] Relop: \t%s\n", yylineno, yytext); return RELOP; }
"="                 { printf("[%4d] Relop: \t%s\n", yylineno, yytext); return RELOP; }
"!="                { printf("[%4d] Relop: \t%s\n", yylineno, yytext); return RELOP; }
"NOT"               { printf("[%4d] NOT: \t%s\n", yylineno, yytext); return NOT; }

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
    /* ASSIGN */
":="                { printf("[%4d] Assign: \t%s\n", yylineno, yytext); return ASSIGN; }

    /* Identificadores e Palavras Reservadas */
{id}                { return tokenId(); }

    /* Símbolos especiais */
":"                 { printf("[%4d] CharEsp: \t%s\n", yylineno, yytext); return *yytext; }
";"                 { printf("[%4d] CharEsp: \t%s\n", yylineno, yytext); return *yytext; }
","                 { printf("[%4d] CharEsp: \t%s\n", yylineno, yytext); return *yytext; }
")"                 { printf("[%4d] CharEsp: \t%s\n", yylineno, yytext); return *yytext; }
"("                 { printf("[%4d] CharEsp: \t%s\n", yylineno, yytext); return *yytext; }

    /* Qualquer outro deve ser ignorado */
.                   printf("Caractere ou token inválido\n");


%%
/* Funções auxiliares no 'aux.c' */