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
{uint}              { yylval.integer = atoi(yytext); return INT_CONSTANT; }
{ureal}             { yylval.real = atof(yytext); return REAL_CONSTANT; }
{char}              { yylval.character = *yytext; return CHAR_CONSTANT; }
    /* Constantes Booleanas */
"true"              { yylval.boolean = 1; return BOOL_CONSTANT; }
"false"             { yylval.boolean = 0; return BOOL_CONSTANT; }

    /* RELOP */ 
">"                 { return RELOP; }
">="                { return RELOP; }
"<"                 { return RELOP; }
"<="                { return RELOP; }
"="                 { return RELOP; }
"!="                { return RELOP; }
"NOT"               { return NOT; }

    /* ADDOP */
"+"                 { return ADDOP; }
"or"                { return ADDOP; }
    /* Minus: special case */
"-"                 { return *yytext; }

    /* MULOP */
"*"                 { return MULOP; }
"/"                 { return MULOP; }
"div"               { return MULOP; }
"mod"               { return MULOP; }
"and"               { return MULOP; }
    /* ASSIGN */
":="                { return ASSIGN; }

    /* Identificadores e Palavras Reservadas */
{id}                { return tokenId(); }

    /* Símbolos especiais */
":"                 { return *yytext; }
";"                 { return *yytext; }
","                 { return *yytext; }
")"                 { return *yytext; }
"("                 { return *yytext; }

    /* Qualquer outro deve ser ignorado */
.                   printf("Unexpected character\n");


%%
/* Funções auxiliares no 'aux.c' */