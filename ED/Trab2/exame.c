/**
@file exame.c
@brief Contém a implementação de funções que tornam possíveis a execução do exame em si,
imprimindo menus, mensagens na tela, e modificando as estruturas de dados árvore binária e lista duplamente encadeada
**/

#include "exame.h"
#include "eds.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char batalhas[15][100];
int batalha;
int fim;
int bloqueado;

/**
@brief Inicializa variáveis globais
\par
Inicializa algumas variáveis muito importantes na execução do trabalho.
A função é chamada a cada vez que um novo exame é iniciado.  
**/
void initglobal(){
    fim = 0;
    batalha = 0;
    bloqueado=0;
    for(int i=0; i<15; i++)
        for(int j=0; j<100; j++)
            batalhas[i][j] = '\0';
}

/**
@brief Lida com a supremacia elemental
\par
Recebe dois ninjas, e retorna um ponteiro para o ninja, entre os dois, superior elementalmente ao outro,
caso haja supremacia elementar. Caso não haja supremacia, o retorno é nulo.
@param a ponteiro para o primeiro ninja
@param b ponteiro para o segundo ninja
**/
Ninja* inf_sup_elem(Ninja* a, Ninja* b){

    if(!strcmp(a->elemento, "Fogo") && !strcmp(b->elemento, "Vento")) return a;
    if(!strcmp(a->elemento, "Vento") && !strcmp(b->elemento, "Fogo")) return b;

    if(!strcmp(a->elemento, "Vento") && !strcmp(b->elemento, "Relampago")) return a;
    if(!strcmp(a->elemento, "Relampago") && !strcmp(b->elemento, "Vento")) return b;

    if(!strcmp(a->elemento, "Relampago") && !strcmp(b->elemento, "Terra")) return a;
    if(!strcmp(a->elemento, "Terra") && !strcmp(b->elemento, "Relampago")) return b;

    if(!strcmp(a->elemento, "Terra") && !strcmp(b->elemento, "Agua")) return a;
    if(!strcmp(a->elemento, "Agua") && !strcmp(b->elemento, "Terra")) return b;

    if(!strcmp(a->elemento, "Agua") && !strcmp(b->elemento, "Fogo")) return a;
    if(!strcmp(a->elemento, "Fogo") && !strcmp(b->elemento, "Agua")) return b;

    return NULL;    
}

