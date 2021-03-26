#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "interpr.h"
#include "aux.h"

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
Operações de função padrão, exceto eof e eoln 
Retorna 0 se ocorreu tudo com sucesso, 1 do contrário.
*/
int functOps(char* opcode, intmdt_addr_t* arg1, intmdt_addr_t* result){
    int tipo1, idx1;
    int tipoR, idxR;
    tsQuery(&idx1, &tipo1, arg1);
    tsQuery(&idxR, &tipoR, result);

    /* numToReal: inteiro ou real vira real*/
    if (strcmp(opcode, "sqrt") == 0){
        if (tipo1 == TYPE_INT){
            if (TabelaS[idx1].value.integer == 0){
                printf("Erro! Raiz quadrada de negativo.\n");
                return 1;
            }
            // op(int) = real
            TabelaS[idxR].value.real = sqrt(TabelaS[idx1].value.integer);
        }else{
            if (TabelaS[idx1].value.real < 0){
                printf("Erro! Raiz quadrada de negativo.\n");
                return 1;
            }
            // op(real) = real
            TabelaS[idxR].value.real = sqrt(TabelaS[idx1].value.real);
        }
    }else if (strcmp(opcode, "sin") == 0){
        if (tipo1 == TYPE_INT){
            // op(int) = real
            TabelaS[idxR].value.real = sin(TabelaS[idx1].value.integer);
        }else{
            // op(real) = real
            TabelaS[idxR].value.real = sin(TabelaS[idx1].value.real);
        }
    }else if (strcmp(opcode, "cos") == 0){
        if (tipo1 == TYPE_INT){
            // op(int) = real
            TabelaS[idxR].value.real = cos(TabelaS[idx1].value.integer);
        }else{
            // op(real) = real
            TabelaS[idxR].value.real = cos(TabelaS[idx1].value.real);
        }
    }else if (strcmp(opcode, "log") == 0){
        if (tipo1 == TYPE_INT){
            if (TabelaS[idx1].value.integer < 0){
                printf("Erro! Log de negativo.\n");
                return 1;
            }
            // op(int) = real
            TabelaS[idxR].value.real = log(TabelaS[idx1].value.integer);
        }else{
            if (TabelaS[idx1].value.real < 0){
                printf("Erro! Log de negativo.\n");
                return 1;
            }
            // op(real) = real
            TabelaS[idxR].value.real = log(TabelaS[idx1].value.real);
        }
    }else if (strcmp(opcode, "exp") == 0){
        if (tipo1 == TYPE_INT){
            // op(int) = real
            TabelaS[idxR].value.real = exp(TabelaS[idx1].value.integer);
        }else{
            // op(real) = real
            TabelaS[idxR].value.real = exp(TabelaS[idx1].value.real);
        }
    }

    /* Outras funções: abs, ord, chr  */
    else if (strcmp(opcode, "abs") == 0){
        if (tipo1 == TYPE_INT){
            // op(int) = int
            TabelaS[idxR].value.integer = abs(TabelaS[idx1].value.integer);
        }else{
            // op(real) = real
            TabelaS[idxR].value.real = fabs(TabelaS[idx1].value.real);
        }
    }else if (strcmp(opcode, "ord") == 0){
        // Casting de inteiro
        if (tipo1 == TYPE_BOOL){
            // op(true) = 1
            // op(false) = 0
            TabelaS[idxR].value.integer = TabelaS[idx1].value.boolean;
        }else if (tipo1 == TYPE_CHAR){
            // op(char) = (int)char
            TabelaS[idxR].value.integer = (int)TabelaS[idx1].value.character;
        }else if (tipo1 == TYPE_INT){
            // Valor já é inteiro, nada a ser feito
        }
    }else if (strcmp(opcode, "chr") == 0){
        // Casting de inteiro
        if (tipo1 == TYPE_CHAR){
            // Já é char, nada a ser feito
        }else if (tipo1 == TYPE_INT){
            TabelaS[idxR].value.character = (char)TabelaS[idx1].value.integer;
        }
    }
    // EOF e EOLN retorna bool, devem ser tratados em outro lugar
    return 0;
}


