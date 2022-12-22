#include <algorithm>
#include <stdlib.h>
#include <iostream>

#include "Biblioteca.h"
#include "Usuario.h"
#include "doctest.h"


TEST_CASE("Testes Biblioteca - B") {

    Biblioteca teste = Biblioteca();
    teste.preencher_livros();
    teste.preencher_pessoas();

    CHECK_EQ(teste.usuario_existe("Antonella Santos") , true);
    CHECK_EQ(teste.usuario_existe("Rodolfo") , false);

    CHECK_EQ(teste.bibliotecario_existe("Ana Sales") , true);
    CHECK_EQ(teste.bibliotecario_existe("Antonella Santos") , false);

    CHECK_EQ(teste.livro_existe("Frankenstein"), true);

    Livro* livroTeste = teste.get_livro_especifico("Frankenstein");
    CHECK_EQ(livroTeste->get_titulo(), "Frankenstein");
}

TEST_CASE("Testes Biblioteca - A") {
    Biblioteca teste = Biblioteca();
    teste.preencher_livros();
    teste.preencher_pessoas();

    Usuario* usuarioTeste = teste.get_usuario_especifico("Mateus Pardini");
    CHECK_EQ("Mateus Pardini", usuarioTeste->get_nome());

    Usuario* usuarioTeste2 = teste.get_usuario_especifico("Mateus");
    CHECK_EQ(nullptr, usuarioTeste2);

    Bibliotecario* bibTeste = teste.get_bibliotecario_especifico("Ana Sales");
    CHECK_EQ("Ana Sales", bibTeste->get_nome());

    Bibliotecario* bibTeste2 = teste.get_bibliotecario_especifico("Mateus Pardini");
    CHECK_EQ(nullptr, bibTeste2);

    Livro testeLivroAdd = Livro("Biblia", "Apóstolos" , "Religioso", 1 );
    teste.adiciona_livros_no_estoque(testeLivroAdd);
    Livro* livroAdicionadoTeste = teste.get_livro_especifico("Biblia");
    CHECK_EQ(testeLivroAdd.get_titulo(), livroAdicionadoTeste->get_titulo());

    Usuario* testeUsuarioAdd = new Usuario("Julia Monteiro", "123456");
    teste.adiciona_usuarios_no_vetor(testeUsuarioAdd);
    Usuario* usuarioAdicionadoTeste = teste.get_usuario_especifico("Julia Monteiro");
    CHECK_EQ(testeUsuarioAdd->get_nome(), usuarioAdicionadoTeste->get_nome());

    Bibliotecario* testeBibliotecarioAdd = new Bibliotecario("Luciene Monteiro", "123456");
    teste.adiciona_bibliotecarios_no_vetor(testeBibliotecarioAdd);
    Bibliotecario* bibliotecarioAdicionadoTeste = teste.get_bibliotecario_especifico("Luciene Monteiro");
    CHECK_EQ(testeBibliotecarioAdd->get_nome(), bibliotecarioAdicionadoTeste->get_nome());
}
