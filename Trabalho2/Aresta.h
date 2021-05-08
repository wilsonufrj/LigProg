#ifndef H_ARESTA
#define H_ARESTA

#include"Vertice.h"

class Aresta{
    public: 
        Aresta(Vertice*,Vertice*,double=1.0);
        Vertice* getPrimeiraPalavra();
        Vertice* getSegundaPalavra();

        void incrementaPeso();


    private:  

        double peso;
        Vertice *palavra1;
        Vertice *palavra2;
};

#endif