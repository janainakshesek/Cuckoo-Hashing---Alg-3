struct node {
    int key;
    int full; 
};

struct tables {
    struct node *table1;
    struct node *table2;
};

// Função que inicializa um nó
struct node *initializeNode ();

// Função que inicializa as tabelas do hash e os nós de cada uma
struct tables *initializeTables (int size);

int hashcode1 (int key);
// Função que calcula o hashcode da primeira tabela

// Função que calcula o hashcode da segunda tabela
int hashcode2 (int key);

// Função que busca uma chave na tabela 1, se não encontrar, busca na tabela 2, se não encontrar, retorna -1
int search (struct tables *tablesContainer, int key);

// Função que insere uma chave na tabela 1, se não for possível, insere na tabela 2, não há colisão na tabela 2
void insert (struct tables *tablesContainer, int key);

// Função que deleta uma chave da tabela 1, se não for possível, deleta da tabela 2
void delete (struct tables *tablesContainer, int key);

// Função que imprime a árvore binária de cada nó da tabela 1 e da tabela 2
void printTree (struct tables *tablesContainer);

// Função que libera a memória alocada para as tabelas
void freeTables (struct tables *tablesContainer);


