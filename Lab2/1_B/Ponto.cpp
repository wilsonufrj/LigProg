#include"Ponto.h"

Ponto::Ponto(double x,double y, double z){
    setX(x);
    setY(y);
    setZ(z);
}

void Ponto::setX(double x){ 
    X =x;
}

void Ponto::setY(double y){
    Y =y;
}

void Ponto::setZ(double z){
    Z =z;
}

double Ponto::getX(){
    return X;
}

double Ponto::getY(){
    return Y;
}

double Ponto::getZ(){
    return Z;
}