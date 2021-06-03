#ifndef PRODUTO_H
#define PRODUTO_H

#include<string>
#include<iostream>

using namespace std;



class Produto{

    friend ostream &operator<<(ostream &, Produto &);

    public:
    Produto(string nomeProduto=" ",string nomeMarca=" ", double preco=0.0);
    
    void setNomeProduto(string);
    void setNomeMarca(string);
    void setPreco(double);

    string getNomeProduto();
    string getNomeMarca();
    double getPreco();

    private:
    string nomeProduto;
    string nomeMarca;
    double preco;
};

#endif