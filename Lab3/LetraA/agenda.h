#include<vector>
#include<string>

using namespace std;

class Agenda{
    public:
        Agenda(int);
        void insereNome(string);
        void mostraNome();
    private:
        long unsigned int maxNomes;
        vector<string> nomes;
};