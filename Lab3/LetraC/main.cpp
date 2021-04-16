#include<iostream>
#include"agenda.h"

int main(){

    Agenda agenda;
    Cadastro cadastro;

    int idade;
    string nome,profissao;

     for(int i=0; i< 3;i++){

        cout<<"Nome: ";
        getline(cin,nome);
        cadastro.setNome(nome);

        cout<<"\nProfissao: ";
        getline(cin,profissao);
        cadastro.setProfissao(profissao);

        cout<<"\nIdade: ";
        cin>>idade;
        cadastro.setIdade(idade);
        cin.ignore();
        agenda.insereCadastro(cadastro);
    } 

    cout<<Agenda::numeroNomes<<endl;

    agenda.mostraCadastro();


    return  0;
}