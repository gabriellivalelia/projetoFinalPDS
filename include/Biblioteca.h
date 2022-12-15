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
        std::vector<Bibliotecario*>_bibliotecarios;
        std::vector<Usuario*> _usuarios;
        std::vector<std::pair<Livro*, std::vector<Usuario*>>> _listas_espera;
        Usuario* _usuarioLogado;
        Bibliotecario* _bibliotecarioLogado;

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
        void adiciona_usuarios_no_vetor(Usuario* usuario);
        void adiciona_bibliotecarios_no_vetor(Bibliotecario* bibliotecario);

        bool usuario_existe(std::string nome);
        bool bibliotecario_existe(std::string nome);

        bool login(bool* isAdm);
        bool logout();

        void add_lista_espera(Livro* livro);
        void ver_listas_espera();
        void update_lista_de_espera();
        void limpar_lista_de_espera();


        void imprime_livros();
        void imprime_pessoas();
        bool eh_super_user();

        Usuario* get_usuario_especifico(std::string nome);
        Bibliotecario* get_bibliotecario_especifico(std::string nome);
        Livro* get_livro_especifico(std::string titulo);

};
#endif
