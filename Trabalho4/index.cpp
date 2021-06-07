#include"Cadastro.h"
#include<iostream>

using namespace std;

int main(){
    
    Cadastro cadastro;

    Paciente paciente("Joao");
    Paciente paciente2("Maria");
    
    cadastro.inserePaciente(paciente);
    cadastro.inserePaciente(paciente2);

    cadastro.buscaPaciente("Carlos");
      

    cadastro.buscaPaciente("Joao");

    cadastro.imprimeArvore();
    
    

    return 0;
}