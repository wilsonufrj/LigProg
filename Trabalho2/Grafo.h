#ifndef H_GRAFO
#define H_GRAFO


#include"Aresta.h"
#include<fstream>

class Grafo{
    public:
        void arestaComum();
        void insereAresta();
        void verticePopular();

        void lerArquivo();
    private:
        fstream FILE;

};

#endif