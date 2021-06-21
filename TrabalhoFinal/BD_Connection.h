#ifndef MYSQL_CONNECTION_H
#define MYSQL_CONNECTION_H

/*--------BIBLIOTECAS C++-----*/
#include<mysql_driver.h>
#include<mysql_connection.h>
#include<cppconn/exception.h>
#include<cppconn/prepared_statement.h>

#include<iostream>
#include<vector>
#include"Produto.h"


using namespace std;


class BD_Connection{
    
    public:
    BD_Connection(const char* servidor = "localhost"
                  ,const char* usuario ="root"
                  ,const char* senha = "12345"
                  ,const char* database = "projetoFinal2"
    );
    ~BD_Connection();
    
    void connection_config();
    void mysql_querysInserir(Produto&);
    Produto* mysql_queryPegaProduto(string);
    void mysql_deletarProduto(string);

    void mysql_atualizaProduto(string,string,string);
    void mysql_atualizaProduto(string,string,float);
    void mysql_atualizaProduto(string,string,int);

    void mysql_printaEstacoes();
    void mysql_mostraDetalhesColecao(string,string,string);



    private:

    sql::Driver *driver;
    sql::Connection *conexao;
    sql::Statement *stmt;
    sql::PreparedStatement *pstmt;
    sql::ResultSet *resultado;

    const char *servidor, *usuario, *senha, *bd;
    
    void mysql_printaColecoes(string);
    
    
};

#endif