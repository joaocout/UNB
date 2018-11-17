#include "eds.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


t_node* node_create(){
    t_node* node = (t_node*)malloc(sizeof(t_node));
    node->left = NULL;
    node->right = NULL;
    node->ninja = NULL;
    return node;
}

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

void ninja_free(Ninja* ninja){
    if(ninja!=NULL){
        free(ninja->nome);
        free(ninja->elemento);
        free(ninja);
    }
}

void aux_tree_create(t_node* node, int i){
    if(i<5){
        i++;
        node->left = node_create();
        node->right = node_create();
        aux_tree_create(node->left, i);
        aux_tree_create(node->right, i);
    }
}

t_node* tree_create(){
    t_node* root = node_create();
    aux_tree_create(root, 1);
    return root; 
}

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

Ninja* fight(Ninja* ninja_one, Ninja* ninja_two, int attribute){
    if(attribute==1){
        if(ninja_one->ninjutsu >= ninja_two->ninjutsu) return ninja_one;
        else return ninja_two;
    }
    else if(attribute==2){
        if(ninja_one->genjutsu >= ninja_two->genjutsu) return ninja_one;
        else return ninja_two;
    }
    else if(attribute==3){
        if(ninja_one->taijutsu >= ninja_two->taijutsu) return ninja_one;
        else return ninja_two;
    }
    else if(attribute==4){
        if(ninja_one->defesa >= ninja_two->defesa) return ninja_one;
        else return ninja_two;
    }
}

void tree_print_preorder(t_node* root){
    if(root->ninja!=NULL) printf("%s\n", root->ninja->nome);
    if(root->left!=NULL) tree_print_preorder(root->left);
    if(root->right!=NULL) tree_print_preorder(root->right);
}

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



t_elemento* element_create(){
    t_elemento* elemento = (t_elemento*)malloc(sizeof(t_elemento));
    elemento->anterior = NULL;
    elemento->proximo = NULL;
    elemento->ninja = NULL;
    return elemento;
}

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

t_lista* list_create(){
    t_lista* lista = (t_lista*)malloc(sizeof(t_lista));
    lista->qtd = 0;
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->primeiro = element_create();
    aux_list_create(lista, lista->primeiro, 1);
    return lista;
}

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

void print_list(t_lista* lista){
    t_elemento* aux = lista->primeiro;
    while(aux!=NULL){
        Ninja* n = aux->ninja;
        printf("%s %s %d %d %d %d\n", n->nome, n->elemento, n->ninjutsu, n->genjutsu, n->taijutsu, n->defesa);
        aux = aux->proximo;
    }
}