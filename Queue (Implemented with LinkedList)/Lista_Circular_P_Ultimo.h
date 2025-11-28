#ifndef LISTA_CIRCULAR_P_ULTIMO_H
#define LISTA_CIRCULAR_P_ULTIMO_H

//Dados
typedef struct No{
    int dado;
    struct No* prox;
} No;

//Funções
No* criar_lista(); //Lista ligada circular com ponteiro no ultimo elemento
void destruir_lista(No** p);

void adicionar_final(No** p,int x);

int acessa_primeiro(No* p);
void remover_inicio(No** p);


#endif