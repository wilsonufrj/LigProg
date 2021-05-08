#ifndef H_VERTICE
#define H_VERTICE

#include<string>

using namespace std;

class Vertice{
    public:
        Vertice(string);
        string getRotulo();
        void somaContador();
        int getContador();

    private:
        string rotulo;
        int contador;
};

#endif