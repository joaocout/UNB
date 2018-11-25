/**
@file eds.c
@brief Contém a implementação de funções que lidam com a manipulação de listas duplamente encadeadas e árvores binárias
**/

#include "eds.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
@brief Cria um novo nó
\par
Retorna um ponteiro para o nó criado, com seus valores inicializados em NULL.
**/
t_node* node_create(){
    t_node* node = (t_node*)malloc(sizeof(t_node));
    node->left = NULL;
    node->right = NULL;
    node->ninja = NULL;
    return node;
}

/**
@brief Cria um novo Ninja
\par
Cria um novo ninja com os atributos recebidos por parâmetro da funcção, e retorna um ponteiro para o ninja criado.
**/
Ninja* ninja_create(char* nome, char* elemento, int ninjutsu, int genjutsu, int taijutsu, int defesa){
    Ninja* ninja = (Ninja*)malloc(sizeof(Ninja));
    ninja->nome = (char*)malloc(sizeof(char)*(strlen(nome)+1));
    strcpy(ninja->nome, nome);
    ninja->elemento = (char*)malloc(sizeof(char)*(strlen(elemento)+1));
    strcpy(ninja->elemento, elemento);
    ninja->ninjutsu = ninjutsu;
    ninja->genjutsu = genjutsu;
    ninja->taijutsu = taijutsu;
    ninja->defesa = defesa;
    return ninja;
}

/**
@brief Remove uma estrutura do tipo ninja
\par
Remove um ninja, liberando toda a memória alocada e utilizada pelo mesmo.
@param ninja ponteiro para o ninja que se deseja remover
**/
void ninja_free(Ninja* ninja){
    if(ninja!=NULL){
        free(ninja->nome);
        free(ninja->elemento);
        free(ninja);
    }
}

/**
@brief Função auxiliar para a criação de uma árvore de 5 níveis
\par
Função auxiliar, recursiva, que cria junto à 'tree_create', a árvore que será utilizada no trabalho.
Para cada nó filho de 'node', é criada uma nova estrutura do tipo node, enquanto o nível for menor que 5.
@param node nó atual da recursão
@param i nível atual na árvore
**/
void aux_tree_create(t_node* node, int i){
    if(i<5){
        i++;
        node->left = node_create();
        node->right = node_create();
        aux_tree_create(node->left, i);
        aux_tree_create(node->right, i);
    }
}

/**
@brief Função de criação de uma árvore binária de 5 níveis
\par
Retorna um ponteriro para a raiz da árvore criada. A árvore é criada através de uma função auxiliar, que facilita a recursão.
**/
t_node* tree_create(){
    t_node* root = node_create();
    aux_tree_create(root, 1);
    return root; 
}

/**
@brief Libera a árvore
\par
Função recursiva que libera toda a memória utilizada pela árvore, removendo sua estrutura.
Para cada nó da árvore, começando-se pela raiz, é liberada a memória utilizada por ele, e o mesmo é removido, em seguida, a mesma
funcção é chamada para seus nós filhos.
@param tree ponteiro para a raiz da árvore que se deseja remover
**/
void tree_free(t_node* tree){
    if(tree!=NULL){
        t_node* aux = tree->left;
        t_node* auxx = tree->right;
        if(tree->ninja!=NULL) ninja_free(tree->ninja);
        free(tree);
        tree_free(aux);
        tree_free(auxx);
    }
}

/**
@brief Representa a luta entre dois ninjas
\par
Simula a luta entre dois ninjas, utilizando um mesmo atributo, e retorna um ponteiro para o ninja vencedor.
@param ninja_one ponteiro para o primeiro ninja que irá lutar
@param ninja_two ponteiro para o segundo ninja que irá lutar
@param attribute atributo que será utilizado na luta
**/
Ninja* fight(Ninja* ninja_one, Ninja* ninja_two, int attribute){
    if(attribute==0){
        if(ninja_one->ninjutsu >= ninja_two->ninjutsu) return ninja_one;
        else return ninja_two;
    }
    else if(attribute==1){
        if(ninja_one->genjutsu >= ninja_two->genjutsu) return ninja_one;
        else return ninja_two;
    }
    else if(attribute==2){
        if(ninja_one->taijutsu >= ninja_two->taijutsu) return ninja_one;
        else return ninja_two;
    }
    else if(attribute==3){
        if(ninja_one->defesa >= ninja_two->defesa) return ninja_one;
        else return ninja_two;
    }
}

/**
@brief Imprime os nós de uma árvore em pré-ordem (recursivamente)
@param root ponteiro para a raiz da árvore que se deseja imprimir
**/
void tree_print_preorder(t_node* root){
    if(root->ninja!=NULL) printf("%s\n", root->ninja->nome);
    if(root->left!=NULL) tree_print_preorder(root->left);
    if(root->right!=NULL) tree_print_preorder(root->right);
}

