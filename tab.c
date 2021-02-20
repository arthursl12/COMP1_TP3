#include <string.h>
#include <stdio.h>

#include "tab.h"

extern int escopo[10];
extern int nivel;      /* nível atual */
extern int L;          /* índice do último elemento da tabela */
extern int Raiz;       

/* Código que inicializa a tabela, deve ser colocado no main */
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
Pesquisa o símbolo 'x' e retorna o índice da Tabela de Símbolos onde ele se 
encontra nos parâmetros passados
*/
void Get_Entry(char x[TNome], int* res_nivel, int* res_i){
    int n, k, aux, achou;
    achou = 0;
    n = nivel;
    // Enquanto tiver níveis (árvores) para explorar
    while (n > 0){
        k = escopo[n];

        // Explore em cada árvore (do nível mais alto para o mais baixo)
        while ((k != 0) && (achou == 0)){
            aux = strcmp(TabelaS[k].nome, x);
            if (aux == 0){
                achou = 1;
                n = 0;
                break;
            }
            else if (x < TabelaS[k].nome) 	
                k = TabelaS[k].esq;
			else 
                k = TabelaS[k].dir;
        }
        n--;
    }


    if (achou == 1){
        *res_nivel =  TabelaS[k].nivel;
        *res_i = k;
        // printf("Encontrado %s. ", TabelaS[k].nome);
        // printf("O item está no nível: %d", TabelaS[k].nivel);
        // printf(", indice: %u\n", k);
    }else{
        Erro(2);
        *res_nivel =  -1;
        *res_i = -1;
    }
}

void Instala(char X[TNome], int type, union value value){
    int S, i, k, aux;
    aux = 1;
    S = escopo[nivel];
    i = S;

    while (S != 0){
        // Enquanto não achar um nó folha
        i = S;
        aux = strcmp(TabelaS[S].nome, X);
        if (aux == 0){
            S = 0;
            Erro(3);
        }else if (X <TabelaS[S].nome)  
            S = TabelaS[S].esq;
		else 
            S = TabelaS[S].dir;
    }
    if (L >= NMax + 1)	
        Erro(1);
    else{
        // Cria o novo nó
        // Copia o nível passado
        TabelaS[L].nivel = nivel;
        // Copia o nome passado
        aux = strlen(X);
        for(k = 0; k <= aux-1; k++)
            TabelaS[L].nome[k] = X[k];
        // Copia o type passado
        TabelaS[L].type = type;
        // aux = strlen(type);
        // for (k = 0; k <= aux-1; k++)
        //     TabelaS[L].type[k] = type[k];
        // Copia o value passado
        TabelaS[L].value = value;
        // aux = strlen(value);
        // for (k = 0; k <= aux-1; k++)
        //     TabelaS[L].value[k] = value[k];
        // Filhos inicializados vazios
        TabelaS[L].esq = TabelaS[L].dir = 0;

        if (escopo[nivel] == 0){
            escopo[nivel] = L;
        }else if (X < TabelaS[i].nome){
            TabelaS[i].esq = L;
        }else{
            TabelaS[i].dir = L;
        }
        L++;
    }
    // imprimir();
}

void imprimir(){
    int i;
    for (i = 1; i <= L-1; i++){
        printf("\n\n");
        printf("Nome : %s\n", TabelaS[i].nome);
        printf("Tipo : %i\n", TabelaS[i].type);
        printf("Valor : %i, %f, %c, %i\n", 
                    TabelaS[i].value.integer,
                    TabelaS[i].value.real,
                    TabelaS[i].value.character,
                    TabelaS[i].value.boolean);
        printf("Nivel : %i\n",TabelaS[i].nivel);
        printf("Esquerdo : %i\n",TabelaS[i].esq);
        printf("Direito : %i\n",TabelaS[i].dir);
        printf("\n");
    }
}

