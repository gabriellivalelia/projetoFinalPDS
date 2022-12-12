#ifndef TRAB_PDS2_PESSOA_H
#define TRAB_PDS2_PESSOA_H

#include <Livro.h>
#include <string>


class Pessoa {
    public:
    private:  
        std::string _nome;
        std::string _senha;
        bool _isBibliotecario;

    public:
    Pessoa(
        std::string nome,
        std::string senha,
        bool isBibliotecario
    );
    std::string get_nome();    
    std::string get_senha();
    bool get_tipo();
    
    void Logar(
        std::string nome,
        std::string senha
    );
    };

#endif
