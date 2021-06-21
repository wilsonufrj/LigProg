CFLAGS = g++
LFLAGS = -Wall

all:	main.o BD_Connection.o CRUD.o Produto.o
	$(CFLAGS)  -o main main.o BD_Connection.o CRUD.o Produto.o -lmysqlcppconn

BD_Connection.o:	BD_Connection.h BD_Connection.cpp
	$(CFLAGS) -c BD_Connection.cpp 

CRUD.o:	CRUD.h CRUD.cpp
	$(CFLAGS)  -c CRUD.cpp

Produto.o:	Produto.h Produto.cpp
	$(CFLAGS) -c Produto.cpp

clean:
	rm -f *.o main

rodar:
	./main