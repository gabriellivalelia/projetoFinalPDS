#include "Pessoa.h"

#include <string> //??
using namespace std;

Pessoa::Pessoa(
  string nome,
  string senha
  //Tipo tipo
) 
{
    this->_nome = nome;
    this->_senha = senha;
    //this->_tipo = tipo;
}

string Pessoa::get_nome() {

}

string Pessoa::get_senha() {

}

void Pessoa::Logar(
    string nome,
    string senha
){

}

// Tipo Pessoa::get_tipo(){

// };
