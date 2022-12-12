#ifndef TRAB_PDS2_LIVRO_H
#define TRAB_PDS2_LIVRO_H

#include <vector>
#include <string>
#include <math.h>
#include <iostream>

class Livro {
    private:
        std::string _titulo;
        std::string _autor;
        std::string _genero;
        unsigned int _quantidade;

    public:
        Livro(
            std::string titulo,
            std::string autor,
            std::string genero,
            unsigned int quantidade
        );

        std::string get_titulo();
        std::string get_autor();
        std::string get_genero();
        unsigned int get_quantidade();
        void update_quantidade(int updateQuantidade);
};

#endif
