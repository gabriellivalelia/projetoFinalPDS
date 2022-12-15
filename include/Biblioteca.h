#ifndef TRAB_PDS2_BIBLIOTECA_H
#define TRAB_PDS2_BIBLIOTECA_H


#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "Livro.h"
#include "Pessoa.h"
#include "Usuario.h"
#include "Bibliotecario.h"


class Biblioteca
{
    private:
        std::vector<Livro>_livros_estoque;
        std::vector<Pessoa>_pessoas;
        std::vector<std::pair<Livro, std::vector<Pessoa>>> _listas_espera;
        Pessoa* _pessoaLogada;

    public:

        Biblioteca();
        bool get_livros_nome(std::string nome);
        void get_livros_autor(std::string autor);
        void get_livros_genero(std::string genero);


        void preencher_livros();
        void preencher_pessoas();

        void devolver_livro_alugado(std::string titulo);
        void adicionar_livro_alugado(std::string titulo);
        void ver_livros_alugados();

        void adiciona_livros_no_estoque(Livro livro);
        void adiciona_pessoas_no_vetor(Pessoa pessoa);

        bool pessoa_existe(std::string nome);

        bool login();
        bool logout();

        void add_lista_espera(Livro livro);
        void ver_listas_espera();
        void update_lista_de_espera();
        void limpar_lista_de_espera();


        void imprime_livros();
        void imprime_pessoas();
        bool eh_super_user();

        Pessoa* get_pessoa_especifica(std::string nome);
        Livro* get_livro_especifico(std::string titulo);

};
#endif
