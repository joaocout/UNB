#include <stdio.h>
#include "pilha.h"

int main () {
    tipo_pilha* pilha = aloca_pilha();
    printf("qtd de elementos = %d\n", pilha->quantidade);
    empilha(pilha, "23242");
    printf("qtd de elementos = %d\n", pilha->quantidade);
    empilha(pilha, "akjahsd");
    printf("qtd de elementos = %d\n", pilha->quantidade);
    empilha(pilha, "8134");
    printf("qtd de elementos = %d\n", pilha->quantidade);
    remove_pilha(pilha);
    return 0;
}