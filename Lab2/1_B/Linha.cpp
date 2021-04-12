#include"Linha.h"
#include<cmath>

Linha::Linha(Ponto ponto1,Ponto ponto2){
    point1.setX(ponto1.getX()) ;
    point1.setY(ponto1.getY()) ;
    point1.setZ(ponto1.getZ()) ;

    point2.setX(ponto2.getX()) ;
    point2.setY(ponto2.getY()) ;
    point2.setZ(ponto2.getZ()) ;
}

void Linha::setPoint1(double x, double y, double z){
    point1.setX(x);
    point1.setY(y);
    point1.setZ(z);
}

void Linha::setPoint2(double x, double y, double z){
    point2.setX(x);
    point2.setY(y);
    point2.setZ(z);
}

double Linha::getComprimento(){
    double somaX,somaY,somaZ,distance;

    somaX = pow(point1.getX()-point2.getX(),2);
    somaY = pow(point1.getY()-point2.getY(),2);
    somaZ = pow(point1.getZ()-point2.getZ(),2);

    distance= sqrt(somaX+somaY+somaZ);

    return distance;

}

