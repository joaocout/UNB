/*
Aluno: JOAO PEDRO ASSUNCAO COUTINHO;
Matricula: 18/0019813;
Turma: A;
Atividade Extra 1 - Estrutura de Dados - UnB;
*/


#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

t_lista* aloca_lista(){
    t_lista* lista = (t_lista*)malloc(sizeof(t_lista));
    lista->primeiro = NULL;
    lista->fim = NULL;
    lista->quantidade = 0;
    return lista;
}

t_produto* aloca_produto(int codigo, char* nome, float preco, int quantidade){
    t_produto* produto = (t_produto*)malloc(sizeof(t_produto));
    produto->codigo = codigo;
    produto->nome = (char*)malloc(strlen(nome)+1);
    strcpy(produto->nome, nome);
    produto->preco = preco;
    produto->quantidade = quantidade;
    return produto;
}

t_elemento* aloca_elemento(int codigo, char* nome, float preco, int quantidade){
    t_elemento* elemento =  (t_elemento*)malloc(sizeof(t_elemento));
    elemento->produto = aloca_produto(codigo, nome, preco, quantidade);
    elemento->proximo = NULL;
}

void remove_lista(t_lista* lista){
    t_elemento* aux = lista->primeiro;
    while (aux != NULL){
        free(aux->produto->nome);
        free(aux->produto);
        t_elemento* auxx = aux->proximo;
        free(aux);
        aux = auxx;
    }
    free(lista);
}

/*retorna 0 caso haja sucesso na operacao e 1 caso contrario*/
int inserir(int posicao, int codigo, char* nome, float preco, int quantidade, t_lista* lista){
    if(lista->quantidade == 0){
        lista->quantidade++;
        lista->primeiro = aloca_elemento(codigo, nome, preco, quantidade);
        lista->fim = lista->primeiro;
        return 0;
    }
    else if(posicao == lista->quantidade){
        lista->quantidade++;
        t_elemento* aux = lista->primeiro;
        while(aux->proximo!=NULL){
            aux = aux->proximo;
        }
        aux->proximo = aloca_elemento(codigo, nome, preco, quantidade);
        lista->fim = aux->proximo;
        return 0;
    }
    else if(posicao<0 || posicao>lista->quantidade){
        return 1;
    }
    else{
        lista->quantidade++;
        t_elemento* aux = lista->primeiro;
        int count = 0;
        while(count!=posicao-1){
            count++;
            aux = aux->proximo;
        }
        t_elemento* auxx = aux->proximo;
        aux->proximo = aloca_elemento(codigo, nome, preco, quantidade);
        aux = aux->proximo;
        aux->proximo = auxx;
        return 0;
    }
}

int codigospares(t_lista* lista){
    t_elemento* aux = lista->primeiro;
    int pares=0;
    while(aux!=NULL){
        if(aux->produto->codigo % 2 == 0)
            pares++;
        aux = aux->proximo;
    }
    return pares;
}

float precomedio(t_lista* lista){
    t_elemento* aux = lista->primeiro;
    float soma=0;
    int count=0;
    while(aux!=NULL){
        soma+=aux->produto->preco;
        aux=aux->proximo;
        count++;
    }
    return soma/count;
}

float menorpreco(t_lista* lista){
    t_elemento* aux = lista->primeiro;
    int count = 0;
    float min;
    while(aux!=NULL){
        if(count==0)
            min = aux->produto->preco;
        else if(aux->produto->preco < min)
            min = aux->produto->preco;
        aux = aux->proximo;
        count++;
    }
    return min;
}

float maiorpreco(t_lista* lista){
    t_elemento* aux = lista->primeiro;
    int count = 0;
    float max;
    while(aux!=NULL){
        if(count==0)
            max = aux->produto->preco;
        else if(aux->produto->preco > max)
            max = aux->produto->preco;
        aux = aux->proximo;
        count++;
    }
    return max;
}

int posicaomaior(t_lista* lista){
    t_elemento* aux = lista->primeiro;
    int posmaior;
    float max;
    int count = 0;
    while(aux!= NULL){
        if(count==0){
            max = aux->produto->preco;
            posmaior = count;
        }
        else if(aux->produto->preco > max){
            max = aux->produto->preco;
            posmaior = count;
        }
        aux = aux->proximo;
        count++;
    }
    return posmaior;
}

float valortotal(t_lista* lista){
    t_elemento* aux = lista->primeiro;
    float soma=0;
    while(aux!= NULL){
        soma+= (aux->produto->quantidade * aux->produto->preco);
        aux = aux->proximo;
    }
    return soma;
}

t_produto* qualproduto(t_lista* lista, int codigo){
    if(lista->quantidade == 0)
        return NULL;
    t_elemento* aux = lista->primeiro;
    while(aux->proximo != NULL){
        if(aux->produto->codigo == codigo)
            return aux->produto;
        aux = aux->proximo;
    }
    return NULL;
}