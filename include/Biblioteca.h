#ifndef TRAB_PDS2_BIBLIOTECA_H
#define TRAB_PDS2_BIBLIOTECA_H
#include <iostream>
#include <fstream>
#include<string.h>
#include <vector>
#include "Livro.h"
#include "Pessoa.h"


class Biblioteca
{
    private:
        std::vector<Livro>_livros_estoque;
        std::vector<Pessoa>_pessoas;
        std::vector<std::pair<Livro, std::vector<Pessoa>>> _lista_espera;

        std::fstream _arquivo_Livros;
        std::fstream _arquivo_pessoas;

    public:

        Biblioteca();
        std::vector<Livro> get_livros_nome(std::string nome);
        std::vector<Livro> get_livros_autor(std::string autor);
        std::vector<Livro> get_livros_genero(std::string genero);

        void preencher_livros(std::string path);//trocar pra private??
        void preencher_pessoas(std::string path);

        void excluir_livro_alugado(Livro livro, Pessoa pessoa);
        void adicionar_livro_alugado(Livro livro, Pessoa pessoa);

        void update_estoque(Livro livro);
        void update_pessoas(Pessoa pessoa);

        bool pessoa_existe(string nome);
        bool login(Pessoa pessoa);

        void update_lista_espera(Livro livro, Pessoa pessoa);

};
#endif
