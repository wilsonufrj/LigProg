#include"Cadastro.h"

//FUNCIONANDO
void Cadastro::inserePaciente(){
    string nome,idade,doenca;
    
    cout<<"Insira o nome do Paciente"<<endl;
    getline(cin,nome);
    cout<<"Idade do Paciente"<<endl;
    getline(cin,idade);
    cout<<"Doenca do Paciente"<<endl;
    getline(cin,doenca);
    Paciente *paciente = new Paciente(nome,idade,doenca);
    
    No<Paciente> *auxPaciente = new No<Paciente>(paciente->getNomePaciente());
    arvorePaciente+=*auxPaciente;

    cout<<*paciente;
}

//FUNCIONANDO
void Cadastro::buscaPaciente(){
    string nome;
    cout<<"Qual o nome do paciente desejado"<<endl;
    getline(cin,nome);
    if(arvorePaciente(nome)==NULL){
        cout<<"Nome nao esta cadastrado"<<endl;
    }else
        cout<<"Acheio o paciente"<<endl;
}

//Incompleta
void Cadastro::imprimeArvore(){
    arvorePaciente.printaArvore();
}