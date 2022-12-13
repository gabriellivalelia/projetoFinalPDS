#include <iostream>
#include "Biblioteca.h"

int main()
{
    //std::cout << "Hello World!" << std::endl;
    //se transformar a biblioteca em uma classe estática, não vai precisar de criar instância
    Biblioteca BibliotecaTeste = Biblioteca();
    BibliotecaTeste.preencher_livros();
    

    BibliotecaTeste.get_livros_autor("Júlia Queen");

    while(!BibliotecaTeste.login())
    {
        system("cls");
        std::cout << "Nome nao encontrado. Tente novamente." << std::endl;
        //codigo vai ficar enrolando aqui enquanto o login não for realizado
    }

    //continuar embaixo
    return 0;
}
