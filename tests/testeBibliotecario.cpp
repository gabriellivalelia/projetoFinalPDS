#include "doctest.h"
#include "Bibliotecario.h"

TEST_CASE("Teste dos gets") {

  Bibliotecario BibliotecarioTeste = Bibliotecario(
        "Maria",
        "12345@"
    );

  CHECK_EQ("Maria", BibliotecarioTeste.get_nome());
  CHECK_EQ("12345@", BibliotecarioTeste.get_senha());
  CHECK_EQ(true, BibliotecarioTeste.get_tipo());
  
}