#include "aux.h"
#include "tokens.h"
#include <stdio.h>

char* names[] = {NULL, "db_type", "db_name", "db_table_prefix", "db_port"};
char* reserved[] = {NULL, "program",
                    "integer","real", "boolean","char",
                    "begin","end",
                    "if","then","else",
                    "do","while",
                    "until","end",
                    "read","write","goto"};
#define reservedSize 18

char* functs[] = {NULL, "sin", "log", "cos", 
                  "ord", "chr", 
                  "abs", "sqrt", "exp", 
                  "eof", "eoln"};
#define functsSize 11

int yywrap (void){
    return 1;
}

/* 
Retorna -1 se 'str' NÃO é está na lista 'list' de tamanho 'size. 
Retorna o índice da palavra no vetor, se ela for encontrada ali.
*/
int resWord(char* str, char* list[], int size){
    int i = 1;
    for(i = 1; i < size; i++){
        if(strcmp(str,list[i]) == 0){
            return i;
        }
    }
    return -1;
}

/*
Retorna o token relativo ao identificador 'yytext' lido. Se for alguma palavra
reservada ou função definida, será retornado um token apropriado.
*/
int tokenId(){
    yylval.identifier = *yytext;
    if (resWord(yytext, reserved, reservedSize) != -1){
        // Palavra reservada
        printf("[%4d] Reserved: \t%s\n", yylineno, yytext);
        return resWord(yytext, reserved, reservedSize);
    }else if(resWord(yytext, functs, functsSize) != -1){
        // Nome de função
        printf("[%4d] Function: \t%s\n", yylineno, yytext);
        return resWord(yytext, functs, functsSize);
    }else{
        // Identificador
        printf("[%4d] Identifier: \t%s\n", yylineno, yytext);
        return IDENTIFIER;
    }
}

void printToken(char* tokenName){
    printf("[%4d] %s: \t%s\n", yylineno, tokenName, yytext);
}

int installID() {
    /* function to install the lexeme, whose first character is pointed to by 
    yytext, and whose length is yyleng, into the symbol table and return a 
    pointer thereto */ 
} 

int installNum() {
    /* similar to installID, but puts numerical 
    constants into a separate table */ 
}