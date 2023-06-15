#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

tree_t *cria_arvore () {
    tree_t *arvore = malloc(sizeof(tree_t));

    if (!arvore) {
        perror("Erro ao alocar memória para a árvore.");
        exit(1);
    }

    arvore->raiz = NULL;

    return arvore;
}

void destroi_arvore (tree_t *arvore) {
    if (arvore->raiz)
        destroi_no(arvore->raiz);
    free(arvore);
}

no_t *cria_no (int chave, int tab, int pos) {
    no_t *no = malloc(sizeof(no_t));

    if (!no) {
        perror("Erro ao alocar memória para o nó.");
        exit(1);
    }

    no->chave = chave;
    no->pos = pos;
    no->tab = tab;
    no->esq = NULL;
    no->dir = NULL;
    no->pai = NULL;
    
    return no;
}

void destroi_no (no_t *no) {
    if (no->esq)
        destroi_no(no->esq);
    if (no->dir)
        destroi_no(no->dir);
    free(no);
}

no_t *insere (tree_t *arvore, no_t *no, int chave, int tab, int pos) {
    if (!no) {
        no = cria_no(chave, tab, pos);
        return no;
    }
    if (no->chave > chave) {
        no->esq = insere(arvore, no->esq, chave, tab, pos);
        no->esq->pai = no;       
    }
    else {
        no->dir = insere(arvore, no->dir, chave, tab, pos);
        no->dir->pai = no;
    }
    return no;
}

int insere_arvore (tree_t *arvore, int chave, int tab, int pos) {

    if (!arvore->raiz) {
        arvore->raiz = cria_no(chave, tab, pos);
        return 1;
    }
    else {
        insere(arvore, arvore->raiz, chave, tab, pos);
    }

    return 1;   
}

void imprime (no_t *n) {
   if (n != NULL){
        imprime(n->esq);
        printf("%d,T%d,%d\n", n->chave, n->tab, n->pos);
        imprime(n->dir);
   }
}

