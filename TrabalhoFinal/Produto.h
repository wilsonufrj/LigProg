#ifndef PRODUTO_H
#define PRODUTO_H

#include<string>
#include<iostream>
#include<iomanip>

using namespace std;


class Produto{
    friend ostream& operator<<(ostream&,Produto&);

    public:
    Produto(string nome         = " ",
            string nomeColecao  = "padrao",
            string descricao    = " ",
            float preco           = 0.0,
            int ano             = 1997,
            string getEstacao     =" ");

    string getNome();
    string getNomeColecao();
    string getDescricao();
    float getPreco();
    int getAno();
    string getEstacao();

    void setNome(string);
    void setNomeColecao(string);
    void setDescricao(string);
    void setEstacao(string);
    void setPreco(float);
    void setAno(int); 

    private:
    
    string nome,nomeColecao,descricao,estacao;
    int ano;
    float preco;
};

#endif