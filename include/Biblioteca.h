#ifndef TRAB_PDS2_BIBLIOTECA_H
#define TRAB_PDS2_BIBLIOTECA_H



class Biblioteca
{
    private:
        
        vector<Livro>_livros_estoque;
        vector<Pessoa>_pessoas;
    
    public:
        
        Biblioteca(vector<Livro> livros_estoque, vector<Pessoa> pessoas);
    
        vector<livro> get_livros_nome(std::string nome);
        vector<livro> get_livros_autor(std::string autor);
        vector<livro> get_livros_genero(std::string genero);

        void update_estoque(Livro livro);
        void update_pessoas(Pessoa pessoa);
};
