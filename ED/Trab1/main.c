#include <stdio.h>
#include "pilha.h"

int main () {
	tipo_pilha* pilha = aloca_pilha();
	
	empilha(pilha, "127938");
	empilha(pilha, "1ASdas");
	empilha(pilha, "asdas");
	empilha(pilha, "Asdfa8");
	empilha(pilha, "1wsdas8");
	printf("qtd = %d | topo = %s\n", pilha->quantidade, pilha->topo->dados);
	print_pilha(pilha);
	printf("\n");

	desempilha(pilha);
	desempilha(pilha);
	printf("qtd = %d | topo = %s\n", pilha->quantidade, pilha->topo->dados);
	print_pilha(pilha);
	printf("\n");

	desempilha(pilha);
	desempilha(pilha);
	printf("qtd = %d | topo = %s\n", pilha->quantidade, pilha->topo->dados);
	print_pilha(pilha);
	printf("\n");

	desempilha(pilha);
	printf("qtd = %d |\n", pilha->quantidade);
	printf("\n");

	empilha(pilha, "a");
	empilha(pilha, "olasldjh");
	printf("qtd = %d | topo = %s\n", pilha->quantidade, pilha->topo->dados);
	print_pilha(pilha);
	printf("\n");	


	remove_pilha(pilha);
	return 0;
}