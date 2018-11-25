/**
\mainpage Trabalho 2 - Exame Chunin (Árvore Binária)
Este trabalho objetiva, através da implementação de uma árvore binária e por meio do auxílio de uma lista duplamente encadeada,
a simulação de um torneio, o exame chunin, baseado no anime "Naruto". No trabalho, deve-se ler os ninjas participantes de um aquivo tipo texto,
que contém os nomes dos ninjas e suas características, escolhendo de forma aleatória, os 16 ninjas participantes do torneio dentre os contidos
no arquivo. Os ninjas escolhidos devem ser inseridos na lista, para depois, cada elemento da lista apontar para um folha da árvore binária
anteriormente criada, e o usuário deve escolher um entre os 16 ninjas.
\n As batalhas ocorrem entre ninjas contidos nos nós-filhos de um mesmo nó-pai, o vencedor da batalha sobe na aŕvore binária.
Quando  o ninja escolhido pelo usuário vai passar por uma batalha, o usuário pode escolher qual atributo será usado na batalha.
Caso contrário, se a batalha for entre máquina e máquina, o atributo utilizado é escolhido de forma randômica.
Vence o ninja que chegar ao topo da aŕvore.

-# <b>Intruções de Compilação:</b>
\n Utilizando o 'makefile' basta, dentro da pasta contendo os arquivos, fazer:
\n     \a make
\n E para executar:
\n     \a ./main
\n
\n Ou para cada arquivo de cada vez:
\n     \a gcc -g -c eds.c
\n     \a gcc -g -c exame.c
\n     \a gcc -g -o main main.c eds.o exame.o
\n E para executar:
\n     \a ./main
\n Versão do Compilador: gcc (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0

-# <b>Smoke Test:</b>
\n main.c:
\n     -Apresentação do Menu
\n      ARQUIVO - main.c
\n      AÇÃO - executar o programa e aguardar exibição do menu
\n      EXPECTATIVA - menu deve abrir e apresentar as opções (Iniciar e Sair)
\n
\n     -Navegação
\n      ARQUIVO - main.c
\n      AÇÃO - iniciar o torneio ao digitar 1 e pressionar ENTER, sair do programa ao digitar 2 e pressionar ENTER
\n      EXPECTATIVA - iniciar o torneio ou finalizar a execução do programa sem problemas
\n
\n     -Torneio
\n      ARQUIVO - main.c
\n      AÇÃO - abrir o programa e digitar 1 no menu, aguardar exibição dos personagens e escolher um deles
\n      EXPECTATIVA - exibir os personagens disponíveis para a escolha, com somente um atributo visível
\n
\n     -Batalhar
\n      ARQUIVO - main.c
\n      AÇÃO - iniciar o torneio e escolher o personagem desejado, aguardar exibição do próximo adversário,
\n      e a escolha do atributo que se deseja utilizar
\n      EXPECTATIVA - Exibir, inicialmente, o nome, o valor do 'Ninjutsu', do 'Genjutsu', do 'Taijutsu' e da 'Defesa',
\n      bem como se há ou não supremacia ou inferioridade elementar em relação ao próximo adversário. Além de exibir o nome do próximo adversário
\n
\n     -Vitória
\n      ARQUIVO - main.c
\n      AÇÃO - vencer uma batalha e aguardar
\n      EXPECTATIVA - Exibir mensagem de vitória e proceder para a próxima batalha, ou, caso a vitória tenha sido na final, uma mensagem de vitória
\n      de torneio será exibida, e o histórico de todas as batalhas será exibido
\n
\n     -Derrota
\n      ARQUIVO - main.c
\n      AÇÃO - vencer uma batalha e aguardar
\n      EXPECTATIVA - exibir mensagem de derrota, exibir histórico das batalhas até a etapa atual, e retornar ao menu, após o usuário pressionar ENTER
\n
\n     -Sair
\n      ARQUIVO - main.c
\n      AÇÃO - no menu, digitar 2, pressionar ENTER, e aguardar
\n      EXPECTATIVA - encerrar a execução do programa e limpar a tela
\n
**/


/**
@file main.c
@brief Arquivo raiz
\par
É responsável pelo início da execução do programa, exibe o menu principal, determinando uma nova seed para a função 'rand',
baseada no tempo atual.
**/
#include "eds.h"
#include "exame.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
@brief Exibe o menu principal
\par
Aguarda a entrada da opção desejada via 'scanf', podendo-se inicar o exame,
ou finalizar a execução do programa.
**/
void menu(){
    int a=0;
    while(a!=2){
        system("clear");
        printf("EXAME CHUNIN\n\n");
        printf("[1] - Iniciar Exame\n");
        printf("[2] - Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &a);
        if(a==1) start();
    }
    system("clear");
}

/**
@ brief Inicia a execução do programa, chamando o menu e gerando uma nova seed para a rand
**/
int main () {
    srand(time(0));
    menu();
    return 0;
}