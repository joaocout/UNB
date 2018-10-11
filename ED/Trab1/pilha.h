#ifndef _PILHA_H_
#define _PILHA_H_



typedef struct elemento{
	struct elemento* proximo;
	char* dados;
}tipo_elemento;

typedef struct{
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
void print_pilha(tipo_pilha* pilha);

#endif