#include"Agenda.h"

using namespace std;

Agenda::Agenda(){
    FILE.open("contatos.txt",ios::in);
}

void Agenda::inserirContato(Contato contato){
    if(contatos.size()>= maxContatos){
        cout<<"Agenda Cheia!!"<<endl;
    }else{
        if(contato.getNome().size()>=10){
            string aux = contato.getNome();
            verificaNome(aux);
            contato.setNome(aux);
        }
            if(verificaNomeIgual(contato.getNome())){
                contatos.push_back(contato);
            }else
                cout<<"Contato Existente"<<endl;
        
    }
}   

void Agenda::verificaNome(string &nome){
        cout<<"Ai ai ai String grande"<<endl;
        nome = nome.substr(0,10);
}

bool Agenda::verificaNomeIgual(string nome){
    for(Contato contato:contatos){
        if(contato.getNome().compare(nome)==0)
            return 0;
    }
    return 1;
}

void Agenda::mostraContato(){
    for(Contato contato:contatos){
        cout<<"Nome: "<<contato.getNome()
        <<" | Profissao: "<<contato.getProfissao()
        <<" | Idade: "<<contato.getIdade()<<endl;
    }
}

void Agenda::apagaContato(int posicao){
    contatos.erase(contatos.begin()+posicao);
}