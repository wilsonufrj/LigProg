#include<string>
#include<vector>
#include<iostream>
#include"Cadastro.h"

using namespace std;

class Agenda{
    public:
        Agenda();
        void insereCadastro(Cadastro);
        void mostraCadastro();
        static int numeroNomes;
    private:
        static const int maxNomes = 3;
        vector<Cadastro> nomes;
};