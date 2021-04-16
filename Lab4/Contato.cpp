#include"Contato.h"

Contato::Contato(string nome,string profissao, int idade){
    setNome(nome);
    setProfissao(profissao);
    setIdade(idade);
}

void Contato::setNome(string nomeIN){nome = nomeIN;}
void Contato::setProfissao(string profissaoIN){ profissao = profissaoIN;}
void Contato::setIdade(int idadeIN){idade = idadeIN;}

string Contato::getNome(){return nome;}
string Contato::getProfissao(){return profissao;}
int Contato::getIdade(){return idade;}
