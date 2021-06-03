#ifndef CATALOGO_H
#define CATALOGO_H

#include<string>
#include<vector>
#include<cstring>
#include<iostream>

using namespace std;

typedef struct{
    string nome="";
    string nomeProdutora="";
    double nota=0;
}Filme;

 bool operator==(const Filme*,const Filme&);
 bool operator<(const Filme*, const Filme&);

  ostream&operator<<(ostream&,Filme&);
  istream&operator>>(istream&,Filme&);

class Catalogo{
    //Impressao Catalogo
    friend ostream&operator<<(ostream &,Catalogo &);
   
    public:
    Catalogo(int=0);
    ~Catalogo();
    Catalogo &operator+=(Filme &);
    Catalogo &operator+=(vector<Filme> &);

    Catalogo &operator-=(Filme&);
   
    Filme *operator()(const string);
    Filme *operator()(const string,string);
    Filme *operator()(const string, double);

    void melhorFilme();
    void reposicionaElemento(unsigned);
    void ordenaVetor();
    
    vector<Filme*> filmes;
    unsigned maxTamanho,cont;

    private:

};

#endif