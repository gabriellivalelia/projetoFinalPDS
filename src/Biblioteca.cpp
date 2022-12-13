#include "Biblioteca.h"


Biblioteca::Biblioteca()
{}

void Biblioteca::get_livros_autor(std::string autor)
{
   for(auto& livro : _livros_estoque)
   {
      if(livro.get_autor() == autor)
      {
      std::cout<< livro.get_titulo() << " de " << livro.get_autor() << " do gênero " << livro.get_genero() << std::endl;
      }
   } 
}

void Biblioteca::get_livros_genero(std::string genero)
{
   for(auto& livro : _livros_estoque)
   {
      if(livro.get_genero() == genero)
      {
      std::cout<< livro.get_titulo() << " de " << livro.get_autor() << " do gênero " << livro.get_genero() << std::endl;
      }
   } 
}

void Biblioteca::get_livros_nome(std::string nome)
{
   for(auto& livro : _livros_estoque)
   {
      if(livro.get_titulo() == nome)
      {
      std::cout<< livro.get_titulo() << " de " << livro.get_autor() << " do gênero " << livro.get_genero() << std::endl;
      }
   } 
}

 void Biblioteca::devolver_livro_alugado(Livro livro, Usuario usuario)
{
   livro.update_quantidade(1);

   usuario.excluir_livro_do_vetor(livro);
}

void Biblioteca::adicionar_livro_alugado(Livro livro, Usuario usuario)
{
  livro.update_quantidade(-1);

  usuario.adicionar_livro_no_vetor(livro);

} 


// Definir como vão ser adicionados
/* void Biblioteca::update_estoque(Livro livro)
{
   
}


void Biblioteca::update_pessoas(Pessoa pessoa)
{

} */

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
   if(pessoa_existe(pessoa.get_nome))
    {
        std::cout<< "Digite sua senha" << std::endl;
        std::string senha;
        std::cin >> senha;
        if(senha == pessoa.get_senha())
        {
            std::cout<< "Login bem-sucedido." << std::endl;
            return true;
        }
        else
        {
            std::cout<< "Senha incorreta. Tente novamente" << std::endl;
            return false;
        }
    }
    else
    {
        std::cout<< "nome não encontrado" << std::endl;
        return false;
    }
}

void Biblioteca::update_lista_espera(Livro livro, Pessoa pessoa)
{

} */
