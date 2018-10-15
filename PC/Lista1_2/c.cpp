#include <bits/stdc++.h>
using namespace std;
int soma[3];


int main  () {
    int n;
    scanf("%d", &n);
    int vet[n];
    int i;
    int k = 0, x;
    for(i=0; i<n; i++){
        scanf("%d", &x);
        soma[k] += x;
    }
    k++;
    for(i=0; i<n-1; i++){
        scanf("%d", &x);
        soma[k] += x;
    }
    k++;
    for(i=0; i<n-2; i++){
        scanf("%d", &x);
        soma[k] += x;
    }
    printf("%d\n", soma[0]-soma[1]);
    printf("%d\n", soma[1]-soma[2]);
    return 0;
}