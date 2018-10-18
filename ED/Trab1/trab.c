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
    int sair = 0;
    char a[100];
    int erro = 0;
    tipo_pilha* pilha = aloca_pilha();
    while(!sair){
        
        system("clear");
        printf("MODO CALCULADORA\n");
        printf("Digite 'sair' para retornar ao menu\n\n");
        if(erro){
            printf("----Número de operandos insuficiente----\n\n");
            erro=0;
        }
        if(pilha->quantidade==0) printf("Pilha Vazia\n");
        else print_pilha(pilha);
        
        printf("-> ");
        scanf(" %s", a);
        
        if(strcmp("sair", a)==0) sair=1;

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
        else if(strcmp("+!", a)==0 && pilha->quantidade>=2){
            while(pilha->quantidade > 1){
                double x = stringtodouble(pilha->topo->dados);
                desempilha(pilha);
                double y = stringtodouble(pilha->topo->dados);
                desempilha(pilha);
                double result = x+y;
                char aux[100] = "\0";
                doubletostring(result, aux);
                empilha(pilha, aux);
            }
        }
        else if(strcmp("-!", a)==0 && pilha->quantidade>=2){
            while(pilha->quantidade > 1){
                double x = stringtodouble(pilha->topo->dados);
                desempilha(pilha);
                double y = stringtodouble(pilha->topo->dados);
                desempilha(pilha);
                double result = x-y;
                char aux[100] = "\0";
                doubletostring(result, aux);
                empilha(pilha, aux);
            }
        }
        else if(strcmp("*!", a)==0 && pilha->quantidade>=2){
            while(pilha->quantidade > 1){
                double x = stringtodouble(pilha->topo->dados);
                desempilha(pilha);
                double y = stringtodouble(pilha->topo->dados);
                desempilha(pilha);
                double result = x*y;
                char aux[100] = "\0";
                doubletostring(result, aux);
                empilha(pilha, aux);
            }
        }
        else if(strcmp("/!", a)==0 && pilha->quantidade>=2){
            while(pilha->quantidade > 1){
                double x = stringtodouble(pilha->topo->dados);
                desempilha(pilha);
                double y = stringtodouble(pilha->topo->dados);
                desempilha(pilha);
                double result = x/y;
                char aux[100] = "\0";
                doubletostring(result, aux);
                empilha(pilha, aux);
            }
        }
        else if(strcmp("c", a)==0 && pilha->quantidade>=2){
            int i = stringtodouble(pilha->topo->dados);
            desempilha(pilha);
            char aux[100] = "\0";
            strcpy(aux, pilha->topo->dados);
            desempilha(pilha);
            while(i){
                empilha(pilha, aux);
                i--;
            }
        }
        else if((!strcmp("+", a) || !strcmp("-", a) || !strcmp("*", a) || !strcmp("/", a) || !strcmp("c", a)) && pilha->quantidade < 2) erro = 1;
        else if((!strcmp("+!", a) || !strcmp("-!", a) || !strcmp("*!", a) || !strcmp("/!", a)) && pilha->quantidade < 2) erro = 1;        
        else empilha(pilha, a);
    }
    if(sair==1){
        remove_pilha(pilha);
        menu();
    }
}

void expressao(){

    int valida=2;
    int sair = 0;
    char a[100] = "\0";
    char pos[100] = "\0";

    while(!sair){
        system("clear");
        printf("MODO RESOLUÇÃO DE EXPRESSÃO\n");
        printf("Digite 'sair' para retornar ao menu\n\n");
        if(valida==0) printf("----Expressão inválida----\n\n");
        else if(valida==1){
            printf("----Expressão válida----\n");
            printf("Forma posfixa: %s\n\n", pos);    
        }
        
        for(int i=0; i<100; i++) pos[i] = '\0';

        valida=1;
        printf("Informe uma expressão na forma infixa:\n");
        printf("-> ");
        scanf(" %[^\n]", a);
        if(!strcmp("sair", a)) sair = 1;
        else{
            tipo_pilha* validar = aloca_pilha();
            for(int i=0; i<strlen(a) && valida; i++){
                if(a[i]=='(' || a[i]=='[' || a[i]=='{'){
                    char aux[2] = "\0";
                    aux[0] = a[i];
                    aux[1] = '\0';
                    empilha(validar, aux);
                }
                else if(a[i]==')' || a[i]==']' || a[i]=='}'){
                    if(validar->quantidade==0) valida=0;
                    else if(a[i]==')'){
                        if(!strcmp("(", validar->topo->dados)) desempilha(validar);
                        else valida=0;
                    }
                    else if(a[i]=='['){
                        if(!strcmp("]", validar->topo->dados)) desempilha(validar);
                        else valida=0;
                    }
                    else if(a[i]=='{'){
                        if(!strcmp("}", validar->topo->dados)) desempilha(validar);
                        else valida=0;
                    }
                }
            }
            if(validar->quantidade > 0) valida=0;
            remove_pilha(validar);
        }
        if(valida==1){
            tipo_pilha* posfixa = aloca_pilha();
            int k=0;
            for(int i=0; i<strlen(a); i++){
                if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z')){
                    pos[k] = a[i];
                    k++;
                }
                else if(a[i]=='+' || a[i]=='-'){
                    while(posfixa->quantidade>0 && 
                    (!strcmp("+", posfixa->topo->dados) || !strcmp("-", posfixa->topo->dados) ||
                    !strcmp("*", posfixa->topo->dados) || !strcmp("/", posfixa->topo->dados))){
                        pos[k] = posfixa->topo->dados[0];
                        k++;
                        desempilha(posfixa);
                    }
                    char aux[2];
                    aux[0] = a[i];
                    aux[1] = '\0';
                    empilha(posfixa, aux);
                }
                else if(a[i]=='*' || a[i]=='/'){
                    while(posfixa->quantidade>0 && 
                    (!strcmp("*", posfixa->topo->dados) || !strcmp("/", posfixa->topo->dados))){
                        pos[k] = posfixa->topo->dados[0];
                        k++;
                        desempilha(posfixa);
                    }
                    char aux[2];
                    aux[0] = a[i];
                    aux[1] = '\0';
                    empilha(posfixa, aux);
                }
                else if(a[i]=='('){
                    char aux[2];
                    aux[0]=a[i];
                    aux[1]='\0';
                    empilha(posfixa, aux);
                }
                else if(a[i]==')'){
                    while(strcmp("(", posfixa->topo->dados)!=0){
                        pos[k] = posfixa->topo->dados[0];
                        k++;
                        desempilha(posfixa);
                    }
                    desempilha(posfixa);
                }
            }
            while(posfixa->quantidade){
                pos[k] = posfixa->topo->dados[0];
                k++;
                desempilha(posfixa);
            }
            remove_pilha(posfixa);
        }
    }
    menu(); 
}

void menu() {
    int a = 4;
    int invalido = 0;
    while(a!=1 && a!=2 && a!=3){
        system("clear");
        printf("[1] - Modo Calculadora\n");
        printf("[2] - Modo Resolução de Expressão\n");
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