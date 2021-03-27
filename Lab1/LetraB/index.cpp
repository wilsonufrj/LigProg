#include<iostream>
#include "fibonacci.h"

using namespace std;

int main(){

    int elemento;
    Fibonacci fibonacci;
    cout<<"Insira o elemento da serie"<<endl;
    cin>>elemento;

    fibonacci.setFibonacci(elemento);
    cout<<"O valor do "<<elemento<<" eh igual a "<<fibonacci.getFibonacci()<<endl;

    return 0;
}