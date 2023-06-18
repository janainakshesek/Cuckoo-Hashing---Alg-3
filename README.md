# Cuckoo-Hashing---Alg-3

Aluna: Janaína Saldiva Kshesek
GRR: 20224892

# OBJETIVO

    O principal objetivo do trabalho é a implementação de uma estrutura de Cuckoo Hashing, a fim de um maior entendimento sobre o funcionamento da mesma. O relatório visa demonstrar os métodos que foram utilizados na implementação do Cuckoo Hashing, explicando a escolha de determinados tipos de estrutura, além de comentar dificuldades no processo de criação.

# ALGORITMO E PRINCIPAIS FUNÇÕES DO CUCKOO HASHIGNG

    O cuckoo hashing consiste numa técnica que visa resolver o problema da colisão em tabelas de hash. O cuckoo hashing impementado no trabalho possui duas funções de hash, que determinam a posição onde cada elemento será inserido. 

    A implementação foi feita utilizando uma struct "node" que guarda a chave e a informação se o nodo está cheio ou vazio, essa struct representa cada campo ("nicho") da tabela. Há mais uma struct que guarda as duas tabelas a serem utilizadas, elas são do tipo "node", já que serão vetores de nodos.

    No arquivo hash.c "constam" as funções utilizadas pelo cuckoo hash. Há 4 funções auxiliares, 2 cujo objetivo é apenas a inicialização dos nodos e das tabelas, sendo elas "initializeNode" e "initializeTables", 1 cujo objetivo é liberação de memória "freeTables" e a função de impressão, "printTree". Há também as duas funções de hash, cujo objetivo é o cálculo das posições dos elementos. Além disso, há as demais funções: inserir, excluir e buscar. 

    -- Função "insert": o objetivo dessa função é, a partir de uma chave informada, calcular a posição em que deve ser colocado o elemento. Primeiro, calcula a posição usando a função hashcode1, verifica se a posição está ocupada a partir do campo "full" da struct. Se estiver ocupada, cria um nodo auxiliar que recebe a chave que está na posição [hash1], depois, insere a chave nova nessa posição [hash1] e coloca a chave do nodo auxiliar na posição [hash2]. Se há chave duplicada apenas ignora.

    -- Função "delete: o objetivo dessa função, é a partir de uma chave informada, buscar a posição da chave utilizando a função busca e marcar como vazio o nodo, caso o valor não exista, apenas retorna.

    -- Função "search: o objetivo dessa função é, a partir de uma chave informada, retornar a posição. Primeiro, busca na tabela 1, se não encontrar, busca na tabela 2 e, caso não exista, retorna -1.

# ORGANIZAÇÃO DO CÓDIGO

    O código foi separado em myht.c sendo o main, hash.c e hash.h contendo as funções do cuckoo hashing e arvore.c e arvore.h, as funções que auxiliam na impressão, que foi feita a partir da função "emordem" usando árvore binária.

# CONCLUSÃO

    A partir desse trabalho foi possível um maior entendimento do funcionamento do cuckoo hashing e do hash em si. Como funciona a questão da colisão e como essa técnica resolve esse problema.