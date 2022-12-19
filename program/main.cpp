#include <iostream>
#include "Biblioteca.h"
#include "Usuario.h"

void imprimir_comandos(bool eh_admin)
{
if(eh_admin)
        {
            std::cout << "  VER - listar Pessoas cadastradas no sistema;" << std::endl; /////////////////////////////////////////////////
            std::cout << "  ADD PESSOA - Adiciona uma pessoa no sistema;" << std::endl; /////////////////////////////////////////////////
            std::cout << "  ADD LIVRO - Adiciona um livro no sistema;" << std::endl; ////////////////////////////////////////////////////
            std::cout << "  LOGOUT - Encerra a sessão;" << std::endl;////////////////////////////////////////////////////////////////////
            std::cout << "  HELP - Lista os comandos disponiveis;" << std::endl; ////////////////////////////////////////////////////////
            std::cout << "  VER ACERVO - Lista todos os livros no banco de dados" << std::endl;///////////////////////////////////////////
            std::cout << std::endl << "->";
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



int main()
{

    Biblioteca biblioteca = Biblioteca();
    biblioteca.preencher_livros();
    biblioteca.preencher_pessoas();

    bool isAdm;


    while(true)
    {
        while(!biblioteca.login(&isAdm))
        {}

        bool deslogado = false;
        bool primeiroLoop = true;
        while(!deslogado)
        {
            std::cout << "Escolha uma acao: (Digite HELP para listar todas as disponíveis) " << std::endl;
            std::cout << std::endl;

            if(primeiroLoop) //feito
            {
                imprimir_comandos(isAdm);
                primeiroLoop = false;
            }


            std::string comando;
            getline(std::cin, comando);

            
            if(comando == "VER")
            {
                if(isAdm)
                {
                    biblioteca.imprime_pessoas();
                }
                else
                {
                    std::cout << "Voce nao tem permissao para utilizar este comando" << std::endl;
                }
            }

            else if(comando == "ADD PESSOA") //em andamento
            {
                if(isAdm)
                {
                    std::string nome, senha, tipo;

                    while (tipo.size() == 0) {                    
                        std::cout<< "Deseja cadastrar um usuário (U) ou um bibliotecário (B)?" << std::endl;
                        getline(std::cin, tipo);
                    }

                    if (tipo == "U")
                    {   
                        while (nome.size() == 0) {
                            std::cout << "Digite o nome do usuário que deseja cadastrar:"  << std::endl;
                            getline(std::cin, nome);
                        }
                        while (senha.size() == 0) {
                            std::cout << "Digite a senha do usuário que deseja cadastrar:"  << std::endl;
                            getline(std::cin, senha);
                        }
                        Usuario aux = Usuario(nome, senha);
                        biblioteca.adiciona_usuarios_no_vetor(&aux);
                    }
                    else if(tipo == "B"){
                        std::cout << "Digite o nome do bibliotecário que deseja cadastrar:"  << std::endl;
                        getline(std::cin, nome);
                        std::cout << "Digite a senha do bibliotecário que deseja cadastrar:"  << std::endl;
                        getline(std::cin, senha);
                        
                        Bibliotecario aux = Bibliotecario(nome, senha);
                        biblioteca.adiciona_bibliotecarios_no_vetor(&aux);
                    }
                    else{
                       std::cout << "Comando inválido." << std::endl << std::endl; 
                    }
                    
                }
                else
                {
                    std::cout << "Voce nao tem permissao para utilizar este comando" << std::endl;
                }
            }

            else if(comando == "ADD LIVRO")
            {
                if(isAdm)
                {
                    std::string titulo, autor, genero;
                    int qtd;

                    std::cout << "Digite o titulo do livro que deseja cadastrar:"  << std::endl;
                    getline(std::cin, titulo);
                    std::cout << "Digite o nome do autor do livro que deseja cadastrar:"  << std::endl;
                    getline(std::cin, autor);
                    std::cout << "Digite a quantidade de exemplares do livro que deseja cadastrar:"  << std::endl;
                    std::cin >> qtd;
                    std::cout << "Digite o genero do livro que deseja cadastrar:"  << std::endl;
                    getline(std::cin, genero);

                    Livro aux = Livro(titulo, autor, genero, qtd);
                    biblioteca.adiciona_livros_no_estoque(aux);

                }
                else
                {
                    std::cout << "Voce nao tem permissao para utilizar este comando" << std::endl;
                }
            }
            
            else if (comando == "HELP")
            {
                imprimir_comandos(isAdm);
            }
            
            else if(comando == "PESQUISAR LIVRO TITULO") //feito
            {
                    if(!isAdm)
                    {
                        std::string nome;
                        while(nome.size() == 0) {
                            std::cout << "Digite o titulo do livro:" <<std::endl;
                            getline(std::cin, nome);
                        }
                        if(biblioteca.get_livros_nome(nome))
                        {
                            std::string resposta;
                            while(resposta != "Y" && resposta != "N") {
                                std::cout<< "Deseja alugar este exemplar? (Y/N)"<< std::endl;
                                getline(std::cin, resposta);
                            }

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

            else if(comando == "PESQUISAR LIVRO AUTOR")
            {
                if(!isAdm)
                {
                    std::string nome;
                    while (nome.size() == 0) {
                        std::cout << "Digite o nome do autor:" <<std::endl;
                        getline(std::cin, nome);
                    }
                    biblioteca.get_livros_autor(nome);
                }
                else
                {
                    std::cout << "Voce nao tem permissao para utilizar este comando" << std::endl;
                }
            }

            else if(comando == "PESQUISAR LIVRO GENERO")
            {
                    if(!isAdm)
                    {
                        std::string nome;
                        while (nome.size() == 0){
                            std::cout << "Digite o genero desejado:" <<std::endl;
                            getline(std::cin, nome);
                        }
                        biblioteca.get_livros_genero(nome);
                    }
                    else
                    {
                        std::cout << "Voce nao tem permissao para utilizar este comando" << std::endl;
                    }
            }

            else if(comando == "VER ACERVO")
            {
                    biblioteca.imprime_livros();
            }

            else if(comando == "LOGOUT")
            {
                deslogado = biblioteca.logout();
                getchar();
            }

            else if(comando == "ALUGAR LIVRO")
            {
                std::string nome;
                while (nome.size() == 0) {
                    std::cout << "Digite o titulo do livro:" <<std::endl;
                    getline(std::cin, nome);
                }
                biblioteca.adicionar_livro_alugado(nome);
   
            }

            else if(comando == "DEVOLVER LIVRO")
            {
                    std::string nome;
                    while (nome.size() == 0) {
                        std::cout << "Digite o titulo do livro:" <<std::endl;
                        getline(std::cin, nome);
                    }
                    biblioteca.devolver_livro_alugado(nome);

            }

            else if(comando == "VER LOCACOES")
            {
                    biblioteca.ver_livros_alugados();

            }
            
            else
            {
                std::cout << "Comando inválido!!" <<std::endl;
            }
        }
    }    
    return 0;
}

