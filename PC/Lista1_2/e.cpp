#include <bits/stdc++.h>
using namespace std;

int comp(const void* a, const void* b){
    return ( *(int*)a - *(int*)b );
}

void scanvet(int* vet, int n){
    for(int i=0; i<n; i++)
        scanf("%d", &vet[i]);
}

void printvet(int* vet, int n){
    for(int i=0; i<n; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

int main () {
    int n, k1, k2;
    scanf("%d %d %d", &n, &k1, &k2);

    int a[n], b[n];
    int i;
    scanvet(a, n);
    scanvet(b, n);
    
    int difab[n];
    for(i=0; i<n; i++)
        difab[i] = abs(a[i] - b[i]);
    
    int k;
    k = k1 + k2;
    while(k){
        qsort(difab, n, sizeof(int), comp);
        difab[n-1] --;
        k--;
    }
    
    long long soma = 0;
    for(i=0; i<n; i++)
        soma+= pow(difab[i], 2);
    printf("%lld\n", soma);

    return 0;
}