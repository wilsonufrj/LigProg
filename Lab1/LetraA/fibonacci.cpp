#include"fibonacci.h"

int calcularFibonacci( int indice){

    if(indice==1 || indice==2){
        return 1;
    }

    return calcularFibonacci(indice-2)+calcularFibonacci(indice-1);
}