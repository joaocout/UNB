/**
@file funcoes.c
@brief Contém a implementação de funções de conversões entre tipos
\par
Contém funções de conversão utilizadas exaustivamente durante o trabalho,
uma função de conversão de 'string' para 'double' e outra de 'double' para 'string'.
**/

#include "funcoes.h"
#include <math.h>
#include <string.h>
/**
@brief Converte uma string para double
\par
Recebe uma string e retorna seu valor em double;
@param string string a ser convertida
**/
double stringtodouble(char* string){
	int comvirgula=0, posvirgula, negativo=0;
	if(string[0]=='-'){
		negativo = 1;
		string[0] = '0';	
	}
    
    if(string[0]=='+') string[0]='0';

	for(int i=0; i<strlen(string); i++){
		if(string[i]=='.' || string[i]==','){
			comvirgula=1;
			posvirgula=i;
		}
	}
    double a = 0;
	if(!comvirgula){
		for(int i=0; i<strlen(string); i++)
			a += (string[i]-'0') * pow(10, strlen(string)-i-1);		
	}
	else{
		for(int i=0; i<posvirgula; i++){
			double temp = string[i] - '0';
			a += temp * pow(10, posvirgula-1-i);
		}
		for(int i= posvirgula+1; i<strlen(string); i++){
			double temp = string[i] - '0';
			a += temp * pow(10, posvirgula-i);
		}
	}
	if(negativo) return -a;
	else return a;
}
/**
@brief Inverte uma string
\par
Recebe uma string e a inverte.
@param string string a ser invertida
**/
void inverter(char* string){
    for(int i=0, j=strlen(string)-1; i<j; i++, j--){
        char aux = string[i];
        string[i] = string[j];
        string[j] = aux;
    }
}

/**
@brief Converte um número para string
\par
Recebe o numero a ser convertido e a string onde será gravada a string resultado;
@param num número double que se deseja converter
@param string string onde se deseja gravar o resultado da conversão
**/
void doubletostring (double num, char* string){
    
    int negativo = 0;
    if(num<0){
        negativo=1;
        num = -num;
    }

    int inum = num;
    if(num==inum){ /*numero inteiro*/
        int i = 0;
        do{/*num gravado ao contrario*/
            string[i] = (inum%10) + '0';
            inum=inum/10;
            i++;
        }while(inum>=1);
        if(negativo) string[strlen(string)] = '-';
        inverter(string);
    }

    else{ /*numero quebrado*/
        int i=0;
        int posvirgula=negativo;
        do{/*descobrir posicao da virgula;*/
            inum=inum/10;
            posvirgula++;
        }while(inum>=1);

        int entrezeroeum = 0;
        if(num>0 && num<1) entrezeroeum=1;
        
        inum = num;
        
        int k = 0;
        while(num-inum>=0.00001 && k<4){
            num=num*10;
            inum=num;
            k++;
        }
        i=0;
        do{/*string gravada sem virgula*/
            string[i] = (inum%10) + '0';
            inum=inum/10;
            i++;
        }while(inum>=1);
        if(entrezeroeum) string[strlen(string)] = '0';
        if(negativo) string[strlen(string)] = '-';
        inverter(string);
        char aux = string[posvirgula];
        for(i=posvirgula; i<strlen(string)+1; i++){
            if(i==posvirgula){
                string[i] = ',';
            }
            else{
                char temp = string[i];
                string[i] = aux;
                aux = temp;
            }
        }
    }
}