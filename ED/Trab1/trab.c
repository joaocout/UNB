/**
\mainpage Trabalho 1 - Calculadora & Avaliação de Expressões Aritméticas
Este trabalho objetiva a realização de uma calculadora, e de um conversor de expressões numéricas na forma infixa para a forma posfixa,
incluindo sua validação e o cálculo de seu resultado, caso seja possível. Tudo utilizando implementado através do uso de pilhas.
-# Modo Calculadora:
\n A calculadora funciona da seguinte forma:
\n Se um número é digitado, o mesmo é empilhado em uma pilha designada para a calculadora;
\n Se uma operação é digitada, a mesma é realizada entre os dois últimos números digitados, o topo e seu anterior, e o resultado é empilhado novamente.
-# Modo Resolução de Expressões:
\n Esse modo opera da seguinte forma:
\n Uma expressão na forma infixa é recebida;
\n Se a mesma for válida, a sua forma posfixa é mostrada;
\n Se for possível, um resultado para a mesma é mostrado na tela;
\n Utilizando pilhas tanto para a geração da forma posfixa, tanto para o cálculo do resultado.
**/

/**
@file trab.c
@brief Arquivo raiz do trabalho
\par
É responsável por toda a parte gráfica do programa, como printar menus, printar resultados e solicitar a emtrada de dados ao user,
além de ser responsável por chamar os dois modos possiveis: 
o modo calculadora e o modo resolução de expressões.
**/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "pilha.h"

/*evitar warning por declaracao implicita de funcao*/
void menu();
void calculadora();
void expressao();



/**
@brief Inicia a execução do modo calculadora
\par
Cria uma pilha e aguarda a entrada de dados via 'scanf';
\n Caso seja um operando o mesmo é empilhado;
\n Caso seja um operador, os operandos são desempilhados, a operação realizada, e o resultado empilhado novamente;
\n Quando o usuário digita 'sair', a funcão retorna ao menu principal.
**/
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



/**
@brief Inicia a execução do modo resolução de expressão
\par
O programa aguarda a entrada de uma expressão na forma infixa via 'scanf';
\n Primeiramente, cria-se uma pilha para a validação da expressão, sendo que essa pilha é removida ao final do processo;
\n Caso a expressão seja válida, inicia-se a geração da expressão posfixa, utilizando uma pilha para armazenar os operadores;
\n Ao final, é exibido se a expressão é válida, sua forma posfixa(caso possível), e seu resultado(caso possível);
\n Caso o usuário entre com 'sair', a funcão retorna ao menu principal. 
**/

