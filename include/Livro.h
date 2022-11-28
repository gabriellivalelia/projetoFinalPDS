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
        static unsigned int _quantidade;
        std::vector <Usuario>; 

    public:
        Livro(
            std::string titulo,
            std::string autor,
            std::string genero,
            stact unsigned int quantidade
        );
        std::string get_titulo();
        std::string get_autor();
        std::string get_genero();
        unsigned int get_quantidade();
        void uppdate_quantidade();
};

#endif
