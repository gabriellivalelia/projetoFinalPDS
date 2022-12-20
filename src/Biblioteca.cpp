#include "Biblioteca.h"
#include <utility>

/**
 * Cria uma nova bibliooteca.
 * @brief Constructor.
 */
Biblioteca::Biblioteca()
{}

/**
 * @brief Busca e imprime os dados de todos os livros de um autor, caso existam.
 * @exception Caso não exista nenhum livro do autor solicitado um alerta indicando isso é impresso.
 * @param autor O nome do autor que será buscado.
 */
void Biblioteca::get_livros_autor(std::string autor) {
   int qtd = 0;

   for(auto& livro : _livros_estoque)
   {
      if(livro.get_autor() == autor)
      {
        std::cout<< livro.get_titulo() << ", por " << livro.get_autor() << ". Genero :" << livro.get_genero() << ". Exemplares Disponiveis: " << livro.get_quantidade() << std::endl;
        qtd++;
      }
   }

   std::cout<<std::endl;

   if(qtd == 0)
   {
      std::cout<< "Lamentamos, mas nao temos exemplares desse autor." << std::endl;
   }
}

/**
 * @brief Busca e imprime os dados de todos os livros de um gênero, caso existam.
 * @exception Caso não exista nenhum livro do gênero solicitado um alerta indicando isso é impresso.
 * @param genero O genero que será buscado.
 */
void Biblioteca::get_livros_genero(std::string genero) {
   int qtd = 0;

   for(auto& livro : _livros_estoque)
   {
      if(livro.get_genero() == genero)
      {
        std::cout<< livro.get_titulo() << ", por " << livro.get_autor() << ". Genero :" << livro.get_genero() << ". Exemplares Disponiveis: " << livro.get_quantidade() << std::endl;
        qtd++;
      }
   }
   std::cout<<std::endl;

   if(qtd == 0)
   {
      std::cout<< "Lamentamos, mas nao temos exemplares desse genero." << std::endl;
   }
}

/**
 * @brief Busca e imprime os dados de um livro a partir de seu título.
 * @param nome Título do livro que será buscado.
 * @exception Caso não exista um livro com o título passado por parâmetro um alerta é impresso indicando isso.
 * @return True caso o livro se encontrado e false caso não.
 */
bool Biblioteca::get_livros_nome(std::string nome) {
   int qtd = 0;

   for(auto& livro : _livros_estoque)
   {
      if(livro.get_titulo() == nome)
      {
        std::cout<< livro.get_titulo() << ", por " << livro.get_autor() << ". Genero :" << livro.get_genero() << ". Exemplares Disponiveis: " << livro.get_quantidade() << std::endl;
        qtd++;
        break;
      }
   }
   if(qtd == 0)
   {
      std::cout<< "Lamentamos, mas nao temos exemplares desse titulo." << std::endl;
      return false;
   }
   else{
      return true;

   }
}

/**
 * @brief Busca por um usuário específico no sistema pelo nome.
 * @param nome Nome do usuário que será buscado.
 * @return O ponteiro do usuário caso encontre e nullptr caso não.
 */
Usuario* Biblioteca::get_usuario_especifico(std::string nome) {
    for(auto& usuario : _usuarios)
    {
        if(usuario->get_nome() == nome)
        {

            return usuario;
        }
    }

    return nullptr;
}

/**
 * @brief Busca por um bibliotecário específico no sistema pelo nome.
 * @param nome Nome do bibliotecário que será buscado.
 * @return O ponteiro do bibliootecário caso encontre e nullptr caso não.
 */
Bibliotecario* Biblioteca::get_bibliotecario_especifico(std::string nome) {

    for(auto& bibliotecario : _bibliotecarios)
    {
        if(bibliotecario->get_nome() == nome)
        {

            return bibliotecario;
        }
    }

    return nullptr;
}

/**
 * @brief Busca por um livro específico no sistema pelo título.
 * @param titulo Título do livro que será buscado.
 * @return O ponteiro do livro caso encontre e nullptr caso não.
 */
Livro* Biblioteca::get_livro_especifico(std::string titulo) {

    for(auto& livro : _livros_estoque)
    {
        if(livro.get_titulo() == titulo)
        {
            return &livro;
        }
    }
   
    return nullptr;
}

