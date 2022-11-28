#ifndef TRAB_PDS2_PESSOA_H
#define TRAB_PDS2_PESSOA_H

#include <string>
using namespace std;

class Pessoa {
    private:  
        string _nome;
        string _senha;


    public:
    Pessoa(
        string nome,
        string senha
    );
    string get_nome();    
    string get_senha();
    
    void Logar(
        string nome,
        string senha
    );
    };

#endif
