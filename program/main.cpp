#include <iostream>
#include "Biblioteca.h"

int main()
{

    Biblioteca BibliotecaTeste = Biblioteca();
    BibliotecaTeste.preencher_livros();
    BibliotecaTeste.preencher_pessoas();

    while(!BibliotecaTeste.login())
    {
        system("cls");
        std::cout << "Nome nao encontrado. Tente novamente." << std::endl;
        //codigo vai ficar enrolando aqui enquanto o login não for realizado
    }

    return 0;
}