/**
 * @brief Remove o livro do vetor de livros alugados do usuário logado e aumenta a quantidade de exemplares disponíveis em 1 do livro devolvido.
 * @exception Caso o livro não seja encontrado na biblioteca um alerta para isso é impresso e a função é finalizada.
 * @param titulo O Título do livro que será devolvido.
 */
void Biblioteca::devolver_livro_alugado(std::string titulo) {
   Livro* livro = get_livro_especifico(titulo);

   if (livro == nullptr) {
        std::cout << "Este livro não pertence ao nosso sitema." << std::endl;
   }else {
        livro->update_quantidade(1); 
        bool devolvido = _usuarioLogado->excluir_livro_do_vetor(*livro);
        update_lista_de_espera();

        if(devolvido){
            std::cout<<"Livro devolvido com sucesso! Obrigada pelo cuidado!" << std::endl << std::endl;
            std::cout<< "Aqui estão suas locações atualizadas:"<< std::endl;
            ver_livros_alugados();
            std::cout << std::endl;
        }

   }
}

/**
 * @brief Adiciona o livro no vetor de livros alugados do usuário logado e diminuí a quantidade de exemplares disponíveis em 1 do livro alugado.
 * @exception Caso o livro exista no sistema mas a quantidade de exemplares disponíveis seja 0, é perguntado ao usuário se ele deseja entrar na 
lista de espera. Em caso afirmativo, a função add_lista_de_espera é chamada, rm caso negativo a função é encerrada, em caso de resposta diferente
um alerta é impresso e a função é finalizada.
* @exception Caso o livro não exista no sistema um alerta é impresso e a função é finalizada.
 * @param titulo O Título do livro que será alugado.
 */
void Biblioteca::adicionar_livro_alugado(std::string titulo)
{
    Livro* livro = get_livro_especifico(titulo);

    if (livro != nullptr) {
        std::cout<< livro->get_titulo() << ", escrito por " << livro->get_autor() << ". Genero " << livro->get_genero() << std::endl <<  std::endl;

        if (livro->get_quantidade() == 0)
        {
            std::cout << "O Titulo escolhido se encontra em falta em nosso estoque. Deseja entrar para lista de espera? (Y/N)" << std::endl;

            std::string resposta;
            getline(std::cin, resposta);

            if(resposta == "Y"){
                add_lista_espera(livro);
            }else if(resposta == "N"){
                std::cout << "Certo! Pesquise outro titulo" << std::endl <<  std::endl;
            }else{
               std::cout << "Comando inválido" << std::endl <<  std::endl; 
            }
        }
        else
        {   
            Livro aux = *livro;
    
            if (_usuarioLogado->adicionar_livro_no_vetor(aux) == true) {
                livro->update_quantidade(-1);
                std::cout <<"Livro alugado com sucesso!"<< std::endl;
            }

            std::cout<< "Aqui estão suas locações atualizadas:"<< std::endl;
            ver_livros_alugados();
            std::cout << std::endl;
        }

    } else if (livro == nullptr) {
        std::cout<< "Lamentamos, mas nao temos exemplares desse titulo." << std::endl <<  std::endl;
    }   
}

/**
 * @brief Cadastra um novo livro no sistema.
 * @param livro O livro que será cadastrado.
 */
void Biblioteca::adiciona_livros_no_estoque(Livro livro)
{
    _livros_estoque.push_back(livro);
    std::cout <<"Livro cadastrado com sucesso!"<< std::endl << std::endl;
    std::cout<< "Aqui está o acervo atualizado:"<< std::endl;
    imprime_livros();
    std::cout << std::endl;  
}

/**
 * @brief Chama a função de ver todos os livros alugados do usuário logado.
 */
void Biblioteca::ver_livros_alugados() {
    _usuarioLogado->visualizar_livros_alugados(); 
}

/**
 * @brief Cadastra um novo usuário no sistema.
 * @param usuario O endereço de memória do usuário que será cadastrado.
 */
void Biblioteca::adiciona_usuarios_no_vetor(Usuario* usuario) {
        _usuarios.push_back(usuario);
        std::cout << "Usuario adicionada com sucesso!" << std::endl;

        std::cout<< "Aqui está a lista de pessoas cadastradas atualizada:"<< std::endl;
        imprime_pessoas();
        std::cout << std::endl;

}

