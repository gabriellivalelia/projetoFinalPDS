#ifndef TRAB_PDS2_PESSOA_H
#define TRAB_PDS2_PESSOA_H

#include "Livro.h"
#include <string>

/** 
* @brief Classe Pessoa que contém os atributos e métodos base dos dois tipos de usuário de nosso sistema. 
*/ 
class Pessoa {
    public:
    private:
        /**
         * Nome da pessoa.
         */   
        std::string _nome;
        /**
         * Senha da pessoa.
         */   
        std::string _senha;
        /**
         * Booleano que recebe true caso a pessoa seja do tipo "Bibliotecário" e false caso seja do tipo "Usuário".
         */   
        bool _isBibliotecario;

    public:
    

    /**
     * Cria uma nova pessoa.
     * @brief Constructor.
     * @param nome O nome da pessoas.
     * @param senha A senha da pessoa.
     */
    Pessoa(
        std::string nome,
        std::string senha
    );
    /**
     * Cria uma nova pessoa.
     * @brief Constructor.
     * @param nome O nome da pessoas.
     * @param senha A senha da pessoa.
     * @param isBibliotecario True caso seja um Bibliotecário e false caso seja um usuário.
     */
    Pessoa(
        std::string nome,
        std::string senha,
        bool isBibliotecario
    );
    /**
     * @brief Obtém o nome da pessoa corrente.
     * @return Nome da pessoa corrente.
     */
    std::string get_nome();
    /**
     * @brief Obtém a senha da pessoa corrente.
     * @return Senha da pessoa corrente.
     */    
    std::string get_senha();
    /**
     * @brief Obtém o tipo da pessoa corrente.
     * @return True caso seja um Bibliotecário e false caso seja um usuário.
     */
    virtual bool get_tipo();
    
};

#endif
