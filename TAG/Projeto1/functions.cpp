/*
Nome : JOAO PEDRO ASSUNCAO COUTINHO
Matricula : 18/0019813

Este arquivo possui as implementacoes das funcoes declaradas em functions.hpp.
*/

#include "functions.hpp"
#include <set>
#include <vector>

using namespace std;


set<int> simple_intersection (set<int> a, set<int> b){
    set<int> result;
    for(int e : a){
        if(b.count(e))  //se ha um elemento de A em B
            result.insert(e);   //esse elemento deve ser inserido no resultado
    }
    return result;
}

set<int> simple_union (set<int> a, set<int> b){
    set<int> result;
    for(int e : a)
        result.insert(e);
    for(int e : b)
        result.insert(e);
    return result;          // resultado eh a uniao dos dois conjuntos
}

set<int> simple_difference (set<int> a, set<int> b){        //a \ b
    set<int> result;
    for(int e : a){
        if(!b.count(e))         //pegamos todos de A que nao estado em B
            result.insert(e);
    }
    return result;
}

bool find_in_vector(int x, vector<int> a){
    for(long unsigned int i = 0; i<a.size(); i++){
        if(a[i] == x) return true;
    }
    return false;
}