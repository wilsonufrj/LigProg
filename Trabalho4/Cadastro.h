#ifndef CADASTRO_H
#define CADASTRO_H

#include"Paciente.h"
#include"Arvore.h"

using namespace std;

class Cadastro{
    public:
    void inserePaciente();
    void buscaPaciente();
    void imprimeArvore();

    private:
    Arvore<Paciente> arvorePaciente;
};


#endif 