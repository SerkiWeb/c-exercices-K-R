CC=gcc
CFLAGS=-Wall
LDFLAGS=
EXEC=main

all: $(EXEC)

main: main.o  b_tree.o nlist.o
	$(cc) -o exec main.o b_tree.o nlist.o 

main.o: main.c b_tree.h nlist.h
	$(cc) $(CFLAGS) -c main.c b_tree.h nlist.h 

nlist.o: nlist.c nlist.h
	$(cc) $(CFLAGS) -c nlist.c nlist.h

b_tree.o: b_tree.c b_tree.h
	$(cc) $(CFLAGS) -c b_tree.c b_tree.h

clean:
	rm exec

clean_all:
	rm -f *.o