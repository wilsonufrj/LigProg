#ifndef AGENDA_H
#define AGENDA_H

#include<vector>
#include<fstream>
#include"Contato.h"
#include<iostream>


class Agenda{
    public:
        Agenda();
        void inserirContato(Contato);
        void mostraContato();
        void apagaContato(int);

    private:
        vector<Contato> contatos;
        static const int maxContatos=3;
        static const int maxTamanhoNome=10;
        fstream FILE;

        void verificaNome(string &);
        bool verificaNomeIgual(string);


};

#endif