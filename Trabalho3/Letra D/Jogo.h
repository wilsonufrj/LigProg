#ifndef JOGO_H
#define JOGO_H

#include<vector>
#include<iostream>
#include"Personagem.h"

using namespace std;

class Jogo{

private:
    int maxPersonagens,cont;
    vector<Personagem*> personagens;


public:
    Jogo(int);
    Jogo &operator()(Personagem &);

    Personagem *operator[](string);
    Personagem *operator[](int);

    unsigned int getNumeroPersonagens();

};

#endif

