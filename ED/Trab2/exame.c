#include "exame.h"
#include "eds.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


Ninja* batalhas[15][2];
int batalha=0;
int fim=0;

void torneio(t_node* root, Ninja* personagem, int etapa){

    if(etapa==5){
        fim=1;
        return;
    }

    if(root->left->ninja==NULL && root->right->ninja==NULL){
        torneio(root->left, personagem, etapa);
        torneio(root->right, personagem, etapa);
    } 
    else if(root->left->ninja!=NULL && root->right->ninja!=NULL && etapa<=4){

        if(!strcmp(root->left->ninja->nome, personagem->nome) || !strcmp(root->right->ninja->nome, personagem->nome)){
            int a = -1;
            while(a<1 || a>4){
                system("clear");
                printf("Etapa %d\n\n", etapa);
                printf("Seu personagem: %s\n\n", personagem->nome);
                printf("1) Ninjutsu: %d\n", personagem->ninjutsu);
                printf("2) Genjutsu: %d\n", personagem->genjutsu);
                printf("3) Taijutsu: %d\n", personagem->taijutsu);
                printf("4) Defesa: %d\n\n", personagem->defesa);
                printf("Seu adversário: ");
                if(!strcmp(root->left->ninja->nome, personagem->nome)) printf("%s\n\n", root->right->ninja->nome);
                else printf("%s\n\n", root->left->ninja->nome);
                printf("Selecione um atributo: ");
                scanf("%d", &a);
                system("clear");
            }
            Ninja* vencedor = fight(root->left->ninja, root->right->ninja, a-1);
            root->ninja = ninja_create(vencedor->nome, vencedor->elemento, vencedor->ninjutsu, vencedor->genjutsu, vencedor->taijutsu, vencedor->defesa);            
            if(!strcmp(vencedor->nome,personagem->nome)){
                system("clear");
                printf("VITORIA\n\n");
                if(a==1){
                    printf("%s (Ninjutsu %d) ", root->left->ninja->nome, root->left->ninja->ninjutsu);
                    printf("x %s (Ninjutsu %d)\n\n", root->right->ninja->nome, root->right->ninja->ninjutsu);
                }
                else if(a==2){
                    printf("%s (Genjutsu %d) ", root->left->ninja->nome, root->left->ninja->genjutsu);
                    printf("x %s (Genjutsu %d)\n\n", root->right->ninja->nome, root->right->ninja->genjutsu);
                }
                else if(a==3){
                    printf("%s (Taijutsu %d) ", root->left->ninja->nome, root->left->ninja->taijutsu);
                    printf("x %s (Taijutsu %d)\n\n", root->right->ninja->nome, root->right->ninja->taijutsu);
                }
                else if(a==4){
                    printf("%s (Defesa %d) ", root->left->ninja->nome, root->left->ninja->defesa);
                    printf("x %s (Defesa %d)\n\n", root->right->ninja->nome, root->right->ninja->defesa);
                }
                ninja_free(root->left->ninja);
                root->left->ninja = NULL;
                ninja_free(root->right->ninja);
                root->right->ninja = NULL;
                printf("%s ganhou a batalha\n", personagem->nome);
                printf("Pressione qqr tecla para continuar: ");
                getchar(); getchar();
            }
            else{
                ninja_free(root->left->ninja);
                root->left->ninja = NULL;
                ninja_free(root->right->ninja);
                root->right->ninja = NULL;
                fim = 1;
                printf("DERROTA\n\n");
                printf("Pressione qqr tecla para continuar: ");
                getchar(); getchar();
                system("clear");
                return;
            }
        }
        else{
            int a = rand()%4;
            Ninja* vencedor = fight(root->left->ninja, root->right->ninja, a); 
            root->ninja = ninja_create(vencedor->nome, vencedor->elemento, vencedor->ninjutsu, vencedor->genjutsu, vencedor->taijutsu, vencedor->defesa);
            ninja_free(root->left->ninja);
            root->left->ninja = NULL;
            ninja_free(root->right->ninja);
            root->right->ninja = NULL;

        }
    }   
}


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

Ninja* escolherninja(t_lista* list){
    int a = 20;
    while(a<1 || a>16){
        system("clear");
        printf("Escolha seu personagem:\n\n");
        print_list(list);
        printf("\n");
        printf("Escolha uma opção: ");
        scanf("%d", &a);
    }
    return buscar_ninja(list, a-1);
}

void start () {

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



    Ninja* personagem = escolherninja(list);

    int i=1;
    while(!fim){
        torneio(root, personagem, i);
        if(i==5) {
            system("clear");
            printf("VC VENCEU O TORNEIO\n");
            printf("Pressione qqr tecla para continuar: ");
            getchar();
            system("clear");
        }
        i++;
    }

    list_free(list);
    tree_free(root);
}