CFLAG = g++
LFLAG = -Wall

all: index.o Cadastro.o 
	$(CFLAG) -o main index.o Cadastro.o 

Cadastro.o: Cadastro.cpp Cadastro.h
	$(CFLAG) -c Cadastro.cpp

clean:
	rm -rf main *.o

rodar:
	./main