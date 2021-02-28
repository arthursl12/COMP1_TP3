#pragma once
#ifndef AUX_H
#define AUX_H

#include <string.h>

/* Constantes para tipos */
#define TYPE_INT    1
#define TYPE_REAL   2
#define TYPE_CHAR   3
#define TYPE_BOOL   4
#define TEMP_TYPE   8

// union value {
//     int integer; 
//     float real; 
//     int boolean; 
//     char character; 
// } value; 
typedef struct quadruple quadruple_t;

union value {
  int integer;
  float real;
  int boolean;
  char character;

  int TS_idx;
  quadruple_t *instr_ptr;
} value;

extern int yylex();
extern int yylineno;
extern char* yytext;

int yywrap (void);
int resWordId(char* str);
int functId(char* str);
int resWord(char* str, char* list[], int size);
int tokenId();
void printToken(char* tokenName);

#endif /* AUX */