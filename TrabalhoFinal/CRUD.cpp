#include"CRUD.h"

CRUD::CRUD():BD_Connection(){}

void CRUD::mostraMenu(){
    cout<<"----------GERENCIADOR DE BANCO DE DADOS MYSQL---------"<<endl;
    cout<<"1 - Incluir um produto"<<endl;
    cout<<"2 - Buscar um produto"<<endl;
    cout<<"3 - Deletar um produto"<<endl;
    cout<<"4 - Atualizar um produto"<<endl;
    cout<<"5 - Buscar Colecao"<<endl;
    cout<<"6 - SAIR"<<endl;
}

//OK(QUASE)
void CRUD::inserirProduto(){
    system("clear");
    string nome, nomeColecao, descricao,estacao;
    string preco,ano;
    
    cout<<"Nome do Produto: ";
    getline(cin,nome);
    cout<<"Nome Colecao: ";
    getline(cin,nomeColecao);
    cout<<"Descricao: ";
    getline(cin,descricao);
    cout<<"Estacao: ";
    getline(cin,estacao);
    cout<<"Preco: ";
    getline(cin,preco);
    cout<<"Ano: ";
    getline(cin,ano);


    Produto *produto = new Produto(nome,nomeColecao,descricao,stof(preco),stoi(ano),estacao);
    BD_Connection::mysql_querysInserir(*produto);
    
}

 //OK (MAS PRECISA VERIFICAR QUANDO A ENTRADA NAO EH UM NUMERO VALIDO)
void CRUD::buscaProduto(){
    system("clear");
    string codigo;
    cout<<"Digite o codigo de identificacao do Produto desejado"<<endl;
    getline(cin,codigo);

    Produto *ptrProduto = BD_Connection::mysql_queryPegaProduto(codigo);
    cout<<*ptrProduto;

}

void CRUD::deletaProduto(){
    system("clear");
    string codigo,escolha;
    cout<<"Digite o codigo de identificacao do Produto para ser excluido"<<endl;
    getline(cin,codigo);

    Produto *ptrProduto = BD_Connection::mysql_queryPegaProduto(codigo);
    cout<<*ptrProduto;
    if(ptrProduto!=NULL){
        cout<<"Deseja realmente excluir esse produto? Pressione s para sim e qualquer outra tecla para voltar ao menu inicial"<<endl;
        getline(cin,escolha);
        if(escolha=="s"){
            BD_Connection::mysql_deletarProduto(codigo);
        }else 
            cout<<"Voltando ao menu inicial..."<<endl;
    }else{
        cout<<"Produto nao encontrado.."<<endl;
    }
} 

void CRUD::atualizaProduto(){
     system("clear");
    string codigo,escolha,valor;
    cout<<"Digite o codigo de identificacao do Produto para ser atualizado"<<endl;
    getline(cin,codigo);

    cout<<*BD_Connection::mysql_queryPegaProduto(codigo);
    cout<<"Qual dos atributos abaixo sera modificado"<<endl;
    cout<<"1 - Nome"<<endl;
    cout<<"2 - Nome colecao"<<endl;
    cout<<"3 - Descricao"<<endl;
    cout<<"4 - Preco"<<endl;
    cout<<"5 - Ano"<<endl;
    cout<<"6 - Estacao"<<endl;
    getline(cin,escolha);
    cout<<"\nNovo valor eh: "<<endl;
    getline(cin,valor);

    switch (stoi(escolha))
    {
    case 1:
        BD_Connection::mysql_atualizaProduto(codigo,"nome",valor);
        break;
    case 2:
        BD_Connection::mysql_atualizaProduto(codigo,"nomeColecao",valor);
        break;
    case 3:
        BD_Connection::mysql_atualizaProduto(codigo,"descricao",valor);
        break;
    case 4:
        BD_Connection::mysql_atualizaProduto(codigo,"preco",stof(valor));
        break;
    case 5:
        BD_Connection::mysql_atualizaProduto(codigo,"ano",stoi(valor));
        break;
    case 6:
        BD_Connection::mysql_atualizaProduto(codigo,"estacao",valor);
        break;
    default:
        cout<<"Opcao invalida..."<<endl;
        break;
    }
}

void CRUD::buscaColecao(){
    system("clear");
    string estacao,colecao,ano,decisao;
    cout<<"Abaixo as estacoes com as devidas coleçoes"<<endl;
    BD_Connection::mysql_printaEstacoes();
    cout<<"Ha o interesse de ver alguma colecao mais detalhada ?[s]sim qualquer tecla para nao"<<endl;
    getline(cin,decisao);
    if(decisao!="s")
        cout<<"Voltando ao menu inicial"<<endl;
    else{
        cout<<"Selecione a estacao"<<endl;
        getline(cin,estacao);
        cout<<"Selecione o nome da colecao"<<endl;
        getline(cin,colecao);
        cout<<"Selecione o ano"<<endl;
        getline(cin,ano);
        mysql_mostraDetalhesColecao(estacao,colecao,ano);
    }
}