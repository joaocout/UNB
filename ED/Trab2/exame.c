#include "exame.h"
#include "eds.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char batalhas[15][100];
int batalha=0;
int fim=0;

void historico(){
    int etapa=1;
    for(int i=0; i<batalha; i++){
        if(i==0) printf("Etapa %d\n\n", etapa);
        if(i==8){
            etapa++;
            printf("\nEtapa %d\n\n", etapa);
        }
        if(i==12){
            etapa++;
            printf("\nEtapa %d\n\n", etapa);
        }
        if(i==14){
            etapa++;
            printf("\nEtapa %d\n\n", etapa);
        }
        printf("%s\n", batalhas[i]);
    }
}

void torneio(t_node* root, Ninja* personagem, int etapa){

    if(etapa==5){
        fim=1;
        system("clear");
        printf("VC VENCEU O TORNEIO\n");
        printf("Pressione ENTER para continuar: ");
        getchar();
        system("clear");
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

            if(a==1) sprintf(batalhas[batalha], "%s(Ninjutsu %d) x %s(Ninjutsu %d)", root->left->ninja->nome, root->left->ninja->ninjutsu,
                            root->right->ninja->nome, root->right->ninja->ninjutsu);
            else if(a==2) sprintf(batalhas[batalha], "%s(Genjutsu %d) x %s(Genjutsu %d)", root->left->ninja->nome, root->left->ninja->genjutsu,
                            root->right->ninja->nome, root->right->ninja->genjutsu);
            else if(a==3) sprintf(batalhas[batalha], "%s(Taijutsu %d) x %s(Taijutsu %d)", root->left->ninja->nome, root->left->ninja->taijutsu,
                            root->right->ninja->nome, root->right->ninja->taijutsu);
            else if(a==4) sprintf(batalhas[batalha], "%s(Defesa %d) x %s(Defesa %d)", root->left->ninja->nome, root->left->ninja->defesa,
                            root->right->ninja->nome, root->right->ninja->defesa);
            batalha++;

            Ninja* vencedor = fight(root->left->ninja, root->right->ninja, a-1);
            root->ninja = ninja_create(vencedor->nome, vencedor->elemento, vencedor->ninjutsu, vencedor->genjutsu, vencedor->taijutsu, vencedor->defesa);            
            system("clear");
            if(!strcmp(vencedor->nome,personagem->nome)){
                printf("VITORIA\n\n");
            }
            else{
                printf("DERROTA\n\n");
                fim=1;
            }
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
            printf("%s ganhou a batalha!\n", root->ninja->nome);
            printf("Pressione ENTER para continuar: ");
            getchar(); getchar();
            system("clear");
        }
        else{
            int a = rand()%4;
            Ninja* vencedor = fight(root->left->ninja, root->right->ninja, a);
            
            a++;
            if(a==1) sprintf(batalhas[batalha], "%s(Ninjutsu %d) x %s(Ninjutsu %d)", root->left->ninja->nome, root->left->ninja->ninjutsu,
                            root->right->ninja->nome, root->right->ninja->ninjutsu);
            else if(a==2) sprintf(batalhas[batalha], "%s(Genjutsu %d) x %s(Genjutsu %d)", root->left->ninja->nome, root->left->ninja->genjutsu,
                            root->right->ninja->nome, root->right->ninja->genjutsu);
            else if(a==3) sprintf(batalhas[batalha], "%s(Taijutsu %d) x %s(Taijutsu %d)", root->left->ninja->nome, root->left->ninja->taijutsu,
                            root->right->ninja->nome, root->right->ninja->taijutsu);
            else if(a==4) sprintf(batalhas[batalha], "%s(Defesa %d) x %s(Defesa %d)", root->left->ninja->nome, root->left->ninja->defesa,
                            root->right->ninja->nome, root->right->ninja->defesa);
            batalha++;
            
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
        i++;
    }
    historico();
    printf("\nPressione ENTER para continuar: ");
    getchar();

    list_free(list);
    tree_free(root);
}