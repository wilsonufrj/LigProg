#include"Catalogo.h"

Catalogo::Catalogo(int maxFilme):filmes(maxFilme),maxTamanho(maxFilme),cont(0){}

Catalogo::~Catalogo(){
   /*  for(unsigned i=0;i<cont;i++){
        delete filmes[i];
    }  
    cout<<"DESTRUINDO"<<endl;*/
} 

//FUNCIONANDO
bool operator==(const Filme*filme1,const Filme &filme2){
    if(filme1->nome == filme2.nome){
        return true;
    }
    return false;
}
//FUNCIONANDO
bool operator<(const Filme *filme1,const Filme &filme2){
    if(filme1->nome.compare(filme2.nome)>0){
        return false;
    }
    return true;
}

//FUNCIONANDO
Catalogo& Catalogo::operator+=(Filme &filme){
    bool confereFilme=false;
    unsigned posicao=0;
    if(cont<maxTamanho){
        for(unsigned i=0;i<cont;i++){
            if(filmes[i]==filme){
                confereFilme=true;   
            }
        }
        if(!confereFilme){
            for(posicao=0;posicao<cont;posicao++){
                if(filme.nome<filmes[posicao]->nome){
                    reposicionaElemento(posicao);
                    break;
                }
            }
            if(cont==0){
                filmes.at(cont++) = &filme;
                cout<<"Filme Adicionado"<<endl;
                return *this;
            }
            filmes.at(posicao) = &filme;
            cont++;
            cout<<"Filme Adicionado"<<endl;


        }else
            cout<<"Filme ja existente"<<endl;
        
    }
    else cout<<"Catalogo Lotado"<<endl;


    return *this;
}

void Catalogo::reposicionaElemento(unsigned posicao){
    for(unsigned j=cont;j>posicao;j--){
        filmes[j] = filmes[j-1];
    }
}

//FUNCIONANDO
Catalogo &Catalogo::operator+=(vector<Filme> &vetorFilmes){

     for(unsigned i=0;i<vetorFilmes.size();i++){
         filmes.insert(filmes.begin()+cont+i,&vetorFilmes[i]);
    } 
    cont+=vetorFilmes.size();

    ordenaVetor();
    return *this;
}

//FUNCIONANDO
Catalogo &Catalogo::operator-=(Filme &filme){
    for(unsigned i=0;i<cont;i++){
        if(&filme == filmes[i]){
            filmes.erase(filmes.begin()+i);
            cont--;
        }
    }
    return *this;
}

//FUNCIONANDO
Filme *Catalogo::operator()(const string nomeFilme){
    for(unsigned i=0; i<cont;i++){
        if(nomeFilme == filmes[i]->nome){
            return filmes[i];
        }
    }
    return NULL;
}

Filme *Catalogo::operator()(const string nomeFilme,string novoNome){
    string auxNOME;
    string escolha;
    double auxNota=0;

    cout<<"Para editar o nome digite NOME, para editar produtora digite PRODUTORA"<<endl;
    cin>>escolha;

    if(escolha == "NOME"){
        for(unsigned i=0; i<cont;i++){
            if(nomeFilme == filmes[i]->nome ){
                auxNOME = filmes[i]->nomeProdutora;
                auxNota = filmes[i]->nota;
            
                filmes.erase(filmes.begin()+i);
                cont--;
            
                Filme *aux = new Filme();
                aux->nome=novoNome;
                aux->nomeProdutora = auxNOME;
                aux->nota = auxNota;
                filmes.insert(filmes.begin()+i,aux);
                cont++;

                return filmes[i];
            }
        }
    }
        else{
            for(unsigned i=0; i<cont;i++){
            if(nomeFilme == filmes[i]->nome ){
                auxNota = filmes[i]->nota;
            
                filmes.erase(filmes.begin()+i);
                cont--;
            
                Filme *aux = new Filme();
                aux->nome=nomeFilme;
                aux->nomeProdutora = novoNome;
                aux->nota = auxNota;
                filmes.insert(filmes.begin()+i,aux);
                cont++;

                return filmes[i];
            }
        }
    }
    return NULL;

}


//FUNCIONANDO
Filme *Catalogo::operator()(const string nomeFilme,double nota){
    string auxProdutora;
    for(unsigned i=0; i<cont;i++){
        if(nomeFilme == filmes[i]->nome){
            auxProdutora = filmes[i]->nomeProdutora;
            filmes.erase(filmes.begin()+i);
            cont--;

            Filme *aux = new Filme();
             aux->nome=nomeFilme;
            aux->nomeProdutora = auxProdutora;
            aux->nota = nota;

            filmes.insert(filmes.begin()+i,aux);
            cont++;

            return filmes[i];
        }
    }
    return NULL;
}

//FUNCIONANDO
ostream &operator<<(ostream &output, Catalogo &catalogo){
    for(unsigned i=0;i<catalogo.cont;i++){
        output<<"( "<<catalogo.filmes[i]->nome<<", "
        <<catalogo.filmes[i]->nomeProdutora<<", "
        <<catalogo.filmes[i]->nota<<" )"<<endl;
    }
    return output;
}

//FUNCIONANDO
ostream &operator<<(ostream &output, Filme &filme){
    output<<"( "<<filme.nome<<", "<<
            filme.nomeProdutora<<", "<<
            filme.nota<<" )"<<endl;

    return output;
}

//REVER PARA NAO DAR MERDA
istream &operator>>(istream &input, Filme &filme){

    string nomeFilme;
    string nomeProdutora;
    double nota;
    cout<<"Adicionar o nome do filme"<<endl;
    input>>nomeFilme;
    cout<<"Adicionar o nome da produtora"<<endl;
    input>>nomeProdutora;
    cout<<"Adicionar a nota do filme do filme"<<endl;
    input>>nota;
    
    filme.nome = nomeFilme;
    filme.nomeProdutora = nomeProdutora;
    filme.nota = nota;

    return input;
}



//FUNCIONANDO
void Catalogo::melhorFilme(){
    double melhorNota = 0;
    unsigned posicao;
    for(unsigned i=0;i<cont;i++){
        if(filmes[i]->nota > melhorNota){
            melhorNota = filmes[i]->nota;
            posicao = i;
        }
    } 

    cout<<filmes.at(posicao)->nome<<endl;
}

//FUNCIONANDO
void Catalogo::ordenaVetor(){
    for(unsigned i=0;i<cont;i++){
        for(unsigned j=i;j<cont-1;j++){
            if(filmes[j+1]->nome<filmes[i]->nome){
                Filme *aux = filmes[i];
                filmes[i] = filmes[j+1];
                filmes[j+1] = aux;
            }
        }
    }
}