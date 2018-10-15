#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    int vet[n];

    int i;
    for(i=0; i<n; i++){
        scanf("%d", &vet[i]);
    }
    int max=0;
    for(i=0; i<n; i++){
        if(vet[i]>max)
            max = vet[i];
    }
    int grana=0;
    for(i=0; i<n; i++){
        grana+= max-vet[i];
    }
    printf("%d\n", grana);
    return 0;
}