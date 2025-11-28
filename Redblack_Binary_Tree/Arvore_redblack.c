#include <stdio.h>

enum Cor {VERMELHO, PRETO};

typedef struct No{
    enum Cor cor;
    int dado;
    struct No *esq,*dir;
} No;

No* rotaciona_esq(No* p){
No* q = p->dir;

//Posição
p->dir = q->esq;
q->esq = p;

//Cor
q->cor = p->cor;
p->cor = VERMELHO;

return p;
}

No* rotaciona_dir(No* p){
    No* q = p->esq;

    p->esq = q->dir;
    q->dir = p;

    q->cor = q->cor;
    p->cor = VERMELHO; 

    return p;
}

void sobe_vermelho(No* p){
    p->cor = VERMELHO;

    p->esq->cor = PRETO;
    p->dir->cor = PRETO;
}

No* buscar_arvore(No* p, int x){
    if(p==NULL) return NULL;

    if (p->dado == x) return p;

    if(x < p->dado) return buscar_arvore(p->esq,x);
    else return buscar_arvore(p->dir,x);
}
