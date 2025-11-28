#include <stdio.h>
#include <stdlib.h>
#include "Pilha_Vetor.h"

Pilha* criar_pilha(){
    Pilha* q = (Pilha*)malloc(sizeof(Pilha)); //Malloc pra pilha
    if(q == NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    q->tam = 100; //Definimos como tamanho max, mas poderia ser outro
    q->dados = (int*)malloc(q->tam * sizeof(int));
    if(q->dados == NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    q->topo = 0;

    return q;
}

void destruir_pilha(Pilha** p){
    //Desaloca o vetor dados
    free((*p)->dados);

    //Desaloca a struct pilha
    free(*p);
    *p = NULL;
}

void adiciona_pilha(Pilha** p, int x){
    if ((*p)->topo == (*p)->tam) return;

    (*p)->dados[(*p)->topo] = x;
    (*p)->topo++;
}

int topo_pilha(Pilha* p){
    if (p->topo != 0) return p->dados[p->topo-1];
    else return -1; //Pilha vazia
}

void remove_pilha(Pilha **p){
    if ((*p)->topo == 0) return; //Pilha vazia
    (*p)->topo--; //Não precisa remover, já que esse valor vai ser subescrito no futuro(lixo)
}

int tamanho_pilha(Pilha *p){
    return p->topo;
}