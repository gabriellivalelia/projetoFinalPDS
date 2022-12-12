#ifndef TRAB_PDS2_BIBLIOTECA_H
#define TRAB_PDS2_BIBLIOTECA_H


#include <iostream>
#include <fstream>
#include<string.h>
#include <vector>
#include "Livro.h"
#include "Usuario.h"


class Biblioteca
{
    private:
        std::vector<Livro>_livros_estoque;
        std::vector<Pessoa>_pessoas;
        std::vector<std::pair<Livro, std::vector<Pessoa>>> _listas_espera;

        std::fstream _arquivo_Livros;
        std::fstream _arquivo_pessoas;

    public:

        Biblioteca();
        void get_livros_nome(std::string nome);
        void get_livros_autor(std::string autor);
        void get_livros_genero(std::string genero);

       /*  void preencher_livros(std::string path);//trocar pra private??
        void preencher_pessoas(std::string path); */

        void devolver_livro_alugado(Livro livro, Usuario usuario);
        void adicionar_livro_alugado(Livro livro, Usuario usuario);

        /*void update_estoque(Livro livro);
        void update_pessoas(Pessoa pessoa);

        bool pessoa_existe(string nome);
        bool login(Pessoa pessoa);

        void update_lista_espera(Livro livro, Pessoa pessoa); */

};
#endif
