#include"Personagem.h"

Personagem::Personagem(string nome,int forca, int inteligencia){
    this->nome = nome;
    this->nivelForca = forca;
    this->inteligencia = inteligencia;
}

ostream &operator<<(ostream &output,Personagem *personagem){
    output<<"("<<personagem->nome<<", "
        << personagem->nivelForca<<", "
        << personagem->inteligencia<<")"<<endl;
    return output;
};

string Personagem::getNome(){return nome;}
int Personagem::getForca(){return nivelForca;}
int Personagem::getInteligencia(){return inteligencia;}