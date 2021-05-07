#ifndef H_ARESTA
#define H_ARESTA

#include<Vertice.h>

class Aresta{
    public: 
        Aresta(Vertice*,Vertice*);
    private:  
        double peso;
        Vertice *palavra1;
        Vertice *palavra2;
};

#endif