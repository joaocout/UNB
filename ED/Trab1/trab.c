#include <stdio.h>
#include "funcoes.h"
#include "pilha.h"


int main (){
    tipo_pilha* pilha = aloca_pilha();
    empilha(pilha, "12.6565");
    empilha(pilha, "11231.6565");
    empilha(pilha, "12.6123565");
    empilha(pilha, "12abd5");
    empilha(pilha, "10985");
    empilha(pilha, "1Asd565");
    empilha(pilha, "112365");
    print_pilha(pilha);
    remove_pilha(pilha);
    return 0;
}