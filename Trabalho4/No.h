#ifndef NO_H
#define NO_H

#include<string>
#include<iostream>

using namespace std;

template<class T> class No;
template<class T> ostream& operator<<(ostream& saida, No<T> &no){
    cout<<"Valor: "<<no.getValor()<<endl;
    if(no.getEsq()==NULL){
        cout<<"No Esquerdo: NULL"<<endl;
    }else{
        cout<<"No Esquerdo: "<<endl<<*no.getEsq()<<endl;
    }
    if(no.getDir()==NULL){
        cout<<"No Direito: NULL"<<endl;
    }else{
        cout<<"No Direito: "<<endl<<*no.getDir()<<endl;
    }
    return saida;
}


template<class T>
class No{

    public:
    No(string);
    ~No();
    void setEsq(No<T>*);
    void setDir(No<T>*);

    No<T>* getEsq();
    No<T>* getDir();
    string getValor();



    private:
    No<T> *esq,*dir;
    string valor;
};

template <class T>
No<T>::No(string valor){
    this->valor = valor;
    esq = NULL;
    dir = NULL;
}

template<class T>
No<T>::~No(){
     
}

template<class T>
No<T>* No<T>::getEsq(){return esq;}

template<class T>
No<T>* No<T>::getDir(){return dir;}

template<class T>
string No<T>::getValor(){ return valor;}

template<class T>
void No<T>::setEsq(No<T> *ptr){ esq = ptr;}

template<class T>
void No<T>::setDir(No<T> *ptr){dir = ptr;}

/* template<class T>
ostream& operator<<(ostream &saida, No<T> &no){
    cout<<"O caralho"<<endl;
    
}*/
 
#endif