CFLAG = g++
LFLAG = -Wall

all:	index.o Nacional.o Estadual.o
	$(CFLAG) -o main index.o Nacional.o Estadual.o

Nacional.o:	Nacional.cpp Nacional.h
	$(CFLAG) -c Nacional.cpp

Estadual.o:	Estadual.cpp Estadual.h
	$(CFLAG) -c Estadual.cpp

clean:
	rm -rf main *.o

rodar:
	./main
