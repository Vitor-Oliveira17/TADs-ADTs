#include <stdio.h>
#include <stdlib.h>
#include "Lista_Circular_P_Ultimo.h"
#include "Fila.h"

Fila* criar_fila(){
    Fila *p = (Fila*)malloc(sizeof(Fila));
    if (p == NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    p->tam = 0;
    p->L = criar_lista(); //Aponta L para uma lista circular
    return p;
}

void destruir_fila(Fila** p){
    //Destroi L;
    destruir_lista(&((*p)->L));

    //Destroi o resto da fila
    free(*p);
    *p = NULL;
}

void adicionar_fila(Fila** p, int x){
    adicionar_final(&((*p)->L),x);
    (*p)->tam++;
}


int topo_fila(Fila* p){
    return acessa_primeiro(p->L);
}

void remover_fila(Fila** p){
    remover_inicio(&((*p)->L));
    (*p)->tam--;
}

int tamanho_fila(Fila* p){
    return p->tam;
}