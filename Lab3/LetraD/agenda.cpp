#include"agenda.h"

using namespace std;

int Agenda::numeroNomes = 0;

Agenda::Agenda(){
}

void Agenda::insereCadastro(Cadastro cadastro){
    if(numeroNomes>=maxNomes){
        cout<<"Nome Maximo na agenda atingido"<<endl;
    }else{  
        nomes.push_back(cadastro);
        numeroNomes++;
    }
}

void Agenda::mostraCadastro(){
    for(auto itens:nomes){
        cout<<"\nNome: "+itens.getNome()+
        "\t Profissao: "+itens.getProfissao()+
        "\t Idade: "<< itens.getIdade();
    }
        
}