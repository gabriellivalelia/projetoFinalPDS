#ifndef TRAB_PDS2_PESSOA_H
#define TRAB_PDS2_PESSOA_H

#include <string>
using namespace std;

class Pessoa {
    private:  
        string _nome;
        unsigned int _senha;

    public:
    Pessoa(
        string nome,
        unsigned int senha
    );
    string get_nome();
    string get_senha();
    void Logar(
        string nome,
        unsigned int senha
    );
    };

#endif