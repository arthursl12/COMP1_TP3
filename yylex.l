%{
    // #include "tokens.h"
    #include "aux.h"
    #include "codinterm.h"
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
int             {sign}{uint}
real            {sign}{ureal}

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
{char}              { printToken("Char"); yylval.character = *(yytext+1); return CHAR_CONSTANT; }
    /* Constantes Booleanas */
"true"              { printToken("Bool"); yylval.boolean = 1; return TRUE_CST; }
"false"             { printToken("Bool"); yylval.boolean = 0; return FALSE_CST; }

    /* RELOP */ 
">"                 { printToken("Relop"); yylval.lexeme_str = strdup(yytext); return RELOP; }
">="                { printToken("Relop"); yylval.lexeme_str = strdup(yytext); return RELOP; }
"<"                 { printToken("Relop"); yylval.lexeme_str = strdup(yytext); return RELOP; }
"<="                { printToken("Relop"); yylval.lexeme_str = strdup(yytext); return RELOP; }
"="                 { printToken("Relop"); yylval.lexeme_str = strdup(yytext); return RELOP; }
"!="                { printToken("Relop"); yylval.lexeme_str = strdup(yytext); return RELOP; }
"NOT"               { printToken("NOT"); return NOT; }

    /* ADDOP */
"+"                 { printToken("Addop"); yylval.lexeme_str = strdup(yytext); return ADDOP; }
"or"                { printToken("Addop"); yylval.lexeme_str = strdup(yytext); return OR; }
    /* Minus: caso especial, o analisador sintático decide */
"-"                 { printToken("Minus"); return MINUS; }

    /* MULOP */
"*"                 { printToken("Mulop"); yylval.lexeme_str = strdup(yytext); return MULOP; }
"/"                 { printToken("Mulop"); yylval.lexeme_str = strdup(yytext); return MULOP; }
"div"               { printToken("Mulop"); yylval.lexeme_str = strdup(yytext); return MULOP; }
"mod"               { printToken("Mulop"); yylval.lexeme_str = strdup(yytext); return MULOP; }
"and"               { printToken("Mulop"); yylval.lexeme_str = strdup(yytext); return AND; }
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