#include<iostream>
#include"Linha.h"

using namespace std;

void printCoordenadas(Ponto ponto){
    static int cont=1;
    cout<<"[Impressao no."<<cont<<"] : Coordenadas de p ("<<ponto.getX()<<", "<<ponto.getY()<<", "<<ponto.getZ()<<")"<<endl;
    cont++;
}

int main(){

    Ponto ponto1;
    Ponto ponto2;

    Linha linha(ponto1,ponto2);

    printCoordenadas(ponto1);
    printCoordenadas(ponto1);

    cout<<"Distancia entre os atuais pontos eh: "<<linha.getComprimento()<<endl;

    return 0;
}