#ifndef TRAB_PDS2_LIVRO_H
#define TRAB_PDS2_LIVRO_H

#include <vector>
#include <string>
#include <math.h>
#include <iostream>

/** 
* @brief Classe Livro que abstrai os Livros da biblioteca. 
*/ 
class Livro {
    private:
        /**
         * Título do livro.
         */ 
        std::string _titulo;
        /**
         * Autor do livro.
         */ 
        std::string _autor;
        /**
         * Gênero do livro.
         */ 
        std::string _genero;
        /**
         * Quantidade de exemplares desse livro no sistema.
         */ 
        unsigned int _quantidade;

    public:
        /**
         * Cria um novo livro.
         * @brief Constructor.
         * @param titulo Título do livro.
         * @param autor Autor do livro.
         * @param genero Gênero do livro.
         * @param quantidade Quantidade de exemplares disponíveis desse livro no sistema.
         */
        Livro(
            std::string titulo,
            std::string autor,
            std::string genero,
            unsigned int quantidade
        );
        /**
         * @brief Obtém o título do livro corrente.
         * @return Título do livro corrente.
         */
        std::string get_titulo();
        /**
         * @brief Obtém o autor do livro corrente.
         * @return Autor do livro corrente.
         */
        std::string get_autor();
        /**
         * @brief Obtém o gênero do livro corrente.
         * @return Gênero do livro corrente.
         */
        std::string get_genero();
        /**
         * @brief Obtém a quantidade de exemplares disponíveis do livro corrente.
         * @return Quantidade de exemplares disponíveis do livro corrente.
         */
        unsigned int get_quantidade();
        /**
         * @brief Altera a quantidade de exemplares disponíveis do livro corrente.
         * @param updateQuantidade Quantidade de exemplares que serão somados(se > 0) ou subtraídos ( se < 0 ) da quantidade atual.
         */
        void update_quantidade(int updateQuantidade);
};

#endif
