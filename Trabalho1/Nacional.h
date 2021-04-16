#include"Estadual.h"
//Porque usar o arrray? O numero de estados brasileiros não mudam
#include<array>

using namespace std;

class Nacional{

    private:
    static const int numeroEstados = 26;
    array<Estadual,numeroEstados> estados;

    public:
    //Mostra media movel no brasil e nos estados individualmente
    void mostrarEvolucaoObitoNacionalEstadual();
    //Mostra quais estados estão com a média móvel alta, em estabilidade ou em alta
    void mostrarEstatisticasEstados();
    //Mostra se o Brasil esta com a media movel alta,em estabilidade ou em alta
    void mostratEstatisticaBrasil();
    //Mostra os estados com as maiores ou com a maior alta, e baixa de acordo com
    // a media móvel
    void estadosLimites();
    //Mostra a quantidade de obitos de todos os dias no brasil
    // e nos estados individualmente
    void mostrarNumeroObitosNacionalEstadual();
};


