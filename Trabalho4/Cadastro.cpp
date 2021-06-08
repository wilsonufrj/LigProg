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
    //ESTRANHO
    if((arvorePaciente+=*auxPaciente)==NULL){
        throw Erros();
    };
    cout<<"--------DADOS CADASTRADOS---------"<<endl;
    cout<<*paciente;
}

//FUNCIONANDO 
void Cadastro::buscaPaciente(){
    string nome;
    cout<<"Qual o nome do paciente desejado"<<endl;
    getline(cin,nome);
    if(arvorePaciente(nome)==NULL){
        throw Erros();
    }else
        cout<<*arvorePaciente(nome)<<endl;
    
    
}

//Incompleta
void Cadastro::imprimeArvore(){
    arvorePaciente.printaArvore();
}

const char* Cadastro::what()const throw(){
    return "Erro na execucao da funcao";
}