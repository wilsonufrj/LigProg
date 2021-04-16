#include<array>
class Estadual{
    public:
        //Soma as mortes 
        int somaMortes();
        double calculaMediaMovel();
    private:
        const static int dias = 10;
        const int diasDaMedia = 3;
        //Array que define a quantidade de mortes por dia
        static int mortesPorDia[dias];
        //Array que armazena as médias moveis com o passar do terceiro dia
        int arrayMediasMoveis[5];
};

//Não fazer o array de morte como constante pois o sistema não será dinamico