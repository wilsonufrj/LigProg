#include "Principais.h"


void AdicionaFilme(Catalogo &catalogo){
    Filme *aux = new Filme();
    cin>>*aux;
    catalogo+=*aux;

}

//Falta testar
void RemoveFilme(Catalogo &catalogo){
    string nomeFilme;
    bool deletou = false;
    cout<<"Insira o nome do filme que sera removido "<<endl;
    cin>>nomeFilme;
    for(unsigned i=0; i<catalogo.cont;i++){
        if(nomeFilme == catalogo.filmes[i]->nome){
            catalogo-=*(catalogo.filmes[i]);
            cout<<"Filme Deletado"<<endl;
            deletou= true;
        }
    }

    if(!deletou)
        cout<<"Filme não encontrado"<<endl;
    
}

//FALTA TESTAR
void EditaFilme(Catalogo &catalogo){
    string novoValor;
    string filme;
    int nota;
    cout<<"Qual da propriedades editar ?"<<endl;
    cout<<" 1 - Editar Filme ou Produtora"<<endl;
    cout<<" 2  - Editar Nota do filme"<<endl;

    int escolha=0;
    cin>>escolha;
    switch(escolha){
        case 1:{
            cout<<"Insira o nome do filme"<<endl;
            cin>>filme;
            cout<<"Insira o novo nome que sera adicionado"<<endl;
            cin>>novoValor;
            //Rever para a entrega
            if(catalogo.operator()(filme,novoValor)!=NULL){
                cout<<"Filme Modificado"<<endl;
            }
            else cout<<"Filme inexistente";
            break;
        }
        case 2:{
            cout<<"Insira o nome do filme"<<endl;
            cin>>filme;
            cout<<"Insira o valor a ser editado"<<endl;
            cin>>nota;
            //Rever para a entrega
            if(catalogo.operator()(filme,nota)!=NULL){
                cout<<"Filme Modificado"<<endl;
            }
            else cout<<"Filme inexistente";
            break;
        }
    }
}

//FALTA TESTAR
void MostraCatalogo(Catalogo &catalogo){
    cout<<catalogo;
}  

//FALTA TESTAR
void MostraFilmeCatalogo(Catalogo &catalogo){
    string nomeFilme;
    bool achou=false;
    cout<<"Qual o nome do filme? "<<endl;
    cin>>nomeFilme;
    for(unsigned i=0; i<catalogo.cont;i++){
        if(nomeFilme == catalogo.filmes[i]->nome){
            cout<<*(catalogo.filmes[i]);
            achou = true;
        }
    }

    if(!achou)
        cout<<"Filme não encontrado"<<endl;
        
}

void melhorFilme(Catalogo &catalogo){
    catalogo.melhorFilme();
}
