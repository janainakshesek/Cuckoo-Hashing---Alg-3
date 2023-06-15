#include <stdio.h>
#include <stdlib.h>
#include "myavl.h"

tree_t *cria_arvore () {
    tree_t *tree = malloc(sizeof(tree_t));

    tree->raiz = NULL;

    return tree;
}

no_t *cria_no (int chave) {
    no_t *no = malloc(sizeof(no_t));

    no->chave = chave;
    no->esq = no->dir = no->pai = NULL;

    return no;
}

no_t *inclui (no_t *no, int chave) {
    if (no == NULL)
        return cria_no(chave);
    if (chave < no->chave) {
        no->esq = inclui(no->esq, chave);
        no->esq->pai = no;
    } else {
        no->dir = inclui(no->dir, chave);
        no->dir->pai = no;
    }
    return no;
}

void em_ordem (no_t *no) {
    if (no == NULL)
        return;
    em_ordem(no->esq);
    printf("%d ", no->chave);
    em_ordem(no->dir);
}       