# Projeto Final PDS
Trabalho final de PDS II - Sistema de gerenciamento de bibliotecas
Grupo: Aline da Silva Amaral, Gabrielli Valelia Sousa da Silva, Maria Monteiro Silva, Pedro Henrique Santana de Miranda

-- User Historys -------------------------------------------------------------------------------------------------------------------------------------------------------

1) Como usuário e bibliotecário quero ter uma senha e nome de usuário para logar no sistema.
a)Para logar o usuário deve colocar nome e senha corretos, se sim permitir entrar, se não imprimir mensagem de erro.
b)Dois nomes iguais não podem existir.
c) Todos os bibliotecários e usuários já possuem cadastrados nome e senha.

2) Como bibliotecário quero ter controle sobre os livros para poder excluir e adicionar.
a) Um livro deve ser adicionado com categoria, autor, nome e quantidade.
b) Ao adicionar ou deletar deve aparecer uma mensagem com o sucesso da ação.
c)Todos os livros adicionados devem ser armazenados em uma estrutura com todos os livros do acervo.

3) Como usuário, quero pesquisar livros por nome/autor/categoria para conseguir visualizá-los.
a) Ao pesquisar nome/categoria/autor exibir todos os títulos especificados e se não houver nenhum deve aparecer "Não existe esse livro em nossa biblioteca".
b) Depois de visualizar a lista por autor/categoria o usuário deverá escrever o livro que quer e selecioná-lo para visualizar suas informações.

4) Como usuário quero acesso ao sistema para poder alugar livros
a) O usuário poderá alugar livros que não estão em falta.
b) Ao alugar a quantidade de livros em estoque diminui e ao devolver a quantidade aumenta.

5) Como usuário, quero conseguir ver quais livros aluguei e poder escolher um  para devolver.
a) O usuário poderá visualizar a lista de livros alugados e selecionar algum para devolver.

6) Como usuário, quero visualizar a quantidade disponível de um livro para alugá-lo ou ter a opção de entrar na lista de reserva.
a) Ao visualizar o livro, terá a opção de reservar e entrar na lista de espera.
b) Caso o usuário reserve, ele entrará numa lista de espera ordenada.
c) Se o livro possui lista de espera e a quantidade sai de 0, o livro deve ser inserido na lista de livros alugados do primeiro usuário da lista.

-- Fluxo do Projeto ----------------------------------------------------------------------------------------------------------------------------------------------------

O projeto é composto por 5 classes.
 - A classe pessoa que é a base para a classe bibliotecário e a classe usuário.
 - A classe usuário que representa o usuário que pode entrar na biblioteca para alugar exemplares, devolver os mesmos e afins.
 - A classe bibliotecário que seria o adm da biblioteca, que pode adicionar livros e pessoas ao sistema e afins.
 - A classe livro, que representa os livros do sistema, com título, gênero, autor e nº de exemplares disponíveis.
 - A classe biblioteca que funciona como controladora do fluxo de todas as outras.

Tanto usuário como bibliotecário podem fazer login. fazer logout e ver tdos os livros do acervo.

Várias funções foram criadas para atender as user historys, e elas estão devidamente expllicadas no código.

As exceções foram tratadas no próprio fluxo do projeto, com condicionais, por escolha do grupo.

Um fluxo normal de funcionamento seria logar, escolher uma das ações possíveis e aí seguir as indicações que o próprio programa dá.

-- Como startar --------------------------------------------------------------------------------------------------------------------------------------------------------

Para compilar basta rodar o comando: make;
Para executar: .bin/main;
Para rodar os testes: make tests;

Ao executar, basta escolher um dos usuários já existentes para fazer login:

// Nome, tipo, senha

Ana Sales,  Bibliotecario(a), 5839ab
Estêvão Rocha,  Bibliotecario(a), 9546fg
Mateus Pardini,  Usuario(a), 4567jh
Rita Milena,  Usuario(a), 2386ab
Antonella Santos,  Usuario(a), 3211rl
Isabel Cruz,  Usuario(a), 2378jd
Emanuel Evaristo,  Usuario(a), 0368xu
Maria Silva,  Usuario(a), 9834vg
Aline Amaral,  Usuario(a), 6790gc
Gabrielli Valelia,  Usuario(a), 1706vs
Pedro Santana,  Usuario(a), 6002ps

