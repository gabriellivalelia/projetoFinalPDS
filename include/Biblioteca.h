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

#include <exception>

class ErroGenericoException : public std::exception {
    public:
    virtual const char* what() const noexcept {
        return "O programa apresenta um erro!";
    }
};

class ErroAutorNaoEncontradoException : public ErroGenericoException {
    public:
    virtual const char* what() const noexcept {
        return "Lamentamos, mas não temos exemplares desse autor. Faça outra Pesquisa :)";
    }
};

class ErroAutorVazioException : public ErroGenericoException {
    public:
    virtual const char* what() const noexcept {
        return "Digite um autor para fazer a pesquisa.";
    }
};

class ErroGeneroNaoEncontradoException : public ErroGenericoException {
    public:
     char* what() {
        return "Lamentamos, mas não temos exemplares desse gênero. Faça outra Pesquisa :)";
    }
};

class ErroGeneroVazioException : public ErroGenericoException {
    public:
     char* what() {
        return "Digite um gênero para fazer a pesquisa.";
    }
};

class ErroNomeNaoEncontradoException : public ErroGenericoException {
    public:
    virtual const char* what() const noexcept {
        return "Lamentamos, mas não temos exemplares desse título. Faça outra Pesquisa :)";
    }
};

class ErroNomeVazioException : public ErroGenericoException {
    public:
    virtual const char* what() const noexcept {
        return "Digite um título para fazer a pesquisa.";
    }
};

class Biblioteca
{
    private:
        std::vector<Livro>_livros_estoque;
        std::vector<Pessoa>_pessoas;
        std::vector<std::pair<Livro, std::vector<Pessoa>>> _listas_espera;
        Pessoa* _pessoaLogada;

    public:

        Biblioteca();
        void get_livros_nome(std::string nome);
        void get_livros_autor(std::string autor);
        void get_livros_genero(std::string genero);
        Pessoa* get_pessoa_logada();

        void preencher_livros();
        void preencher_pessoas();

        void devolver_livro_alugado(std::string titulo);
        void adicionar_livro_alugado(std::string titulo);

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

        Pessoa* get_pessoa_especifica(std::string nome);
        Livro* get_livro_especifico(std::string titulo);

};
#endif
