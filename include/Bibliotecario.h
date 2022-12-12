#ifndef PDS2_BIBLIOTECARIO_H
#define PDS2_BIBLIOTECARIO_H

using namespace std;
#include "Pessoa.h"
#include "Usuario.h"
#include <string>

class Bibliotecario : public Pessoa 
{
    public:
    Bibliotecario
    (
        string nome,
        string senha
    );

};

#endif
