#include "Biblioteca.h"
#include <utility>

Biblioteca::Biblioteca()
{}

void Biblioteca::get_livros_autor(std::string autor)
{
   int qtd = 0;

   for(auto& livro : _livros_estoque)
   {
      if(livro.get_autor() == autor)
      {
        std::cout<< livro.get_titulo() << ", escrito por " << livro.get_autor() << "e do gênero " << livro.get_genero() << ". Exemplares Disponíveis: " << livro.get_quantidade() << std::endl;
        qtd++;
      }
   }

   if(qtd == 0)
   {  
      //exceção
      std::cout<< "Lamentamos, mas não temos exemplares desse autor. Faça outra Pesquisa :)" << std::endl;
   }
   else{
      std::cout<< "Quer alugar algum desses livros? Digite \"Alugar\" para continuar."<< std::endl;
   }
}


void Biblioteca::get_livros_genero(std::string genero)
{
   int qtd = 0;

   for(auto& livro : _livros_estoque)
   {
      if(livro.get_genero() == genero)
      {
        std::cout<< livro.get_titulo() << ", escrito por " << livro.get_autor() << "e do gênero " << livro.get_genero() << ". Exemplares Disponíveis: " << livro.get_quantidade() << std::endl;
      }
   }


   if(qtd == 0)
   {
      //exceção
      std::cout<< "Lamentamos, mas não temos exemplares desse gêneror. Faça outra Pesquisa :)" << std::endl;
   }
   else{
      std::cout<< "Quer alugar algum desses livros? Digite \"Alugar\" para continuar."<< std::endl;
   }
}


void Biblioteca::get_livros_nome(std::string nome)
{
   int qtd = 0;

   for(auto& livro : _livros_estoque)
   {
      if(livro.get_titulo() == nome)
      {
        std::cout<< livro.get_titulo() << ", escrito por " << livro.get_autor() << "e do gênero " << livro.get_genero() << ". Exemplares Disponíveis: " << livro.get_quantidade() << std::endl;
      }
   }


   if(qtd == 0)
   {
      //exceção
      std::cout<< "Lamentamos, mas não temos exemplares desse título. Faça outra Pesquisa :)" << std::endl;
   }
   else{
      std::cout<< "Quer alugar um exemplar? Digite \"Alugar\" para continuar."<< std::endl;
   }
}


Pessoa* Biblioteca::get_pessoa_logada()
{
    return _pessoaLogada;
}


Pessoa* Biblioteca::get_pessoa_especifica(std::string nome)
{

    for(auto& pessoa : _pessoas)
    {
        if(pessoa.get_nome() == nome)
        {

            return &pessoa;
        }
    }

    //exceção
    std::cout<<"Pessoa não encontrada!"<<std::endl;
    return nullptr;
}


Livro* Biblioteca::get_livro_especifico(std::string titulo)
{

    for(auto& livro : _livros_estoque)
    {
        if(livro.get_titulo() == titulo)
        {
            std::cout << "Livro: "<< livro.get_titulo() << ", "<< livro.get_quantidade() << " disponiveis" << std::endl;
            return &livro;
        }
    }

    //exceção
    std::cout<<"Livro não encontrado!"<<std::endl;
    return nullptr;
}


void Biblioteca::devolver_livro_alugado(std::string titulo)
{
   Usuario* logado = (Usuario*) _pessoaLogada;
   Livro* livro = get_livro_especifico(titulo);

   livro->update_quantidade(1);
   logado->excluir_livro_do_vetor(*livro);
   update_lista_de_espera();
}


