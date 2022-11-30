#include "Usuario.h"
#include "Livro.h"
#include <string>

Usuario::Usuario(
    string nome,
    string senha
    //Tipo tipo
) : Pessoa(nome, senha){};


void Usuario::visualizar_livros_alugados() {

}

void adicionar_livros(Livro livro)
{
   _livros_alugados.push_back(livro);
}

void excluir_livros(Livro livro)
{
    string aux = livro.get_titulo;
    for(auto i = listalivros.begin() ; i <listalivros.end(); i++)
    {
        if(aux == i -> get_titulo)
        {
            _livros_alugados.erase(livro);
        }
    }
    
}
