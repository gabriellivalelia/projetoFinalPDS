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

        std::fstream _arquivo_Livros;
        std::fstream _arquivo_pessoas;
    
    public:        
        
        Biblioteca();
        std::vector<livro> get_livros_nome(std::string nome);
        std::vector<livro> get_livros_autor(std::string autor);
        std::vector<livro> get_livros_genero(std::string genero);

        std::vector<livro> preencher_livros(std::string path);
        std::vector<livro> preencher_pessoas(std::string path);


        void update_estoque(Livro livro);
        void update_pessoas(Pessoa pessoa);

        bool pessoa_existe(string nome);
        bool login(Pessoa pessoa);
};
