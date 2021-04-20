#ifndef NACIONAL_H
#define NACIONAL_H

#include"Estadual.h"
#include"Dados.h"
#include<iostream>
#include<vector>

using namespace std;

class Nacional{

    static void fimFuncao();

    private:
        void setEstatistica();
        void setTendenciaPais();
        void setMortesPorDiasPais();
        void setMediaMovelPais();
        void setPorcentagemTendenciaPais(double);
        void printaTendencia();
        //Somente para debug
        void printaMediaMovelPais();
        void printaMortesPorDiaPais();
        int getTendenciaPais();
        double getPorcentagemTendenciaPais();
        
        Estadual estados[QUANTIDADE_ESTADO]={
            Estadual(RIO,DIAS_VERIFICADOS,"Rio"),
            Estadual(SAO_PAULO,DIAS_VERIFICADOS,"Sao Paulo"),
            Estadual(MINAS_GERAIS,DIAS_VERIFICADOS,"Minas Gerais"),
            Estadual(CEARA,DIAS_VERIFICADOS,"Ceara")
        };
        int totalBrasil;

        vector<Estadual> alta;
        vector<Estadual> estavel;
        vector<Estadual> baixa;

        vector<int> mortesPorDiaPais;
        vector<double> mediaMovelPais;

        int tendenciaPais;
        double porcentagemTendenciaPais;

        
        
    public:
        Nacional();
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

#endif