void expressao(){

    int valida=2;
    int sair = 0;

    char a[150] = "\0";
    char pos[150] = "\0";

    int comnumeros=0;
    double result=0;

    while(!sair){
        system("clear");
        printf("MODO RESOLUÇÃO DE EXPRESSÃO\n");
        printf("Digite 'sair' para retornar ao menu\n\n");
        if(valida==0) printf("----Expressão inválida----\n\n");
        else if(valida==1){
            printf("----Expressão válida----\n");
            printf("Forma posfixa: %s\n", pos);
            if(comnumeros){
                printf("Resultado: %.3lf\n", result);
                comnumeros=0;
            }
            printf("\n");
        }
        
        for(int i=0; i<100; i++) pos[i] = '\0';

        valida=1;
        printf("Informe uma expressão na forma infixa:\n");
        printf("-> ");
        scanf(" %[^\n]", a);
        if(!strcmp("sair", a)) sair = 1;
        else{
            /*validando a expressao*/
            valida=0;

            /*ha algum numero ou icognita?*/
            for(int i=0; i<strlen(a) && !valida; i++){
                if((a[i]>='0' && a[i]<='9')||(a[i]>='a' && a[i]<='z')||(a[i]>='A' && a[i]<='Z')) valida=1;
            }

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
                    else if(a[i]==']'){
                        if(!strcmp("[", validar->topo->dados)) desempilha(validar);
                        else valida=0;
                    }
                    else if(a[i]=='}'){
                        if(!strcmp("{", validar->topo->dados)) desempilha(validar);
                        else valida=0;
                    }
                }
            }
            if(validar->quantidade > 0) valida=0;
            remove_pilha(validar);
        }
        if(valida==1 && !sair){
            /*convertendo para posfixa*/
            tipo_pilha* posfixa = aloca_pilha();
            int k=0;

            comnumeros=1;
            for(int i=0; i<strlen(a); i++){
                if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z')) comnumeros=0;
            }


            for(int i=0; i<strlen(a); i++){
                if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z' ) || (a[i]>='0' && a[i]<='9') || a[i]=='.' || a[i]==','){
                    pos[k] = a[i];
                    k++;
                    while((a[i+1]>='a' && a[i+1]<='z') || (a[i+1]>='A' && a[i+1]<='Z' ) || (a[i+1]>='0' && a[i+1]<='9') || a[i+1]=='.' || a[i+1]==','){
                        i++;
                        pos[k] = a[i];
                        k++;
                    }
                    pos[k] = ' ';
                    k++;
                }
                else if(a[i]=='+' || a[i]=='-'){
                    while(posfixa->quantidade>0 && 
                    (!strcmp("+", posfixa->topo->dados) || !strcmp("-", posfixa->topo->dados) ||
                    !strcmp("*", posfixa->topo->dados) || !strcmp("/", posfixa->topo->dados))){
                        pos[k] = posfixa->topo->dados[0];
                        k++;
                        pos[k] = ' ';
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
                        pos[k] = ' ';
                        k++;
                        desempilha(posfixa);
                    }
                    char aux[2];
                    aux[0] = a[i];
                    aux[1] = '\0';
                    empilha(posfixa, aux);
                }
                else if(a[i]=='(' || a[i]=='[' || a[i]=='{'){
                    char aux[2];
                    aux[0]=a[i];
                    aux[1]='\0';
                    empilha(posfixa, aux);
                }
                else if(a[i]==')'){
                    while(strcmp("(", posfixa->topo->dados)!=0){
                        pos[k] = posfixa->topo->dados[0];
                        k++;
                        pos[k] = ' ';
                        k++;
                        desempilha(posfixa);
                    }
                    desempilha(posfixa);
                }
                else if(a[i]==']'){
                    while(strcmp("[", posfixa->topo->dados)!=0){
                        pos[k] = posfixa->topo->dados[0];
                        k++;
                        pos[k] = ' ';
                        k++;
                        desempilha(posfixa);
                    }
                    desempilha(posfixa);
                }
                else if(a[i]=='}'){
                    while(strcmp("{", posfixa->topo->dados)!=0){
                        pos[k] = posfixa->topo->dados[0];
                        k++;
                        pos[k] = ' ';
                        k++;
                        desempilha(posfixa);
                    }
                    desempilha(posfixa);
                }
            }
            while(posfixa->quantidade){
                pos[k] = posfixa->topo->dados[0];
                k++;
                pos[k] = ' ';
                k++;
                desempilha(posfixa);
            }
            remove_pilha(posfixa);
        }
        if(comnumeros){
            /*caso seja uma expressao numerica, calculando o resultado*/
            tipo_pilha* resultado = aloca_pilha();
            for(int i=0; i<strlen(pos); i++){
                if((pos[i]>='0' && pos[i]<='9')  ||  pos[i]==','  || pos[i]=='.'){
                    char aux[100] = "\0";
                    int k=0;
                    aux[k] = pos[i];
                    k++;
                    while((pos[i+1]>='0' && pos[i+1]<='9')  ||  pos[i+1]==','  || pos[i+1]=='.'){
                        i++;
                        aux[k] = pos[i];
                        k++;
                    }
                    empilha(resultado, aux);
                }
                else if(pos[i]=='+' || pos[i]=='-' || pos[i]=='/' || pos[i]=='*'){
                    double y = stringtodouble(resultado->topo->dados);
                    desempilha(resultado);
                    double x = stringtodouble(resultado->topo->dados);
                    desempilha(resultado);
                    double z = 0;
                    if(pos[i]=='+') z = x+y;
                    else if(pos[i]=='-') z = x-y;
                    else if(pos[i]=='*') z = x*y;
                    else if(pos[i]=='/') z = x/y;
                    char auxx[100] = "\0";
                    doubletostring(z, auxx);
                    empilha(resultado, auxx);
                }
            }
            result = stringtodouble(resultado->topo->dados);
            remove_pilha(resultado);
        }
    }
    menu(); 
}



/**
@brief Mostra o menu principal
\par
São exibidos os modos de operação ao usuário, e aguarda-se a entrada de dados;
\n '1' para o modo calculadora;
\n '2' para o modo resolução de expressões;
\n '3' para encerrar a execução do programa.
**/
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



/**
@brief Inicia a execução do programa simplesmente chamando a função menu 
**/
int main (){
    menu();
    return 0;
}