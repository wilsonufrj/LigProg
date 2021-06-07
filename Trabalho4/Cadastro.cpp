#include"Cadastro.h"

//FUNCIONANDO
void Cadastro::inserePaciente(Paciente &paciente){
    No<Paciente> *auxPaciente = new No<Paciente>(paciente.getNomePaciente());
    arvorePaciente+=*auxPaciente;
}

//FUNCIONANDO
void Cadastro::buscaPaciente(string nome){
    if(arvorePaciente(nome)==NULL){
        cout<<"Nome nao existe na arvore"<<endl;
    }else
        cout<<"Acheio o paciente"<<endl;
}

//FUNCIONANDO
void Cadastro::imprimeArvore(){
    arvorePaciente.printaArvore();
}