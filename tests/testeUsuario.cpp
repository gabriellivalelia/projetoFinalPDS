#include "doctest.h"
#include "Usuario.h"

//testa construtor
TEST_CASE("Testar construtos para entrada de strings corretas") {
    Usuario UsuarioTeste = Usuario(
        "Maria Silva",
        "123456"
    );

  CHECK_EQ("Maria Silva", UsuarioTeste.get_nome());
  CHECK_EQ("123456", UsuarioTeste.get_senha());
}

TEST_CASE("Testar construtos para entrada de strings incorretas") {
    Usuario UsuarioTeste = Usuario(
        "María",
        "@@"
    );

  CHECK_EQ("María", UsuarioTeste.get_nome());
  CHECK_EQ("@@", UsuarioTeste.get_senha());
}

//testa visualizar_livros_alugados
// TEST_CASE("Testar metodo quando não há locações") { -> precisa retornar vetor
//     Usuario UsuarioTeste = Usuario(
//         "Maria Silva",
//         "123456"
//     );

//     CHECK_EQ("Voce nao tem livros alugados.", UsuarioTeste.visualizar_livros_alugados());
// }

// TEST_CASE("Testar metodo quando não há locações") {
//     Usuario UsuarioTeste = Usuario(
//         "Maria Silva",
//         "123456"
//     );

//     CHECK_EQ(0, UsuarioTeste._livros_alugados.size());
// }
