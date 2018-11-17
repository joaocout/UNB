#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "eds.h"


void randvet(int* vet, int range){
    int usado[range];
    for(int i=0; i<range; i++) usado[i]=0;
    for(int i=0; i<16; i++) vet[i] = 0;
    for(int i=0; i<16; i++){
        int aux = rand()%range;
        if(usado[aux]){
            while(usado[aux]){
                aux = rand()%range;
            }
        }
        vet[i] = aux;
        usado[aux] = 1;
    }
}


int main () {

    srand(time(0));
    t_lista* list = list_create();
    t_lista* aux_list = list_create();
    t_node* root = tree_create();

    char a[100], b[100];
    int c, d, e, f, linhas = 0;

    FILE* fd = fopen("ninjas.txt", "r");
    while(fscanf(fd, " %[^,], %[^,], %d, %d, %d, %d", a , b, &c, &d, &e, &f)!=EOF){
        linhas++;
    }
    rewind(fd);
    
    int random[16];
    randvet(random, linhas);

    for(int i=0; i<16; i++){
        int cont=0;
        while(fscanf(fd, " %[^,], %[^,], %d, %d, %d, %d", a , b, &c, &d, &e, &f)!=EOF){
            if(cont==random[i]){
                inserir_ninja(list, i, a, b, c, d, e, f);
                inserir_ninja(aux_list, i, a, b, c, d, e, f);
            }
            cont++;
        }
        rewind(fd);
    }
    fclose(fd);
    copiar_ninjas(root, aux_list);
    list_free(aux_list);

    print_list(list);
    puts(" ");
    tree_print_preorder(root);

    list_free(list);
    tree_free(root);
    return 0;
}