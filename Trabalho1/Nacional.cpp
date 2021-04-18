#include"Nacional.h"

void Nacional::mostrarNumeroObitosNacionalEstadual(){
    int totalBrasil=0;
    for(Estadual estado:estados){
            totalBrasil+=estado.somaMortes();   
            cout<<"Estado: "<<estado.getNomeEstado()
            <<"\tMortes: "<<estado.somaMortes()<<endl;
    }

    cout<<"Total de mortos no Brasil: "<<totalBrasil<<endl;
}

//RODAR NOVAMENTE PARA TESTAR ESSA FUNÇÃO
void Nacional::mostrarEstatisticasEstados(){
    for(int media:estados[0].getMediaMovel()){
        cout<<"Estado: "<<estados[0].getNomeEstado()
        <<media<<endl;
    }
}