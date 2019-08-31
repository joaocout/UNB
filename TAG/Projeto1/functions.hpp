/*
Nome : JOAO PEDRO ASSUNCAO COUTINHO
Matricula : 18/0019813

Este arquivo possui funcoes utilizadas no arquivo principal do programa,
funcoes de operacoes entre conjuntos, e uma funcao de busca linear em vetor.
*/

#ifndef __FUNCTIONS__H__
#define __FUNCTIONS__H__

#include <set>
#include <vector>

using namespace std;


//intersecao entre um set A e um B
//retorna um set resultante
set<int> simple_intersection (set<int> a, set<int> b);

//uniao entre um set A e um B
//retorna um set resultante
set<int> simple_union (set<int> a, set<int> b);

//diferenca entre um set A e um B
//retorna um set resultante
set<int> simple_difference (set<int> a, set<int> b);

//encontra um elemento x em um vector
//retorna true caso encontre, e false caso contrario
bool find_in_vector(int x, vector<int> a);

#endif