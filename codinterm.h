#ifndef CODINTERM_H
#define CODINTERM_H

#define MAXCODELEN 8192

#include "lists.h"
#include "aux.h"

typedef struct quadruple quadruple_t;

// union intmdt_value {
//   int TS_idx;
//   int int_const_ptr;
//   float float_const_ptr;
//   int bool_const_ptr;
//   quadruple_t *instr_ptr;
// } intmdt_value;

typedef struct {
  list_head_t *truelist;
  list_head_t *falselist;
} boolean_list_t;

typedef struct {
  // enum {symbol, TYPE_INT, TYPE_REAL, TYPE_BOOL, TYPE_CHAR, code, temp} type;
  int type;
  union value value;
  boolean_list_t* list;
} intmdt_addr_t;

/* Quádrupla */
struct quadruple {
  int n;
  char *op;
  intmdt_addr_t *arg1;
  intmdt_addr_t *arg2;
  intmdt_addr_t *result;
};

/* Guarda a lista de quádruplas (instruções geradas) */
typedef struct {
  quadruple_t *code[MAXCODELEN];
  unsigned int n; /* Qtd de instruções já feitas */
} intmdt_code_t;


int gen(intmdt_code_t *intermediate_code,
        char *op, intmdt_addr_t *arg1, intmdt_addr_t *arg2,
        intmdt_addr_t *result);

intmdt_addr_t *newtemp(int tipo);        

/*
Funções para TrueList e FalseList de booleanos
*/
int quadruple_cmp(const void *, const void *);
list_head_t *list_makelist(quadruple_t*instr_ptr);
list_head_t *list_makelist_intmt(intmdt_addr_t* intmt);
list_head_t *list_makelist_string(char* string);

list_head_t *list_merge(list_head_t *p1, list_head_t *p2);
int backpatch(list_head_t *p, quadruple_t *i);

intmdt_code_t *init_code();
void intmdt_addr_print(intmdt_addr_t *t);
void print_intmdt_code(intmdt_code_t *code);
void printQuad(quadruple_t* quad, int i);
void printList(list_head_t * lst);
void printListIntmt(list_head_t * lst);


void free_quadruple(quadruple_t *quad);
void free_intmdt_code(intmdt_code_t *code);

#endif /* CODINTERM_H */