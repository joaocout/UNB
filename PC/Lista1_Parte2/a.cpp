#include <bits/stdc++.h>
using namespace std;


int main () {
    int n, k;

    scanf("%d %d", &n, &k);
    stack <int> estacionamento;
    
    int i;
    int in, out;
    int ok = 1;

    for(i=0; i<n; i++){
        scanf("%d %d", &in, &out);
        if(estacionamento.empty()){
            estacionamento.push(out);
        }
        else if(in < estacionamento.top() && out < estacionamento.top()){
            estacionamento.push(out);
        }
        else if(in >= estacionamento.top()){
            estacionamento.pop();
            while(in >= estacionamento.top()){
                estacionamento.pop();
            }
            if(!estacionamento.empty()){
                if()
            }
            estacionamento.push(out);
        }

    }
    if(ok) printf("Sim\n");
    else printf("Nao\n");
    return 0;
}