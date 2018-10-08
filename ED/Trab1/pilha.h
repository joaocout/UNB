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

void remove_pilha(tipo_pilha* pilha);

void empilha(tipo_pilha* pilha, char* dados);

/*retorna os dados desempilhados*/
char* desempilha(tipo_pilha* pilha);


#endif