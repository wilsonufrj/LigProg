#include<iostream>
#include"fibonacci.h"

using namespace std;

int main(){
    int elemento;
    cin>>elemento;
    cout<<"O "<<elemento<< " eh igual a "<<calcularFibonacci(elemento)<<endl;

    return OK;
}