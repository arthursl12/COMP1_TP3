#include <stdio.h>

#include "aux.h"
#include "y.tab.h"

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
Retorna o índice dado pelo YACC ao token da palavra reservada str
*/
int resWordId(char* str){
    if (strcmp(str, "program") == 0)
        return PROGRAM;
    else if (strcmp(str, "integer") == 0)
        return INTEGER;
    else if (strcmp(str, "real") == 0)
        return REAL;
    else if (strcmp(str, "boolean") == 0)
        return BOOLEAN;
    else if (strcmp(str, "char") == 0)
        return CHAR;
    else if (strcmp(str, "begin") == 0)
        return BEGIN_STMT;
    else if (strcmp(str, "end") == 0)
        return END;
    else if (strcmp(str, "if") == 0)
        return IF;
    else if (strcmp(str, "then") == 0)
        return THEN;
    else if (strcmp(str, "else") == 0)
        return ELSE;
    else if (strcmp(str, "do") == 0)
        return DO;
    else if (strcmp(str, "while") == 0)
        return WHILE;
    else if (strcmp(str, "until") == 0)
        return UNTIL;
    else if (strcmp(str, "read") == 0)
        return READ;
    else if (strcmp(str, "write") == 0)
        return WRITE;
    else if (strcmp(str, "goto") == 0)
        return GOTO;
    else
        return -1;
}


/*
Retorna o índice dado pelo YACC ao token da função padrão str
*/
int functId(char* str){
    if (strcmp(str, "sin") == 0)
        return SIN;
    else if (strcmp(str, "cos") == 0)
        return COS;
    else if (strcmp(str, "real") == 0)
        return LOG;
    else if (strcmp(str, "boolean") == 0)
        return ORD;
    else if (strcmp(str, "char") == 0)
        return CHR;
    else if (strcmp(str, "begin") == 0)
        return ABS;
    else if (strcmp(str, "end") == 0)
        return SQRT;
    else if (strcmp(str, "exp") == 0)
        return EXP;
    else if (strcmp(str, "eof") == 0)
        return EOF_TOKEN;
    else if (strcmp(str, "eoln") == 0)
        return EOLN;
    else
        return -1;
}

/* 
Retorna -1 se 'str' NÃO é está na lista 'list' de tamanho 'size. 
Retorna o índice da palavra para o YACC, se ela for encontrada ali.
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
    yylval.string = strdup(yytext);
    if (resWord(yytext, reserved, reservedSize) != -1){
        // Palavra reservada
        // printf("[%4d] Reserved: \t%s\n", yylineno, yytext);
        return resWordId(yytext);
    }else if(resWord(yytext, functs, functsSize) != -1){
        // Nome de função
        // printf("[%4d] Function: \t%s\n", yylineno, yytext);
        // return IDENTIFIER_F;
        return functId(yytext);
    }else{
        // Identificador
        // printf("[%4d] Identifier: \t%s\n", yylineno, yytext);
        return IDENTIFIER;
    }
}

void printToken(char* tokenName){
    // printf("[%4d] %s: \t%s\n", yylineno, tokenName, yytext);
}