#include"Paciente.h"


Paciente::Paciente(string nome,string idade,string doenca):
    nome(nome),idade(idade),doenca(doenca){}

ostream& operator<<(ostream& saida,Paciente &paciente){
    cout<<"Nome: "<<paciente.getNomePaciente()<<endl<<
    "Idade: "<<paciente.getIdade()<<endl<<
    "Doenca: "<<paciente.getDoenca()<<endl;
    return saida;
}






string Paciente::getNomePaciente(){return nome;}
string Paciente::getIdade(){return idade;}
string Paciente::getDoenca(){return doenca;}
