#ifndef TRAB_PDS2_LIVRO_H
#define TRAB_PDS2_LIVRO_H

#include "Pessoa.h"
#include "Usuario.h"
#include <vector>
#include <string>

class Livro {
    private:
        std::string _titulo;
        std::string _autor;
        std::string _genero;
        stact unsigned int _quantidade;
        std vector <Usuario:: Usuario> 



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
