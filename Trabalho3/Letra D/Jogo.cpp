#include"Jogo.h"

Jogo::Jogo(int maxPerson):maxPersonagens(maxPerson),cont(0),personagens(maxPerson){};

Jogo &Jogo::operator()(Personagem &personagem){
    if(cont< maxPersonagens )
        personagens.at(cont++) = &personagem;
    else cout<<"Jogo Lotado"<<endl;
    return *this;
}

Personagem *Jogo::operator[](string nome){
    for(int i=0;i<cont;i++){
        if(nome == personagens[i]->getNome()){
            return personagens.at(i);
        }
    }
    return NULL;
}

Personagem *Jogo::operator[](int numero){
    if(numero<0  || numero>cont)
        return NULL;
    else
        return personagens.at(numero);
}

unsigned int Jogo::getNumeroPersonagens(){return cont;}