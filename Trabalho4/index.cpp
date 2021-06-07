#include"Cadastro.h"
#include<iostream>

using namespace std;

int main(){
    
    Cadastro cadastro;
    string opcao;
    cout<<"SISTEMA DE CADASTRO"<<endl;
    cout<<" 1 - Insere um Paciente no Cadastro"<<endl;
    cout<<" 2 - Busca o nome de um Paciente"<<endl;
    cout<<" 3 - Imprime Pacientes"<<endl;
    cout<<" 4 - SAIR"<<endl;

    cout<<"\tSelecione uma opcao"<<endl;

    while(1){
        getline(cin,opcao);
        switch(stoi(opcao)){
            case 1:{
                //cout<<"Opcao 1 Escolhida"<<endl;
                cadastro.inserePaciente();
                break;
            }
            case 2: {
                cadastro.buscaPaciente();
                break;
            }
            case 3:{
                cadastro.imprimeArvore();
                break;
            }
            case 4:
                break;
            
            default:{
                cout<<"Opcao invalida"<<endl;
                break;
            }
        }

        if(stoi(opcao)==4){
            break;
        }
    }

    return 0;
}