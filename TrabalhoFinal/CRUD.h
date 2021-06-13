#ifndef CRUD_H
#define CRUD_H

#include"BD_Connection.h"

#include<string>
#include<iostream>

using namespace std;


class CRUD:public BD_Connection,public Produto{
    public:
    CRUD();

    void inserirProduto();
    void buscaProduto();
    void deletaProduto();
    void atualizaProduto();
    void buscaColecao();

    void mostraMenu();

    

};

#endif