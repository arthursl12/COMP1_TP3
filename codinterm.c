#include "codinterm.h"
#include "tab.h"
#include <stdlib.h>
#include <stdio.h>

/* 
   Does absolutely nothing. Only exists so we can
   use it as *cmp and not have list_init complain.
*/
int quadruple_cmp(const void *key, const void *value){
  return (key == value);
}

/*  
    Creates a new list containing only instr_ptr.
    Returns a pointer to the newly created list.
    Returns NULL on failure.
    This function uses the linked_lists functions
    and structs, but passes NULL for unnecissary 
    arguments, such as cmp() and *key.
*/
list_head_t *list_makelist(quadruple_t *instr_ptr) {
  list_head_t *head =  list_init(quadruple_cmp);

  list_insert(head, NULL, instr_ptr);

  return head;
}

/*  
    creates a quadruple_t containing the op, arguments, and result
    passed to this function. Then, the quadruple_t is inserted into
    the next empty location in the given intmdt_code_t. Returns 0 on
    error, 1 on success.
*/
int gen(intmdt_code_t *intermediate_code,
        char *op, intmdt_addr_t *arg1, intmdt_addr_t *arg2,
        intmdt_addr_t *result) {

  quadruple_t *instr = malloc(sizeof(quadruple_t));

  if (instr == NULL) {
    fprintf(stderr, "Error on malloc in gen();\n");
    return(0);
  }
  instr->op = op;
  instr->arg1 = arg1;
  instr->arg2 = arg2;
  instr->result = result;

  if (intermediate_code->n < MAXCODELEN) {
    intermediate_code->code[intermediate_code->n] = instr;
    intermediate_code->n++;
    return(1);
  } else { 
    fprintf(stderr, "Error in gen(): overwriting or max limit hit for intmdt_code\n");
    return(0);
  }
}

/*  
    Cria uma nova variável temporária e a instala na tabela de símbolos. 
    Variáveis Temporárias começam com @. 
    
    Retorna o índice dela na tabela de símbolos
*/
intmdt_addr_t *newtemp(int tipo) {
    /* Contador de variáveis temporárias */
    static int temp_num = 0;  	
    temp_num++;

    /* Nova entrada da TS */
    char nome[15];
    union value val;
    sprintf(nome, "@%d", temp_num);

    /* Guarda na TS */
    Instala(nome, tipo, CLS_TEMP, val);
    int resN;
    int resIdx;
    Get_Entry(nome, &resN, &resIdx);

    /* Aloca e retorna uma componente de quádrupla */
    intmdt_addr_t *addr = malloc ( sizeof(intmdt_addr_t));

    if (addr == NULL) {
        fprintf(stderr, "Failed to malloc intmdt_addr_t in newtemp()\n");
        return NULL;
    }
    addr->type = TS_ENTRY;
    (addr->value).TS_idx = resIdx;
    
    return addr;
}

/* 
   Initialize the intermediate_code variable for the system.
   This function simply mallocs an intmdt_code_t and sets its
   n value to 0.
*/
intmdt_code_t *init_code() {
  intmdt_code_t *temp = malloc( sizeof( intmdt_code_t ));
  if (temp == NULL) {
    fprintf(stderr, "Error: failed to malloc intmdt_code_t in init_code()\n");
    exit(1);
  }
  temp->n = 0;
  return temp;
}

void intmdt_addr_print(intmdt_addr_t *t) {
    if (t == NULL) {
        printf("\t\t");
        return;
    }
  
    switch(t->type){
        // case symbol:
        //   printf("Symbol: %s\t", (char*) (t->addr).entry_ptr->key);
        //   break;
        // case TYPE_INT:
        //     printf("Integer: %d\t", (t->value).integer);
        //     break;
        // case TYPE_REAL:
        //     printf("Float: %f\t", (t->value).real);
        //     break;
        // case TYPE_CHAR:
        //     printf("Bool: %d\t", (t->value).character);
        //     break;
        // case code:
        //   printf("Code: %p\t", (void*) t->addr.instr_ptr);
        //   break;
        case TYPE_BOOL:
            printf("Bool: %d\t", (t->value).boolean);
            break;
        case TEMP_TYPE:
            printf("Temporario: %s\t", TabelaS[t->value.TS_idx].nome);
            break;
        case TS_ENTRY:{
            int idx = t->value.TS_idx;
            int class = TabelaS[idx].class;
            switch (class){
                case CLS_TEMP:
                    printf("Temporario: %s\t", TabelaS[idx].nome);
                    break;
                case CLS_VARIABLE:
                    printf("Variavel: %s\t", TabelaS[idx].nome);
                    break;
                case CLS_PARAM:
                    printf("Parametro: %s\t", TabelaS[idx].nome);
                    break;
                case CLS_CST:{
                    int tipo = TabelaS[idx].type;
                    switch (tipo){
                        case TYPE_INT:
                            printf("Int: %d (%s)\t", 
                                    TabelaS[idx].value.integer,
                                    TabelaS[idx].nome);
                            break;
                        case TYPE_REAL:
                            printf("Real: %f (%s)\t", 
                                    TabelaS[idx].value.real,
                                    TabelaS[idx].nome);
                            break;
                        case TYPE_CHAR:
                            printf("Char: %d (%s)\t", 
                                    TabelaS[idx].value.character,
                                    TabelaS[idx].nome);
                            break;
                        case TYPE_BOOL:
                            printf("Bool: %d (%s)\t", 
                                    TabelaS[idx].value.boolean,
                                    TabelaS[idx].nome);
                            break;
                    }
                    break;
                }
            }
        }
    }
}

void print_intmdt_code(intmdt_code_t *code) {
  printf("Intermediate Code:\n");
  printf("Op\tArg1\t\tArg2\t\tResult\n");
  unsigned int i = 0;
  while (i < code->n) {
    printf("%s\t",code->code[i]->op);
    
    intmdt_addr_print(code->code[i]->arg1);
    
    intmdt_addr_print(code->code[i]->arg2);

    intmdt_addr_print(code->code[i]->result);
    
    printf("\n");
    
    i++;
  }
}


void free_quadruple(quadruple_t *quad) {
  free (quad);
  quad = NULL;
}


void free_intmdt_code(intmdt_code_t *code) {
  unsigned int i = 0;
  while (i < code->n) {
    free_quadruple(code->code[i]);
    i++;
  }
  free(code);
  code = NULL;
}
