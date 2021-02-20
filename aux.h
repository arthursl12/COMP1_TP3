#pragma once
#ifndef AUX_H
#define AUX_H

#include <string.h>
union value {
    int integer; 
    float real; 
    int boolean; 
    char character; 
} value; 

extern int yylex();
extern int yylineno;
extern char* yytext;

int yywrap (void);
int resWordId(char* str);
int resWord(char* str, char* list[], int size);
int tokenId();
void printToken(char* tokenName);

#endif /* AUX */