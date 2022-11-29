#ifndef TRAB_PDS2_USUARIO_H
#define TRAB_PDS2_USUARIO_H

#include "Pessoa.h"
#include "Livro.h"
#include <vector>
#include <string>

class Usuario : public Pessoa {
    private:
        std::vector<Livro> _livros_alugados;
    public:
        Usuario(
            string nome,
            string senha
            //Tipo tipo
        );
        void alugar_livro(Livro livro);
        void devolver_livro(Livro livro);
        void visualizar_livros_alugados();
};

#endif
