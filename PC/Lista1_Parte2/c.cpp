#include <bits/stdc++.h>
using namespace std;

int main  () {
    int n;
    set<int>erros[3];
    scanf("%d", &n);

    for(i=0; i<3; i++){
        for(j=0; j<n-i; j++){
            int aux;
            scanf("%d", &aux);
            erros[i].insert(aux);
        }
    }
    for


    return 0;
}