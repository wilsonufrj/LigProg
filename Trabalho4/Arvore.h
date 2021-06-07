#ifndef ARVORE_H
#define ARVORE_H

#include<iostream>
#include"No.h"
using namespace std;

template<class T>
class Arvore:public No<T>{

    public:
    Arvore();

    No<T>* operator+=( No<T>&);
    No<T>* operator()(const string&);

    void printaArvore();
    No<T>* getRaiz();

    private:
    No<T>* raiz;
    No<T>* insereOBJ(No<T>*,string);
    No<T>* buscaArvore(No<T>* ,const string); //Busca
    void recursaoPrinta(No<T>*);
};

template<class T>
Arvore<T>::Arvore():raiz(NULL){}

template<class T>
No<T>* Arvore<T>::getRaiz(){return raiz;}

//Adicionar um elemento na arvore
//FUNCIONANDO
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
            return newNo; 
        }else
            insereOBJ(no->getEsq(),valor);
    }else{
        if(no->getValor().compare(valor)<0){
            if(no->getDir()==NULL){
                No<T>* newNo = new No<T>(valor);
                no->setDir(newNo);
                return newNo;
            }else
                insereOBJ(no->getDir(),valor);
        }
    }

    return NULL;
}

//Fazer a busca na arvore
template<class T>
No<T>* Arvore<T>::operator()(const string &nome){
    if(raiz!=NULL){
        No<T>* aux = buscaArvore(raiz,nome);
        if(aux!=NULL){
            return aux;
        }
    }
    return NULL;
}


//FUNCIONANDO
template<class T>
No<T>* Arvore<T>::buscaArvore(No<T>* no, const string nome){
    No<T>* auxNoEsq = no->getEsq();
    No<T>* auxNoDir = no->getDir();
    No<T>* retorno=NULL;
    bool naoAchou=false,mudouNo;
    
        while(naoAchou==false){
            mudouNo=false;
            if(nome.compare(no->getValor())==0){
                retorno = no;
                break;
            }

            if(nome.compare(no->getValor())<0){
                if(no->getEsq()!=NULL){
                    no = no->getEsq();
                    mudouNo = true;
                }

                if(no->getEsq()!=NULL)
                    auxNoEsq = no->getEsq();
                if(no->getDir()!=NULL)
                    auxNoDir = no->getDir();
            }


            else{
                if(no->getDir()!=NULL){
                    no = no->getDir();
                    mudouNo = true;
                }

                if(no->getEsq()!=NULL)
                    auxNoEsq = no->getEsq();
                if(no->getDir()!=NULL)
                    auxNoDir = no->getDir();
            }

            if(mudouNo==false){
                naoAchou=true;
            }
        }

    if(retorno!=NULL){
        return retorno;
    }
    return NULL;
}

//FUNCIONANDO
template<class T>
void Arvore<T>::printaArvore(){
    if(raiz==NULL){
        cout<<"Arvore Vazia"<<endl;
    }else
        recursaoPrinta(raiz);
}

template<class T>
void Arvore<T>::recursaoPrinta(No<T> *no){
    cout<<*no;
    if(no->getEsq()==NULL){
        cout<<"No Esquerdo: NULL"<<endl;
    }else{
        cout<<"No Esquerdo: "<<endl;
        recursaoPrinta(no->getEsq());
    }
    if(no->getDir()==NULL){
        cout<<"No Direito: NULL"<<endl;
    }else{
        cout<<"No Direito: "<<endl;
        recursaoPrinta(no->getDir());
    }
}

#endif