#ifndef PILHA_VETOR_H
#define PILHA_VETOR_H

//Dados
typedef struct Pilha{
    int topo,tam;
    int* dados;
} Pilha;

//Funções
Pilha* criar_pilha();
void destruir_pilha(Pilha** p);

void adiciona_pilha(Pilha** p, int x); //Retorna -1 se a pilha estiver cheia

int topo_pilha(Pilha* p); //Retorna -1 se a pilha estiver vazia
void remove_pilha(Pilha **p); //Retorna -1 se a pilha estiver vazia
int tamanho_pilha(Pilha *p);
#endif

