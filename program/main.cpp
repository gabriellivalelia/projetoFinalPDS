#include <iostream>
#include "Biblioteca.h"
#include "Usuario.h"


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

    Usuario* Pedro = (Usuario*)BibliotecaTeste.get_pessoa_logada();
    std::cout<< BibliotecaTeste.get_pessoa_logada() << std::endl;
    std::cout<< (Usuario*)BibliotecaTeste.get_pessoa_logada()<< std::endl;


    BibliotecaTeste.add_lista_espera(*(BibliotecaTeste.get_livro_especifico("O Visconde que me amava")));
    BibliotecaTeste.ver_listas_espera();
    BibliotecaTeste.devolver_livro_alugado(*(BibliotecaTeste.get_livro_especifico("O Visconde que me amava")), *Pedro );
    BibliotecaTeste.update_lista_de_espera();
    return 0;
}