#ifndef H_GRAFO
#define H_GRAFO


#include"Aresta.h"
#include<fstream>
#include<vector>
#include<iostream>

using namespace std;

class Grafo{
    public:
        Grafo();
        void arestaComum(int);
        void insereAresta(Aresta*); //OK
        void insereVertice(Vertice*);
        //Retorna o vertice com o contador maior
        void verticePopular();

        void lerArquivo();
        void quebraLinha(string);
    private:

        fstream FILE;
        string nomeArquivo;
        vector<Aresta*> arestas;
        vector<Vertice*> vertices;
        
};

#endif