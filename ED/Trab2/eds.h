/**
@file eds.h
@brief Arquivo de header/declaração das funções implementadas no arquivo eds.c
\par
Contém declarações de structs, e funções que lidam com a manipulação de listas duplamente encadeadas e árvores binárias.
 **/

#ifndef __EDS_H__
#define __EDS_H__

/**
@brief Struct que representa um Ninja, contendo todos seus atributos
 **/
typedef struct {
    char* nome;
    char* elemento;
    int ninjutsu;
    int genjutsu;
    int taijutsu;
    int defesa;
} Ninja;

/**
@brief Struct que representa um nó da árvore binária
\par
@var ninja ponteiro para estrutura do tipo Ninja
@var left ponteiro para nó filho da esquerda
@var right ponteiro para nó filho da direita
**/
typedef struct node {
    Ninja* ninja;
    struct node* left;
    struct node* right;
} t_node;


/**
@brief Struct que representa um elemento da lista duplamente encadeada
\par
@var ninja ponteiro para estrutura do tipo Ninja
@var anterior ponteiro para o elemento anterior ao atual
@var proximo ponteiro para o próximo elemento
**/
typedef struct elemento{
    Ninja* ninja;
    struct elemento* anterior;
    struct elemento* proximo;
}t_elemento;

/**
@brief Struct que representa a lista duplamente encadeada
\par
@var qtd quantidade de elementos na lista
@var ultimo ponteiro para o último elemento da lista
@var primeiro ponteiro para o primeiro elemento da lista
**/
typedef struct{
    int qtd;
    t_elemento* primeiro;
    t_elemento* ultimo;
}t_lista;


t_node* node_create();

Ninja* ninja_create(char* nome, char* elemento, int ninjutsu, int genjutsu, int taijutsu, int defesa);

void ninja_free(Ninja* ninja);

t_node* tree_create();

void tree_free(t_node* tree);

Ninja* fight(Ninja* ninja_one, Ninja* ninja_two, int attribute);

void tree_print_preorder(t_node* root);

void copiar_ninjas(t_node* root, t_lista* list);


t_lista* list_create();

t_elemento* element_create();

void inserir_ninja(t_lista* lista, int posicao, char* nome, char* elemento, int ninjutsu, int genjutsu, int taijutsu, int defesa);

void list_free(t_lista* lista);

void print_list(t_lista* lista);

Ninja* buscar_ninja(t_lista* list, int posicao);

#endif