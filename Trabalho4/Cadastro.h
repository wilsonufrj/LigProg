#ifndef CADASTRO_H
#define CADASTRO_H

#include"Paciente.h"
#include"Arvore.h"
#include"Erros.h"
using namespace std;

class Cadastro{
    public:


    virtual const char* what() const throw();

    void inserePaciente();
    void buscaPaciente();
    void imprimeArvore();

    private:
    Arvore<Paciente> arvorePaciente;
};


#endif 