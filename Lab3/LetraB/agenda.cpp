#include"agenda.h"
#include<iostream>
#include<string>

using namespace std;

int Agenda::numeroNomes = 0;

Agenda::Agenda(){
}

void Agenda::insereNome(string nome){
    if(numeroNomes>maxNomes){
        cout<<"Nome Maximo na agenda atingido"<<endl;
    }else{
        if(nome.size()>10){
            cout<<"Carateres máximo para nome atingido"<<endl;
            nome = nome.substr(0,10);
        }
        nomes[numeroNomes] = nome;
        numeroNomes++;
    }
}

void Agenda::mostraNome(){
    for(auto itens:nomes)
        cout<< itens<<endl;
}