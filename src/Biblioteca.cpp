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



void Biblioteca::adiciona_livros_no_estoque(Livro livro)
{
   _livros_estoque.push_back(livro);
}


void Biblioteca::adiciona_pessoas_no_vetor(Pessoa pessoa)
{
   _pessoas.push_back(pessoa);
}

void Biblioteca::preencher_livros()
{
   Livro um = Livro("O Visconde que me amava", "Júlia Queen" , "Romance", 8 );
   Livro dois = Livro("O Duque e eu", "Júlia Queen", "Romance" , 4  );
   Livro tres = Livro( "Diário de um banana: Segurando Vela", "Jeff Kenny ", "InfantoJuvenil", 5 );
   Livro quatro = Livro("Diário de um banana: Vai ou Racha", "Jeff Kenny ", "InfantoJuvenil", 3 );
   Livro cinco = Livro("Diário de um banana: Rodrick é o cara", "Jeff Kenny ", "InfantoJuvenil", 12 );
   Livro seis = Livro("A culpa é das estrelas" ,"John Green" , "Romance", 12);
   Livro sete = Livro("Cidade de Papel" , "John Green" , "Romance", 4);
   Livro oito = Livro( "Orgulho e Preconceito", "Jane Austen", "Romance" , 6 );
   Livro nove = Livro( "Turma da Mônica: Almanaque", "Maurício de Souza", "Quadrinhos", 4 );

   _livros_estoque.push_back(um);
   _livros_estoque.push_back(dois);
   _livros_estoque.push_back(tres);
   _livros_estoque.push_back(quatro);
   _livros_estoque.push_back(cinco);
   _livros_estoque.push_back(seis);
   _livros_estoque.push_back(sete);
   _livros_estoque.push_back(oito);


   /* Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
   Livro um = Livro(, , , , );
 */
}


void Biblioteca::preencher_pessoas()
{
    Bibliotecario Ana = Bibliotecario("Ana Sales", "5839ab");
    _pessoas.push_back(Ana);
    Bibliotecario Estevao = Bibliotecario("Estêvão Rocha", "9546fg");
    _pessoas.push_back(Estevao);
    Bibliotecario Mateus = Bibliotecario("Mateus Pardini", "4567jh");
    _pessoas.push_back(Mateus);
    Bibliotecario Rita = Bibliotecario("Rita Milena", "2386ab");
    _pessoas.push_back(Rita);
    Bibliotecario Antonella = Bibliotecario("Antonella Santos", "3211rl");
    _pessoas.push_back(Antonella);

    Usuario Isabel = Usuario("Isabel Cruz", "2378jd");
    _pessoas.push_back(Isabel);
    Usuario Emanuel = Usuario("Emanuel Evaristo", "0369xu");
    _pessoas.push_back(Emanuel);
    Usuario Maria = Usuario("Maria Silva", "9834vg");
    _pessoas.push_back(Maria);
    Usuario Aline = Usuario("Aline Amaral", "6790gç");
    _pessoas.push_back(Aline);
    Usuario Gabrielli = Usuario("Gabrielli Valelia", "1706vs");
    _pessoas.push_back(Gabrielli);
    Usuario Pedro = Usuario("Pedro Santana", "6002ps");
    _pessoas.push_back(Pedro);
   
}

bool Biblioteca::pessoa_existe(string nome)
{
   return true;
}

bool login(Pessoa pessoa)
{
   return true;
}

void Biblioteca::update_lista_espera(Livro livro, Pessoa pessoa)
{

} 

void Biblioteca::imprime_livros(){

    for(auto& livro : _livros_estoque)
    {
        std::cout<< livro.get_titulo() << ", escrito por " << livro.get_autor() << "e do gênero " << livro.get_genero() << std::endl;
    }
}
