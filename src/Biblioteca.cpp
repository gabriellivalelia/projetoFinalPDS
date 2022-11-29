#include "Biblioteca.h"
#include <iostream>
#include <fstream>
#include<string.h>
#include <vector>

std::vector<Livro> Biblioteca::get_livros_autor(std::string autor)
{
    std::vector<Livro> livros;
    return livros;
}
std::vector<Livro> Biblioteca::get_livros_genero(std::string genero)
{
    std::vector<Livro> livros;
    return livros;
}
std::vector<Livro> Biblioteca::get_livros_nome(std::string nome)
{
    std::vector<Livro> livros;
    return livros;
}

Biblioteca::Biblioteca()
{

}

void Biblioteca::excluir_livro_alugado(Livro livro, Pessoa pessoa)
{

}

void Biblioteca::adicionar_livro_alugado(Livro livro, Pessoa pessoa)
{

}

void Biblioteca::update_estoque(Livro livro)
{

}
void Biblioteca::update_pessoas(Pessoa pessoa)
{

}

void Biblioteca::preencher_livros(std::string path)
{


}

//adiciona todas as pessoas de path no atributo _pessoas
void Biblioteca::preencher_pessoas(std::string path)
{
    //int quantidade_pessoas = -1;

    try
    {
        std::ifstream arquivo_livros(path);
        std::string linha;

        while(getline(arquivo_livros, linha))
        {
            int index = 0;
            std::string nome;
            std::string senha;
            while(linha[index] != ';')
            {
                index++;
            }

            index++;
            int inicio_senha = index;
            while(linha[index] != ';')
            {
                index++;
            }
            senha = linha.substr(inicio_senha, index);
            this->_pessoas.push_back(Pessoa(nome, senha));
        }
    }
    catch(exception e)
    {
        
    }
}

bool Biblioteca::pessoa_existe(string nome)
{

}

bool login(Pessoa pessoa)
{

}

void Biblioteca::update_lista_espera(Livro livro, Pessoa pessoa)
{

}