/**
@brief Copia os ninjas de uma lista para as folhas de uma árvore binária
\par
Recursivamente, utiliza uma lista duplamente encadeadam, para copiar os elementos para as folhas da árvore.
Ao final do processo, a lista não poderá ser mais utilizada.
@param root ponteiro para a raiz da árvore para onde os ninjas serão copiados
@param list ponteiro para a lista onde os ninjas estão
**/
void copiar_ninjas(t_node* root, t_lista* list){
    if(root->left!=NULL) copiar_ninjas(root->left, list);
    if(root->right!=NULL) copiar_ninjas(root->right, list);
    if(root->left==NULL && root->right==NULL){
        t_elemento* aux = list->primeiro;
        root->ninja = aux->ninja;
        list->primeiro = aux->proximo;
        free(aux);
    }
}

/**
@brief Cria um elemento de uma lista duplamente encadeada
\par
Cria um elemento da lista, inicializando seus valores, e retorna um ponteiro para o elemento criado.
**/
t_elemento* element_create(){
    t_elemento* elemento = (t_elemento*)malloc(sizeof(t_elemento));
    elemento->anterior = NULL;
    elemento->proximo = NULL;
    elemento->ninja = NULL;
    return elemento;
}

/**
@brief Auxilia a criação de uma lista de tamanho 16
\par 
Opera de forma semelhante à 'aux_tree_create', utilizando recursividade para criar uma lista com 16 elementos vazios.
@param lista ponteiro para a lista que está sendo criada
@param elemento ponteiro para o elemento em que a recursão se encontra
@param i número do elemento atual
**/
void aux_list_create(t_lista* lista, t_elemento* elemento, int i){
    if(i<16){
        i++;
        t_elemento* aux = element_create();
        elemento->proximo = aux;
        aux->anterior = elemento;
        if(i==16) lista->ultimo = aux;
        aux_list_create(lista, aux, i);
    }
}

/**
@brief Cria uma lista de tamanho 16
\par
Opera de forma semelhante à 'tree_create' utilizando uma função auxiliar que facilita a recursão.
Retorna um ponteiro para a lista criada.
**/
t_lista* list_create(){
    t_lista* lista = (t_lista*)malloc(sizeof(t_lista));
    lista->qtd = 0;
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->primeiro = element_create();
    aux_list_create(lista, lista->primeiro, 1);
    return lista;
}

/**
@brief Remove uma lista duplamente encadeada
@param lista lista que se deseja remover
**/
void list_free(t_lista* lista){
    t_elemento* aux = lista->primeiro;
    while(aux!=NULL){

        if(aux->ninja!=NULL) ninja_free(aux->ninja);
        t_elemento* auxx = aux->proximo;
        free(aux);
        aux = auxx;
    }
    free(lista);
}

/**
@brief Insere um ninja na posição desejada de uma lista previamente alocada
\par
Recebe a lista que se deseja inserir, a posicao, e os atributos do ninja que será inserido.
A lista já deve estar criada, e os índices vão de 0 a 15, pois devem haver 16 elementos vazios criadas pela funcção 'list_create'.
**/
void inserir_ninja(t_lista* lista, int posicao, char* nome, char* elemento, int ninjutsu, int genjutsu, int taijutsu, int defesa){
    lista->qtd++;
    t_elemento* aux = lista->primeiro;
    int i = 0;
    while(i!=posicao){
        aux = aux->proximo;
        i++;
    }
    aux->ninja = ninja_create(nome, elemento, ninjutsu, genjutsu, taijutsu, defesa);
}

/**
@brief Printa uma lista de acordo com o utilizado no trabalho
\par
Printa uma lista, com os personagens números de acordo com seus índices.
Mostra somente um dos atributos do ninja, atributo escolhido de forma randômica.
@param lista lista que se deseja imprimir
**/
void print_list(t_lista* lista){
    t_elemento* aux = lista->primeiro;
    int i=1;
    while(aux!=NULL){
        Ninja* n = aux->ninja;
        printf("Personagem %d:\n", i);
        int a = rand()%100;

        printf("Ninjutsu: ");
        if(a>=0 && a<=24) printf("%d ",aux->ninja->ninjutsu);
        else printf("?? ");

        printf("Genjutsu: ");
        if(a>=25 && a<=49) printf("%d ",aux->ninja->genjutsu);
        else printf("?? ");

        printf("Taijutsu: ");
        if(a>=50 && a<=74) printf("%d ",aux->ninja->taijutsu);
        else printf("?? ");

        printf("Defesa: ");
        if(a>=75 && a<=99) printf("%d ",aux->ninja->defesa);
        else printf("?? ");

        printf("\n\n");
        aux = aux->proximo;
        i++;
    }
}

/**
@brief Busca um ninja em determinada posição
\par
Busca por um ninja em determinada posição de uma lista.
Retorna um ponteiro para o ninja que está na posição buscada.
@param list lista que se deseja buscar
@param posicao posição que se deseja buscar
**/
Ninja* buscar_ninja(t_lista* list, int posicao){
    int i=0;
    t_elemento* aux = list->primeiro;
    while(i!=posicao){
        aux = aux->proximo;
        i++;
    }
    return aux->ninja;
}