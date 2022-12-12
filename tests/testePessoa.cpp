#include "doctest.h"
#include "Pessoa.h"

TEST_CASE("Teste dos gets") {

  Pessoa PessoaTeste = Pessoa(
        "Amália",
        "12345@",
        false
    );

  CHECK_EQ("Amália", PessoaTeste.get_nome());
  CHECK_EQ("12345@", PessoaTeste.get_senha());
  CHECK_EQ(false, PessoaTeste.get_tipo());
  
}