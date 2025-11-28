#include <stdio.h>
#include <stdlib.h>
#include "Lista_Circular_P_Ultimo.h"   

No* criar_lista(){
    return NULL;
}

void adicionar_final(No** p,int x){
    No* q = (No*)malloc(sizeof(No));
    q->dado = x;

    if (*p == NULL){ //Nenhum elemento na lista
        *p = q;
        q->prox = q;
    }
    else{
        No* aux = (*p)->prox;
        (*p)->prox = q;
        q->prox = aux;
        *p = q;
    }
}

void destruir_lista(No** p){
    if(*p == NULL)return; // Se a lista ja for vazia

    if(*p == (*p)->prox){ // Se a lista tiver 1 unico elemento
        free(*p);
        *p = NULL;
        return;
    }

    No* q = (*p)->prox;
    No* aux = q->prox;

    while(q != *p){
        free(q);
        q = aux;
        aux = aux->prox;
    }
    free(*p);
    *p = NULL;
}

int acessa_primeiro(No* p){
    if (p == NULL) return -1;

    No* q = p->prox;
    return q->dado;
}

void remover_inicio(No** p){
    if (*p == NULL) return; //Lista vazia

    No* q = *p;
    if (q->prox == q){ //1 Nó
        free(q);
        *p = NULL;
        return;
    }
    q = q->prox;
    (*p)->prox = q->prox;
    free(q);
}
