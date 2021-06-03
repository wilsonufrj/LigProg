#ifndef GLOBAIS_H
#define GLOBAIS_H

#include<iostream>
#include "Jogo.h"
#include"Personagem.h"

Personagem *maisforte(Jogo &jogo){
    Personagem *maisForte;
    int forca=0;
    for(unsigned i=0;i<jogo.getNumeroPersonagens();i++){
        if(jogo[i]->getForca() >= forca){
            maisForte = jogo[i];
            forca = jogo[i]->getForca();
        }
    }

    return maisForte;
}

Personagem *maisinteligente(Jogo &jogo){
    Personagem *maisInteligente;
    int inteligencia=0;

    for(unsigned i=0;i<jogo.getNumeroPersonagens();i++){
        if(jogo[i]->getInteligencia()>=inteligencia){
            maisInteligente = jogo[i];
            inteligencia = jogo[i]->getInteligencia();
        }
    }
    return maisInteligente;
}

Personagem *calculaEstatistica(Jogo &jogo, Personagem *(*nomeFuncao)(Jogo &)){
    return (*nomeFuncao)(jogo);
}

#endif