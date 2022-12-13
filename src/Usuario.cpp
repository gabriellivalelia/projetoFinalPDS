#include "Usuario.h"


Usuario::Usuario(
    std::string nome,
    std::string senha
) : Pessoa(nome, senha, false){};


void Usuario::visualizar_livros_alugados() {

   for(auto& livro : _livros_alugados)
   {
      std::cout<< livro.get_titulo() << ", escrito por " << livro.get_autor() << "e do gênero " << livro.get_genero() << std::endl;
   } 
}

void Usuario::adicionar_livro_no_vetor(Livro livro) {
   _livros_alugados.push_back(livro);
}


void Usuario::excluir_livro_do_vetor(Livro livro){
    
   for(auto i = _livros_alugados.begin(); i != _livros_alugados.end(); i++ )
   {
      if(livro.get_titulo() == i->get_titulo())
      {
        _livros_alugados.erase(i);
      }
   }
};

