#include <iostream>
#include "Biblioteca.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    Biblioteca BibliotecaTeste = Biblioteca();

    BibliotecaTeste.preencher_livros();

    BibliotecaTeste.imprime_livros();


    return 0;
}
