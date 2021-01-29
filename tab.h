#pragma once
#ifndef TAB_H
#define TAB_H

#define NMax 1000

int escopo[10];
int nivel;      /* nível atual */
int L;          /* índice do último elemento da tabela */

int Raiz;       

struct{
    char nome[10];      /* Nome do símbolo */
    int nivel;          /* Nível do símbolo */
    char atributo[10];  /* Atributo do símbolo */
    int esq;            /* Subárvore da esquerda */
    int dir;            /* Subárvore da direita */
}TabelaS[300];          /* Array que contém a tabela de Símbolos */


void Entrada_Bloco();
void Erro(int numero);
void Saida_Bloco();
void Get_Entry(char name[10]);
void Instala(char name[10], char atributo[10]);
void imprimir();

#endif /* TAB */