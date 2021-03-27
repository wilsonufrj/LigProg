#include<iostream>
#include <string>
#include"agenda.h"

using namespace std;

int main(){

    Agenda agenda;
    
    string name;
    agenda.setNames();
    cout<<"Nomes Armazenados"<<endl;
    agenda.getNames();
    
    return 0;
}