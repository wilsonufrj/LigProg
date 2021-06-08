#ifndef ERROS_H
#define ERROS_H

#include<exception>

class Erros:public exception{
    public:
    Erros():exception(){}

    virtual const char* what() const throw(){
        return "Erro ao executar a funcao";
    }
};



#endif