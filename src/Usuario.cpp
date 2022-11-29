#include "Usuario.h"
#include "Livro.h"
#include <string>

Usuario::Usuario(
    string nome,
    string senha
    //Tipo tipo
) : Pessoa(nome, senha){};

void Usuario::alugar_livro(Livro livro) {

}

void Usuario::devolver_livro(Livro livro) {

}

void Usuario::visualizar_livros_alugados() {

}