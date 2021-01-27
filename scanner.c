#include <stdio.h>
#include "tokens.h"
#include "aux.h"

/* Main simples apenas para ler a entrada e passar para o analisador léxico */
int main (int argc, char* argv[]){
    int ntoken, vtoken;

    ntoken = yylex();
    while (ntoken){
        ntoken = yylex();
    }
    return 0;
}