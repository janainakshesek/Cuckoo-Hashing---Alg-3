#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hash.h"

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
    else if (tablesContainer->table2[hash2].deleted)
        return -2;
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
    
    struct node *aux = malloc(sizeof(struct node));

    if (!tablesContainer->table1[hash1].full){
        tablesContainer->table1[hash1].key = key;
        tablesContainer->table1[hash1].full = 1;
        tablesContainer->table1[hash1].deleted = 0;

    } else {
        aux = &tablesContainer->table1[hash1];
        hash2 = hashcode2(aux->key);

        if (!tablesContainer->table2[hash2].full){
            tablesContainer->table2[hash2].key = aux->key;
            tablesContainer->table2[hash2].full = 1;
            tablesContainer->table2[hash2].deleted = 0;

            tablesContainer->table1[hash1].key = key;
            tablesContainer->table1[hash1].full = 1;
            tablesContainer->table1[hash1].deleted = 0;

        } 
    }
}

void delete (struct tables *tablesContainer, int key) {
    int searchResult = search(tablesContainer, key);

    if (tablesContainer->table2[searchResult].key == key){
        tablesContainer->table2[searchResult].full = 0;
        tablesContainer->table2[searchResult].deleted = 1;
    } else if (tablesContainer->table1[searchResult].key == key) {
        tablesContainer->table1[searchResult].full = 0;
        tablesContainer->table1[searchResult].deleted = 1;
    } 
}

void print (struct tables *tablesContainer) {

    for (int i =0; i < 11; i++) {
        if (tablesContainer->table1[i].full){
            printf("table1[%d] = %d\n", i, tablesContainer->table1[i].key);
        }
    }
    for (int i =0; i < 11; i++) {
        if (tablesContainer->table2[i].full){
            printf("table2[%d] = %d\n", i, tablesContainer->table2[i].key);
        }
    }
}
