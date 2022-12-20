#include "Livro.h"

/**
 * Cria um novo livro.
 * @brief Constructor.
 * @param titulo Título do livro.
 * @param autor Autor do livro.
 * @param genero Gênero do livro.
 * @param quantidade Quantidade de exemplares disponíveis desse livro no sistema.
 */
Livro::Livro(
    std::string titulo,
    std::string autor,
    std::string genero,
    unsigned int quantidade
) {
    _titulo = titulo;
    _autor = autor;
    _genero = genero;
    _quantidade = quantidade;
}

/**
 * @brief Obtém o título do livro corrente.
 * @return Título do livro corrente.
 */
std::string Livro::get_titulo() {
    return _titulo;
}

/**
 * @brief Obtém o autor do livro corrente.
 * @return Autor do livro corrente.
 */
std::string Livro::get_autor() {
   return _autor;
}

/**
 * @brief Obtém o gênero do livro corrente.
 * @return Gênero do livro corrente.
 */
std::string Livro::get_genero() {
   return _genero;
}

/**
 * @brief Obtém a quantidade de exemplares disponíveis do livro corrente.
 * @return Quantidade de exemplares disponíveis do livro corrente.
 */
unsigned int Livro::get_quantidade() {
    return _quantidade;
}

/**
 * @brief Altera a quantidade de exemplares disponíveis do livro corrente.
 * @exception Caso se queira diminuir uma quantidade de exemplares maior que a disponível, se imprimme um alerta. 
 * @param updateQuantidade Quantidade de exemplares que serão somados(se > 0) ou subtraídos ( se < 0 ) da quantidade atual.
 */
void Livro::update_quantidade(int updateQuantidade) {

    if(updateQuantidade < 0 && abs(updateQuantidade) > _quantidade)
    {
        std::cout<< "Quantidade insuficiente para essa operação!" <<std::endl;
    }
    else
    {
       _quantidade = (unsigned int) _quantidade +  updateQuantidade; 
    }
   
} 