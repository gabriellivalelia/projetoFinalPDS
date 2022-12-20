#ifndef TRAB_PDS2_USUARIO_H
#define TRAB_PDS2_USUARIO_H

#include "Pessoa.h"
#include "Livro.h"
#include <vector>
#include <string>
#include <iostream>

/** 
* @brief Classe Usuário que abstrai o usuário que pode alugar livros no sistema, devolvê-los e afins. Herda de Pessoa. 
*/ 
class Usuario : public Pessoa {
    private:
        /**
         * Vetor do tipo Livro que armazena os Livros que o usuário corrente alugou.
         */  
        std::vector<Livro> _livros_alugados;
    public:
        /**
         * Cria um novo usuário.
         * @brief Constructor.
         * @param nome O nome do usuário.
         * @param senha A senha do usuário.
         */
        Usuario(
            std::string nome,
            std::string senha
        );

        /**
         * @brief Imprime todos os livros alugados pelo usuário corrente.
         * @exception Caso o usuário não tiver livros alugados imprime um alerta indicando isso.
         */
        void visualizar_livros_alugados();

        /**
         * @brief Adiciona um livro no vetor de livros alugados pelo usuário corrente.
         * @param livro O livro que será adicionado.
         * @exception Caso o livro já esteja no vetor, um alerta e impresso indicando isso e o livro não é inserido.
         * @return True caso a ação seja bem sucedida, o que acontece caso esse livro ainda não exista no vetor, e false caso contrário.
         */
        bool adicionar_livro_no_vetor(Livro livro);

        /**
         * @brief Remove um livro do vetor de livros alugados pelo usuário corrente.
         * @exception Caso o livro não esteja no vetor de livros alugaar, um alerta é impresso indicando isso.
         * @param livro O livro que será removido.
         */
        void excluir_livro_do_vetor(Livro livro);


};

#endif
