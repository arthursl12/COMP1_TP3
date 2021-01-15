%{
    #include "tokens.h"
%}
/* Para usar o 'yylineno' (número da linha) */
%option nounput yylineno   

%%

:                   { printf("[%4d] COLON: \t%s\n", yylineno, yytext); return COLON; }
"db_type"           return TYPE;
"db_name"           return NAME;
"db_table_prefix"   return TABLE_PREFIX;
"db_port"           return PORT;

[a-zA-z][_a-zA-Z0-9]*       return IDENTIFIER;
[1-9][0-9]*                 return INTEGER;
[ \t\n]                      ;
.                           printf("Unexpected character\n");


%%
/* Funções auxiliares no 'scanner.c' */