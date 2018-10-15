#include <bits/stdc++.h>
using namespace std;

void scanvet(int* vet, int n){
    int i;
    for(i=0; i<n; i++)
        scanf("%d", &vet[i]);
}

int deivis(int* a, int* b, int n, int x){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(a[i]+b[j] == x)
                return 1;
        }
    }
    return 0;
}

int main () {
    int n, x;
    scanf("%d %d", &n, &x);
    int a[n], b[n];
    scanvet(a, n);
    scanvet(b, n);
    printf("%d\n", deivis(a, b, n, x));
    return 0;
}