/* 
Avaliação de operações aritméticas 
Retorna 0 se ocorreu tudo com sucesso, 1 do contrário.
*/
int arithmeticOps(char* opcode, 
                   intmdt_addr_t* arg1, 
                   intmdt_addr_t* arg2, 
                   intmdt_addr_t* result)
{
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
        return 0;
    }else if (strcmp("-",opcode) == 0){
        int tipo1, idx1;
        int tipo2, idx2;
        int tipoR, idxR;
        tsQuery(&idx1, &tipo1, arg1);
        tsQuery(&idx2, &tipo2, arg2);
        tsQuery(&idxR, &tipoR, result);

        if (tipoR == TYPE_INT){
            // int - int = int
            TabelaS[idxR].value.integer = \
                TabelaS[idx1].value.integer - TabelaS[idx2].value.integer;
        }else if (tipo1 == TYPE_INT){
            // int - real = real
            TabelaS[idxR].value.real = \
                TabelaS[idx1].value.integer - TabelaS[idx2].value.real;
        }else if (tipo2 == TYPE_INT){
            // real - int = real
            TabelaS[idxR].value.real = \
                TabelaS[idx1].value.real - TabelaS[idx2].value.integer;
        }else{
            // real - real = real
            TabelaS[idxR].value.real = \
                TabelaS[idx1].value.real - TabelaS[idx2].value.real;
        }
        return 0;
    }else if (strcmp("*",opcode) == 0){
        int tipo1, idx1;
        int tipo2, idx2;
        int tipoR, idxR;
        tsQuery(&idx1, &tipo1, arg1);
        tsQuery(&idx2, &tipo2, arg2);
        tsQuery(&idxR, &tipoR, result);

        if (tipoR == TYPE_INT){
            // int * int = int
            TabelaS[idxR].value.integer = \
                TabelaS[idx1].value.integer * TabelaS[idx2].value.integer;
        }else if (tipo1 == TYPE_INT){
            // int * real = real
            TabelaS[idxR].value.real = \
                TabelaS[idx1].value.integer * TabelaS[idx2].value.real;
        }else if (tipo2 == TYPE_INT){
            // real * int = real
            TabelaS[idxR].value.real = \
                TabelaS[idx1].value.real * TabelaS[idx2].value.integer;
        }else{
            // real * real = real
            TabelaS[idxR].value.real = \
                TabelaS[idx1].value.real * TabelaS[idx2].value.real;
        }
        return 0;
    }else if (strcmp("/",opcode) == 0){
        int tipo1, idx1;
        int tipo2, idx2;
        int tipoR, idxR;
        tsQuery(&idx1, &tipo1, arg1);
        tsQuery(&idx2, &tipo2, arg2);
        tsQuery(&idxR, &tipoR, result);

        if (tipoR == TYPE_INT){
            if(TabelaS[idx2].value.integer == 0){
                printf("Division for 0 is not allowed\n");
                return 1;
            }
            // int / int = real
            TabelaS[idxR].value.integer = \
                TabelaS[idx1].value.integer / TabelaS[idx2].value.integer;
        }else if (tipo1 == TYPE_INT){
            if(TabelaS[idx2].value.real == 0){
                printf("Division for 0 is not allowed\n");
                return 1;
            }
            // int / real = real
            TabelaS[idxR].value.real = \
                TabelaS[idx1].value.integer / TabelaS[idx2].value.real;
        }else if (tipo2 == TYPE_INT){
            if(TabelaS[idx2].value.integer == 0){
                printf("Division for 0 is not allowed\n");
                return 1;
            }
            // real / int = real
            TabelaS[idxR].value.real = \
                TabelaS[idx1].value.real / TabelaS[idx2].value.integer;
        }else{
            if(TabelaS[idx2].value.integer == 0){
                printf("Division for 0 is not allowed\n");
                return 1;
            }
            // real / real = real
            TabelaS[idxR].value.real = \
                TabelaS[idx1].value.real / TabelaS[idx2].value.real;
        }
        return 0;
    }else if (strcmp("div",opcode) == 0){
        int tipo1, idx1;
        int tipo2, idx2;
        int tipoR, idxR;
        tsQuery(&idx1, &tipo1, arg1);
        tsQuery(&idx2, &tipo2, arg2);
        tsQuery(&idxR, &tipoR, result);

        if (tipoR == TYPE_INT){
            if(TabelaS[idx2].value.integer == 0){
                printf("Div for 0 is not allowed\n");
                return 1;
            }
            // int / int = int
            TabelaS[idxR].value.integer = \
                TabelaS[idx1].value.integer / TabelaS[idx2].value.integer;
        }
        return 0;
    }else if (strcmp("mod",opcode) == 0){
        int tipo1, idx1;
        int tipo2, idx2;
        int tipoR, idxR;
        tsQuery(&idx1, &tipo1, arg1);
        tsQuery(&idx2, &tipo2, arg2);
        tsQuery(&idxR, &tipoR, result);

        if (tipoR == TYPE_INT){
            if(TabelaS[idx2].value.integer == 0){
                printf("Mod for 0 is not allowed\n");
                return 1;
            }
            // int % int = int
            TabelaS[idxR].value.integer = \
                TabelaS[idx1].value.integer % TabelaS[idx2].value.integer;
        }
    }
    return 0;
}

