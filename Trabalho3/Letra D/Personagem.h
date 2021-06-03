#ifndef PERSONAGENS_H
#define PERSONAGENS_H

#include<string>
#include<iostream>
using namespace std;

class Personagem
{

    friend ostream &operator<<(ostream &,Personagem*);

private:
    string nome;
    int nivelForca,inteligencia;
public:
    Personagem(string,int,int);

    string getNome();
    int getForca();
    int getInteligencia();


};

#endif

