#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir, *pai;
} no_t;

typedef struct tree {
    struct no *raiz;
} tree_t;

tree_t *cria_arvore();

no_t *cria_no(int chave);

no_t *inclui (no_t *no, int chave);

