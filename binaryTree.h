typedef struct tree {
    struct no *raiz;
} tree_t;

typedef struct no {
    int chave;
    int tab;
    int pos;
    struct no *esq, *dir, *pai;
} no_t;

tree_t *cria_arvore ();

void destroi_arvore (tree_t *arvore);

no_t *cria_no (int chave, int tab, int pos);

void destroi_no (no_t *no);

no_t *insere (tree_t *arvore, no_t *no, int chave, int tab, int pos);

int insere_arvore (tree_t *arvore, int chave, int tab, int pos);

void imprime (no_t *n);

