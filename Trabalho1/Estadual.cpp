#include"Estadual.h"
#include<iostream>

using namespace std;

Estadual::Estadual(const int vetorMortes[],int quantidadeDias,string nome){
    setMortesPorDia(vetorMortes,quantidadeDias);
    setNomeEstado(nome);
    setMediaMovel();
}

//Funcionando
int Estadual::somaMortes(){
    int total=0;
    for(int dias: mortesPorDia){
            total+=dias;
    }
    return total;
}

void Estadual::setMortesPorDia(const int mortes[], int quantidade){
    for(int i=0;i<quantidade;i++){
        mortesPorDia.push_back(mortes[i]);
    }
}

void Estadual::setMediaMovel(){
    mediaMovel.push_back(mortesPorDia[1]);
    mediaMovel.push_back((mortesPorDia[1]+mortesPorDia[2])/2);
    for(int unsigned i=2; i<mortesPorDia.size();i++){
        double media = (mortesPorDia[i-2]+mortesPorDia[i-1]+mortesPorDia[i])/3;
        mediaMovel.push_back(media);
    }
}

void Estadual::setNomeEstado(string nome){
    nomeEstado = nome;
}

string Estadual::getNomeEstado(){return nomeEstado;}
vector<double> Estadual::getMediaMovel(){return mediaMovel;}