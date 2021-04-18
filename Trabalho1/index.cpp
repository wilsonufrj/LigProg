#include<iostream>
#include"Nacional.h"

using namespace std;

int main(){
    cout<<"\tBem-vindo a Estatísticas COVID-2021\n"<<endl;
    cout<<"\t                        MENU                           "<<endl;
    cout<<"\t|------------------------------------------------------|"<<endl;
    cout<<"\t| PRESSIONA UMA DAS OPCOES ABAIXO                      |"<<endl;
    cout<<"\t| 0 - Exibir a media movel no Brasil e nos estados     |"<<endl;
    cout<<"\t| 1 - Exibir situacao nos estados                      |"<<endl;
    cout<<"\t| 2 - Exibir situacao no Brasil                        |"<<endl;
    cout<<"\t| 3 - Exibir estados com maior alta e menor baixa      |"<<endl;
    cout<<"\t| 4 - Exibir numero de obitos                          |"<<endl;
    cout<<"\t| 5 - SAIR                                             |"<<endl;
    cout<<"\t|------------------------------------------------------|"<<endl;
    int opcaoMenu;
    Nacional Brasil;

    while(1){
        //Pesquisar outro metodo de entrada
        cin>>opcaoMenu;
        switch(opcaoMenu){
            case 0:
                cout<<"mostrarEvolucaoObitoNacionalEstadual"<<endl;
                //Brasil.mostrarEvolucaoObitoNacionalEstadual();
                break;
            case 1:
                //cout<<"mostrarEstatisticasEstados()"<<endl;
                Brasil.mostrarEstatisticasEstados();
                break;
            case 2:
                //cout<<"mostratEstatisticaBrasil()"<<endl;
                //Brasil.mostrarEstatisticaBrasil();
                break;
            case 3:
                cout<<"mostrarEstadosLimites"<<endl;
                //Brasil.estadosLimites();
                break;
            case 4:
                //DONE
                Brasil.mostrarNumeroObitosNacionalEstadual();
                break;
            case 5:
                break;
            default:
                cout<<"Opcao Invalida"<<endl;
                break;
        }

        if(opcaoMenu==5)
            break;
        
    }
    return 0;
}