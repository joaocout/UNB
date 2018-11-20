#include <iostream>
using namespace std;

int tab[1000];
int moedas[1000];
int n;

int min(int a, int b){
    if(a<=b) return a;
    else return b;
}

int dp(int x){
    if(x==0) return 0;
    if(tab[x]) return tab[x];
    
    int melhor = 1e9;
    for(int i=0; i<n; i++){
        if(moedas[i]<=x)
            melhor = min(melhor, 1+dp(x-moedas[i]));
    }
    return tab[x] = melhor; 
}

int main () {
    int x;
    cin >> n >> x;
    for(int i=0; i<n; i++)
        scanf("%d", &moedas[i]);
    cout << dp(x) << endl;
    return 0;
}