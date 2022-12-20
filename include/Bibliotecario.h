#ifndef PDS2_BIBLIOTECARIO_H
#define PDS2_BIBLIOTECARIO_H

using namespace std;
#include "Pessoa.h"
#include "Usuario.h"
#include <string>

/** 
* @brief Classe Bibliotecário que abstrai o usuário que pode administrar a biblioteca, adiconando livros e pessoas no sistema. Herda de Pessoa. 
*/ 
class Bibliotecario : public Pessoa 
{
    public:
    /**
     * Cria um novo bibliotecário.
     * @brief Constructor.
     * @param nome O nome do bibliotecário.
     * @param senha A senha do bibliotecário.
     */
    Bibliotecario(
        string nome,
        string senha
    );
};

#endif
