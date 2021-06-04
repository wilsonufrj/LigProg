#ifndef ARVORE_H
#define ARVORE_H

#include<iostream>
using namespace std;

template<class T>
class Arvore:public No<T>{

    public:
    //Ver se essa valor tem que ser string para comparar
    Arvore(string valor);


    No<T>* operator+=( No<T>&);
    No<T>* operator()(string&);

    void printaArvore();
    No<T>* getRaiz();

    private:
    No<T>* raiz;
    No<T>* insereOBJ(No<T>*,string);
    No<T>* emOrdem(No<T>* ,string); //Busca
};

template<class T>
Arvore<T>::Arvore(string valor):No<T>(valor){
    raiz = NULL;
}

template<class T>
No<T>* Arvore<T>::getRaiz(){return raiz;}

//Adicionar um elemento na arvore
template<class T>
No<T>* Arvore<T>::operator+=( No<T> &objeto){

    if(raiz==NULL){
        raiz = new No<T>(objeto.getValor());
        return raiz;
    }
    else{                   
        No<T>* aux =insereOBJ(raiz, objeto.getValor());
        if(aux!=NULL){
           return aux;

        }
    } 

    return NULL;

}

//FUNCIONANDO
template<class T>
No<T>* Arvore<T>::insereOBJ(No<T> *no, string valor){
    if(no->getValor().compare(valor)>0){
        if(no->getEsq() == NULL){
            No<T> *newNo = new No<T>(valor);
            no->setEsq(newNo);
            return newNo; //TEM QUE MUDAR PARA newNo
        }else
            insereOBJ(no->getEsq(),valor);
    }else{
        if(no->getValor().compare(valor)<0){
            if(no->getDir()==NULL){
                No<T>* newNo = new No<T>(valor);
                no->setDir(newNo);
                return newNo;//TEM QUE MUDAR PARA newNo
            }else
                insereOBJ(no->getDir(),valor);
        }
    }

    return NULL;
}

//Fazer a busca na arvore
//Passar o nó raiz e verificar ao percorrer os valores dos No são iguais ao buscado
//NAO TESTADO
template<class T>
No<T>* Arvore<T>::operator()( string &nome){
    if(raiz!=NULL){
        No<T> aux = emOrdem(raiz,nome);
        if(aux!= NULL)
            return aux;
    }
    return NULL;
}

//Busca de um no
//NAO TESTADO
template<class T>
No<T>* Arvore<T>::emOrdem(No<T>* no,string nome){
    if(no!=NULL){
        if(nome.compare(no->getValor())==0){
            return no;
        }
        else{
            emOrdem(no->getEsq());
            emOrdem(no->getDir());
        }
    }
}

//FUNCIONANDO
template<class T>
void Arvore<T>::printaArvore(){
    cout<<*raiz;
}



#endif