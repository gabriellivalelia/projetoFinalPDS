#include "Bibliotecario.h"

#include <string>

Bibliotecario::Bibliotecario
(
    std::string nome,
    std::string senha
) : Pessoa(nome, senha, true){}

