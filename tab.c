#include <string.h>
#include <stdio.h>

#include "tab.h"


extern int escopo[10];
extern int nivel;      /* nível atual */
extern int L;          /* índice do último elemento da tabela */

extern int Raiz;       

// int main(){
//     L = 1;                  /* Primeira posição da tabela é 1. 
//                                L é o final da árvore */
//     nivel = 1;              /* Primeiro nível é 1 */
//     escopo[nivel] = 0;      /* escopo[1] contém o indice do primeiro elemento */
//     return 0;
// }

void Erro(int num){
    char opcao;
    switch (num){
        case 1:{
            printf("Tabela cheia\n");
            break;
        }
        case 2:{
            printf("Item não encontrado\n");
            break;
        }
        case 3:{
            printf("Item já está na tabela\n");
            break;
        }
    }
}

void Entrada_Bloco(){
    nivel++;
    if (nivel > NMax)
        Erro(1);
    else
        escopo[nivel] = 0;
}

void Saida_Bloco(){
    if(escopo[nivel] != 0)
        L = escopo[nivel];
    nivel--;
}

/*
Implementando manualmente a função depreciada strcmpi
*/
int strcmpi(const char *__s1, const char *__s2){
    int res = strcmp(__s1, __s2);
    if (res == 0){
        return 0;
    }else{
        if (strlen(__s1) < strlen(__s2)){
            return -1;
        }else{
            return 1;
        }
    }
}

/*
Pesquisa o símbolo 'x' e retorna o índice da Tabela de Símbolos onde ele se 
encontra
*/
void Get_Entry(char x[10]){
    int n, k, aux, achou;
    achou = 0;
    n = nivel;
    // Enquanto tiver níveis (árvores) para explorar
    while ((n > 0) && (achou == 0)){
        k = escopo[n];
        // Explore em cada árvore (do nível mais alto para o mais baixo)
        while ((k != 0) && (achou == 0)){
            aux = strcmpi(x, TabelaS[k].nome);
            if (aux == 0)
                achou = 1;
            else if (aux < 0)
                k = TabelaS[k].esq;
            else
                k = TabelaS[k].dir;
        }
        n--;
    }

    if (achou == 1){
        printf("O item está no nível: %d", TabelaS[k].nivel);
        printf("               Indice: %u", k);
    }else{
        Erro(2);
    }
}

void Instala(char X[10], char atribut[10]){
    int S, i, k, aux;
    aux = 1;
    S = escopo[nivel];

    while (S != 0){
        // Enquanto não achar um nó folha
        i = S;
        aux = strcmpi(X, TabelaS[S].nome);
        if (aux == 0){
            S = 0;
            Erro(3);
        }else if (aux < 0)
            S = TabelaS[S].esq;
        else 
            S = TabelaS[S].dir;
    }

    if ((L < NMax + 1) && (aux != 0)){
        // Cria o novo nó
        TabelaS[L].nivel = nivel;
        // Copia o atributo passado
        aux = strlen(atribut);
        for (k = 0; k <= aux-1; k++)
            TabelaS[L].atributo[k] = atribut[k];
        // Filhos inicializados vazios
        TabelaS[L].esq = 0;
        TabelaS[L].dir = 0;
        // Copia o nome passado
        aux = strlen(X);
        for(k = 0; k <= aux-1; k++)
            TabelaS[L].nome[k] = X[k];
        
        if (escopo[nivel] == 0)
            escopo[nivel] = L;
        else if (X > TabelaS[i].nome)
            TabelaS[i].esq = L;
        else
            TabelaS[i].dir = L;
        L++;
    }
}

void imprimir(){
    int i;
    for (i = 1; i <= L-1; i++){
        printf("\n\n");
        printf("Nome : %s\n", TabelaS[i].nome);
        printf("Atributo : %s\n", TabelaS[i].atributo);
        printf("Nivel : %i\n",TabelaS[i].nivel);
        printf("Esquerdo : %i\n",TabelaS[i].esq);
        printf("Direito : %i\n",TabelaS[i].dir);
        printf("\n");
    }
}

