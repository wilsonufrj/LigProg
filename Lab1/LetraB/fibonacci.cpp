#include"fibonacci.h"

void Fibonacci::setFibonacci(int indice){
    fibonacci = computeFibonacci(indice);
}

int Fibonacci::getFibonacci(){
    return fibonacci;
}

int Fibonacci::computeFibonacci(int indice){
     if(indice==1 || indice==2)
            return 1;

          return computeFibonacci(indice-2)+computeFibonacci(indice-1);
}