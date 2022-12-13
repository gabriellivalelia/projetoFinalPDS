#include <iostream>
#include "Biblioteca.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    Biblioteca BibliotecaTeste = Biblioteca();

    BibliotecaTeste.preencher_livros();

    BibliotecaTeste.get_livros_autor("Júlia Queen");


    return 0;
}
