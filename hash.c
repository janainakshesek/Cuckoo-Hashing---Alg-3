#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hash.h"
#include "binaryTree.h"

struct node *initializeNode () {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->full = 0;
    newNode->key = 0;
    
    return newNode;
}

struct tables *initializeTables (int size) {
    struct node *table1 = malloc(sizeof(struct node) * size);
    struct node *table2 = malloc(sizeof(struct node) * size);

    struct tables *tablesContainer = malloc(sizeof(struct tables));

    tablesContainer->table1 = table1;
    tablesContainer->table2 = table2;

    for (int i = 0; i < size; i++) {
        tablesContainer->table1[i] = *initializeNode();
        tablesContainer->table2[i] = *initializeNode();
    }

    return tablesContainer;
}

int hashcode1 (int key) {
    return key % 11;
}

int hashcode2 (int key) {
    return floor(11 * (key * 0.9 - floor(key * 0.9)));
}

int search (struct tables *tablesContainer, int key) {
    int hash1 = hashcode1(key);
    int hash2 = hashcode2(key);

    if (tablesContainer->table1[hash1].key == key)
        return hash1;
    else {
        if (tablesContainer->table2[hash2].key == key){
            return hash2;
        } else {
            return -1;
        }
    }
}

void insert (struct tables *tablesContainer, int key) {
    int hash1, hash2;

    hash1 = hashcode1(key);
    
    struct node *aux = initializeNode();

    if (!tablesContainer->table1[hash1].full){
        tablesContainer->table1[hash1].key = key;
        tablesContainer->table1[hash1].full = 1;
    } else {
        aux = &tablesContainer->table1[hash1];
        hash2 = hashcode2(aux->key);

        if (!tablesContainer->table2[hash2].full){
            tablesContainer->table2[hash2].key = aux->key;
            tablesContainer->table2[hash2].full = 1;

            tablesContainer->table1[hash1].key = key;
            tablesContainer->table1[hash1].full = 1;
        } 
    }
}

void delete (struct tables *tablesContainer, int key) {
    int searchResult = search(tablesContainer, key);

    if (searchResult == -1){
        return;
    } else if (tablesContainer->table2[searchResult].key == key){
        tablesContainer->table2[searchResult].full = 0;
    } else if (tablesContainer->table1[searchResult].key == key) {
        tablesContainer->table1[searchResult].full = 0;
    } 
}

void printTree (struct tables *tablesContainer) {
    tree_t *arvore = cria_arvore();

    for (int i =0; i < 11; i++) {
        if (tablesContainer->table1[i].full){
            insere_arvore(arvore, tablesContainer->table1[i].key, 1, i);
        }
    }
    for (int i =0; i < 11; i++) {
        if (tablesContainer->table2[i].full){
            insere_arvore(arvore, tablesContainer->table2[i].key, 2, i);
        }
    }

    imprime(arvore->raiz);
    destroi_arvore(arvore);
}

void freeTables (struct tables *tablesContainer) {
    free(tablesContainer->table1);
    free(tablesContainer->table2);
    free(tablesContainer);
}