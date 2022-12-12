#include "Livro.h"


Livro::Livro(
    std::string titulo,
    std::string autor,
    std::string genero,
    unsigned int quantidade
)
{
    _titulo = titulo;
    _autor = autor;
    _genero = genero;
    _quantidade = quantidade;
}

std::string Livro::get_titulo() {
    return _titulo;
}

std::string Livro::get_autor() {
   return _autor;
}

std::string Livro::get_genero() {
   return _genero;
}

unsigned int Livro::get_quantidade() {
    return _quantidade;
}

void Livro::update_quantidade(int updateQuantidade){

    if(updateQuantidade < 0 && abs(updateQuantidade) > _quantidade)
    {
        std::cout<< "Quantidade insuficiente para essa operação!" <<std::endl;
    }
    else
    {
       _quantidade = (unsigned int) _quantidade +  updateQuantidade; 
    }

    
} 