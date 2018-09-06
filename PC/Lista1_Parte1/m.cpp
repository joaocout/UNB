#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    int ok=0;
    while(!ok){
        n++;
        string aux = to_string(n);
        int i, j, sair=0;
        for(i=0; i<aux.size()-1 && !sair; i++){
            for(j=i+1; j<aux.size() && !sair; j++){
                if(aux[i]==aux[j])
                    sair=1;
            }
        }
        if(!sair)
            ok=1;
    }
    printf("%d\n", n);
    return 0;
}