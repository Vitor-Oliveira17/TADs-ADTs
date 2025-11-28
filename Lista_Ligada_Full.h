#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

// Dados
typedef struct no {
    char dado;
    struct no* prox;
    } No;
    
// Funções
No* criar_lista(); // Use No* L = criar_lista();
void destruir_lista(No** p);

void inserir_caractere_inicio(No* p, char letra);
void inserir_caractere_final(No* p, char letra);

No* inserir_lista_final(No* lista1,No** lista2); //Entre &lista2
No* inserir_lista_inicio(No* lista1,No** lista2); //Entre &lista2

void remover_caracteres(No* p, char letra);

void imprimir_lista(No* p);

void inverter_lista(No* p);
void substituir_letra(No* p, char a, char b);

#endif