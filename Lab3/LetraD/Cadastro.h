#include<string>
#include<iostream>

using namespace std;

class Cadastro{
    public:
        void setNome(string);
        void setProfissao(string);
        void setIdade(int);

        string getNome();
        string getProfissao();
        int getIdade();

    private:
        string nome, profissao;
        int idade;
        void verificaTamanho(string&);
};