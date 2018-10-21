/**
@file funcoes.h
@brief Contém os headers/declaração das funcões implementadas no arquivo funcoes.c
\par
Contém funcoes de conversão entre tipos, muito utilizadas no trabalho
**/


#ifndef _FUNCOES_H_
#define _FUNCOES_H_

/*funcoes utilizadas no trabalho*/


/*recebe uma string e a transforma em um numero ponto flutante de precisao dupla*/
double stringtodouble(char* string);


/*recebe um numero em ponto flutuante e uma string onde sera salva
a transformacao desse numero para string*/
void doubletostring(double num, char* string);

#endif