void Biblioteca::adicionar_livro_alugado(std::string titulo)
{
  Usuario* logado = (Usuario*) _pessoaLogada;
  Livro* livro = get_livro_especifico(titulo);

  if (livro->get_quantidade() == 0)
  {
    std::cout << "O Título escolhido se encontra em falta em nosso estoque. Deseja entrar para lista de espera? (Y/N)" << std::endl;

    std::string resposta;
    std::cin >> resposta; ;

    if(resposta == "Y")
    {
        add_lista_espera(*livro);
    }
    else if(resposta == "N"){
        std::cout << "Certo! Pesquise outro título" << std::endl;
    }
  }
  else{
    livro->update_quantidade(-1);
    logado->adicionar_livro_no_vetor(*livro);
  }

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
   Livro um = Livro("O Visconde que me amava", "Júlia Queen" , "Romance", 0 );
   Livro dois = Livro("O Duque e eu", "Júlia Queen", "Romance" , 4  );
   Livro tres = Livro( "Diário de um banana: Segurando Vela", "Jeff Kenny ", "InfantoJuvenil", 5 );
   Livro quatro = Livro("Diário de um banana: Vai ou Racha", "Jeff Kenny ", "InfantoJuvenil", 3 );
   Livro cinco = Livro("Diário de um banana: Rodrick é o cara", "Jeff Kenny ", "InfantoJuvenil", 12 );
   Livro seis = Livro("A culpa é das estrelas" ,"John Green" , "Romance", 12);
   Livro sete = Livro("Cidade de Papel" , "John Green" , "Romance", 4);
   Livro oito = Livro( "Orgulho e Preconceito", "Jane Austen", "Romance" , 6 );
   Livro nove = Livro( "Turma da Mônica: Almanaque", "Maurício de Souza", "Quadrinhos", 4 );
   Livro dez = Livro("É assim  que acaba" , "Colleen Hoover" , "Romance", 3);
   Livro onze = Livro("É assim que começa", "Colleen Hoover", "Romance" , 5 );
   Livro doze = Livro("Frankenstein" , "Mary Shelley", "Terror" , 7 );
   Livro treze = Livro("Histórias Extraordinárias", "Edgar Allan Poe" , "Terror" , 1 );
   Livro quatorze = Livro("O exorcista", "William Peter Blatty" , "Terror" , 6);
   Livro quinze = Livro("Com não ser um babaca: Guia de etiqueta para o cotidiano" , "Megam Doherty" , "Comédia", 2 );
   Livro dezesseis = Livro("As 100 piores Ideias da História", "MIchael N. Smith", "Comédia", 5);
   Livro dezessete = Livro("Farenheit 451", "Ray Bradbury", "Ficção Científica", 2);
   Livro dezoito = Livro("Admirável Mundo Novo" , "Aldous Huxley", "Ficção científica" , 4 );
   Livro dezenove = Livro("Grande Sertão Veredas" , "João Guimarães Rosa", "Literatura Brasileira", 2 );
   Livro vinte = Livro("Memórias Póstumas de Brás Cubas" , "Machado de Assis", "Literatura Brasileira", 4 );
   Livro vinteEUm = Livro("Dom Casmurro", "Machado de Assis", "Literatura Brasileira", 5 );


   _livros_estoque.push_back(um);
   _livros_estoque.push_back(dois);
   _livros_estoque.push_back(tres);
   _livros_estoque.push_back(quatro);
   _livros_estoque.push_back(cinco);
   _livros_estoque.push_back(seis);
   _livros_estoque.push_back(sete);
   _livros_estoque.push_back(oito);
   _livros_estoque.push_back(nove);
   _livros_estoque.push_back(dez);
   _livros_estoque.push_back(onze);
   _livros_estoque.push_back(doze);
   _livros_estoque.push_back(treze);
   _livros_estoque.push_back(quatorze);
   _livros_estoque.push_back(quinze);
   _livros_estoque.push_back(dezesseis);
   _livros_estoque.push_back(dezessete);
   _livros_estoque.push_back(dezoito);
   _livros_estoque.push_back(dezenove);
   _livros_estoque.push_back(vinte);
   _livros_estoque.push_back(vinteEUm);

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

bool Biblioteca::pessoa_existe(std::string nome)
{
    for( Pessoa pessoa : _pessoas)
    {
        if(pessoa.get_nome() == nome)
        {
            return true;
        }
    }
    return false;
}

void Biblioteca::ver_listas_espera()
{

    for(auto& par : _listas_espera)
    {
        std::cout << "Livro: " << par.first.get_titulo() << std::endl;

        for(auto& pessoa_espera : par.second)
        {
            std::cout << "-" << pessoa_espera.get_nome();
        }
        std::cout << std::endl;
    }
}


bool Biblioteca::login()
{
  std::string _nome, _senha;

    std::cout<< "Digite seu nome" << std::endl;
    getline(cin ,_nome);

    std::cout<< "Digite sua senha" << std::endl;
    getline(cin ,_senha);

    if(pessoa_existe(_nome))
    {
        std::string senhaReal;

        Pessoa* logando = get_pessoa_especifica(_nome);

        if(logando->get_senha() == _senha)
        {
            std::cout<< "Login bem-sucedido." << std::endl;
            this->_pessoaLogada = logando;
            std::cout<< "Bem-vindo, "<<(this->_pessoaLogada)->get_nome() << std::endl;
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

bool Biblioteca::logout(){
   
   std::cout << "Deseja realmente fazer logout? (Y/N)" << std::endl;

   std::string resposta;
   
   std::cin >> resposta;

   if(resposta == "Y"){
       
      _pessoaLogada = nullptr;
      std::cout << "Logout realizado com sucesso!" << std::endl;
      return true;
   }
   else if(resposta == "N"){
      std::cout << "Logout cancelado!" << std::endl;
      return false;
   }
   else{
     // Pôr uma exceção aqui
     return false;
   }

}

void Biblioteca::add_lista_espera(Livro livro)
{
    bool pessoaNaLista = false;
    bool livroNaLista = false;

    for(auto& par : _listas_espera)
    {
        if(par.first.get_titulo() == livro.get_titulo())
        {
            livroNaLista = true;

            if(livroNaLista)
            {
                for(auto& pessoa_espera : par.second)
                {
                    if(pessoa_espera.get_nome() == _pessoaLogada->get_nome())
                    {
                        pessoaNaLista = true;
                        std::cout << "Voce ja esta na lista de espera para este livro, tenha paciencia" << std::endl;
                        break;
                    }
                }

                if(!pessoaNaLista)
                {
                    par.second.push_back(*_pessoaLogada);
                    std::cout << "Pronto! Assim que esse exemplar estiver disponível ele entrará ele será alocado para você!" << std::endl;
                }
            }
        }
    }

    if(!livroNaLista)
    {
        std::pair<int, char> as;
        std::vector<Pessoa>pessoas;
        pessoas.push_back(*_pessoaLogada);

        _listas_espera.push_back(make_pair(livro, pessoas));
        std::cout << "Pronto! Assim que esse exemplar estiver disponível ele entrará ele será alocado para você!" << std::endl;
    }

}



void Biblioteca::limpar_lista_de_espera(){

    auto it = _listas_espera.begin();

    while ( it != _listas_espera.end())
    {
        if (it->second.size() == 0)
        {
            it = _listas_espera.erase(it);
        }
        else
        {
            it++;
        }  
    }

}

void Biblioteca::update_lista_de_espera(){


    for(auto& par : _listas_espera)
    {
        if(par.first.get_quantidade() > 0 )
        {
           par.first.update_quantidade(-1);
           Usuario* aux = (Usuario*)&par.second[0];
           aux->adicionar_livro_no_vetor(par.first);
           //std::cout<<"Livro " << par.first.get_titulo() << " alugado para " << aux->get_nome() << std::endl; 
           par.second.erase(par.second.begin());
           
        }
    }

    limpar_lista_de_espera();
}

void Biblioteca::imprime_livros(){

    for(auto& livro : _livros_estoque)
    {
        std::cout<< livro.get_titulo() << ", escrito por " << livro.get_autor() << "e do gênero " << livro.get_genero() << std::endl;
    }
}
