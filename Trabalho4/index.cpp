#include"Cadastro.h"
#include"No.h"
#include"Arvore.h"
#include<iostream>

using namespace std;

class Paciente{
    public:
    Paciente(string nome):nome(nome){};
    private:
    string nome;
};

int main(){
    
    No<Paciente> paciente("Gabrielle");
    No<Paciente> paciente2("Caio");
    No<Paciente> paciente3("Bruna");
    No<Paciente> paciente4("Wilson");
    No<Paciente> paciente5("Zambeze");



    Arvore<Paciente> arv("Teste");
    

    //Teste para o template No
    /* string var2 = "From de other side";
    string *ptr2 = &var2;

    noInt.setEsq(ptr);
    noInt.setDir(ptr2);

    cout<<noInt.getValor()<<endl;
    if(noInt.getEsq()!=NULL){
        cout<<"Endereco: "<<noInt.getEsq()<<endl<<
        "Valor: "<< *noInt.getEsq()<<endl;
    }

    if(noInt.getDir()!=NULL){
        cout<<"Endereco: "<<noInt.getDir()<<endl<<
        "Valor: "<< *noInt.getDir()<<endl;
    } */

    arv+=paciente;
    arv+=paciente2;
    arv+=paciente3;
    arv+=paciente4;
    arv+=paciente5;

    
    /* cout<<"Raiz: "<<arv.getRaiz()->getValor()<<endl<<
    "No esquerdo: "<<*arv.getEsq()<<endl; */

    arv.printaArvore();

    return 0;
}