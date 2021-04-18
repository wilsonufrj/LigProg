#include<vector>
#include<string>
using namespace std;
class Estadual{
    public:
        Estadual(const int[],int,string);
        int somaMortes();
        double calculaMediaMovel();
        string getNomeEstado();
        vector<double> getMediaMovel();

    private:
        const int diasDaMedia = 3;
        //Array que define a quantidade de mortes por dia
        vector<int> mortesPorDia;
        //Array que armazena as médias moveis
        vector<double> mediaMovel;
        string nomeEstado;

        void setNomeEstado(string);
        void setMortesPorDia(const int[],int);
        void setMediaMovel();


};