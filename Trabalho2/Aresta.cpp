#include"Aresta.h"

Aresta::Aresta(Vertice *palavra1, Vertice *palavra2,double peso){
    this->peso = peso;
    this->palavra1 = palavra1;
    this->palavra2 = palavra2; 
}

void Aresta::incrementaPeso(){
    this->peso+=1;
}

Vertice* Aresta::getPrimeiraPalavra(){return palavra1;}
Vertice* Aresta::getSegundaPalavra(){return palavra2;}