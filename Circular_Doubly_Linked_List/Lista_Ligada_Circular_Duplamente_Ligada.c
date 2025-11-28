#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista_Ligada_Circular_Duplamente_Ligada.h"

No* criar_lista(){
    return NULL;
}

void destruir_lista(No** p){
    if (*p == NULL) return; //Caso a lista seja vazia

    No* q = (*p)->prox;
    No* aux;
    while (q != *p){
        aux = q;
        q = q->prox;
        free(aux);
    }
    free(*p);
    *p = NULL;
}

void adicionar_final(No** p, char palavra[], int num){
    No* q = (No*) malloc(sizeof(No));
    if(q == NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    strcpy(q->palavra,palavra);
    q->valor = num;

    if(*p == NULL){
        *p = q;
        q->prox = q; 
        q->ant = q;
    }
    else{
        No* aux = (*p)->ant; //aux aponta para ultimo membro
        //Linka o 1º e novo membro da lista
        (*p)->ant;
        q->prox = *p;
        //Linka o ultimo com o novo membro
        aux->prox = q;
        q->ant = aux;
    }    
}

void remover_no(No** p, No** remover){
    if (*p == NULL || *remover == NULL) return;

    No* q = *remover;
    //Se há apenas 1 nó
    if(q->prox == q){
    free(q);
    *remover = NULL;
    *p = NULL;
    return;
    }

    //Caso geral
    (q->ant)->prox = q->prox;
    (q->prox)->ant = q->ant;

    if(*p==q) *p = q->prox; 
    free(q);
    *remover = NULL;
    }


No* percorre_n_anteriores(No* p, int n,int tamanho){
    for(int i = 0;i<n%tamanho;i++){
        p = p->ant;
    }
    return p;
}

No* percorre_n_proximos(No* p, int n,int tamanho){
    for(int i = 0;i<n%tamanho;i++){
        p = p->prox;
    }
    return p;
}

