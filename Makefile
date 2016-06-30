CC=g++
CFLAGS= -c -Wall

all:btree

btree:  lerArquivo.o main.o
		$(CC) main.o lerArquivo.o -o btree.exe
main.o: main.cpp
		$(CC) $(CFLAGS) main.cpp

lerArquivo.o: lerArquivo.cpp
		$(CC) $(CFLAGS) lerArquivo.cpp

clean:
	rm -rf *.o btree.exe
