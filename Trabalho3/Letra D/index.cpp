#include<iostream>
#include"Jogo.h"
#include"globais.h"

using namespace std;
int main () {
/* Construtor da classe Jogo possui argumento que define
o número de personagens */
Jogo jogo (4);
/* Construtor da classe Personagem possui argumentos nome,
nível de força e nível de inteligência ----OK!!!*/
Personagem hulk ("Hulk", 90, 20);
Personagem homemDeFerro ("Homem de Ferro", 60, 90);
Personagem capitao ("Capitao America", 50, 70);

Personagem thor ("Thor", 80, 60);
/* Operador () sobrecarregado adiciona os personagens ao
jogo de forma cascateada----OK!! */
jogo(hulk)(homemDeFerro)(capitao)(thor);
/* Operador [] sobrecarregado retorna ponteiro para objeto
da classe Personagem a partir de índice---OK!!! e operador <<
sobrecarregado imprime todas as características do
personagem na tela---OK!! */
if (jogo ["Hulk"]) {
cout << jogo ["Hulk"];
} else {
cout << "\nPersonagem nao encontrado!" << endl;
}
if (jogo ["Homem Formiga"]) {
cout << jogo ["Homem Formiga"];
} else {
cout << "\nPersonagem nao encontrado!" << endl;
}
/* Operador [] sobrecarregado retorna ponteiro para objeto
da classe Personagem a partir de índice e operador <<
sobrecarregado imprime todas as características do
personagem na tela ---OK!!*/
cout << "\n== Personagens: " << endl;
for (unsigned i = 0; i < jogo.getNumeroPersonagens (); i++) {
cout << jogo [i];
}
/* Função global calculaEstatistica retorna ponteiro para
Personagem que possui maior força ou maior inteligência,
conforme o ponteiro para função passada como segundo
argumento */
cout << "\n*** Mais Forte:\n"
<< calculaEstatistica (jogo, maisforte);
cout << "\n*** Mais Inteligente:\n"
<< calculaEstatistica (jogo, maisinteligente);
return 0;
}