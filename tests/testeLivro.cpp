#include "doctest.h"
#include "Livro.h"

TEST_CASE("Teste dos métodos get") {

  Livro LivroTeste = Livro(
        "Arte da Guerra",
        "Pedro Dantas",
        "Leitura",
        2
    );

  CHECK_EQ("Arte da Guerra", LivroTeste.get_titulo());
  CHECK_EQ("Pedro Dantas", LivroTeste.get_autor());
  CHECK_EQ("Leitura", LivroTeste.get_genero());
  CHECK_EQ(2, LivroTeste.get_quantidade());  
}

TEST_CASE("Teste dos método update quantidade") {

  Livro LivroTeste = Livro(
        "Arte da Guerra",
        "Pedro Dantas",
        "Leitura",
        2
    );

  LivroTeste.update_quantidade(-2);

  CHECK_EQ(0, LivroTeste.get_quantidade());  
}


