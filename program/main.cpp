#include <iostream>
#include "Biblioteca.h"
#include "Usuario.h"

#include <algorithm>
#include <stdlib.h>

/**
 * @brief Imprime todos os comandos disponíveis de acordo com o tipo de pessoa logada.
 * @param eh_admin True caso seja bibliotecário e false caso seja usuário.
 */
void imprimir_comandos(bool eh_admin) {
    if(eh_admin)
    {
        std::cout << "  VER - listar Pessoas cadastradas no sistema;" << std::endl; /////////////////////////////////////////////////
        std::cout << "  ADD PESSOA - Adiciona uma pessoa no sistema;" << std::endl; /////////////////////////////////////////////////
        std::cout << "  ADD LIVRO - Adiciona um livro no sistema;" << std::endl; ////////////////////////////////////////////////////
        std::cout << "  LOGOUT - Encerra a sessão;" << std::endl;////////////////////////////////////////////////////////////////////
        std::cout << "  HELP - Lista os comandos disponiveis;" << std::endl; ////////////////////////////////////////////////////////
        std::cout << "  VER ACERVO - Lista todos os livros no banco de dados" << std::endl;///////////////////////////////////////////
    }
    else
    {
        std::cout << "  PESQUISAR LIVRO TITULO - Busca o livro atraves do titulo no banco de dados e permite alugá-lo." << std::endl;/////////////////////
        std::cout << "  PESQUISAR LIVRO AUTOR - Busca os livros do autor no banco de dados" << std::endl;/////////////////////////////
        std::cout << "  PESQUISAR LIVRO GENERO - Busca o livro do genero no banco de dados" << std::endl;/////////////////////////////
        std::cout << "  VER LOCACOES - Lista todos os livros alugados pelo usuario" << std::endl;
        std::cout << "  VER ACERVO - Lista todos os livros no banco de dados" << std::endl;///////////////////////////////////////////
        std::cout << "  DEVOLVER LIVRO - Retorna um livro à biblioteca" << std::endl;/////////////////////////////////////////////////
        std::cout << "  ALUGAR LIVRO - Aluga um livro da biblioteca" << std::endl; ///////////////////////////////////////////////////
        std::cout << "  LOGOUT - Encerra a sessão" << std::endl;                    //////////////////////////////////////////////////
        std::cout << "  HELP - Lista os comandos disponiveis;" << std::endl<< std::endl << "->"; /////////////////////////////////////
    }
}


/**
 * @brief Verfica se uma string contém um número.
 * @param str String para ser verficada.
 */
bool isNumber(const string& str) {
    return !str.empty() &&
        std::find_if(str.begin(), str.end(),
            [](unsigned char c) { return !std::isdigit(c); }) == str.end();
}

/**
 * @brief Função principal do sistema.
 */
