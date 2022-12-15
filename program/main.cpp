#include <iostream>
#include "Biblioteca.h"
#include "Usuario.h"

void imprimir_comandos(bool eh_admin)
{
if(eh_admin)
        {
            std::cout << "  VER - listar Pessoas cadastradas no sistema;" << std::endl;
            std::cout << "  ADD PESSOA - Adiciona uma pessoa no sistema;" << std::endl;
            std::cout << "  ADD LIVRO - Adiciona um livro no sistema;" << std::endl;
            std::cout << "  LOGOUT - Encerra a sessão;" << std::endl;/////////////////////////////////////////////////////
            std::cout << "  HELP - Lista os comandos disponiveis;" << std::endl;
            std::cout << std::endl << "->";
        }
        else
        {
            std::cout << "  PESQUISAR LIVRO TITULO - Busca o livro atraves do titulo no banco de dados" << std::endl;/////////////////////
            std::cout << "  PESQUISAR LIVRO AUTOR - Busca os livros do autor no banco de dados" << std::endl;/////////////////////////////
            std::cout << "  PESQUISAR LIVRO GENERO - Busca o livro do genero no banco de dados" << std::endl;/////////////////////////////
            std::cout << "  VER LOCACOES - Lista todos os livros alugados pelo usuario" << std::endl;
            std::cout << "  VER ACERVO - Lista todos os livros no banco de dados" << std::endl;///////////////////////////////////////////
            std::cout << "  DEVOLVER LIVRO - Retorna um livro à biblioteca" << std::endl;/////////////////////////////////////////////////
            std::cout << "  ALUGAR LIVRO - Aluga um livro da biblioteca" << std::endl; ///////////////////////////////////////////////////
            std::cout << "  LOGOUT - Encerra a sessão" << std::endl;                    //////////////////////////////////////////////////
            std::cout << "  HELP - Lista os comandos disponiveis;" << std::endl<< std::endl << "->";
        }
}

void aguardar()
{
    std::string a;
    std::cin >>a; // mudar

}
int main()
{

    Biblioteca biblioteca = Biblioteca();
    biblioteca.preencher_livros();
    biblioteca.preencher_pessoas();

    while(true)
    {
        system("cls");
        while(!biblioteca.login())
        {
            system("cls");
            std::cout << "Nome nao encontrado. Tente novamente." << std::endl;
            //codigo vai ficar enrolando aqui enquanto o login não for realizado
        }

        bool deslogado = false;
        bool primeiroLoop = true;
        while(!deslogado)
        {
            system("cls");
            std::cout << "Escolha uma acao: " << std::endl;
            std::cout << std::endl;

            if(primeiroLoop)
            {
                imprimir_comandos(biblioteca.eh_super_user());
                primeiroLoop = false;
            }


            std::string comando;
            getline(std::cin, comando);
            bool croc;

            //comandos bibliotecario
            {
            if(comando == "VER")
            {
                if(biblioteca.eh_super_user())
                {
                    //fazer
                }
                else
                {
                    std::cout << "Voce naum tem permissaum para utilizar este comando" << std::endl;
                }
            }

            if(comando == "ADD PESSOA")
            {
                if(biblioteca.eh_super_user())
                {
                    //fazer
                }
                else
                {
                    std::cout << "Voce naum tem permissaum para utilizar este comando" << std::endl;
                }
            }

            if(comando == "ADD LIVRO")
            {
                if(biblioteca.eh_super_user())
                {
                    //fazer
                }
                else
                {
                    std::cout << "Voce naum tem permissaum para utilizar este comando" << std::endl;
                }
            }
            }

            ////comandos usuario
            {
                if(comando == "PESQUISAR LIVRO TITULO")
                {
                    if(!biblioteca.eh_super_user())
                    {
                        std::cout << "Digite o titulo do livro:" <<std::endl;
                        std::string nome;
                        getline(std::cin, nome);
                        if(biblioteca.get_livros_nome(nome))
                        {
                            std::cout<< "Deseja alugar este exemplar? (Y/N)"<< std::endl;

                            std::string resposta;
                            std::cin >> resposta;

                            if(resposta == "Y")
                            {
                                biblioteca.adicionar_livro_alugado(nome);
                                aguardar();
                            }

                        }
                    }
                    else
                    {
                        std::cout << "Voce nao tem permissao para utilizar este comando" << std::endl;
                    }
                }

                if(comando == "PESQUISAR LIVRO AUTOR")
                {
                if(!biblioteca.eh_super_user())
                {
                    std::cout << "Digite o nome do autor:" <<std::endl;
                    std::string nome;
                    getline(std::cin, nome);
                    biblioteca.get_livros_autor(nome);

                    std::string a;
                    std::cin >>a; // mudar
                }
                else
                {
                    std::cout << "Voce nao tem permissao para utilizar este comando" << std::endl;
                }
            }

                if(comando == "PESQUISAR LIVRO GENERO")
                {
                    if(!biblioteca.eh_super_user())
                    {
                        std::cout << "Digite o genero textual:" <<std::endl;
                        std::string nome;
                        getline(std::cin, nome);
                        biblioteca.get_livros_genero(nome);
                    }
                    else
                    {
                        std::cout << "Voce nao tem permissao para utilizar este comando" << std::endl;
                    }
                }

                if(comando == "VER ACERVO")
                {
                    if(!biblioteca.eh_super_user())
                    {
                        biblioteca.imprime_livros();
                        aguardar();
                    }
                    else
                    {
                        std::cout << "Voce nao tem permissao para utilizar este comando" << std::endl;
                        aguardar();
                    }
                }

                if(comando == "LOGOUT")
                {
                    deslogado = biblioteca.logout();
                    getchar();
                }

                if(comando == "ALUGAR LIVRO")
                {
                    std::cout << "Digite o titulo do livro:" <<std::endl;
                    std::string nome;
                    getline(std::cin, nome);
                    biblioteca.adicionar_livro_alugado(nome);
                    aguardar();
                }

                if(comando == "DEVOLVER LIVRO")
                {

                    std::cout << "Digite o titulo do livro:" <<std::endl;
                    std::string nome;
                    getline(std::cin, nome);
                    std::cout << nome;
                    biblioteca.devolver_livro_alugado(nome);
                    aguardar();
                }

                if(comando == "VER LOCACOES")
                {
                    biblioteca.ver_livros_alugados();
                    aguardar();
                }
            }
        }
    }
    return 0;
}

