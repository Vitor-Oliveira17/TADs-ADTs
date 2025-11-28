#ifndef FILA_H
#define FILA_H
#include "Lista_Circular_P_Ultimo.h"

//Dados
typedef struct Fila{
    int tam;
    No* L;
}Fila;

//Funções
Fila* criar_fila();
void destruir_fila(Fila** p);

void adicionar_fila(Fila** p, int x);
void remover_fila(Fila** p);

int topo_fila(Fila* p);
int tamanho_fila(Fila* p);


#endif