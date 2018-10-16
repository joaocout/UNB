#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



tipo_pilha* aloca_pilha (){
	tipo_pilha* pilha;
	pilha = (tipo_pilha*) malloc(sizeof(tipo_pilha));
	pilha->topo = NULL;
	pilha->quantidade = 0;
	return pilha;
}


tipo_elemento* aloca_elemento(char* dados){
	tipo_elemento* elemento = (tipo_elemento*)malloc(sizeof(tipo_elemento));
	elemento->dados = (char*) malloc(sizeof(char)*(strlen(dados)+1));
	strcpy(elemento->dados, dados);
	elemento->proximo = NULL;
	return elemento;
}


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


void desempilha(tipo_pilha* pilha){
	pilha->quantidade--;
	tipo_elemento* aux = pilha->topo;
	pilha->topo = aux->proximo;
	free(aux->dados);
	free(aux);
}


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


/*printa os elementos do stack, obedecendo as restricoes de acesso aos elementos*/
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