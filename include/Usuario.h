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
        void visualizar_livros_alugados();
        void adicionar_livros();
        void excluir_livros();
};

#endif
