%{
    #include "myscanner.h"
%}
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
int yywrap (void){
    return 1;
}     

int main (void){
    int ntoken, vtoken;

    ntoken = yylex();
    while (ntoken){
        // printf("%d\n", ntoken);
        ntoken = yylex();
    }
    return 0;
} 