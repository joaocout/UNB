#include <bits/stdc++.h>
using namespace std;


int main () {
    int n, x;
    scanf("%d %d", &n, &x);
    int i, vet[n];

    for(i=0; i<n; i++)
        scanf("%d", &vet[i]);
    
    int max = -1;
    for(i=0; i<n; i++){
        if(vet[i] >= x){
            max = i+1;
        }
    }

    printf("%d\n", max);
    return 0;
}