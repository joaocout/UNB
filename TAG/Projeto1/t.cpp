#include <set>
#include <iostream>
#include <iterator>

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


int main() {

    set<int> a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);

    set<int> b;
    b.insert(2);
    b.insert(4);
    b.insert(6);

    cout << "INTERSECTION" << endl;
    set<int> i = simple_intersection(a, b);
    for(int e : i) cout << e << " ";
    cout << endl;

    cout << "UNION" << endl;
    set<int> u = simple_union(a, b);
    for(int e : u) cout << e << " ";
    cout << endl;

    cout << "DIFFERENCE" << endl;
    set<int> d = simple_difference(a, b);
    for(int e : d) cout << e << " ";
    cout << endl;
}