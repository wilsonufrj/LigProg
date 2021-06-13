#include"BD_Connection.h"
#include"CRUD.h"


int main(){
    CRUD crud;
    
    //system("clear");
    string opcoes;

    while(1){
        crud.mostraMenu();
        getline(cin,opcoes);

        switch (stoi(opcoes)){
            case 1:
                crud.inserirProduto();
                break;
            case 2:
                crud.buscaProduto();
                break;
            case 3:
                crud.deletaProduto();
                break;
            case 4:
                crud.atualizaProduto();
            case 5:
                crud.buscaColecao();
                break;
            case 6:
                break;
            default:
                cout<<"Opcao Invalida..."<<endl;
        }

        if(stoi(opcoes)==6)
            break;
    
    }
  

    return 0;
}