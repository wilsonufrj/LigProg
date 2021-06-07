#ifndef PACIENTE_H
#define PACIENTE_H

#include<string>
#include<iostream>

using namespace std;



class Paciente{

    friend ostream& operator<<(ostream&, Paciente&);

   public:
    Paciente(string,string,string);

    virtual string getNomePaciente();
    virtual string getIdade();
    virtual string getDoenca();

    private:
    string nome,idade,doenca;
    
};


#endif 