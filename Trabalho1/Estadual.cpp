#include"Estadual.h"
#include<iostream>
#include<array>

using namespace std;

int Estadual::mortesPorDia[dias] = {1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1};

//Funcionando
int Estadual::somaMortes(){
    int total=0;
    for(int dias: mortesPorDia){
            total+=dias;
    }
    return total;
}

//So calcula a media
double Estadual::calculaMediaMovel(){
    double media;
    for(int i=0;i<diasDaMedia;i++){
            cout<<"Valor "<<mortesPorDia[(dias-1)-i]<<endl;
        media += mortesPorDia[(dias-1)-i];
    }
    cout<<"Total Media: "<<media<<endl;

    return media/3;
}