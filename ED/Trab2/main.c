#include "eds.h"
#include "exame.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void menu(){
    int a=0;
    while(a!=1 && a!=2){
        system("clear");
        printf("EXAME CHUNIN\n\n");
        printf("[1] - Iniciar Exame\n");
        printf("[2] - Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &a);
    }
    if(a==1) start();
    else if(a==2) system("clear");
}

int main () {
    srand(time(0));
    menu();
    return 0;
}