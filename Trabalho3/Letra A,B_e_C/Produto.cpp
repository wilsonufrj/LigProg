#include"Produto.h"
 
Produto::Produto(string nomeDoProduto,string nomeDaMarca,double Preco)
: nomeProduto(nomeDoProduto),nomeMarca(nomeDaMarca),preco(Preco){
    cout<<"Produto Criado"<<endl;
}

ostream &operator<<(ostream &output, Produto &produto){
    output<< "("<<produto.nomeMarca<<", "
            <<produto.nomeProduto<<", "
            <<produto.preco<<" )";
    
    return output;
}

void Produto::setNomeProduto(string nome){nomeProduto = nome;}
void Produto::setNomeMarca(string nome){nomeMarca = nome;}
void Produto::setPreco(double precoV){preco = precoV;}


string Produto::getNomeProduto(){return nomeProduto;}
string Produto::getNomeMarca(){return nomeMarca;}
double Produto::getPreco(){return preco;}
