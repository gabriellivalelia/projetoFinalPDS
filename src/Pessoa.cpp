#include "Pessoa.h"

#include <string> //??
using namespace std;

Pessoa::Pessoa(
  string nome,
  string senha
) 
{
    this->_nome = nome;
    this->_senha = senha;
}

string Pessoa::get_nome() {

}

unsigned int Pessoa::get_senha() {

}

void Pessoa::Logar(
    string nome,
    unsigned int senha
){

}
