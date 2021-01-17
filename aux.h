#pragma once
#ifndef AUX_H
#define AUX_H

#include <string.h>

extern int yylex();
extern int yylineno;
extern char* yytext;
// extern YYSTYPE yylval; 

int yywrap (void);
int resWord(char* str, char* list[], int size);
int tokenId();
void printToken(char* tokenName);
int installID();
int installNum();

#endif /* AUX */