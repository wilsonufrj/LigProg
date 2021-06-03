CFLAG = g++
LFLAG = -Wall

all: index.o Catalogo.o Principais.o
	$(CFLAG) -o main index.o Catalogo.o Principais.o

Catalogo.o: Catalogo.cpp Catalogo.h
	$(CFLAG) -c Catalogo.cpp

Principais.o: Principais.cpp Principais.h
	$(CFLAG) -c Principais.cpp

clean:
	rm -rf main *.o

rodar:
	./main