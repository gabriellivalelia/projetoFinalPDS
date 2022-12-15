#include "Usuario.h"


Usuario::Usuario(
    std::string nome,
    std::string senha
) : Pessoa(nome, senha, false){}


void Usuario::visualizar_livros_alugados() {
   
   if(_livros.size() == 0)
   {
      std::cout << "Voce nao tem livros alocados" << std::endl << std::endl;
   }
   else{

      for(auto& livro : this-> _livros)
      {
         std::cout<< livro.get_titulo() << ", escrito por " << livro.get_autor() << " e do gênero " << livro.get_genero() << std::endl;
      }
      std::cout<< std::endl;
   }  
}

void Usuario::adicionar_livro_no_vetor(Livro livro) {
   _livros.push_back(livro);
}


void Usuario::excluir_livro_do_vetor(Livro livro){
    
   for(auto i = _livros.begin(); i != _livros.end(); i++ )
   {
      if(livro.get_titulo() == i->get_titulo())
      {
        _livros.erase(i);
        break;
      }
   }
};

