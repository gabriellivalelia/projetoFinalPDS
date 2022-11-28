#include "Biblioteca.h"

vector<livro> Biblioteca::get_livros_autor(std::string autor)
{

}
vector<Livro> Biblioteca::get_livros_genero(std::string genero)
{

}
vector<Livro> Biblioteca::get_livros_nome(std::string nome)
{

}


void Biblioteca::update_estoque(Livro livro)
{

}
void Biblioteca::update_pessoas(Pessoa pessoa)
{

}

void Biblioteca::preencher_estoque(std::string path)
{


}

//adiciona todas as pessoas de path no atributo _pessoas
void Biblioteca::preencher_pessoas(std::string path)
{
    int quantidade_pessoas = -1;

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
}
