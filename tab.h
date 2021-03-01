#pragma once
#ifndef TAB_H
#define TAB_H

#include "aux.h"

#define NMax 1000
#define TNome 20
#define TType 20
#define TValue 50

int escopo[10];
int nivel;      /* nível atual */
int L;          /* índice do último elemento da tabela */

int Raiz;       

struct{
    char nome[TNome];       /* Nome do símbolo */
    int nivel;              /* Nível do símbolo */
    int type;       /* Atributo do símbolo */
    int class;      /* Classe do símbolo */
    union value value; 
    // char value[TValue];     
    int esq;            /* Subárvore da esquerda */
    int dir;            /* Subárvore da direita */
}TabelaS[300];          /* Array que contém a tabela de Símbolos */


void Entrada_Bloco();
void Erro(int numero);
void Saida_Bloco();
void Get_Entry(char name[TNome], int* res_nivel, int* res_i);
void Instala(char name[TNome], int type, int class, union value value);
void imprimir();

#endif /* TAB */