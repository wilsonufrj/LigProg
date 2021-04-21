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
    cout<<fixed<<setprecision(2)<<"com "<<getPorcentagemTendenciaPais()<<" % na media movel de casos"<<endl;

    cout<<"\nESTADOS EM ALTA"<<endl;
    for(int unsigned i=0;i<alta.size();i++){
        cout<<alta[i].getNomeEstado()<<
        " com "<<fixed<<setprecision(2)<<alta[i].getPorcentagemTendencia()<<
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
    cout<<"\t\t\tTOTAL DO NUMERO DE OBITOS"<<endl;
    for(Estadual estado:estados){
            totalBrasil+=estado.somaMortes();   
            cout<<"Estado: "<<estado.getNomeEstado()
            <<"\nTotal de Mortes: "<<estado.somaMortes()<<endl;
    }

    cout<<"Total de mortos no Brasil: "<<totalBrasil<<endl;
    fimFuncao();

}

void Nacional::mostrarEstatisticasEstados(){
        cout<<"\t\t\tESTATISTICAS DOS ESTADOS"<<endl;
    cout<<"ESTADO(S) EM ALTA"<<endl;
    for(int unsigned i=0;i<alta.size();i++){
        cout<<"\t-"<<alta[i].getNomeEstado()<<endl;
    }
    cout<<"ESTADO(S) EM ESTABILIDADE"<<endl;
    for(int unsigned i=0;i<estavel.size();i++){
        cout<<"\t-"<<estavel[i].getNomeEstado()<<endl;
    }
    cout<<"ESTADO(S) EM BAIXA"<<endl;
    for(int unsigned i=0;i<baixa.size();i++){
        cout<<"\t-"<<baixa[i].getNomeEstado()<<endl;
    }
    fimFuncao();
}

void Nacional::mostrarEstatisticaBrasil(){
        cout<<"\t\t\tESTATISTICAS NO BRASIL"<<endl;

    printaTendencia();
    fimFuncao();
}

void Nacional::printaTendencia(){
    if(tendenciaPais<0)
        cout<<"Brasil com BAIXA de casos"<<endl;
    else{
        if(tendenciaPais>0)
            cout<<"Brasil com ALTA de casos"<<endl;
        else
            cout<<"Brasil em ESTABILIDADE de casos"<<endl;
    }
}

void Nacional::estadosLimites(){
    cout<<"\t\t\tESTADOS LIMITES"<<endl;
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
    cout<<"ESTADO MAIOR ALTA  : "<<estadoMaiorAlta<<endl;
    cout<<"ESTADO MENOR BAIXA : "<<estadoMenorBaixa<<endl;

    fimFuncao();
}

void Nacional::setEstatistica(){
    for(Estadual estado:estados){
        if(estado.getTendencia()>0){
            alta.push_back(estado);
        }else{
            if(estado.getTendencia()<0){
                baixa.push_back(estado);
            }else{
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
    porcentagem = double((mediaMovelPais[mediaMovelPais.size()-1] - mediaMovelPais[mediaMovelPais.size()-2])/(mediaMovelPais[mediaMovelPais.size()-2]));
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



int Nacional::getTendenciaPais(){return tendenciaPais;}

double Nacional::getPorcentagemTendenciaPais(){return porcentagemTendenciaPais;}