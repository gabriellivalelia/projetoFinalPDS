#ifndef TRAB_PDS2_BIBLIOTECA_H
#define TRAB_PDS2_BIBLIOTECA_H


#include <iostream>
#include <string.h>
#include <vector>
#include "Livro.h"
#include "Pessoa.h"
#include "Usuario.h"
#include "Bibliotecario.h"

/** 
* @brief Classe Biblioteca que funciona como a classe que gerencia todo o sistema. 
*/ 
class Biblioteca
{
    private:
        /**
         * Vetor do tipo Livro que contém todos os livros do sistema.
         */ 
        std::vector<Livro>_livros_estoque;

        /**
         * Vetor do tipo Bibliotecário* que contém todos os bibliotecários do sistema.
         */ 
        std::vector<Bibliotecario*>_bibliotecarios;

        /**
         * Vetor do tipo Usuário* que contém todos os usuários do sistema.
         */ 
        std::vector<Usuario*> _usuarios;

        /**
         * Vetor de pares, .onde o primeiro termo é o do tipo Livro* e o segundo do tipo vector do tipo Usuário*, esse último que contém o ponteiro 
        que referencia a cada pessoa na lista de espera do primeiro, o Livro, por ordem de solicitação.
         */ 
        std::vector<std::pair<Livro*, std::vector<Usuario*>>> _listas_espera;

        /**
         * Endereço de memória que referencia ao usuário que logou, no vetor _usuarios, caso quem esteja logado seja do tipo Usuario.
         Caso contrário armazena um nullptr.
         */ 
        Usuario* _usuarioLogado;

        /**
         * Endereço de memória que referencia ao bibliotecário que logou, no vetor _bibliotecarios, caso quem esteja logado seja do tipo Bibliotecário.
         Caso contrário armazena um nullptr.
         */ 
        Bibliotecario* _bibliotecarioLogado;

    public:
        /**
         * Cria um novo livro.
         * @brief Constructor.
         */
        Biblioteca();

        /**
         * @brief Busca e imprime os dados de um livro a partir de seu título.
         * @param nome Título do livro que será buscado.
         * @return True caso o livro se encontrado e false caso não.
         */
        bool get_livros_nome(std::string nome);

        /**
         * @brief Busca e imprime os dados de todos os livros de um autor, caso existam, e uma mensagem de alerta, caso não.
         * @param autor O nome do autor que será buscado.
         */
        void get_livros_autor(std::string autor);

        /**
         * @brief Busca e imprime os dados de todos os livros de um gênero, caso existam, e uma mensagem de alerta, caso não.
         * @param genero O genero que será buscado.
         */
        void get_livros_genero(std::string genero);

        /**
         * @brief Preenche o vetor de livros com livros pré determinados a cada inicialização do programa.
         */
        void preencher_livros();

        /**
         * @brief Preenche o vetor de usuários e bibliotecários com dados pré determinados a cada inicialização do programa.
         */
        void preencher_pessoas();

        /**
         * @brief Remove o livro do vetor de livros alugados do usuário logado e aumenta a quantidade de exemplares disponíveis em 1 do livro devolvido.
         * @param titulo O Título do livro que será devolvido.
         */
        void devolver_livro_alugado(std::string titulo);

        /**
         * @brief Adiciona o livro no vetor de livros alugados do usuário logado e diminuí a quantidade de exemplares disponíveis em 1 do livro alugado.
         * @param titulo O Título do livro que será alugado.
         */
        void adicionar_livro_alugado(std::string titulo);

        /**
         * @brief Cha a a função de ver todos os livros alugados do usuário logado.
         */
        void ver_livros_alugados();

        /**
         * @brief Cadastra um novo livro no sistema.
         * @param livro O livro que será cadastrado.
         */
        void adiciona_livros_no_estoque(Livro livro);

        /**
         * @brief Cadastra um novo usuário no sistema.
         * @param usuario O endereço de memória do usuário que será cadastrado.
         */
        void adiciona_usuarios_no_vetor(Usuario* usuario);

        /**
         * @brief Cadastra um novo bibliotecário no sistema.
         * @param bibliotecario O endereço de memória do bibliotecário que será cadastrado.
         */
        void adiciona_bibliotecarios_no_vetor(Bibliotecario* bibliotecario);
        
        /**
         * @brief Busca por um usuário no sistema através do nome.
         * @param nome Nome do usuário que será buscado.
         * @return True caso encontre e false caso não.
         */
        bool usuario_existe(std::string nome);

        /**
         * @brief Busca por um bibliotecário no sistema através do nome.
         * @param nome Nome do biliotecário que será buscado.
         * @return True caso encontre e false caso não.
         */
        bool bibliotecario_existe(std::string nome);

        /**
         * @brief Busca por um livro no sistema através do título.
         * @param titulo Título do livro que será buscado.
         * @return True caso encontre e false caso não.
         */
        bool livro_existe(std::string titulo);

        /**
         * @brief Função de Login do sistema.
         * @param isAdm Variável do tipo bool* que recebe true caso o login seja bem sucedido e feito por um bibliotecário e false caso seja feito
        por um usuário. Essa variável é usada no controle de manipulação dos métodos na main.
         * @return True caso o login seja bem sucedido e false caso não.
         */
        bool login(bool* isAdm);

        /**
         * @brief Função de Logout do sistema.
         * @return True caso o logout seja bem sucedido e false caso não.
         */
        bool logout();

        /**
         * @brief Adiciona o usuário logado na lista de espera do livro passado como parâmetro.
         * @param livro endereço de memória do livro, no vetor da biblioteca.
         */
        void add_lista_espera(Livro* livro);

        /**
         * @brief Imprime todos os livros e os respectivos nome das pessoas que estão em listas de epsera do mesmo do vetor _listas_de_espera.
         */
        void ver_listas_espera();

        /**
         * @brief Caso algum livro que tenha lista de espera fique com quantidade de exemplares disponíveis maior que zero, aloca o livro para 
        a primeira pessoa da lista e a remove da lista de espera.
         */
        void update_lista_de_espera();

        /**
         * @brief Caso algum livro que tenha lista de espera fique sem pessoas na lista, remove o pair do vetor listas_de_espera.
         */
        void limpar_lista_de_espera();

        /**
         * @brief Imprime todos os livros do sistema.
         */
        void imprime_livros();

        /**
         * @brief Imprime todas as pessoas do sistema ( Usuários e Bibliotecários ).
         */
        void imprime_pessoas();

        /**
         * @brief Busca por um usuário específico no sistema pelo nome.
         * @param nome Nome do usuário que será buscado.
         * @return O ponteiro do usuário caso encontre e nullptr caso não.
         */
        Usuario* get_usuario_especifico(std::string nome);

        /**
         * @brief Busca por um bibliotecário específico no sistema pelo nome.
         * @param nome Nome do bibliotecário que será buscado.
         * @return O ponteiro do bibliootecário caso encontre e nullptr caso não.
         */
        Bibliotecario* get_bibliotecario_especifico(std::string nome);

        /**
         * @brief Busca por um livro específico no sistema pelo título.
         * @param titulo Título do livro que será buscado.
         * @return O ponteiro do livro caso encontre e nullptr caso não.
         */
        Livro* get_livro_especifico(std::string titulo);

};
#endif