/**
@brief Exibe o histórico de batalhas até a etapa em que o personagem escolhido competiu
**/
void historico(){
    int etapa=1;
    printf("HISTORICO DE BATALHAS: \n\n");
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

/**
@brief Responsável pela execução das etapas do torneio
\par
Executa as etapas do torneio, imprimindo mensagens de vitória, de derrota além da mensagem de campeão.
Recursivamente chega ao nós cujos filhos, não são nulos(ou seja, possuem dois ninjas a lutar), e chama a função 'fight', declarada em eds.h.
Imprime também as mensagens de superioridade e inferioridade elementar, e manuseia os atributos caso haja uma das duas. Imprime os atributos
do personagem escolhido, conforme as restrições do trabalho(o atributo utilizado anteriormente não pode ser utilizado) e o nome do próximo
adversário, e solicita entrada de escolha via 'scanf'. Grava via 'sprintf', o histórico de cada batalha na matriz global 'batalhas', utilizando
a global 'batalha' para determinar em qual batalha atualmente se está. A global 'fim' determina se o torneio chegou ou não ao fim, e a global bloqueado
determina qual atributo foi anteriormente esolhido pelo usuário, e portanto não deve ser utilizado novamente.
@param root ponteiro para a raiz da árvore em que as batalhas ocorrerão
@param personagem ponteiro para o ninja escolhido pelo usuário
@param etapa armazena a etapa atual do torneio
**/
void torneio(t_node* root, Ninja* personagem, int etapa){

    if(etapa==5){
        fim=1;
        system("clear");
        printf("VC VENCEU O TORNEIO!\n\n");
        printf("Pressione ENTER para continuar: ");
        getchar();
        return;
    }

    if(root->left->ninja==NULL && root->right->ninja==NULL){
        torneio(root->left, personagem, etapa);
        torneio(root->right, personagem, etapa);
    } 
    else if(root->left->ninja!=NULL && root->right->ninja!=NULL && etapa<=4){
        
        if(!strcmp(root->left->ninja->nome, personagem->nome) || !strcmp(root->right->ninja->nome, personagem->nome)){
            
            int temp1 = personagem->ninjutsu;
            int temp2 = personagem->genjutsu;
            int temp3 = personagem->taijutsu;
            int temp4 = personagem->defesa;

            int supremacia;
            Ninja* superior = inf_sup_elem(root->left->ninja, root->right->ninja);
            if(superior==NULL) supremacia = 0;
            else if(!strcmp(superior->nome, personagem->nome)) supremacia = 1;
            else supremacia = -1;

            int esquerda=0;
            if(!strcmp(personagem->nome, root->left->ninja->nome)) esquerda=1;

            double multiplicador;
            if(supremacia==1) multiplicador = 1.2;
            else if(supremacia==-1) multiplicador = 0.8;

            if(supremacia==1 || supremacia==-1){
                personagem->ninjutsu *= multiplicador;
                personagem->genjutsu *= multiplicador;
                personagem->taijutsu *= multiplicador;
                personagem->defesa *= multiplicador;
                if(esquerda){
                    root->left->ninja->ninjutsu *= multiplicador;
                    root->left->ninja->genjutsu *= multiplicador;
                    root->left->ninja->taijutsu *= multiplicador;
                    root->left->ninja->defesa *= multiplicador;
                }
                else{
                    root->right->ninja->ninjutsu *= multiplicador;
                    root->right->ninja->genjutsu *= multiplicador;
                    root->right->ninja->taijutsu *= multiplicador;
                    root->right->ninja->defesa *= multiplicador;
                }
            }

            int a = -1;
            while(a<1 || a>4){
                system("clear");
                printf("Etapa %d\n\n", etapa);
                printf("Seu personagem: %s\n\n", personagem->nome);
                if(supremacia==1){
                    if(esquerda) printf("SUPREMACIA ELEMENTAL: %s > %s\n", root->left->ninja->elemento, root->right->ninja->elemento);
                    else printf("SUPREMACIA ELEMENTAL: %s > %s\n", root->right->ninja->elemento, root->left->ninja->elemento);
                    printf("Todos os atributos foram multiplicados por 1.2\n\n");
                }
                else if(supremacia==-1){
                    if(esquerda) printf("INFERIORIDADE ELEMENTAL: %s < %s\n", root->left->ninja->elemento, root->right->ninja->elemento);
                    else printf("INFERIORIDADE ELEMENTAL: %s < %s\n", root->right->ninja->elemento, root->left->ninja->elemento);
                    printf("Todos os atributos foram multiplicados por 0.8\n\n");
                }
                
                if(bloqueado!=1) printf("1) Ninjutsu: %d\n", personagem->ninjutsu);
                else printf("XX) XX: XX\n");
                
                if(bloqueado!=2) printf("2) Genjutsu: %d\n", personagem->genjutsu);
                else printf("XX) XX: XX\n");
                
                if(bloqueado!=3) printf("3) Taijutsu: %d\n", personagem->taijutsu);
                else printf("XX) XX: XX\n");
                
                if(bloqueado!=4) printf("4) Defesa: %d\n\n", personagem->defesa);
                else printf("XX) XX: XX\n\n");

                printf("Seu adversario: ");
                if(!strcmp(root->left->ninja->nome, personagem->nome)) printf("%s\n\n", root->right->ninja->nome);
                else printf("%s\n\n", root->left->ninja->nome);
                printf("Selecione um atributo: ");
                scanf("%d", &a);
                if(a==bloqueado) a=0;
                system("clear");
            }
            bloqueado = a;

            if(a==1) sprintf(batalhas[batalha], "%s(Ninjutsu %d) x %s(Ninjutsu %d)", root->left->ninja->nome, root->left->ninja->ninjutsu,
                            root->right->ninja->nome, root->right->ninja->ninjutsu);
            else if(a==2) sprintf(batalhas[batalha], "%s(Genjutsu %d) x %s(Genjutsu %d)", root->left->ninja->nome, root->left->ninja->genjutsu,
                            root->right->ninja->nome, root->right->ninja->genjutsu);
            else if(a==3) sprintf(batalhas[batalha], "%s(Taijutsu %d) x %s(Taijutsu %d)", root->left->ninja->nome, root->left->ninja->taijutsu,
                            root->right->ninja->nome, root->right->ninja->taijutsu);
            else if(a==4) sprintf(batalhas[batalha], "%s(Defesa %d) x %s(Defesa %d)", root->left->ninja->nome, root->left->ninja->defesa,
                            root->right->ninja->nome, root->right->ninja->defesa);

            if(supremacia==1) strcat(batalhas[batalha], " [x1.2]");
            else if(supremacia==-1) strcat(batalhas[batalha], " [x0.8]");

            Ninja* vencedor = fight(root->left->ninja, root->right->ninja, a-1);
            system("clear");
            if(!strcmp(vencedor->nome,personagem->nome)){
                printf("Resultado da Etapa %d: VITORIA\n\n", etapa);
            }
            else{
                printf("Resultado da Etapa %d: DERROTA\n\n", etapa);
                fim=1;
            }
            printf("%s\n\n", batalhas[batalha]);
            batalha++;

            personagem->ninjutsu = temp1;
            personagem->genjutsu = temp2;
            personagem->taijutsu = temp3;
            personagem ->defesa = temp4;
            if(esquerda){
                root->left->ninja->ninjutsu = temp1;
                root->left->ninja->genjutsu = temp2;
                root->left->ninja->taijutsu = temp3;
                root->left->ninja->defesa = temp4;
            }
            else{
                root->right->ninja->ninjutsu = temp1;
                root->right->ninja->genjutsu = temp2;
                root->right->ninja->taijutsu = temp3;
                root->right->ninja->defesa = temp4;
            }

            root->ninja = ninja_create(vencedor->nome, vencedor->elemento, vencedor->ninjutsu, vencedor->genjutsu, vencedor->taijutsu, vencedor->defesa);
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

            Ninja* vencedor = fight(root->left->ninja, root->right->ninja, a);
            root->ninja = ninja_create(vencedor->nome, vencedor->elemento, vencedor->ninjutsu, vencedor->genjutsu, vencedor->taijutsu, vencedor->defesa);
            ninja_free(root->left->ninja);
            root->left->ninja = NULL;
            ninja_free(root->right->ninja);
            root->right->ninja = NULL;
        }
    }   
}

/**
@brief Gera um vetor randômico de 16 elemetos
\par
Gera um vetor randômico, de tamanho 16, com valores entre 0 e range-1(quantidade de linhas do arquivo lido-1),
que será utilizado para saber quais linhas do arquivo participarão do torneio. Se range for >=16, é garantido, que é possível criar o vetor,
e que todos seus termos são diferentes.
@param vet vetor para onde serão copiados os números aleatórios
@param range faixa de valores disponíveis (0 até range-1)
**/
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

/**
@brief Mostra ao usuário os ninjas(de acordo com a especificação do trabalho) e solicita a escolha de um
\par
Utilizando a funcção declarada em eds.h,  'print_list' printa os ninjas que disputarão o torneio, e utilizando a função 'buscar_ninjas',
busca o ninja escolhido pelo usuário. Retorna um ponteiro para o ninja escolhido.
@param list lista de onde será escolhido o ninja
**/
Ninja* escolherninja(t_lista* list){
    int a = 20;
    while(a<1 || a>16){
        system("clear");
        printf("Escolha seu personagem:\n\n");
        print_list(list);
        printf("\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &a);
    }
    return buscar_ninja(list, a-1);
}

/**
@brief Inicia o torneio em si
\par
Inicia o torneio, lendo os ninjas do arquivo, selecionando-os aleatóriamente (é gerado um vetor randômico de 16 elementos, cujos
valores dos elementos vão de 0 até a quantidade de linhas-1, e os valores dos elementos desse vetor randômico, são as linhas do arquivo que serão
selecionadas para competir), copiando-os para as folhas da árvore, pede ao usuário que escolha um dos ninjas e chama a função 'torneio' até que
o personagem escolhido perca, ou seja campeão. Utiliza duas listas duplamente encadeadas, uma auxliiar, que será utilizada para copiar os ninjas para as folhas da árvore,
e outra, que será utilizada para outras tarefas durante a execução do torneio.
**/
void start () {

    initglobal();
    
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
    system("clear");
    historico();
    printf("\nPressione ENTER para continuar: ");
    getchar();
    system("clear");

    list_free(list);
    tree_free(root);
}