/**
 * @brief Cadastra um novo bibliotecário no sistema.
 * @param bibliotecario O endereço de memória do bibliotecário que será cadastrado.
 */
void Biblioteca::adiciona_bibliotecarios_no_vetor(Bibliotecario* bibliotecario) {
        _bibliotecarios.push_back(bibliotecario);
        std::cout << "Pessoa adicionada com sucesso!" << std::endl << std::endl;

        std::cout<< "Aqui está a lista de pessoas cadastradas atualizada:"<< std::endl;
        imprime_pessoas();
        std::cout << std::endl;
}

/**
 * @brief Preenche o vetor de livros com livros pré determinados a cada inicialização do programa.
 */
void Biblioteca::preencher_livros() {
   Livro um = Livro("O Visconde que me amava", "Julia Queen" , "Romance", 1 );
   Livro dois = Livro("O Duque e eu", "Julia Queen", "Romance" , 4  );
   Livro tres = Livro( "Diario de um banana: Segurando Vela", "Jeff Kenny ", "InfantoJuvenil", 5 );
   Livro quatro = Livro("Diario de um banana: Vai ou Racha", "Jeff Kenny ", "InfantoJuvenil", 3 );
   Livro cinco = Livro("Diario de um banana: Rodrick eh o cara", "Jeff Kenny ", "InfantoJuvenil", 12 );
   Livro seis = Livro("A culpa eh das estrelas" ,"John Green" , "Romance", 12);
   Livro sete = Livro("Cidade de Papel" , "John Green" , "Romance", 4);
   Livro oito = Livro( "Orgulho e Preconceito", "Jane Austen", "Romance" , 6 );
   Livro nove = Livro( "Turma da Monica: Almanaque", "Mauricio de Souza", "Quadrinhos", 4 );
   Livro dez = Livro("Eh assim  que acaba" , "Colleen Hoover" , "Romance", 3);
   Livro onze = Livro("Eh assim que começa", "Colleen Hoover", "Romance" , 5 );
   Livro doze = Livro("Frankenstein" , "Mary Shelley", "Terror" , 7 );
   Livro treze = Livro("Historias Extraordinarias", "Edgar Allan Poe" , "Terror" , 1 );
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

/**
 * @brief Preenche o vetor de usuários e bibliotecários com dados pré determinados a cada inicialização do programa.
 */
void Biblioteca::preencher_pessoas() {
    Bibliotecario* Ana = new Bibliotecario("Ana Sales", "5839ab");
    _bibliotecarios.push_back(Ana);
    Bibliotecario* Estevao = new Bibliotecario("Estêvão Rocha", "9546fg");
    _bibliotecarios.push_back(Estevao);
    
    Usuario* Mateus = new Usuario("Mateus Pardini", "4567jh");
     _usuarios.push_back(Mateus);
    Usuario* Rita = new Usuario("Rita Milena", "2386ab");
     _usuarios.push_back(Rita);
    Usuario* Antonella = new Usuario("Antonella Santos", "3211rl");
     _usuarios.push_back(Antonella);
    Usuario* Isabel = new Usuario("Isabel Cruz", "2378jd");
     _usuarios.push_back(Isabel);
    Usuario* Emanuel = new Usuario("Emanuel Evaristo", "0369xu");
    _usuarios.push_back(Emanuel);
    Usuario* Maria = new Usuario("Maria Silva", "9834vg");
    _usuarios.push_back(Maria);
    Usuario* Aline = new Usuario("Aline Amaral", "6790gc");
    _usuarios.push_back(Aline);
    Usuario* Gabrielli = new Usuario("Gabrielli Valelia", "1706vs");
    _usuarios.push_back(Gabrielli);
    Usuario* Pedro = new Usuario("Pedro Santana", "6002ps");
    _usuarios.push_back(Pedro);

}

/**
 * @brief Busca por um bibliotecário no sistema através do nome.
 * @param nome Nome do biliotecário que será buscado.
 * @return True caso encontre e false caso não.
 */
bool Biblioteca::bibliotecario_existe(std::string nome) {
    std::cout << nome << std::endl;
    for( Bibliotecario* bibliotecario : _bibliotecarios)
    {
        if(bibliotecario->get_nome() == nome)
        {
            return true;
        }
    } 
    return false;
}

/**
 * @brief Busca por um usuário no sistema através do nome.
 * @param nome Nome do usuário que será buscado.
 * @return True caso encontre e false caso não.
 */
bool Biblioteca::usuario_existe(std::string nome) {
    for( Usuario* usuario : _usuarios)
    {
        if(usuario->get_nome() == nome)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Busca por um livro no sistema através do título.
 * @param titulo Título do livro que será buscado.
 * @return True caso encontre e false caso não.
 */
bool Biblioteca::livro_existe(std::string titulo) {
    for (Livro livro : _livros_estoque)
    {
        if (livro.get_titulo() == titulo)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Imprime todos os livros e os respectivos nome das pessoas que estão em listas de epsera do mesmo do vetor _listas_de_espera.
 */
void Biblioteca::ver_listas_espera() {
    for(auto& par : _listas_espera)
    {
        std::cout << "Livro: " << par.first->get_titulo() << std::endl;

        for(auto& pessoa_espera : par.second)
        {
            std::cout << "-" << pessoa_espera->get_nome();
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Função de Login do sistema.
 * @param isAdm Variável do tipo bool* que recebe true caso o login seja bem sucedido e feito por um bibliotecário e false caso seja feito
por um usuário. Essa variável é usada no controle de manipulação dos métodos na main.
* @exception Caso o usuário insira um tipo inválido, um alerta é impresso e a função é finalizada.
* @exception Caso o nome digitado não seja encontrado um alerta é impresso e a função é finalizada.
* @exception Caso a senha digitada seja diferente da cadastrada um alerta é impresso e a função é finalizada.
* @return True caso o login seja bem sucedido e false caso não.
*/
bool Biblioteca::login(bool* isAdm) {
  std::string _nome, _senha, _tipo;
    
    while(_nome.size() == 0) {
        std::cout<< "Digite seu nome" << std::endl;
        getline(cin ,_nome);
    }

    while (_senha.size() == 0) {
        std::cout<< "Digite sua senha" << std::endl;
        getline(cin ,_senha);
    }

    while (_tipo.size() == 0) {
        std::cout<< "Você é Usuário (U) ou Bibliotecario (B)?" << std::endl;
        getline(cin ,_tipo);
    }
    
    if(_tipo == "B")
    {   
        if(bibliotecario_existe(_nome))
        {
                std::string senhaReal;

                Bibliotecario* logando = get_bibliotecario_especifico(_nome);
                Bibliotecario aux = *logando;

            if(aux.get_senha() == _senha)
            {

                std::cout<< "Login bem-sucedido." << std::endl;
                this->_bibliotecarioLogado = logando;
                std::cout<< "Bem-vindo (a), "<<aux.get_nome() << std::endl << std::endl;
                *isAdm = true;
                return true;
            }
            else 
            {
                std::cout<< "Senha incorreta. Tente novamente" << std::endl << std::endl;
                return false;
            }
        }
        else if (usuario_existe(_nome)) {
                std::cout << "Tente novamente como usuário." << std::endl << std::endl; 
                return false;
        }
        else
        {
            std::cout<< "Nome não encontrado. Tente novamente." << std::endl << std::endl;
            return false;
        }
    }
    else if (_tipo == "U")
    {
         if(usuario_existe(_nome))
         {
                std::string senhaReal;

                Usuario* logando = get_usuario_especifico(_nome);
                Usuario aux = *logando;

            if(aux.get_senha() == _senha)
            {

                std::cout<< "Login bem-sucedido." << std::endl;
                this->_usuarioLogado = logando;
                std::cout<< "Bem-vindo (a), "<<aux.get_nome() << std::endl << std::endl;
                *isAdm = false;
                return true;
            }
            else
            {
                std::cout<< "Senha incorreta. Tente novamente" << std::endl << std::endl;
                return false;
            }
        }
        else if (bibliotecario_existe(_nome)) {
            std::cout << "Tente novamente como bibliotecário." << std::endl << std::endl; 
            return false;
        }
        else
        {
            std::cout<< "Nome não encontrado. Tente novamente." << std::endl << std::endl;
            return false;
        }
    } else {
        std::cout<< "Tipo Invalido. Tente novamente." << std::endl << std::endl;
            return false;
    }
}

/**
 * @brief Função de Logout do sistema.
 * @exception Antes de se fazer o logout de fato, é pedida uma confirmação. Em caso de resposta afirmativa,
 o logout é feito, caso negativa, um alerta é impresso e a função é finalizada, e caso a resposta seja diferente um 
    alerta é impresso e a função é finalizado.
    * @return True caso o logout seja bem sucedido e false caso não.
    */
bool Biblioteca::logout() {

   std::cout << "Deseja realmente fazer logout? (Y/N)" << std::endl;

   std::string resposta;

   std::cin >> resposta;

   if(resposta == "Y"){

      _usuarioLogado = nullptr;
      _bibliotecarioLogado = nullptr;
      std::cout << "Logout realizado com sucesso!" << std::endl << std::endl;
      return true;
   }
   else if(resposta == "N"){
      std::cout << "Logout cancelado!" << std::endl << std::endl;
      return false;
   }
   else{
     std::cout << "Comando inválido!" << std::endl << std::endl;
     return false;
   }

}

/**
 * @brief Adiciona o usuário logado na lista de espera do livro passado como parâmetro.
 * @exception Caso a pessoa logada já esteja na lista de espera do livro solicitado, um alerta 
 sinalizando isso é impresso e a função é finalizada.
 * @param livro endereço de memória do livro, no vetor da biblioteca.
 */
void Biblioteca::add_lista_espera(Livro* livro) {
    bool pessoaNaLista = false;
    bool livroNaLista = false;

    for(auto& par : _listas_espera)
    {
        if(par.first->get_titulo() == livro->get_titulo())
        {
            livroNaLista = true;

            if(livroNaLista)
            {
                for(auto& pessoa_espera : par.second)
                {
                    if(pessoa_espera->get_nome() == _usuarioLogado->get_nome())
                    {
                        pessoaNaLista = true;
                        std::cout << "Voce ja esta na lista de espera para este livro, tenha paciencia" << std::endl << std::endl;
                        break;
                    }
                }

                if(!pessoaNaLista)
                {
                    par.second.push_back(_usuarioLogado);
                    std::cout << "Pronto! Assim que esse exemplar estiver disponivel elesera alocado para voce!" << std::endl << std::endl;
                }
            }
        }
    }
    if(!livroNaLista)
    {
        std::pair<int, char> as;
        std::vector<Usuario*>pessoas;
        pessoas.push_back(_usuarioLogado);

        _listas_espera.push_back(make_pair(livro, pessoas));
        std::cout << "Pronto! Assim que esse exemplar estiver disponivel ele sera alocado para voce!" << std::endl << std::endl;
    }
}

/**
 * @brief Caso algum livro que tenha lista de espera fique sem pessoas na lista, remove o pair do vetor listas_de_espera.
 */
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

/**
 * @brief Caso algum livro que tenha lista de espera fique com quantidade de exemplares disponíveis maior que zero, aloca o livro para 
a primeira pessoa da lista e a remove da lista de espera.
 */
void Biblioteca::update_lista_de_espera() {

    for(auto& par : _listas_espera)
    {
        std::cout<< par.first->get_quantidade();

        if(par.first->get_quantidade() > 0 )
        {
           par.first->update_quantidade(-1);
           Usuario* aux = par.second[0];
           aux->adicionar_livro_no_vetor(*par.first);
           par.second.erase(par.second.begin());
        }
    }
    limpar_lista_de_espera();
}

/**
 * @brief Imprime todos os livros do sistema.
 */
void Biblioteca::imprime_livros() {

    for(auto& livro : _livros_estoque)
    {
        std::cout<< livro.get_titulo() << ", escrito por " << livro.get_autor() << ". Genero " << livro.get_genero() << std::endl;
    }
    std::cout<<std::endl;
}

/**
 * @brief Imprime todas as pessoas do sistema ( Usuários e Bibliotecários ).
 */
void Biblioteca::imprime_pessoas() {

    for(auto& bibliotecario : _bibliotecarios)
    {
        std::cout<< bibliotecario->get_nome() << ",  " << "Bibliotecario(a)" << std::endl;
    }
    for(auto& usuario : _usuarios)
    {
        std::cout<< usuario->get_nome() << ",  " << "Usuario(a)" << std::endl;
    }
    std::cout<<std::endl;
}



