#include<iostream>

#include"Paralelepipedo.h"

using namespace std;

int main(){
    double x,y,z;
    cout<<"Insira os valores de Largura, altura e profundidade respectivamente";
    cin>>x;
    cin>>y;
    cin>>z;

    Paralelepipedo bloco(x,y,z);

    cout<<"O volume inicial eh de : "<<bloco.getVolume()<<endl;

    bloco.setX(-1.0);
    bloco.setY(-2);
    bloco.setZ(-4);

    cout<<"Volume atualizado : "<<bloco.getVolume()<<endl;

    bloco.setX(1.0);
    bloco.setY(2.6);
    bloco.setZ(8.2);

    cout<<"Volume atualizado : "<<bloco.getVolume()<<endl;

    return 0;
}