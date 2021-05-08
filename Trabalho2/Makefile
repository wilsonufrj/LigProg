CFLAG = g++
LFLAG = -Wall

all:	index.o Grafo.o Aresta.o Vertice.o
	$(CFLAG) -o main index.o Grafo.o Aresta.o Vertice.o

Vertice.o:	Vertice.cpp Vertice.h
	$(CFLAG) -c Vertice.cpp

Aresta.o:	Aresta.cpp Aresta.h
	$(CFLAG) -c Aresta.cpp

Grafo.o:	Grafo.cpp Grafo.h
	$(CFLAG) -c Grafo.cpp

clean:
	rm -rf main *.o

rodar:
	./main