/*
Avaliação de operações de entrada e saída
*/
void ioOps(char* opcode, intmdt_addr_t* arg1, intmdt_addr_t* result){
    if (strcmp("print",opcode) == 0){
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
    }else if (strcmp("read",opcode) == 0){
        int tipoR, idxR;
        tsQuery(&idxR, &tipoR, result);
        char buf[128];
        fgets(buf, sizeof(buf), stdin);

        if (tipoR == TYPE_INT){
            sscanf(buf,"%i", &TabelaS[idxR].value.integer);
        }else if (tipoR == TYPE_REAL){
            sscanf(buf,"%f", &TabelaS[idxR].value.real);
        }else if (tipoR == TYPE_CHAR){
            sscanf(buf,"%c", &TabelaS[idxR].value.character);
        }else if (tipoR == TYPE_BOOL){
            int temp;
            sscanf(buf,"%i", &temp);
            if (temp >= 1){
               TabelaS[idxR].value.boolean = 1;
            }else{
                TabelaS[idxR].value.boolean = 0;
            }
        }
    }   
}

bool isGoto(char* opcode){
    if (strcmp("goto",opcode) == 0 || strcmp("gotoAB",opcode) == 0
        || strcmp("gotoN",opcode) == 0 || strcmp("gotoF",opcode) == 0
        || strcmp("gotoRE",opcode) == 0 || strcmp("gotoRG",opcode) == 0
        || strcmp("gotoT",opcode) == 0 || strcmp("gotoB",opcode) == 0
        || strcmp("gotoV1",opcode) == 0 || strcmp("gotoV2",opcode) == 0)
    {
        return true;
    }else{
        return false;
    }
}

int simpleRelop(char* opcode, int tipo1, int idx1, int tipo2, int idx2){
    int compRes = 0;
    if (strcmp(">", opcode) == 0){
        if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
            compRes = \
            (TabelaS[idx1].value.integer > TabelaS[idx2].value.integer);
        }else if (tipo1 == TYPE_REAL && tipo2 == TYPE_REAL){
            compRes = \
            (TabelaS[idx1].value.real > TabelaS[idx2].value.real);
        }else if (tipo1 == TYPE_REAL && tipo2 == TYPE_INT){
            compRes = \
            (TabelaS[idx1].value.real > TabelaS[idx2].value.integer);
        }else if (tipo1 == TYPE_INT && tipo2 == TYPE_REAL){
            compRes = \
            (TabelaS[idx1].value.integer > TabelaS[idx2].value.real);
        }
    }else if (strcmp(">=", opcode) == 0){
        if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
            compRes = \
            (TabelaS[idx1].value.integer >= TabelaS[idx2].value.integer);
        }else if (tipo1 == TYPE_REAL && tipo2 == TYPE_REAL){
            compRes = \
            (TabelaS[idx1].value.real >= TabelaS[idx2].value.real);
        }else if (tipo1 == TYPE_REAL && tipo2 == TYPE_INT){
            compRes = \
            (TabelaS[idx1].value.real >= TabelaS[idx2].value.integer);
        }else if (tipo1 == TYPE_INT && tipo2 == TYPE_REAL){
            compRes = \
            (TabelaS[idx1].value.integer >= TabelaS[idx2].value.real);
        }
    }else if (strcmp("<", opcode) == 0){
        if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
            compRes = \
            (TabelaS[idx1].value.integer < TabelaS[idx2].value.integer);
        }else if (tipo1 == TYPE_REAL && tipo2 == TYPE_REAL){
            compRes = \
            (TabelaS[idx1].value.real < TabelaS[idx2].value.real);
        }else if (tipo1 == TYPE_REAL && tipo2 == TYPE_INT){
            compRes = \
            (TabelaS[idx1].value.real < TabelaS[idx2].value.integer);
        }else if (tipo1 == TYPE_INT && tipo2 == TYPE_REAL){
            compRes = \
            (TabelaS[idx1].value.integer < TabelaS[idx2].value.real);
        }
    }else if (strcmp("<=", opcode) == 0){
        if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
            compRes = \
            (TabelaS[idx1].value.integer <= TabelaS[idx2].value.integer);
        }else if (tipo1 == TYPE_REAL && tipo2 == TYPE_REAL){
            compRes = \
            (TabelaS[idx1].value.real <= TabelaS[idx2].value.real);
        }else if (tipo1 == TYPE_REAL && tipo2 == TYPE_INT){
            compRes = \
            (TabelaS[idx1].value.real <= TabelaS[idx2].value.integer);
        }else if (tipo1 == TYPE_INT && tipo2 == TYPE_REAL){
            compRes = \
            (TabelaS[idx1].value.integer <= TabelaS[idx2].value.real);
        }
    }
    return compRes;
}

