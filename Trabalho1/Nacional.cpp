#include"Nacional.h"

Nacional::Nacional(){
    tendenciaPais = 0;

    setEstatistica();
    setMortesPorDiasPais();
    setMediaMovelPais();
    setTendenciaPais();

}

void Nacional::mostrarEvolucaoObitoNacionalEstadual(){
    printaTendencia();
    cout<<" com "<<getPorcentagemTendenciaPais()<<" % na media movel de casos"<<endl;

    cout<<"\nESTADOS EM ALTA"<<endl;
    for(int unsigned i=0;i<alta.size();i++){
        cout<<alta[i].getNomeEstado()<<
        " com "<<alta[i].getPorcentagemTendencia()<<
        " % na media movel de casos"<<endl;
    }
    cout<<"\nESTADOS EM ESTABILIDADE"<<endl;
    for(int unsigned i=0;i<estavel.size();i++){
        cout<<estavel[i].getNomeEstado()<<
        " com "<<estavel[i].getPorcentagemTendencia()<<
        " % na media movel de casos"<<endl;
    }
    cout<<"\nESTADOS EM BAIXA"<<endl;
    for(int unsigned i=0;i<baixa.size();i++){
        cout<<baixa[i].getNomeEstado()<<
        " com "<<baixa[i].getPorcentagemTendencia()<<
        " % na media movel de casos"<<endl;
    }
    fimFuncao();

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

void Nacional::mostrarEstatisticaBrasil(){
    printaTendencia();
    fimFuncao();
}

void Nacional::printaTendencia(){
    if(tendenciaPais<0)
        cout<<"Brasil em baixa de casos"<<endl;
    else{
        if(tendenciaPais>0)
            cout<<"Brasil em alta de casos"<<endl;
        else
            cout<<"Brasil em estabilidade de casos"<<endl;
    }
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

void Nacional::setMortesPorDiasPais(){
    int totalMortes=0;
    for(int dias=0;dias<DIAS_VERIFICADOS;dias++){
        for(int qtdEstados=0;qtdEstados<QUANTIDADE_ESTADO;qtdEstados++){
            totalMortes+=estados[qtdEstados].getMortesPorDia()[dias];
        }
        mortesPorDiaPais.push_back(totalMortes);
        totalMortes=0;
    }
}
void Nacional::setMediaMovelPais(){
    double media =0 ;
    mediaMovelPais.push_back(mortesPorDiaPais[0]);
    mediaMovelPais.push_back(double(mortesPorDiaPais[0]+mortesPorDiaPais[1])/2.0);
    for(int unsigned i=2; i<mortesPorDiaPais.size();i++){
        media = (mortesPorDiaPais[i-2]+mortesPorDiaPais[i-1]+mortesPorDiaPais[i])/3.0;
        mediaMovelPais.push_back(media);
    }
}

void Nacional::setTendenciaPais(){
    double porcentagem=0;
    /*cout<<"Ultima media movel"<<mediaMovel[mediaMovel.size()-1]<<
    "Penultima mediaMovel "<< mediaMovel[mediaMovel.size()-2]<<
    endl;*/
    porcentagem = double((mediaMovelPais[mediaMovelPais.size()-1] - mediaMovelPais[mediaMovelPais.size()-2])/(mediaMovelPais[mediaMovelPais.size()-2]));
    cout<<"Porcentagem: "<<porcentagem*100<<endl;
    //Alta
    if(porcentagem*100 >= 15){
        tendenciaPais =1;
        setPorcentagemTendenciaPais(porcentagem*100);
    }
    else{
        if(porcentagem*100 <= -15){ //Baixa
            tendenciaPais = -1;
            setPorcentagemTendenciaPais(porcentagem*100);
        }
        else{
            tendenciaPais = 0;
            setPorcentagemTendenciaPais(porcentagem*100);
        } //Estabilidade
    }
}

void Nacional::setPorcentagemTendenciaPais(double porcentagem){
    porcentagemTendenciaPais = porcentagem;
}

void Nacional::fimFuncao(){
    cout<<"-------------------------------------------------------\n\n";
}

void Nacional::printaMediaMovelPais(){
    cout<<"Media Movel"<<endl;
    for(int unsigned i=0;i<mediaMovelPais.size();i++){
        cout<<"Dia"<<i<<": "<<mediaMovelPais[i]<<endl;
    }

    cout<<"Tendecia: "<<getTendenciaPais()<<" e Porcentagem:  "<<getPorcentagemTendenciaPais()<<endl;
    fimFuncao();
}

void Nacional::printaMortesPorDiaPais(){
    cout<<"Mortes Por Dia"<<endl;
    for(int unsigned i=0;i<mortesPorDiaPais.size();i++){
        cout<<"Dia"<<i<<": "<<mortesPorDiaPais[i]<<endl;
    }
    fimFuncao();
}

int Nacional::getTendenciaPais(){return tendenciaPais;}
double Nacional::getPorcentagemTendenciaPais(){return porcentagemTendenciaPais;}