#ifndef __EDS_H__
#define __EDS_H__


typedef struct {
    char* nome;
    char* elemento;
    int ninjutsu;
    int genjutsu;
    int taijutsu;
    int defesa;
} Ninja;

typedef struct node {
    Ninja* ninja;
    struct node* left;
    struct node* right;
} t_node;


typedef struct elemento{
    Ninja* ninja;
    struct elemento* anterior;
    struct elemento* proximo;
}t_elemento;

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

/*void copiar_ninjas(t_node* root, t_lista* list);
*/


t_lista* list_create();

t_elemento* element_create();

void inserir_ninja(t_lista* lista, int posicao, char* nome, char* elemento, int ninjutsu, int genjutsu, int taijutsu, int defesa);

void list_free(t_lista* lista);

void print_list(t_lista* lista);


#endif