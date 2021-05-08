#include"Grafo.h"

Grafo::Grafo(){
    nomeArquivo = "teste.txt";
    lerArquivo();
}

void Grafo::arestaComum(int numero){
    for(int i=0;i<numero;i++){
        
    }
}

void Grafo::insereAresta(Aresta *aresta){
    //Fazer primeiro a leitura** Depois terminar
    for(Aresta* verifica:arestas){
        if(verifica->getPrimeiraPalavra()->getRotulo() == aresta->getPrimeiraPalavra()->getRotulo()
            && verifica->getSegundaPalavra()->getRotulo() == aresta->getSegundaPalavra()->getRotulo()){
                verifica->incrementaPeso();
                
            }
        else{
            arestas.push_back(aresta);
        }
    }

    //ORDENA AS ARESTAS
}

void Grafo::insereVertice(Vertice *vertice){
    bool existe=0;
    for(auto procuraVertice:vertices){
        if(procuraVertice->getRotulo() == vertice->getRotulo()){
            procuraVertice->somaContador();
            existe=1;
        }
    }

    if(!existe)
        cout<<"Adicionei um Vertice"<<endl;
        vertices.push_back(vertice);
    
}

void Grafo::lerArquivo(){
    string linha;
    vector<string> palavras;
    string aux;
    int cont=0;
    FILE.open(nomeArquivo, fstream::in);
    if(!FILE.is_open()){
        cout<<"Erro ao Abrir o arquivo"<<endl;
        return;
    }
    //TESTE PARA A LEITURA DO ARQUIVO
    while(getline(FILE,linha)){
        string aux="";
        for(auto palavra:linha){
            if(palavra==' ' || palavra=='.' || palavra==','){
                //cout<<aux<<endl;
                Vertice auxiliarVertice(aux);
                insereVertice(&auxiliarVertice);
                aux="";
            }
            else{
                aux+=palavra;
            }
        }
        break;
    }

    for(auto vertice:vertices){
        cout<<vertice->getRotulo()<<endl;
    }

    FILE.close();
}

/* void Grafo::quebraLinha(string linha){
    int cont=0;
    string palavra;
    
    while (linha[cont]!="\n")
    {
        getline(linha,palavra,' ');
        cont++;
    }
    
} */

