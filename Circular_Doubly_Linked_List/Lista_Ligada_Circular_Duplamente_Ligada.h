#ifndef LISTA_LIGADA_CIRCULAR_DUPLAMENTE_LIGADA_H
#define LISTA_LIGADA_CIRCULAR_DUPLAMENTE_LIGADA_H

// Dados
typedef struct no {
    struct no* ant;
    char palavra[31];
    int valor;
    struct no* prox;
    } No;

//Funções
No* criar_lista();
void destruir_lista(No** p);

void adicionar_final(No** p, char palavra[], int num);
void remover_no(No** p, No** remover);

No* percorre_n_anteriores(No* p, int n,int tamanho);
No* percorre_n_proximos(No* p, int n,int tamanho);

#endif