#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, t, c;
    scanf("%d %d %d", &n, &t, &c);
    int vet[n];
    int i;
    int resp=0, auxcont=0;
    for(i=0; i<n; i++){
        scanf("%d", &vet[i]);
    }
    for(i=0; i<n; i++){
        if(vet[i]<=t){
            auxcont++;
        }
        if(auxcont==c){
            resp++;
            auxcont=0;
            if(c>1 && c%2==1)
                i=i-2;
            else if(c%2==0 && c>1)
                i--;
        }
        if(vet[i]>t)
            auxcont=0;
    }
    
    printf("%d\n", resp);
    return 0;
}
