#include <bits/stdc++.h>
using namespace std;

void scanvet(int* vet, int n){
    int i;
    for(i=0; i<n; i++)
        scanf("%d", &vet[i]);
}

int main () {
    int n;
    scanf("%d", &n);
    int vet[n];
    scanvet(vet, n);
    int i;
    int max;
    for(i=0; i<n-1; i++){
        if(i==0)
            max = abs(vet[i] - vet[i+1]);
        else{
            if(abs(vet[i] - vet[i+1]) > max)
            max = abs(vet[i] - vet[i+1]);
        }
    }
    printf("%d\n", max);
    return 0;
}