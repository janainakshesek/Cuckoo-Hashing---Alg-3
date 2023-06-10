struct node {
    int key;
    int full;
    int deleted;
};

struct tables {
    struct node *table1;
    struct node *table2;
};

int hashcode1 (int key);

int hashcode2 (int key);

int search (struct tables *tablesContainer, int key);

void insert (struct tables *tablesContainer, int key);

void delete (struct tables *tablesContainer, int key);

void print (struct tables *tablesContainer);


