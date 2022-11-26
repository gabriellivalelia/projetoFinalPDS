#ifndef TRAB_PDS2_USUARIO_H
#define TRAB_PDS2_USUARIO_H

#include "Pessoa.h"
#include "Livro.h"
#include <vector>
#include <string>

class Usuario : public Pessoa {
    private:
        vector<Livro> _livros_alugados;
    public:
        Usuario(
            string nome,
            unsigned int senha
        );
        void alugar_livro(Livro livro);
        void devolver_livro(Livro livro);
        void visualizar_livros_alugados();
};

#endif
