#include<iostream>
#include<string>
#include"Nacional.h"

using namespace std;

int main(){
    cout<<"\t\tBem-vindo a Estatísticas COVID-2021\n"<<endl;
    cout<<"\t                        MENU                           "<<endl;
    cout<<"\t|------------------------------------------------------|"<<endl;
    cout<<"\t| PRESSIONE UMA DAS OPCOES ABAIXO                      |"<<endl;
    cout<<"\t| 1 - Exibir a media movel no Brasil e nos estados     |"<<endl;
    cout<<"\t| 2 - Exibir situacao nos estados                      |"<<endl;
    cout<<"\t| 3 - Exibir situacao no Brasil                        |"<<endl;
    cout<<"\t| 4 - Exibir estados com maior alta e menor baixa      |"<<endl;
    cout<<"\t| 5 - Exibir numero de obitos                          |"<<endl;
    cout<<"\t| 0 - SAIR                                             |"<<endl;
    cout<<"\t|------------------------------------------------------|"<<endl;
    string entrada;
    int opcaoMenu;
    Nacional Brasil;

    while(1){
        getline(cin,entrada);
        opcaoMenu = stoi(entrada);
        switch(opcaoMenu){
            case 1:
                Brasil.mostrarEvolucaoObitoNacionalEstadual();
                break;
            case 2:
                Brasil.mostrarEstatisticasEstados();
                break;
            case 3:
                Brasil.mostrarEstatisticaBrasil();
                break;
            case 4:
                Brasil.estadosLimites();
                break;
            case 5:
                Brasil.mostrarNumeroObitosNacionalEstadual();
                break;

            case 0:
                break;

            default:
                cout<<"Opcao Invalida"<<endl;
                break;
        }

        if(opcaoMenu==0)
            break;
    }
    return 0;
}