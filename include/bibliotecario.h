#ifndef PDS2_BIBLIOTECARIO_H
#define PDS2_BIBLIOTECARIO_H

using namespace std;
#include "pessoa.h"
#include "usuario.h"

class Bibliotecario : Pessoa 
{
    public:
    Bibliotecario
    (
        string nome,
        unsigned int senha
    );

    void cadastrar_usuario();

    void adicionar_livros();

    void excluir_livros();
};
