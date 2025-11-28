#include <stdio.h>
#include <stdlib.h>
#include "Lista_Ligada_Full.h"

No* criar_lista(){
    No *q;
    q = (No*) malloc(sizeof(No));
    if (q == NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    q->dado = '\0';
    q->prox = NULL;
    return q;
}

void inserir_caractere_final(No* p, char letra){
    No* aux;
    No* q;
    q = (No*) malloc(sizeof(No));
    if (q == NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    q->dado = letra;
    q->prox = NULL;

    //aux aponta para o começo da lista e percorre até seu fim
    aux = p;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = q;
}

void inserir_caractere_inicio(No* p, char letra){
    No* q;
    q = (No*) malloc(sizeof(No));
    if (q == NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    q->dado = letra;
    q->prox = p->prox;
    p->prox = q;
}

No* inserir_lista_final(No* lista1,No** lista2){
    No* q = lista1;

    while(q->prox != NULL){
        q = q->prox;
    }

    q->prox = (*lista2)->prox;

    free(*lista2);
    *lista2 = NULL;

    return lista1;
}

No* inserir_lista_inicio(No* lista1,No** lista2){
    No* p = *lista2;

    while(p->prox != NULL){
        p = p->prox;
    }

    p->prox = lista1->prox;
    lista1->prox = (*lista2)->prox;

    free(*lista2);
    *lista2 = NULL;

    return lista1;
}


void imprimir_lista(No* p){
    No* q;
    for (q = p->prox; q != NULL; q = q->prox)
        printf("%c", q->dado);
    printf("\n");
}

void destruir_lista(No** p){
    No* q;
    
    while(*p != NULL){
        q = *p;
        *p = (*p)->prox;
        free(q);
    }
}    

void remover_caracteres(No* p, char letra){
    No* q = p;
    while (q->prox != NULL){
        if (q->prox->dado == letra){
            No* aux = q->prox;
            q->prox = aux->prox;
            free(aux); 
        } else{
            q = q->prox;
        }
    }
}

void inverter_lista(No* p){
    No* q = NULL;
    No* r = p->prox;
    No* s;

    while (r != NULL){
        s = r->prox; 
        r->prox = q; //na primeira iteração garante que o primeiro membro aponte pata NULL
        q = r;
        r = s;
    }
    p->prox = q;
}
 
void substituir_letra(No* p, char a, char b){
    p = p->prox;
    while(p != NULL){
        if (p->dado == a){
            p->dado = b;
        }
    p = p->prox;
    }
}
