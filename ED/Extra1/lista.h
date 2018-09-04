/*
Aluno: JOAO PEDRO ASSUNCAO COUTINHO;
Matricula: 18/0019813;
Turma: A;
Atividade Extra 1 - Estrutura de Dados - UnB;
*/


#ifndef __LISTA_H__
#define __LISTA_H__



/*tipos pre-definidos*/
typedef struct{
    int codigo;
    char* nome;
    float preco;
    int quantidade;
}t_produto;

typedef struct elemento{
    t_produto* produto;
    struct elemento* proximo;
}t_elemento;

typedef struct{
    t_elemento* primeiro;
    t_elemento* fim;
    int quantidade;
}t_lista;



/*assinatura de funcoes*/

/*inicializa a estrutura lista, e consequentemente, as variaveis primeiro, fim, e quantidade*/
t_lista* aloca_lista();

/*aloca um elemento da lista, inicilizando o ponteiro para o proximo elemento e invocando a funcao aloca_produto*/
t_elemento* aloca_elemento(int codigo, char* nome, float preco, int quantidade);

/*aloca dinamicamente os dados de um produto*/
t_produto* aloca_produto(int codigo, char* nome, float preco, int quantidade);

/*libera a memora utilizada pelo programa*/
void remove_lista(t_lista* lista);

/*insere elementos em determinadas posicoes de uma lista*/
/*retorna 0 caso a operacao seja bem sucedida, e 1 caso contrario*/
int inserir(int posicao, int codigo, char*nome, float preco, int quantidade, t_lista* lista);


/*funcionalidades extras*/
int codigospares(t_lista* lista);
float precomedio(t_lista* lista);
float menorpreco(t_lista* lista);
float maiorpreco(t_lista* lista);
int posicaomaior(t_lista* lista);
float valortotal(t_lista* lista);
t_produto* qualproduto(t_lista* lista, int codigo);

#endif