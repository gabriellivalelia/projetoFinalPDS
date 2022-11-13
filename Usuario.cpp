#include "Usuario.h"
#include "Livro.h"

Usuario::Usuario(
    string nome,
    unsigned int senha
) : Pessoa(nome, senha){};

void Usuario::alugar_livro(Livro livro) {

}

void Usuario::devolver_livro(Livro livro) {

}

void Usuario::visualizar_livros_alugados() {

}
