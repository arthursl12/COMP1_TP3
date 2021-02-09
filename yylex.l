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

/* Constantes Numéricas com Sinal */
int             {sign}?{uint}
real            {sign}?{ureal}

/* Identificadores */
letter          [A-Za-z] 
id              {letter}({letter}|{digit})* 

%%
    /* Delimitadores e Espaços */
{ws}                ;
    /* Constantes */
{uint}              { printToken("Integer"); yylval.integer = atoi(yytext); return INT_CONSTANT; }
{ureal}             { printToken("Real"); yylval.real = atof(yytext); return REAL_CONSTANT; }
{int}               { printToken("SInteger"); yylval.integer = atoi(yytext); return INT_CONSTANT; }
{real}              { printToken("SReal"); yylval.real = atof(yytext); return REAL_CONSTANT; }
{char}              { printToken("Char"); yylval.character = *yytext; return CHAR_CONSTANT; }
    /* Constantes Booleanas */
"true"              { printToken("Bool"); yylval.boolean = 1; return BOOL_CONSTANT; }
"false"             { printToken("Bool"); yylval.boolean = 0; return BOOL_CONSTANT; }

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
"or"                { printToken("Addop"); return ADDOP; }
    /* Minus: special case */
"-"                 { printToken("Minus"); return *yytext; }

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
":"                 { return *yytext; }
";"                 { return *yytext; }
","                 { return *yytext; }
")"                 { return *yytext; }
"("                 { return *yytext; }

    /* Qualquer outro deve ser ignorado */
.                   printf("Unexpected character\n");


%%
/* Funções auxiliares no 'aux.c' */