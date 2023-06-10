CFLAGS = -Wall -std=c99 -g
LDFLAGS = -lm

CC = gcc

objects = myht.o hash.o

all: myht

myht: $(objects)
	$(CC) $(CFLAGS) -o myht $(objects) $(LDFLAGS)

myht.o: myht.c 
	$(CC) $(CFLAGS) -c myht.c

hash.o: hash.c 
	$(CC) $(CFLAGS) -c hash.c

clean:
	rm -rf $(objects) myht

purge: clean
	rm -f myht
