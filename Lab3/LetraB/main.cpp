#include<iostream>
#include"agenda.h"

int main(){

    Agenda agenda;

    cout<<Agenda::numeroNomes<<endl;
    agenda.insereNome("Wilsonuhduehduehuehduehdu");

    agenda.insereNome("Caio");
    agenda.insereNome("Gabrielle");
    agenda.insereNome("Gabrielle");

    cout<<Agenda::numeroNomes<<endl;

    agenda.mostraNome();

    return  0;
}