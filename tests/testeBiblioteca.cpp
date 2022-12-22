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

    CHECK_EQ(livro_existe("Frankenstein"), true);

    Livro livroTeste = teste.get_livro_especifico("Frankenstein");
    CHECK_EQ(livroTeste.get_titulo(), "Frankenstein");
}
