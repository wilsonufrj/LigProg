#include"Paralelepipedo.h"
#include<iostream>

using namespace std;

Paralelepipedo::Paralelepipedo(double x,double y, double z){
    setX(x);
    setY(y);
    setZ(z);

}

void Paralelepipedo::setX(double largura){
    if(largura<=0){
        cout<<"Valor menor ou igual a zero"<<endl;
        x = 1;
    }
    else
        x = largura;
}

void Paralelepipedo::setY(double altura){
    if(altura<=0){
        cout<<"Valor menor ou igual a zero"<<endl;
        y = 1;
       
    }
    else
        y = altura;
}

void Paralelepipedo::setZ(double profundidade){
    if(profundidade<=0){
        cout<<"Valor menor ou igual a zero"<<endl;
        z = 1;
    }
    else
        z = profundidade;
}

inline double Paralelepipedo::computeVolume(double altura,double largura,double profundidade){
    return altura*largura*profundidade;
}

double Paralelepipedo::getVolume(){
    return computeVolume(x,y,z);
}