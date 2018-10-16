#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "pilha.h"

/*evitar warning por declaracao implicita de funcao*/
void menu();
void calculadora();
void expressao();


void calculadora(){
    int exit = 0;
    char a[100];
    int erro = 0;
    tipo_pilha* pilha = aloca_pilha();
    while(!exit){
        
        system("clear");
        printf("MODO CALCULADORA\n");
        printf("Digite 'exit' para retornar ao menu\n");
        if(erro){
            printf("----Número de operandos insuficiente----\n\n");
            erro=0;
        }
        if(pilha->quantidade==0) printf("Pilha Vazia\n");
        else print_pilha(pilha);
        
        printf("-> ");
        scanf("%s", a);
        
        if(strcmp("exit", a)==0) exit=1;

        else if(strcmp("+", a)==0 && pilha->quantidade>=2){
            double x = stringtodouble(pilha->topo->dados);
            desempilha(pilha);
            double y = stringtodouble(pilha->topo->dados);
            desempilha(pilha);
            double result = x+y;
            char aux[100] = "\0";
            doubletostring(result, aux);
            empilha(pilha, aux);
        }
        else if(strcmp("-", a)==0 && pilha->quantidade>=2){
            double x = stringtodouble(pilha->topo->dados);
            desempilha(pilha);
            double y = stringtodouble(pilha->topo->dados);
            desempilha(pilha);
            double result = x-y;
            char aux[100] = "\0";
            doubletostring(result, aux);
            empilha(pilha, aux);
        }
        else if(strcmp("*", a)==0 && pilha->quantidade>=2){
            double x = stringtodouble(pilha->topo->dados);
            desempilha(pilha);
            double y = stringtodouble(pilha->topo->dados);
            desempilha(pilha);
            double result = x*y;
            char aux[100] = "\0";
            doubletostring(result, aux);
            empilha(pilha, aux);
        }
        else if(strcmp("/", a)==0 && pilha->quantidade>=2){
            double x = stringtodouble(pilha->topo->dados);
            desempilha(pilha);
            double y = stringtodouble(pilha->topo->dados);
            desempilha(pilha);
            double result = x/y;
            char aux[100] = "\0";
            doubletostring(result, aux);
            empilha(pilha, aux);
        }
        else if((a[0]=='/'||a[0]=='*'||a[0]=='-'||a[0]=='+') && pilha->quantidade<2) erro = 1;
        else empilha(pilha, a);
    }
    if(exit==1){
        remove_pilha(pilha);
        menu();
    }
}
void expressao(){
    system("clear");
}

void menu() {
    int a = 4;
    int invalido = 0;
    while(a!=1 && a!=2 && a!=3){
        system("clear");
        printf("[1] - Modo Calculadora\n");
        printf("[2] - Modo Expressão\n");
        printf("[3] - Sair\n");
        if(invalido) printf("\n----Opção inválida----\n");
        printf("\n");
        printf("Escolha uma opção: ");
        scanf("%d", &a);
        if(a!=1 && a!=2 && a!=3) invalido=1;
    }
    if(a==1) calculadora();
    else if(a==2) expressao();
    else if(a==3) system("clear");
}

int main (){
    menu();
    return 0;
}