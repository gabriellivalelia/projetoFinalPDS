#include "Pessoa.h"


Pessoa::Pessoa(
  std::string nome,
  std::string senha,
  bool isBibliotecario
  
) 
{
    this->_nome = nome;
    this->_senha = senha;
    this->_isBibliotecario = isBibliotecario;
}

Pessoa::Pessoa(
  std::string nome,
  std::string senha
) 
{
    this->_nome = nome;
    this->_senha = senha;    
}

std::string Pessoa::get_nome() {
    return _nome;
}

std::string Pessoa::get_senha() {
    return _senha;
}

bool Pessoa::get_tipo(){
   return _isBibliotecario;
}




