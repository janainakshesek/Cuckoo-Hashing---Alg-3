#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

#define M 11

int main () {
    char tipo;
    int chave;
    
    struct tables *tablesContainer = initializeTables(M);

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

    printTree(tablesContainer);

    freeTables(tablesContainer);

    return 0;
}