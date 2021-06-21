#include"BD_Connection.h"

BD_Connection::BD_Connection(const char* servidor,const char* usuario,const char* senha,const char*database):
servidor(servidor),usuario(usuario),senha(senha),bd(database){
    connection_config();
}

BD_Connection::~BD_Connection(){
}

void BD_Connection::connection_config(){

   try{
       driver = get_driver_instance();
       conexao = driver->connect(servidor,usuario,senha);

   }catch(sql::SQLException &e){
       cout<<"Nao foi possivel conectar com o servidor: "<<e.what()<<endl;
       exit(1);
   }


}

void BD_Connection::mysql_querysInserir(Produto &produto){
    connection_config();
    conexao->setSchema("projetoFinal2");
    stmt = conexao->createStatement();

    pstmt = conexao->prepareStatement("INSERT INTO PRODUTO(nome,nomeColecao,descricao,preco,ano,estacao) VALUES(?,?,?,?,?,?)");
    pstmt->setString(1, produto.getNome());
    pstmt->setString(2, produto.getNomeColecao());
    pstmt->setString(3, produto.getDescricao());
    pstmt->setDouble(4, produto.getPreco());
    pstmt->setInt(5, produto.getAno());
    pstmt->setString(6, produto.getEstacao());
    pstmt->execute();
    cout << "Produto Adicionado"<< endl;
    
    
}

Produto* BD_Connection::mysql_queryPegaProduto(string id){
    connection_config();
    Produto *auxProduto = new Produto;

    conexao->setSchema("projetoFinal2");
    pstmt = conexao->prepareStatement("SELECT * FROM PRODUTO ");
    resultado = pstmt->executeQuery();
        
        //ENCONTRA UMA LINHA
        while(resultado->next()){
            //PERCORRE TODAS AS COLUNAS DESSA LINHA
            if(resultado->getInt(1) == stoi(id)){
                auxProduto->setNome(resultado->getString(2));
                auxProduto->setNomeColecao(resultado->getString(3)); 
                auxProduto->setDescricao(resultado->getString(4));
                auxProduto->setPreco(resultado->getDouble(5));
                auxProduto->setAno(resultado->getInt(6));
                auxProduto->setEstacao(resultado->getString(7)); 

                return auxProduto;
            }
             
        }
    

    return NULL;
}

void BD_Connection::mysql_deletarProduto(string id){
    connection_config();
    conexao->setSchema("projetoFinal2");

    pstmt = conexao->prepareStatement("DELETE FROM PRODUTO WHERE ID = ?");
    pstmt->setInt(1,stoi(id));
    resultado = pstmt->executeQuery();
    cout<<"Linha excluida do banco de dados.."<<endl;
} 



void BD_Connection::mysql_atualizaProduto(string id,string nomeColuna,string valor){
    connection_config();
    conexao->setSchema("projetoFinal2");

    string sqlString = "UPDATE PRODUTO SET "+ nomeColuna + " = ? WHERE ID = ?";

    pstmt = conexao->prepareStatement(sqlString);
    pstmt->setString(1,valor);
    pstmt->setInt(2,stoi(id));
    pstmt->executeQuery();  
    cout<<"Linha atualizada"<<endl;
}

void BD_Connection::mysql_atualizaProduto(string id,string nomeColuna,float valor){
    connection_config();
    conexao->setSchema("projetoFinal2");

    string sqlString = "UPDATE PRODUTO SET "+ nomeColuna + " = ? WHERE ID = ?";

    pstmt = conexao->prepareStatement(sqlString);
    pstmt->setDouble(1,valor);
    pstmt->setInt(2,stoi(id));
    pstmt->executeQuery();  
    cout<<"Linha atualizada"<<endl;
}

void BD_Connection::mysql_atualizaProduto(string id,string nomeColuna,int valor){
    connection_config();
    conexao->setSchema("projetoFinal2");

    string sqlString = "UPDATE PRODUTO SET "+ nomeColuna + " = ? WHERE ID = ?";

    pstmt = conexao->prepareStatement(sqlString);
    pstmt->setInt(1,valor);
    pstmt->setInt(2,stoi(id));
    pstmt->executeQuery();  
    cout<<"Linha atualizada"<<endl;
}

void BD_Connection::mysql_printaEstacoes(){
    vector<string> adicionaEstacao;
    bool encontraEstacao = false;
    connection_config();
    conexao->setSchema("projetoFinal2");


    
    pstmt = conexao->prepareStatement("SELECT * FROM PRODUTO");
    resultado = pstmt->executeQuery();

    while (resultado->next()){
      
        if(adicionaEstacao.empty()){
            adicionaEstacao.push_back(resultado->getString(7));
        }else{
            for(long unsigned int i=0; i<adicionaEstacao.size();i++){
                if(adicionaEstacao[i].compare(resultado->getString(7))==0){
                    encontraEstacao=true;
                }
            }

            if(!encontraEstacao){
                adicionaEstacao.push_back(resultado->getString(7));
            }
        }
        encontraEstacao=false;
        
    }

    for(long unsigned int i=0;i<adicionaEstacao.size();i++){
        cout<<adicionaEstacao[i]<<endl;
        mysql_printaColecoes(adicionaEstacao[i]);
    }    

}

void BD_Connection::mysql_printaColecoes(string estacao){
    connection_config();
    int contaProduto=0;
    conexao->setSchema("projetoFinal2");


    pstmt = conexao->prepareStatement("SELECT * FROM PRODUTO WHERE estacao = ?");
    pstmt->setString(1,estacao);
    resultado = pstmt->executeQuery();

    while (resultado->next()){
        cout<<"Nome da Colecao: "<< resultado->getString(3)<< "\tAno: "<<resultado->getInt(6)<<endl;
        contaProduto+=1;
    }
    
    cout<<"Total de Colecoes: "<<contaProduto<<endl;
    cout<<"--------------------------------"<<endl;

}

void BD_Connection::mysql_mostraDetalhesColecao(string estacao,string colecao,string ano){
    connection_config();
    conexao->setSchema("projetoFinal2");

    pstmt = conexao->prepareStatement("SELECT * FROM PRODUTO WHERE estacao = ?");
    pstmt->setString(1,estacao);
    resultado = pstmt->executeQuery();

        while(resultado->next()){
            if(resultado->getString(3) == colecao && resultado->getInt(6)==stoi(ano)){
               cout<<"ID: "<<resultado->getInt(1)<<endl<<
                "Nome: "<<resultado->getString(2)<<endl<<
                "Nome da Colecao: "<<resultado->getString(3)<<endl<<
                "Descricao: "<<resultado->getString(4)<<endl<<
                "Preco: "<<resultado->getDouble(5)<<endl<<
                "Ano: "<<resultado->getInt(6)<<endl<<
                "Estacao: "<<resultado->getString(7)<<endl;

            cout<<"\n--------------------------------"<<endl;
            }
        }

}