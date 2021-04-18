#include"Estadual.h"
#include"Dados.h"
#include<iostream>

using namespace std;

class Nacional{

    private:
        Estadual estados[QUANTIDADE_ESTADO]={
            Estadual(RIO,DIAS_VERIFICADOS,"Rio"),
            Estadual(SAO_PAULO,DIAS_VERIFICADOS,"Sao Paulo"),
            Estadual(MINAS_GERAIS,DIAS_VERIFICADOS,"Minas Gerais")
        };

    public:
        //Mostra media movel no brasil e nos estados individualmente
        void mostrarEvolucaoObitoNacionalEstadual();
        //Mostra quais estados estão com a média móvel alta, em estabilidade ou em alta
        void mostrarEstatisticasEstados();
        //Mostra se o Brasil esta com a media movel alta,em estabilidade ou em alta
        void mostrarEstatisticaBrasil();
        //Mostra os estados com as maiores ou com a maior alta, e baixa de acordo com
        // a media móvel
        void estadosLimites();
        //Mostra a quantidade de obitos de todos os dias no brasil
        // e nos estados individualmente
        void mostrarNumeroObitosNacionalEstadual();
};


