#ifndef ESTADUAL_H
#define ESTADUAL_H

#include<vector>
#include<string>
#include<iostream>

using namespace std;
class Estadual{
    public:
        Estadual();
        Estadual(const int[],int,string);
        int somaMortes();
        double calculaMediaMovel();
        string getNomeEstado();
        vector<double> getMediaMovel();
        int getTendencia();
        double getPorcentagemTendencia();
        //Metodo de teste
        void printMediaMovel();

    private:
        int tendencia;
        double porcentagemTendencia;
        const int diasDaMedia = 3;
        //Array que define a quantidade de mortes por dia
        vector<int> mortesPorDia;
        //Array que armazena as médias moveis
        vector<double> mediaMovel;
        string nomeEstado;

        void setNomeEstado(string);
        void setMortesPorDia(const int[],int);
        void setMediaMovel();
        void setTendencia();
        void setPorcentagemTendencia(double);


};

#endif