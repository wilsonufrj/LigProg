#ifndef CARRINHO_H
#define CARRINHO_H

#include"Produto.h"
#include<vector>
#include<iostream>

using namespace std;


class Carrinho{

    friend ostream &operator<<(ostream &, Carrinho &);

    public:
    Carrinho(int);
    Carrinho(const Carrinho&);
    ~Carrinho();
    
    Carrinho &operator+(Produto &);
    Carrinho &operator-(Produto &);

    private:
    int maxItens,cont;
    vector<Produto*> produtos;
};

#endif