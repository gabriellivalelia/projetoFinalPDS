#include "Bibliotecario.h"

#include <string>

/**
 * Cria um novo bibliotecário.
 * @brief Constructor.
 * @param nome O nome do bibliotecário.
 * @param senha A senha do bibliotecário.
 */
Bibliotecario::Bibliotecario( 
    std::string nome,
    std::string senha
) : Pessoa(nome, senha, true){}

