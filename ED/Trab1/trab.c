#include <stdio.h>
#include "funcoes.h"
#include "pilha.h"

int main (){
    tipo_pilha* pilha = aloca_pilha();
        empilha(pilha, "12,98");
        empilha(pilha, "63,15");
        empilha(pilha, "90,12");
        empilha(pilha, "2234");
        print_pilha(pilha);
        remove_pilha(pilha);
    return 0;
}