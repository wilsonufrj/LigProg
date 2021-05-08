#include"Vertice.h"

Vertice::Vertice(string nome){
    this->rotulo = nome;
    contador = 0;
}

void Vertice::somaContador(){this->contador+=1;}

string Vertice::getRotulo(){return rotulo;}
int Vertice::getContador(){return contador;}