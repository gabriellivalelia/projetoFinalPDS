#ifndef TRAB_PDS2_BIBLIOTECA_H
#define TRAB_PDS2_BIBLIOTECA_H


#include <iostream>
#include <fstream>
#include<string.h>
#include <vector>
#include "Livro.h"
#include "Usuario.h"
#include "Bibliotecario.h"


class Biblioteca
{
    private:
        std::vector<Livro>_livros_estoque;
        std::vector<Pessoa>_pessoas;
        std::vector<std::pair<Livro, std::vector<Pessoa>>> _listas_espera;

    public:

        Biblioteca();
        void get_livros_nome(std::string nome);
        void get_livros_autor(std::string autor);
        void get_livros_genero(std::string genero);

        void preencher_livros(); 
        void preencher_pessoas(); 

        void devolver_livro_alugado(Livro livro, Usuario usuario);
        void adicionar_livro_alugado(Livro livro, Usuario usuario);

        void adiciona_livros_no_estoque(Livro livro);
        void adiciona_pessoas_no_vetor(Pessoa pessoa);

        bool pessoa_existe(std::string nome);
        bool login();

        void update_lista_espera(Livro livro, Pessoa pessoa); 

        void imprime_livros();
        void imprime_pessoas();

};
#endif
