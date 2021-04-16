#include<string>
#include<array>

using namespace std;

class Agenda{
    public:
        Agenda();
        void insereNome(string);
        void mostraNome();
        static int numeroNomes;
    private:
        static const int maxNomes = 10;
        array<string,maxNomes> nomes;
};