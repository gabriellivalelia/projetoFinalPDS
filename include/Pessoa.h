#ifndef TRAB_PDS2_PESSOA_H
#define TRAB_PDS2_PESSOA_H

#include <Livro.h>
#include <string>
using namespace std;

// enum class Tipo {BIBLIOTECARIO, USUARIO};

class Pessoa {
    public:
    private:  
        string _nome;
        string _senha;
       // Tipo _tipo;

    public:
    Pessoa(
        string nome,
        string senha
        //Tipo tipo
    );
    string get_nome();    
    string get_senha();
    // Tipo get_tipo();
    
    void Logar(
        string nome,
        string senha
    );
    };

#endif
