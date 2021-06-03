#include"Principais.h"



int main(){
    unsigned quantidadeFilmes=0,existente=0;
    vector<Filme> auxFilme;
    string linha;

    int pos,tam;
    string nome,nomeProdutora,nota;

    fstream FILE;
    FILE.open("arquivo.txt",fstream::in);
    if(!FILE.is_open()){
        cerr<<"Arquivo não enconntrado"<<endl;
        exit(0);
    }

     while(FILE.good()){
        getline(FILE,linha);
        pos = linha.find("\n");
        quantidadeFilmes = stoi(linha.substr(0,pos));

        getline(FILE,linha);
         pos = linha.find("\n");
        existente = stoi(linha.substr(0,pos)); 

        for(unsigned i=0;i<existente;i++){
           Filme *filme = new Filme();
           getline(FILE,linha);

           pos = linha.find(",");
           nome = linha.substr(0,pos);
            filme->nome = nome;

           tam = pos+1;
           pos = linha.find(",",tam);
           nomeProdutora = linha.substr(tam,pos-tam);
           filme->nomeProdutora = nomeProdutora;
        
           tam = pos+1;
           pos = linha.find("/0",tam);
           nota = linha.substr(tam,pos-tam);
           filme->nota = stoi(nota); 

           auxFilme.push_back(*filme);
       }
        getline(FILE,linha);
        break;
    } 
    
    FILE.close();    

    cout<<quantidadeFilmes<<endl;
    Catalogo catalogo(quantidadeFilmes);
    catalogo+=auxFilme;

    
    int opcoes;
    cout<<"--------------BEM - VINDO AO CATALOGO DE FILMES---------------"<<endl;
    cout<<"1 - PARA ADICIONAR FILME"<<endl;
    cout<<"2 - PARA REMOVER UM FILME"<<endl;
    cout<<"3 - PARA EDITAR UM FILME"<<endl;
    cout<<"4 - PARA MOSTRAR TODOS OS FILMES EXISTENTES NO CATALOGO"<<endl;
    cout<<"5 - PARA MOSTRAR APENAS UM FILME DO CATALOGO"<<endl;
    cout<<"6 - PARA MOSTRAR O FILME COM A MAIOR NOTA"<<endl;
    cout<<"-----ESCOLHA UMA OPCAO DO MENU-------"<<endl;
    while(1){
        cin>>opcoes;
        
        switch(opcoes){
            case 1:{
                AdicionaFilme(catalogo);
                break;
            }
            case 2:{
                RemoveFilme(catalogo);
                break;
            }

            case 3:{
                EditaFilme(catalogo);

                break;
            }
            case 4:{
                MostraCatalogo(catalogo);

                break;
            }
            case 5:{
                MostraFilmeCatalogo(catalogo);
                break;
            }
            case 6:{
                melhorFilme(catalogo);
                break;
            }
            case 9:
                break;

            default:{
                cout<<"Opcao inválida"<<endl;
                break;
            }
        }
        cout<<"-----ESCOLHA UMA OPCAO DO MENU-------"<<endl;
        if(opcoes==9)
            break;
        
    }    

    //ESCREVER NO ARQUIVO
     FILE.open("arquivo.txt",fstream::out);
     FILE<<catalogo.maxTamanho<<endl;
     FILE<<catalogo.cont<<endl;
    for(unsigned i=0;i<catalogo.cont;i++){
        

        FILE<<catalogo.filmes[i]->nome<<","<<
        catalogo.filmes[i]->nomeProdutora<<","<<
        catalogo.filmes[i]->nota<<endl;
    }
    
    FILE.close();

    cout<<"Fim do programa"<<endl;
 
    return 0;
}