# projetoFinalPDS
Trabalho final de PDS II - Sistema de gerenciamento de bibliotecas


Grupo: Aline da Silva Amaral, Gabrielli Valelia Sousa da Silva, Maria Monteiro Silva, Pedro Henrique Santana de Miranda

1-O usuário e o bibliotecário devem poder logar no sistema, mas somente o usuário pode se cadastrar.
a) Ao cadastrar gerar id e enviar nome e senha.
b) Para logar o usuário deve colocar nome e senha corretos, se sim permitir entrar, se não imprimir mensagem de erro.
c) Dois nomes iguais não podem existir.
d) Todos os bibliotecários já possuem cadastrados nome e senha.

2-Somente bibliotecário pode adicionar e deletar livros dos acervos.
a) Um livro deve ser adicionado com categoria, autor, nome e quantidade.
b) Ao adicionar verificar se está no vetor e ao apagar verificar se saiu corretamente.
c) Todos os livros adicionados devem ser armazenados na lista/vetor com todos os livros do acervo.

3-O usuário pode pesquisar livros por nome do livro, do autor e categoria e visualizar todos os livros daquele acervo.
a) Ao pesquisar nome/categoria/autor imprimir todos os títulos especificados e se não houver nenhum deve imprimir "Não existe esse livro em nossa biblioteca".
b) Depois de visualizar a lista por autor/categoria o usuário deverá escrever o livro que quer e selecioná-lo para visualizar suas informações.

4-O usuário pode alugar, devolver um livro e visualizar os livros que estão alugados com ele.
a) O usuário poderá alugar livros com quantidade != de 0.
b) Ao alugar a quantidade deve diminuir e ao devolver a quantidade deve aumentar.
c) Poderá visualizar a lista de livros alugados e selecionar algum para devolver.

5-O usuário pode visualizar a quantidade de livros disponíveis e reservar um livro caso a quantidade seja 0.
a) Terá a opção de reservar e entrar na lista de espera.
b) Caso o usuário reserve ele entrará numa lista de espera ordenada.

6-Ter uma lista de reserva para livros com quantidade 0.
a) Se o livro possui lista de espera e a quantidade sai de 0, o livro deve ser inserido na lista de livros alugados do primeiro usuário da lista.

