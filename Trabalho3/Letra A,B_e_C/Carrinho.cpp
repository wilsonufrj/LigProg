#include "Carrinho.h"
 
Carrinho::Carrinho(int tamMax):maxItens(tamMax),cont(0),produtos(tamMax){}

Carrinho::Carrinho(const Carrinho &copia):maxItens(copia.maxItens),cont(copia.cont),produtos(copia.maxItens){
    for(int i=0;i<cont;i++){
        produtos.at(i) = new Produto(*copia.produtos.at(i));
    }
};

 Carrinho::~Carrinho(){
    for(int i=0;i<cont;i++){
        cout<<"Destruindo..\n";
        delete produtos[i];
    }
} 

ostream &operator<<(ostream &output,Carrinho &carrinho){
    for(int i=0;i<carrinho.cont;i++){
        output<<*carrinho.produtos.at(i)<<endl;
    }

    return output;
}

 Carrinho &Carrinho::operator+(Produto &produto){
     if(cont < maxItens-1){
         produtos.at(cont++) = new Produto(produto);
     }
     else{
         cout<<"Limite maximo atingido"<<endl;
     }
     return *this;
 }

 Carrinho &Carrinho::operator-(Produto &produto){
     for(int i=0;i<cont;i++){
         if(produtos[i] == &produto){
             produtos.erase(produtos.begin()+i);
             cout<<"Produto Excluido"<<endl;
             cont--;
         }

     }
     return *this;
 }

 