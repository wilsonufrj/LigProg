#include<iostream>
#include"Agenda.h"

using namespace std;

int main(){

    Agenda agenda;
    Contato contato("Joao","Pedreiro",19);

    Contato contato3("Maria","Pedreiro",1);
    Contato contato4("Carla","Pedreiro",30);
    

    agenda.inserirContato(contato);
    agenda.inserirContato(contato3);
    agenda.inserirContato(contato4);
    //cout<<contato.getNome()<<endl;
    //cout<<contato2.getNome()<<endl;

    agenda.mostraContato();

    agenda.apagaContato(1);
    cout<<"Depois------------------"<<endl;
    agenda.mostraContato();



    return 0;
}