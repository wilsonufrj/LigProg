#include"Nacional.h"

Nacional::Nacional(){
    setEstatistica();
}

void Nacional::mostrarNumeroObitosNacionalEstadual(){
    int totalBrasil=0;
    for(Estadual estado:estados){
            totalBrasil+=estado.somaMortes();   
            cout<<"Estado: "<<estado.getNomeEstado()
            <<"\tMortes: "<<estado.somaMortes()<<endl;
    }

    cout<<"Total de mortos no Brasil: "<<totalBrasil<<endl;
    fimFuncao();

}

//RODAR NOVAMENTE PARA TESTAR ESSA FUNÇÃO
void Nacional::mostrarEstatisticasEstados(){
    //cout<<estados[0].getNomeEstado()<<endl;
   // cout<<estados[0].getTendencia()<<"\n\n"<<endl;
    cout<<"ESTADOS EM ALTA"<<endl;
    for(int unsigned i=0;i<alta.size();i++){
        cout<<alta[i].getNomeEstado()<<endl;
    }
    cout<<"ESTADOS EM ESTABILIDADE"<<endl;
    for(int unsigned i=0;i<estavel.size();i++){
        cout<<estavel[i].getNomeEstado()<<endl;
    }
    cout<<"ESTADOS EM BAIXA"<<endl;
    for(int unsigned i=0;i<baixa.size();i++){
        cout<<baixa[i].getNomeEstado()<<endl;
    }
    fimFuncao();
}

void Nacional::estadosLimites(){
    double maiorAlta=0,menorBaixa=0;
    string estadoMaiorAlta,estadoMenorBaixa; 
    for(Estadual estado:alta){
        if(estado.getPorcentagemTendencia()>maiorAlta){
            estadoMaiorAlta = estado.getNomeEstado(); 
        }
    }
    for(Estadual estado:baixa){
        if(estado.getPorcentagemTendencia()<menorBaixa){
            estadoMenorBaixa = estado.getNomeEstado(); 
        }
    }
    cout<<"ESTADO MAIOR ALTA : "<<estadoMaiorAlta<<endl;
    cout<<"ESTADO MENOR BAIXA : "<<estadoMenorBaixa<<endl;

    fimFuncao();
}

void Nacional::setEstatistica(){
    for(Estadual estado:estados){
        /*cout<<"Nome: "<<estado.getNomeEstado()
        <<"\tTendencia: "<<estado.getTendencia()<<endl;*/
        if(estado.getTendencia()>0){
            //cout<<"Nome: "<<estado.getNomeEstado()<<endl;
            alta.push_back(estado);
        }else{
            if(estado.getTendencia()<0){
               // cout<<"Nome: "<<estado.getNomeEstado()<<endl;
                baixa.push_back(estado);
            }else{
               // cout<<"Nome: "<<estado.getNomeEstado()<<endl;
                estavel.push_back(estado);
            }
        }
    }
}

/*void Nacional::setTendencia(){
    double porcentagem;
    
    if(porcentagem*100 >= 15)
        tendencia =1;
    else{
        if(porcentagem*100 <= -15) //Baixa
            tendencia = -1;
        else
            porcentagem = 0; //Estabilidade
    }
}*/

void Nacional::fimFuncao(){
    cout<<"-------------------------------------------------------\n\n";
}