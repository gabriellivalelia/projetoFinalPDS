#ifndef TRAB_PDS2_USUARIO_H
#define TRAB_PDS2_USUARIO_H

#include "Pessoa.h"
#include "Livro.h"
#include <vector>
#include <string>
#include <iostream>

class Usuario : public Pessoa {
    private:
        std::vector<Livro> _livros_alugados;
    public:
        Usuario(
            std::string nome,
            std::string senha
        );
        void visualizar_livros_alugados();

        void adicionar_livro_no_vetor(Livro livro);

        void excluir_livro_do_vetor(Livro livro);

};

#endif
