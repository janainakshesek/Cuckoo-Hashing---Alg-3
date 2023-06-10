#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

#define M 11

int main () {
    char tipo;
    int chave;
    struct node *table1 = malloc(sizeof(struct node) * M);
    struct node *table2 = malloc(sizeof(struct node) * M);

    struct tables *tablesContainer = malloc(sizeof(struct tables));

    tablesContainer->table1 = table1;
    tablesContainer->table2 = table2;

    while (scanf("%c %d\n", &tipo, &chave) == 2) {
        if (tipo == 'i') {
            insert(tablesContainer, chave);
        }
        else if (tipo == 'r') {
            delete (tablesContainer, chave);
        }
        else {
            printf("Tipo de operacao invalida!\n");
        }
    }

    print(tablesContainer);

    return 0;
}