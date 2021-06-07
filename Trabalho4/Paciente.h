#ifndef PACIENTE_H
#define PACIENTE_H

#include<string>

using namespace std;

class Paciente{

   public:
    Paciente(string nome):nome(nome){};
    string getNomePaciente();

    private:
    string nome;
    int idade;
    string doenca;
};


#endif 