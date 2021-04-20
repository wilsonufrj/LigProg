#include"Estadual.h"

using namespace std;

Estadual::Estadual(const int vetorMortes[],int quantidadeDias,string nome){
    tendencia = 0;
    porcentagemTendencia = 0;
    setMortesPorDia(vetorMortes,quantidadeDias);
    setNomeEstado(nome);
    setMediaMovel();
    setTendencia();
    
}

//Funcionando
int Estadual::somaMortes(){
    int total=0;
    for(int dias: mortesPorDia){
            total+=dias;
    }
    return total;
}

void Estadual::setMortesPorDia(const int mortes[], int quantidade){
    for(int i=0;i<quantidade;i++){
        mortesPorDia.push_back(mortes[i]);
    }
}


void Estadual::setMediaMovel(){
    double media =0 ;
    mediaMovel.push_back(mortesPorDia[0]);
    mediaMovel.push_back(double(mortesPorDia[0]+mortesPorDia[1])/2.0);
    for(int unsigned i=2; i<mortesPorDia.size();i++){
        media = (mortesPorDia[i-2]+mortesPorDia[i-1]+mortesPorDia[i])/3.0;
        mediaMovel.push_back(media);
    }
}

void Estadual::setNomeEstado(string nome){
    nomeEstado = nome;
}

void Estadual::setTendencia(){
    double porcentagem;
    /*cout<<"Ultima media movel"<<mediaMovel[mediaMovel.size()-1]<<
    "Penultima mediaMovel "<< mediaMovel[mediaMovel.size()-2]<<
    endl;*/
    porcentagem = double((mediaMovel[mediaMovel.size()-1] - mediaMovel[mediaMovel.size()-2])/(mediaMovel[mediaMovel.size()-2]));
    //cout<<"Porcentagem: "<<porcentagem<<endl;
    //Alta
    if(porcentagem*100 >= 15){
        tendencia =1;
        setPorcentagemTendencia(porcentagem);
    }
    else{
        if(porcentagem*100 <= -15){ //Baixa
            tendencia = -1;
            setPorcentagemTendencia(porcentagem);
        }
        else{
            porcentagem = 0;
            setPorcentagemTendencia(porcentagem);
        } //Estabilidade
    }
}

void Estadual::setPorcentagemTendencia(double porcentagem){
    porcentagemTendencia = porcentagem;
}

void Estadual::printMediaMovel(){
    for(int unsigned i =0;i< mediaMovel.size();i++){
        cout<<mediaMovel[i]<<endl;
    }
}

string Estadual::getNomeEstado(){return nomeEstado;}
vector<double> Estadual::getMediaMovel(){return mediaMovel;}
int Estadual::getTendencia(){return tendencia;}
double Estadual::getPorcentagemTendencia(){return porcentagemTendencia;}