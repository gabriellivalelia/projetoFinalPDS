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


    BibliotecaTeste.add_lista_espera(*(BibliotecaTeste.get_livro_especifico("O Visconde que me amava")));
    BibliotecaTeste.ver_listas_espera();
    return 0;
}