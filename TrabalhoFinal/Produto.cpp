#include"Produto.h"

Produto::Produto(string nome,string nomeColecao,string descricao,float preco,int ano,string estacao):
nome(nome),nomeColecao(nomeColecao),descricao(descricao),estacao(estacao),ano(ano),preco(preco){}

ostream& operator<<(ostream& saida, Produto& produto){
    cout<<"Nome: \t\t\t"<<produto.nome<<endl<<
    "Nome Colecao: \t\t"<<produto.nomeColecao<<endl<<
    "Descricao: \t\t"<<produto.descricao<<endl<<
    "Preco: \t\t\t"<<produto.preco<<endl<<
    "Ano: \t\t\t"<<produto.ano<<endl<<
    "Estacao: \t\t"<<produto.estacao<<endl<<setw(10);

    return saida;
}

string Produto::getNome(){ return nome;}
string Produto::getNomeColecao(){ return nomeColecao;}
string Produto::getDescricao(){ return descricao;}
string Produto::getEstacao(){return estacao;}
float Produto::getPreco(){return preco;}
int Produto::getAno(){return ano;}

void Produto::setNome(string nome){this->nome=nome;}
void Produto::setNomeColecao(string nomeColecao){this->nomeColecao=nomeColecao;}
void Produto::setDescricao(string descricao){this->descricao=descricao;}
void Produto::setEstacao(string estacao){this->estacao=estacao;}
void Produto::setPreco(float preco){this->preco=preco;}
void Produto::setAno(int ano){this->ano=ano;}