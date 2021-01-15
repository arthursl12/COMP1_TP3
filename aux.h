#pragma once
#ifndef AUX_H
#define AUX_H

#include <string.h>

extern int yylex();
extern int yylineno;
extern char* yytext;

char* names[] = {NULL, "db_type", "db_name", "db_table_prefix", "db_port"};
char* reserved[] = {"program",
                    "integer","real", "boolean","char",
                    "begin","end",
                    "if","then","else"
                    "do","while",
                    "until","end",
                    "read","write","goto",
                    "false","true"};
#define reservedSize 18

int yywrap (void){
    return 1;
}

/* 
Retorna -1 se 'str' NÃO é uma palavra reservada. Retorna o índice da palavra
no vetor, se for uma palavra reservada
*/
int resWord(char* str){
    int i = 0;
    for(i = 0; i < reservedSize; i++){
        if(strcmp(str,reserved[i]) == 0){
            return i;
        }
    }
    return -1;
}

int findId(char* str){
    if (resWord(str) != 0){
        return resWord(str);
    }
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

#endif /* AUX */