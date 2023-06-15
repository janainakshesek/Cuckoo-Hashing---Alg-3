CFLAGS = -Wall -std=c99 -g
LDFLAGS = -lm

CC = gcc

objects = myht.o hash.o binaryTree.o

all: myht

myht: $(objects)
	$(CC) $(CFLAGS) -o myht $(objects) $(LDFLAGS)

myht.o: myht.c 
	$(CC) $(CFLAGS) -c myht.c

hash.o: hash.c 
	$(CC) $(CFLAGS) -c hash.c

binaryTree.o: binaryTree.c
	$(CC) $(CFLAGS) -c binaryTree.c

clean:
	rm -rf $(objects) myht

purge: clean
	rm -f myht
