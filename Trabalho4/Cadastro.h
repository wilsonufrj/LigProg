#ifndef CADASTRO_H
#define CADASTRO_H

#include"Paciente.h"
#include"Arvore.h"

class Cadastro{
    public:
    void inserePaciente(Paciente&);
    void buscaPaciente(string);
    void imprimeArvore();

    private:
    Arvore<Paciente> arvorePaciente;
};


#endif 