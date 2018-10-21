/**
@file pilha.h
@brief Contém os headers/declaração de structs e de funções implementadas no arquivo pilha.c
**/

#ifndef _PILHA_H_
#define _PILHA_H_


/**
@brief Struct que representa um elemento da pilha
\par
@var proximo Ponteiro para o próximo elemento da pilha
@var dados String dos dados que estão empilhados
**/
typedef struct elemento{
	struct elemento* proximo;
	char* dados;
}tipo_elemento;


/**
@brief Struct que representa uma pilha
\par
@var topo ponteiro para o elemento do topo de uma pilha
@var quantidade quantidade de elementos atualmente na pilha
**/
typedef struct pilha{
	tipo_elemento* topo;
	int quantidade;
}tipo_pilha;



/*retorna endereco da pilha alocada*/
tipo_pilha* aloca_pilha();

/*retorna endereco do elemento alocado*/
tipo_elemento* aloca_elemento(char* dados);

/*remove tudo que ha na pilha e libera todas as memorias alocadas*/
void remove_pilha(tipo_pilha* pilha);

/*adiciona elemento ao topo da pilha*/
void empilha(tipo_pilha* pilha, char* dados);

/*retira elemento do topo da pilha*/
void desempilha(tipo_pilha* pilha);

/*printa tudo que ha na pilha, obedecendo as restricoes de acesso aos elementos*/
/*com o topo mais abaixo e a base mais acima, como esta na especificacao*/
void print_pilha(tipo_pilha* pilha);

#endif