int main() {

    /**
     * Incializa a biblioteca.
     */ 
    Biblioteca biblioteca = Biblioteca();

    /**
     * Aloca os livros pré-determinados.
     */ 
    biblioteca.preencher_livros();
    /**
     * Aloca as pessoas pré-determinadas.
     */ 
    biblioteca.preencher_pessoas();

    /**
     * Armazena o tipo de usuário logado. True caso seja bibliotecário e false caso seja usuário.
     */ 
    bool isAdm;


    while(true)
    {
        /**
         * Fica na função login até que ele seja bem sucedido.
         */ 
        while(!biblioteca.login(&isAdm))
        {}

        /**
         * Recebe true ao fazer o logout.
         */ 
        bool deslogado = false;

        /**
         * Permite a impressão inicial dos comandos disponíveis.
         */ 
        bool primeiroLoop = true;

        /**
         * Roda até o usuário fazer logout.
         */ 
        while(!deslogado)
        {
            std::cout << "Escolha uma acao: (Digite HELP para listar todas as disponíveis) " << std::endl << std::endl;

            
            /**
             * Imprime os comandos disponíveis pela primeira vez.
             */ 
            if(primeiroLoop)
            {
                imprimir_comandos(isAdm);
                primeiroLoop = false;
            }

            /**
             * Ação a ser executada.
             */ 
            std::string comando;
            getline(std::cin, comando);

            /**
             * Caso o comando seja "VER", verifica se é um bibliotecário, se sim chama o método imprimir pessoas, se não imprime um alerta.
             */ 
            if(comando == "VER")
            {
                if(isAdm)
                {
                    biblioteca.imprime_pessoas();
                }
                else
                {
                    std::cout << "Voce nao tem permissao para utilizar este comando" << std::endl << std::endl;
                }
            }

            /**
             * Caso o comando seja "ADD PESSOA", verifica se é um bibliotecário, caso não seja, imprime um alerta..
             */ 
            else if(comando == "ADD PESSOA")
            {
                if(isAdm)
                {
                    /**
                     * Informações da pessoa que serão inseridas no teclado para o cadastro.
                     */ 
                    std::string nome, senha, tipo = "";

                    /**
                     * Pergunta o tipo de pessoa para cadastrar enquanto for enviada uma string vazia.
                     */ 
                    while (tipo.size() == 0) {                    
                        std::cout<< "Deseja cadastrar um usuário (U) ou um bibliotecário (B)?" << std::endl;
                        getline(std::cin, tipo);
                    }

                    if (tipo == "U") 
                    {   
                        /**
                         * Pergunta o nome da pessoa para cadastrar enquanto for enviada uma string vazia.
                         */ 
                        while (nome.size() == 0) {
                            std::cout << "Digite o nome do usuário que deseja cadastrar:"  << std::endl;
                            getline(std::cin, nome);
                        }

                        /**
                         * Pergunta a senha da pessoa para cadastrar enquanto for enviada uma string vazia.
                         */ 
                        while (senha.size() == 0) {
                            std::cout << "Digite a senha do usuário que deseja cadastrar:"  << std::endl;
                            getline(std::cin, senha);
                        }

                        /**
                         * Verifica se a pessoa já está no sistema, se sim, imprime um alerta e finaliza a função, se não, cadastra.
                         */ 
                        if (!biblioteca.usuario_existe(nome)) { //deu CERTO
                            Usuario* aux = new Usuario(nome, senha);
                            biblioteca.adiciona_usuarios_no_vetor(aux);
                        } else {
                            std::cout<< "Erro: Este usuário já está cadastrado."<< std::endl << std::endl;
                        }
                    }
                    else if(tipo == "B"){
                        /**
                         * Pergunta o nome da pessoa para cadastrar enquanto for enviada uma string vazia.
                         */ 
                        while (nome.size() == 0) {
                            std::cout << "Digite o nome do bibliotecário que deseja cadastrar:"  << std::endl;
                            getline(std::cin, nome);
                        }

                        /**
                         * Pergunta a senha da pessoa para cadastrar enquanto for enviada uma string vazia.
                         */ 
                        while (senha.size() == 0) {
                            std::cout << "Digite a senha do bibliotecário que deseja cadastrar:"  << std::endl;
                            getline(std::cin, senha);
                        }

                        /**
                         * Verifica se a pessoa já está no sistema, se sim, imprime um alerta e finaliza a função, se não, cadastra.
                         */ 
                        if (!biblioteca.bibliotecario_existe(nome)) { //deu CERTO
                            Bibliotecario* aux = new Bibliotecario(nome, senha);
                            biblioteca.adiciona_bibliotecarios_no_vetor(aux);
                        } else {
                            std::cout<< "Erro: Este bibliotecário já está cadastrado."<< std::endl << std::endl;
                        }

                    }
                    /**
                     * Se o tipo for diferente de U e B, imprime um alerta e finaliza função.
                     */ 
                    else {
                       std::cout << "Comando inválido." << std::endl << std::endl; 
                    }
                    
                }
                else
                {
                    std::cout << "Voce não tem permissao para utilizar este comando" << std::endl << std::endl;
                }
            }

            /**
             * Caso o comando seja "ADD LIVRO", verifica se é um bibliotecário, caso não seja, imprime um alerta.
             */ 
            else if(comando == "ADD LIVRO")
            {
                if(isAdm)
                {
                    /**
                     * Informações do livro que serão inseridas no teclado para o cadastro.
                     */ 
                    std::string titulo, autor, genero, buffer, str_qtd;
                    int qtd;
                    
                    /**
                     * Pergunta o título do livro para cadastrar enquanto for enviada uma string vazia.
                     */ 
                    while (titulo.size() == 0) {
                        std::cout << "Digite o titulo do livro que deseja cadastrar:"  << std::endl;
                        getline(std::cin, titulo);
                    }

                    /**
                     * Pergunta o autor do livro para cadastrar enquanto for enviada uma string vazia.
                     */ 
                    while (autor.size() == 0) {
                        std::cout << "Digite o nome do autor do livro que deseja cadastrar:"  << std::endl;
                        getline(std::cin, autor);
                    }

                    /**
                     * Pergunta a quantidade de exemplares  do livro para cadastrar enquanto for enviada uma string vazia ou algo que não é um inteiro.
                     */ 
                    while (str_qtd.size() == 0) {
                        std::cout << "Digite a quantidade de exemplares do livro que deseja cadastrar:"  << std::endl;
                        getline(std::cin, str_qtd);
                    }
                    while (!isNumber(str_qtd) || stoi(str_qtd) <= 0 || str_qtd.size() == 0) { //|| str_qtd <= "0"
                        std::cout << "A quantidade mínima deve ser maior que 0 e deve ser um número."  << std::endl;
                        getline(std::cin, str_qtd);
                    }
                    qtd = stoi(str_qtd);

                    /**
                     * Pergunta o gênero do livro para cadastrar enquanto for enviada uma string vazia.
                     */ 
                    while (genero.size() == 0) {
                        std::cout << "Digite o genero do livro que deseja cadastrar:"  << std::endl;
                        getline(std::cin, genero);
                    }
                    
                    /**
                     * Verifica se o livro já está no sistema, se sim, imprime um alerta e finaliza a função, se não, cadastra.
                     */ 
                    if (!biblioteca.livro_existe(titulo)) {
                        Livro aux = Livro(titulo, autor, genero, qtd);
                        biblioteca.adiciona_livros_no_estoque(aux);
                    } else {
                        std::cout<< "Erro: Este livro já está no acervo."<< std::endl << std::endl;
                    }
                }
                else
                {
                    std::cout << "Voce nao tem permissao para utilizar este comando" << std::endl;
                }
            }
            
            /**
             * Caso o comando seja "HELP", chama a função que imprime as funções disponíveis.
             */ 
            else if (comando == "HELP")
            {
                imprimir_comandos(isAdm);
            }
            
            /**
             * Caso o comando seja "PESQUISAR LIVRO TITULO", verifica se é um usuário, caso não seja, imprime um alerta..
             */ 
            else if(comando == "PESQUISAR LIVRO TITULO") //feito
            {
                    if(!isAdm)
                    {
                        /**
                         * Titulo do livro que será inserido no teclado.
                         */ 
                        std::string nome;

                        /**
                         * Pergunta o título do livro para buscar enquanto for enviada uma string vazia.
                         */ 
                        while(nome.size() == 0) {
                            std::cout << "Digite o titulo do livro:" <<std::endl;
                            getline(std::cin, nome);
                        }

                        /**
                         * Verifica se o livro existe.
                         */ 
                        if(biblioteca.get_livros_nome(nome))
                        {
                            
                            std::string resposta;

                            /**
                             * Pergunta a resposta do usuário quanto ao enquanto for enviada uma string inválida.
                             */ 
                            while(resposta != "Y" && resposta != "N") {
                                std::cout<< "Deseja alugar este exemplar? (Y/N)"<< std::endl;
                                getline(std::cin, resposta);
                            }
                             
                            /**
                             * Em caso afirmativa aloca o livro para o usuário logado.
                             */ 
                            if(resposta == "Y")
                            {
                                biblioteca.adicionar_livro_alugado(nome);
                            }

                        }
                    }
                    else
                    {
                        std::cout << "Voce nao tem permissao para utilizar este comando" << std::endl;
                    }
            }
            
            /**
             * Caso o comando seja "PESQUISAR LIVRO AUTOR", verifica se é um usuário, caso não seja, imprime um alerta.
             */ 
            else if(comando == "PESQUISAR LIVRO AUTOR")
            {
                if(!isAdm)
                {
                    std::string nome;

                    /**
                     * Pergunta o autor enquanto for enviada uma string vazia.
                     */ 
                    while (nome.size() == 0) {
                        std::cout << "Digite o nome do autor:" <<std::endl;
                        getline(std::cin, nome);
                    }

                    biblioteca.get_livros_autor(nome);
                }
                else
                {
                    std::cout << "Voce não tem permissao para utilizar este comando" << std::endl;
                }
            }
            
            /**
             * Caso o comando seja "PESQUISAR LIVRO GENERO", verifica se é um usuário, caso não seja, imprime um alerta.
             */ 
            else if(comando == "PESQUISAR LIVRO GENERO")
            {
                    if(!isAdm)
                    {
                        std::string nome;

                        /**
                         * Pergunta o genero enquanto for enviada uma string vazia.
                         */ 
                        while (nome.size() == 0){
                            std::cout << "Digite o genero desejado:" <<std::endl;
                            getline(std::cin, nome);
                        }
                        biblioteca.get_livros_genero(nome);
                    }
                    else
                    {
                        std::cout << "Voce não tem permissao para utilizar este comando" << std::endl;
                    }
            }
            
            /**
             * Caso o comando seja "VER ACERVO", chama a função que lista os livros do sistema.
             */ 
            else if(comando == "VER ACERVO")
            {
                biblioteca.imprime_livros();
            }

            /**
             * Caso o comando seja "LOGOUT", chama a função de logout.
             */ 
            else if(comando == "LOGOUT")
            {
                deslogado = biblioteca.logout();
                getchar();
            }

            /**
             * Caso o comando seja "ALUGAR LIVRO", verifica se é um usuário, caso não seja, imprime um alerta.
             */ 
            else if(comando == "ALUGAR LIVRO")
            {
                if (!isAdm) {
                    std::string nome;

                    /**
                     * Pergunta o título do livro para buscar enquanto for enviada uma string vazia.
                     */ 
                    while (nome.size() == 0) {
                        std::cout << "Digite o titulo do livro:" <<std::endl;
                        getline(std::cin, nome);
                    }

                    biblioteca.adicionar_livro_alugado(nome);
                }
                else
                {
                    std::cout << "Voce não tem permissao para utilizar este comando." << std::endl;
                }
   
            }

            /**
             * Caso o comando seja "DEVOLVER LIVRO", verifica se é um usuário, caso não seja, imprime um alerta.
             */ 
            else if(comando == "DEVOLVER LIVRO")
            {
                if (!isAdm) {
                    std::string nome;

                    /**
                     * Pergunta o título do livro para buscar enquanto for enviada uma string vazia.
                     */ 
                    while (nome.size() == 0) {
                        std::cout << "Digite o titulo do livro:" <<std::endl;
                        getline(std::cin, nome);
                    }
                    biblioteca.devolver_livro_alugado(nome);
                }
                else
                {
                    std::cout << "Voce nao tem permissao para utilizar este comando" << std::endl;
                }
            }

            /**
             * Caso o comando seja "VER LOCACOES", verifica se é um usuário, caso não seja, imprime um alerta.
             */ 
            else if(comando == "VER LOCACOES")
            {
                if (!isAdm) {
                    biblioteca.ver_livros_alugados();
                }
                else
                {
                    std::cout << "Voce nao tem permissao para utilizar este comando" << std::endl;
                }

            }
            
            /**
             * Caso o comando não seja nenhum dos disponíveis, imprime um alerta.
             */ 
            else
            {
                std::cout << "Comando inválido!!" <<std::endl;
            }
        }
    }    
    return 0;
}

