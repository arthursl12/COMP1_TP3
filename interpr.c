#include <stdio.h>
#include "interpr.h"

/* 
Se algum tipo for temporário (apontar para a tabela de símbolos) busca na 
tabela de símbolos o tipo verdadeiro
*/
void tempTipoI(int* tipo1, intmdt_addr_t* s1){
    if (*tipo1 == TS_ENTRY){
        int idx = s1->value.TS_idx;
        *tipo1 = TabelaS[idx].type;
    }
}


/* 
Para um intmdt_addr que seja do tipo TS_ENTRY (entrada da tabela de símbolos),
retorna (nos parâmetros passados por referência) seu índice na tabela e seu 
tipo verdadeiro
*/
void tsQuery(int* idx, int* tipo, intmdt_addr_t* addr){
    if (addr->type == TS_ENTRY){
        *idx = addr->value.TS_idx;
        *tipo = TabelaS[*idx].type;
    }
}

/* 
Interpretador do vetor de quádruplas fornecido.
Usa a tabela de símbolos (variável global).

Retorna 0 para interpretação com sucesso.
Retorna 1 caso haja algum erro.
*/
int evaluate(intmdt_code_t* intermediate_code){
    int PC = 0;     // Program counter, índice da quádrupla atual
    quadruple_t* atual = intermediate_code->code[0];    // Quádrupla inicial



    while (PC < intermediate_code->n){
        // Pega operação da quádrupla atual
        char* opcode = atual->op;
        intmdt_addr_t* arg1 = atual->arg1;
        intmdt_addr_t* arg2 = atual->arg2;
        intmdt_addr_t* result = atual->result;
        // printf("Opcode: %s, PC=%i\n", opcode, PC);

        // "Switch" com a operação da quádrupla
        if (strcmp("+",opcode) == 0){
            int tipo1, idx1;
            int tipo2, idx2;
            int tipoR, idxR;
            tsQuery(&idx1, &tipo1, arg1);
            tsQuery(&idx2, &tipo2, arg2);
            tsQuery(&idxR, &tipoR, result);

            if (tipoR == TYPE_INT){
                // int + int = int
                TabelaS[idxR].value.integer = \
                    TabelaS[idx1].value.integer + TabelaS[idx2].value.integer;
            }else if (tipo1 == TYPE_INT){
                // int + real = real
                TabelaS[idxR].value.real = \
                    TabelaS[idx1].value.integer + TabelaS[idx2].value.real;
            }else if (tipo2 == TYPE_INT){
                // real + int = real
                TabelaS[idxR].value.real = \
                    TabelaS[idx1].value.real + TabelaS[idx2].value.integer;
            }else{
                // real + real = real
                TabelaS[idxR].value.real = \
                    TabelaS[idx1].value.real + TabelaS[idx2].value.real;
            }
        }else if (strcmp(":=",opcode) == 0){
            int tipo1, idx1;
            int tipoR, idxR;
            tsQuery(&idx1, &tipo1, arg1);
            tsQuery(&idxR, &tipoR, result);

            if (tipoR == TYPE_REAL && tipo1 == TYPE_INT){
                TabelaS[idxR].value.real = (float) TabelaS[idx1].value.integer;
            }else if (tipo1 == TYPE_INT){
                TabelaS[idxR].value.integer = TabelaS[idx1].value.integer;
            }else if (tipo1 == TYPE_REAL){
                TabelaS[idxR].value.real = TabelaS[idx1].value.real;
            }else if (tipo1 == TYPE_CHAR){
                TabelaS[idxR].value.character = TabelaS[idx1].value.character;
            }else if (tipo1 == TYPE_BOOL){
                TabelaS[idxR].value.boolean = TabelaS[idx1].value.boolean;
            }
        }else if (strcmp("print",opcode) == 0){
            int tipo1, idx1;
            tsQuery(&idx1, &tipo1, arg1);

            if (tipo1 == TYPE_INT){
                printf("%i\n", TabelaS[idx1].value.integer);
            }else if (tipo1 == TYPE_REAL){
                printf("%f\n", TabelaS[idx1].value.real);
            }else if (tipo1 == TYPE_CHAR){
                printf("%c\n", TabelaS[idx1].value.character);
            }else if (tipo1 == TYPE_BOOL){
                printf("%i\n", TabelaS[idx1].value.boolean);
            }
        }else if (strcmp("end", opcode) == 0){
            break;
        }else{
            printf("Operação não encontrada: %s\n", opcode);
            return 1;
        }


        // Controle do Loop
        PC++;
        if (PC >= intermediate_code->n){
            // Acabaram as quádruplas
            return 0;
        }
        atual = intermediate_code->code[PC];
    }
    return 0;
}
