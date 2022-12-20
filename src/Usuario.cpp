#include "Usuario.h"


Usuario::Usuario(
    std::string nome,
    std::string senha
) : Pessoa(nome, senha, false){};


void Usuario::visualizar_livros_alugados() {
   
   if(_livros_alugados.size() == 0)
   {
      std::cout << "Voce nao tem livros alugados" << std::endl << std::endl;
   }
   else{
      for(auto livro = _livros_alugados.begin(); livro != _livros_alugados.end(); livro++ )
      {
         std::cout<< livro->get_titulo() << ", escrito por " << livro->get_autor() << " e do gênero " << livro->get_genero() << std::endl;
      }
   } 
}

bool Usuario::adicionar_livro_no_vetor(Livro livro) {
   int qtd = 0;
   for(auto livro_existe = _livros_alugados.begin(); livro_existe != _livros_alugados.end(); livro_existe++ )
   {
      if (livro_existe->get_titulo() == livro.get_titulo()) {
         std::cout << "Este livro já está na sua lista de locações." << std::endl;
         qtd++;
         return false;
      }
   }
   if (qtd == 0) {
      _livros_alugados.push_back(livro);
      return true;
   }
}


void Usuario::excluir_livro_do_vetor(Livro livro){
    
   for(auto i = _livros_alugados.begin(); i != _livros_alugados.end(); i++ )
   {
      if(livro.get_titulo() == i->get_titulo())
      {
        _livros_alugados.erase(i);
        break;
      }
   }
};

