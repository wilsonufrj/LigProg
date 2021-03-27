#include<string>
#include<iostream>
#include"agenda.h"

using namespace std;

void Agenda::setNames(){
    string aux;
    for(int posicao=0;posicao<3;posicao++){
        cout<<"Insira o "<< posicao+1 <<" nome"<<endl;
        getline(cin,aux);
        names[posicao] = nameValidation(aux);
    }
            
}

string Agenda::nameValidation(string name){
    if(name.length()>10){
        cout<<"Nome com mais de 10 caracteres"<<endl;
        name = name.substr(0,10);
    }

    return name;
}

void Agenda::getNames(){
     for(int i=0;i<3;i++){
                cout<<names[i]<<endl;
            }
}