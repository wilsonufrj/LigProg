#include"Cadastro.h"

void Cadastro::setIdade(int idadeIN){
    idade = idadeIN;
}

void Cadastro::setNome(string nomeIN){
    verificaTamanho(nomeIN);
    nome = nomeIN;
}
void Cadastro::setProfissao(string profissaoIN){
    verificaTamanho(profissaoIN);
    profissao = profissaoIN;
}


int Cadastro::getIdade(){return idade;}

string Cadastro::getNome(){return nome;}

string Cadastro::getProfissao(){return profissao;}

void Cadastro::verificaTamanho(string &nome){
     if(nome.size()>10){
            std::cout<<"Carateres máximo para String atingido"<<std::endl;
            nome = nome.substr(0,10);
        }
} 