int eqRelop(char* opcode, int tipo1, int idx1, int tipo2, int idx2){
    int compRes = 0;
    if (strcmp("=", opcode) == 0){
        if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
            compRes = \
            (TabelaS[idx1].value.integer == TabelaS[idx2].value.integer);
        }else if (tipo1 == TYPE_REAL && tipo2 == TYPE_REAL){
            compRes = \
            (TabelaS[idx1].value.real == TabelaS[idx2].value.real);
        }else if (tipo1 == TYPE_REAL && tipo2 == TYPE_INT){
            compRes = \
            (TabelaS[idx1].value.real == TabelaS[idx2].value.integer);
        }else if (tipo1 == TYPE_INT && tipo2 == TYPE_REAL){
            compRes = \
            (TabelaS[idx1].value.integer == TabelaS[idx2].value.real);
        }else if (tipo1 != tipo2){
            compRes = 0;
        }else if (tipo1 == TYPE_CHAR && tipo2 == TYPE_CHAR){
            compRes = \
            (TabelaS[idx1].value.character == TabelaS[idx2].value.character);
        }else if (tipo1 == TYPE_BOOL && tipo2 == TYPE_BOOL){
            compRes = \
            (TabelaS[idx1].value.boolean == TabelaS[idx2].value.boolean);
        }
    }else if (strcmp("!=", opcode) == 0){
        if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
            compRes = \
            (TabelaS[idx1].value.integer != TabelaS[idx2].value.integer);
        }else if (tipo1 == TYPE_REAL && tipo2 == TYPE_REAL){
            compRes = \
            (TabelaS[idx1].value.real != TabelaS[idx2].value.real);
        }else if (tipo1 == TYPE_REAL && tipo2 == TYPE_INT){
            compRes = \
            (TabelaS[idx1].value.real != TabelaS[idx2].value.integer);
        }else if (tipo1 == TYPE_INT && tipo2 == TYPE_REAL){
            compRes = \
            (TabelaS[idx1].value.integer != TabelaS[idx2].value.real);
        }else if (tipo1 != tipo2){
            compRes = 0;
        }else if (tipo1 == TYPE_CHAR && tipo2 == TYPE_CHAR){
            compRes = \
            (TabelaS[idx1].value.character != TabelaS[idx2].value.character);
        }else if (tipo1 == TYPE_BOOL && tipo2 == TYPE_BOOL){
            compRes = \
            (TabelaS[idx1].value.boolean != TabelaS[idx2].value.boolean);
        }
    }
    return compRes;
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
        // printf("PC=%i, Opcode: %s\n", PC, opcode);

        // "Switch" com a operação da quádrupla
        if (strcmp("+",opcode) == 0 || strcmp("-",opcode) == 0
            || strcmp("*",opcode) == 0 || strcmp("/",opcode) == 0
            || strcmp("div",opcode) == 0 || strcmp("mod",opcode) == 0)
        {
            if (arithmeticOps(opcode, arg1, arg2, result) != 0){
                // Ocorreu algum erro na avaliação
                return 1;
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
                // printf("Antes: var(%i)=%i, val=%i\n", idxR, TabelaS[idxR].value.boolean, TabelaS[idx1].value.boolean);
                TabelaS[idxR].value.boolean = TabelaS[idx1].value.boolean;
                // printf("Depois: var(%i)=%i, val=%i\n", idxR, TabelaS[idxR].value.boolean, TabelaS[idx1].value.boolean);

            }
        }
        /* Operador menos unário */
        else if (strcmp("-1",opcode) == 0){
            int tipo1, idx1;
            int tipoR, idxR;
            tsQuery(&idx1, &tipo1, arg1);
            tsQuery(&idxR, &tipoR, result);

            if (tipo1 == TYPE_INT){
                TabelaS[idxR].value.integer = -1 * TabelaS[idx1].value.integer;
            }else{
                TabelaS[idxR].value.real = -1 * TabelaS[idx1].value.real;
            }
        }


        /* Operações de funções padrão */
        else if (resWord(opcode, functs, functsSize) != -1 
                 && strcmp("eof",opcode) != 0 && strcmp("eoln",opcode) != 0){
            if (functOps(opcode, arg1, result) != 0){
                // Algum erro ocorreu na avaliação
                return 1;
            }
        }else if (strcmp("eof",opcode) == 0){
            if (feof(stdin)){
                // Temos que ir para onde result manda
                PC = result->value.instr_ptr->n;
                atual = intermediate_code->code[PC];
                continue;
            }else{
                // Vamos andar o PC em 1 e ir para onde o goto dali manda
                PC++;
                atual = intermediate_code->code[PC];
                continue;
            }
        }else if (strcmp("eoln",opcode) == 0){
            if (fgetc(stdin) == '\n'){
                // Temos que ir para onde result manda
                PC = result->value.instr_ptr->n;
                atual = intermediate_code->code[PC];
                continue;
            }else{
                // Vamos andar o PC em 1 e ir para onde o goto dali manda
                PC++;
                atual = intermediate_code->code[PC];
                continue;
            }
        }
        
        /* Operações de IO */
        else if (strcmp("print",opcode) == 0 || strcmp("read",opcode) == 0){
            ioOps(opcode, arg1, result);
        }


        /* RELOP's */
        else if (strcmp(">", opcode) == 0 || strcmp(">=", opcode) == 0 ||
                 strcmp("<", opcode) == 0 || strcmp("<=", opcode) == 0 ||
                 strcmp("=", opcode) == 0 || strcmp("!=", opcode) == 0)
        {
            int tipo1, idx1;
            int tipo2, idx2;
            int tipoR, idxR;
            tsQuery(&idx1, &tipo1, arg1);
            tsQuery(&idx2, &tipo2, arg2);

            int compRes = 0;
            if (strcmp(">", opcode) == 0 || strcmp(">=", opcode) == 0 ||
                strcmp("<", opcode) == 0 || strcmp("<=", opcode) == 0)
            {
                compRes = simpleRelop(opcode, tipo1, idx1, tipo2, idx2);
            }else{
                compRes = eqRelop(opcode, tipo1, idx1, tipo2, idx2);
            }

            if (result->type != TYPE_LABEL){
                tsQuery(&idxR, &tipoR, result);
                TabelaS[idxR].value.boolean = compRes;
            }else{
                if (compRes){
                    // Temos que ir para onde result manda
                    PC = result->value.instr_ptr->n;
                    atual = intermediate_code->code[PC];
                    continue;
                }else{
                    // Vamos andar o PC em 1 e ir para onde o goto dali manda
                    PC++;
                    atual = intermediate_code->code[PC];
                    continue;
                }
            }
        }
        
        /* GOTO's */
        else if (isGoto(opcode) && strcmp("gotoB",opcode) != 0){
            if (result == NULL){
                printf("Erro! GOTO para nulo\n");
                return 1;
            }
            // Temos que ir para onde result manda, se ele existir
            PC = result->value.instr_ptr->n;
            atual = intermediate_code->code[PC];
            continue;
        }else if (strcmp("gotoB",opcode) == 0){
            if (result == NULL){
                // gotoB foi gerado para um print, por exemplo, não precisamos dele
            }else{
                // gotoB foi gerado para uma operação que usa o valor booleano 
                // de uma variável booleana, agora precisamos dele

                // Temos que ir para onde result manda
                PC = result->value.instr_ptr->n;
                atual = intermediate_code->code[PC];
                continue;
            }
        }else if (strcmp("boolV",opcode) == 0){
            if (result->type != TYPE_LABEL){
                // boolV foi gerado para um print, por exemplo,
                // Funciona como uma atribuição para um temporário
                int tipo1, idx1;
                int tipoR, idxR;
                tsQuery(&idxR, &tipoR, result);
                tsQuery(&idx1, &tipo1, arg1);
                TabelaS[idxR].value.boolean = TabelaS[idx1].value.boolean;
            }else{
                // boolV funciona como um goto, 
                // para avaliação de expressões booleanas
                // Temos que ir para onde result manda, se for verdadeiro
                int tipo1, idx1;
                tsQuery(&idx1, &tipo1, arg1);

                if (TabelaS[idx1].value.boolean == 1){
                    // Valor verdadeiro, só seguir o goto
                    PC = result->value.instr_ptr->n;
                    atual = intermediate_code->code[PC];
                    // printf("boolV verdadeiro: goto=%i\n", PC);

                    continue;
                }else{
                    // Valor falso, segue o goto da linha seguinte
                    PC++;
                    quadruple_t* seguinte = intermediate_code->code[PC];
                    PC = seguinte->result->value.instr_ptr->n;
                    atual = intermediate_code->code[PC];
                    // printf("boolV falso: goto=%i\n", PC);
                    continue;
                }
            }
        }
        
        /* Comando end */
        else if (strcmp("end", opcode) == 0){
            break;
        /* Guarda para operações eventualmente não encontradas */
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
