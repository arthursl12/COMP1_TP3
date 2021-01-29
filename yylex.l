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
{ureal}             { printToken("Real"); return REAL_CONSTANT; }
{char}              { printToken("Char"); return CHAR_CONSTANT; }
    /* Constantes Booleanas */
"true"              { printToken("Bool"); return BOOL_CONSTANT; }
"false"             { printToken("Bool"); return BOOL_CONSTANT; }

    /* RELOP */ 
">"                 { printToken("Relop"); return RELOP; }
">="                { printToken("Relop"); return RELOP; }
"<"                 { printToken("Relop"); return RELOP; }
"<="                { printToken("Relop"); return RELOP; }
"="                 { printToken("Relop"); return RELOP; }
"!="                { printToken("Relop"); return RELOP; }
"NOT"               { printToken("NOT"); return NOT; }

    /* ADDOP */
"+"                 { printToken("Addop"); return ADDOP; }
"-"                 { printToken("Addop"); return ADDOP; }
"or"                { printToken("Addop"); return ADDOP; }

    /* MULOP */
"*"                 { printToken("Mulop"); return MULOP; }
"/"                 { printToken("Mulop"); return MULOP; }
"div"               { printToken("Mulop"); return MULOP; }
"mod"               { printToken("Mulop"); return MULOP; }
"and"               { printToken("Mulop"); return MULOP; }
    /* ASSIGN */
":="                { printToken("Assign"); return ASSIGN; }

    /* Identificadores e Palavras Reservadas */
{id}                { return tokenId(); }

    /* Símbolos especiais */
":"                 { printToken("CharEsp"); return *yytext; }
";"                 { printToken("CharEsp"); return *yytext; }
","                 { printToken("CharEsp"); return *yytext; }
")"                 { printToken("CharEsp"); return *yytext; }
"("                 { printToken("CharEsp"); return *yytext; }

    /* Qualquer outro deve ser ignorado */
.                   printf("Caractere ou token inválido\n");


%%
/* Funções auxiliares no 'aux.c' */