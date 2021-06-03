#include"Produto.h"
#include "Carrinho.h"
using namespace std;

int main () {
Carrinho car (5);
Produto brinquedo ("brinquedo", "estrela", 90.00);
Produto arroz ("arroz", "Tio Joao", 20.00);
Produto pneu ("pneu", "Goodyear", 150.00);
car = car + brinquedo;
car = car + arroz;
car = car + pneu;
cout << "*** Completo\n" << car;
car = car - arroz;
cout << "*** Reduzido\n" << car;
{
// Cópia do carrinho é criada em um bloco interno à função principal
Carrinho carCopia (car);
cout << "\n*** Copia\n" << carCopia;
}
brinquedo.setPreco(200.00);
cout << "*** Com preco do brinquedo atualizado\n" << car;
return 0;
}