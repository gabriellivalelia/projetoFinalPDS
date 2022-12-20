#include "Pessoa.h"

/**
 * Cria uma nova pessoa.
 * @brief Constructor.
 * @param nome O nome da pessoa.
 * @param senha A senha da pessoa.
 * @param isBibliotecario True caso seja um Bibliotecário e false caso seja um usuário.
 */
Pessoa::Pessoa(
  std::string nome,
  std::string senha,
  bool isBibliotecario
  
) {
    this->_nome = nome;
    this->_senha = senha;
    this->_isBibliotecario = isBibliotecario;
}

/**
 * Cria uma nova pessoa.
 * @brief Constructor.
 * @param nome O nome da pessoa.
 * @param senha A senha da pessoa.
 */
Pessoa::Pessoa(
  std::string nome,
  std::string senha
) {
    this->_nome = nome;
    this->_senha = senha;    
}

/**
 * @brief Obtém o nome da pessoa corrente.
 * @return Nome da pessoa corrente.
 */
std::string Pessoa::get_nome() {
    return _nome;
}

/**
 * @brief Obtém a senha da pessoa corrente.
 * @return Senha da pessoa corrente.
 */ 
std::string Pessoa::get_senha() {
    return _senha;
}

/**
 * @brief Obtém o tipo da pessoa corrente.
 * @return True caso seja um Bibliotecário e false caso seja um usuário.
 */
bool Pessoa::get_tipo(){
   return _isBibliotecario;
}




