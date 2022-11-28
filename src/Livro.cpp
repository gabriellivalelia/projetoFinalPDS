#include "Livro.h"


Livro::Livro(
    std::string titulo,
    std::string autor,
    std::string genero,
    static unsigned int quantidade,
)
{
    _titulo = titulo;
    _autor = autor;
    _genero = genero;
    _quantidade = quantidade;
}

string Livro::get_titulo() {

}

string Livro::get_autor() {

}

string Livro::get_genero() {

}

unsigned int Livro::get_quantidade() {
    return _quantidade;
}

void Livro::update_quantidade(){

}