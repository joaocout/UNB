/**
@file pilha.c
@brief Contém a implementação de funções responsáveis pelo manejo de pilhas
\par
Contém a implementação de funcões de alocação de pilha, de inserção de elementos, entre outras.
**/

#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
@brief Retorna um ponteiro para a pilha alocada
\par
Aloca dinamicamente uma pilha, inicializando os seus valores para '0' ou 'NULL'.
**/
tipo_pilha* aloca_pilha (){
	tipo_pilha* pilha;
	pilha = (tipo_pilha*) malloc(sizeof(tipo_pilha));
	pilha->topo = NULL;
	pilha->quantidade = 0;
	return pilha;
}

/**
@brief Retorna um ponteiro para o elemento alocado
\par
Aloca dinamicamente um elemento de uma pilha, incializando seus valores.
@param dados string que está sendo empilhada na pilha, sua memória também é alocada dinamicamente
**/
tipo_elemento* aloca_elemento(char* dados){
	tipo_elemento* elemento = (tipo_elemento*)malloc(sizeof(tipo_elemento));
	elemento->dados = (char*) malloc(sizeof(char)*(strlen(dados)+1));
	strcpy(elemento->dados, dados);
	elemento->proximo = NULL;
	return elemento;
}

/**
@brief Insere um elemento no topo de uma pilha
\par
Recebe os dados que serão empilhados e a onde serão empilhados.
@param pilha ponteiro para a pilha em que se deseja empilhar
@param dados dados(string) que serão empilhados
**/
void empilha(tipo_pilha* pilha, char* dados){
	if(pilha->topo == NULL){
		pilha->topo = aloca_elemento(dados);
		pilha->quantidade++;
	}
	else{
		pilha->quantidade++;
		tipo_elemento* aux = pilha->topo;
		pilha->topo = aloca_elemento(dados);
		pilha->topo->proximo = aux;
	}
}

/**
@brief Remove um elemento do topo de uma pilha
\par
Recebe um ponteiro para a pilha de onde se removerá elementos.
@param pilha ponteiro para a pilha de que se deseja desempilhar
**/
void desempilha(tipo_pilha* pilha){
	pilha->quantidade--;
	tipo_elemento* aux = pilha->topo;
	pilha->topo = aux->proximo;
	free(aux->dados);
	free(aux);
}

/**
@brief Remove completamente uma pilha
\par
Recebe um ponteiro para a pilha que se deseja remover, remove-se a pilha liberando toda a memória
anteriormente alocada.
@param pilha ponteiro para a pilha que se deseja remover
**/
void remove_pilha(tipo_pilha* pilha){
	tipo_elemento* aux = pilha->topo;
	while(aux!=NULL){
		free(aux->dados);
		tipo_elemento* auxx = aux->proximo;
		free(aux);
		aux = auxx;
	}
	free(pilha);
}


/**
@brief Printa todo o conteúdo de uma pilha
\par
Recebe um ponteiro para a pilha que se deseja mostrar o conteúdo,
o processo é feito respeitando a restrição de acesso aos elementos de uma pilha,
e o conteúdo é printado seguindo os moldes da especificação do trabalho.
@param pilha ponteiro para a pilha que se deseja mostrar
**/
void print_pilha(tipo_pilha* pilha){
	tipo_pilha* aux = aloca_pilha();
	while(pilha->topo!=NULL){
		char* a = (char*) malloc(sizeof(char) * (strlen(pilha->topo->dados)+1));
		strcpy(a, pilha->topo->dados);
		desempilha(pilha);
		empilha(aux, a);
		free(a);
	}
	while(aux->topo!=NULL){
		printf("%d. %s\n", aux->quantidade, aux->topo->dados);
		char* a = (char*) malloc(sizeof(char) * (strlen(aux->topo->dados)+1));
		strcpy(a, aux->topo->dados);
		desempilha(aux);
		empilha(pilha, a);
		free(a);
	}
	free(aux);
}