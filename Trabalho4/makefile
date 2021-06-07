CFLAG = g++
LFLAG = -Wall

all: index.o Cadastro.o Paciente.o 
	$(CFLAG) -o main index.o Cadastro.o Paciente.o 

Cadastro.o: Cadastro.cpp Cadastro.h
	$(CFLAG) -c Cadastro.cpp

Paciente.o: Paciente.cpp Paciente.h
	$(CFLAG) -c Paciente.cpp

clean:
	rm -rf main *.o

rodar:
	./main