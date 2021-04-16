#include<iostream>
#include"agenda.h"

int main(){
    Agenda agenda(3);
    agenda.insereNome("Wilsonuhduehduehuehduehdu");
    agenda.insereNome("Caio");
    agenda.insereNome("Gabrielle");
    agenda.insereNome("Gabrielle");


    agenda.mostraNome();

    return  0;
}