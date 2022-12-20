#include "Usuario.h"

/**
* Cria um novo usuário.
* @brief Constructor.
* @param nome O nome do usuário.
* @param senha A senha do usuário.
*/
Usuario::Usuario(
    std::string nome,
    std::string senha
) : Pessoa(nome, senha, false){};

/**
* @brief Imprime todos os livros alugados pelo usuário corrente.
* @exception Caso o usuário não tiver livros alugados imprime um alerta indicando isso.
*/
void Usuario::visualizar_livros_alugados() {
   
   if(_livros_alugados.size() == 0){
      std::cout << "Voce nao tem livros alugados." << std::endl << std::endl;
   }
   else{
      for(auto livro = _livros_alugados.begin(); livro != _livros_alugados.end(); livro++ )
      {
         std::cout << livro->get_titulo() << ", escrito por " << livro->get_autor() << " e do gênero " << livro->get_genero() << std::endl;
      }
      std::cout << std::endl;
   } 
}

/**
* @brief Adiciona um livro no vetor de livros alugados pelo usuário corrente.
* @param livro O livro que será adicionado.
* @exception Caso o livro já esteja no vetor, um alerta e impresso indicando isso e o livro não é inserido.
* @return True caso a ação seja bem sucedida, o que acontece caso esse livro ainda não exista no vetor, e false caso contrário.
*/
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

   return false;
}

/**
* @brief Remove um livro do vetor de livros alugados pelo usuário corrente.
* @exception Caso o livro não esteja no vetor de livros alugaar, um alerta é impresso indicando isso.
* @param livro O livro que será removido.
*/
void Usuario::excluir_livro_do_vetor(Livro livro){

   bool encontrado = false;

   for(auto i = _livros_alugados.begin(); i != _livros_alugados.end(); i++ ){
      if(livro.get_titulo() == i->get_titulo())
      {
        _livros_alugados.erase(i);
        encontrado = true;
        break;
      }
   }

   if(!encontrado){
     std::cout << "Este livro não está na sua lista de locações, logo não é possível devolvê-lo." << std::endl;
   }

};

