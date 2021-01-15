#include <stdio.h>
#include "tokens.h"
#include "aux.h"



int main (int argc, char* argv[]){
    int ntoken, vtoken;

    ntoken = yylex();
    while (ntoken){
        // printf("%d\n", ntoken);
        ntoken = yylex();
    }
    return 0;
} 

// int main(int argc, char* argv[]){
//     int ntoken, vtoken;
    
//     ntoken = yylex();
//     while(ntoken){
//         printf("%d\n", ntoken);
//         if (yylex() != COLON){
//             printf("Syntax error in line %d, Expected a ':' but found %s\n", yylineno, yytext);
//             return 1;
//         }
//         vtoken = yylex();
//         switch (ntoken){
//         case TYPE:
//         case NAME:
//         case TABLE_PREFIX:
//             if (vtoken != IDENTIFIER){
//                 printf("Syntax error in line %d, Expected an identifier but found %s\n", yylineno, yytext);
//                 return 1;
//             }
//             printf("%s is set to %s\n", names[ntoken], yytext);
//             break;
//         case PORT:
//             if (vtoken != INTEGER){
//                 printf("Syntax error in line %d, Expected an integer but found %s\n", yylineno, yytext);
//                 return 1;
//             }
//             printf("%s is set to %s\n", names[ntoken], yytext);
//             break;
//         default:
//             printf("Syntax error in line %d\n", yylineno);
//             break;
//         }
//         ntoken = yylex();
//     }
//     return 0;
// }