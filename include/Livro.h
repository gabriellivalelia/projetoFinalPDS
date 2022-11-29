#ifndef TRAB_PDS2_LIVRO_H
#define TRAB_PDS2_LIVRO_H

#include "Pessoa.h"
//#include "Usuario.h"
#include <vector>
#include <string>

class Livro {
    private:
        std::string _titulo;
        std::string _autor;
        std::string _genero;
        unsigned int _quantidade;
        //std::vector <Usuario> _lista_espera; 

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
        void update_quantidade();
};

#endif
