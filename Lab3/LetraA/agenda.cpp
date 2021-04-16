#include"agenda.h"
#include<iostream>
#include<string>

using namespace std;

Agenda::Agenda(int max){
    maxNomes = max;
}

void Agenda::insereNome(string nome){
    if(nomes.size()>=maxNomes){
        cout<<"Nome Maximo na agenda atingido"<<endl;
    }else{
        if(nome.size()>10){
            cout<<"Carateres máximo para nome atingido"<<endl;
            nome = nome.substr(0,10);
        }
        nomes.push_back(nome);
    }
}

void Agenda::mostraNome(){
    for(auto itens:nomes)
        cout<< itens<<endl;
}