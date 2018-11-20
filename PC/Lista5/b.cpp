#include <bits/stdc++.h>
using namespace std;

int tab[1000];
pair<int, int> itens[1000];
int n;

int min(int a, int b){
    if(a<=b) return a;
    else return b;
}

int dp(int w){
    if(w==0) return 0;
    if(tab[i]) return tab[i];
    
}

int main () {
    int w;
    cin >> w >> n;
    for(int i=0; i<n; i++)
        scanf("%d", &itens[i].first);
    for(int i=0; i<n; i++)
        scanf("%d", &itens[i].second);

    cout << dp(w) << endl;
    return 0;
}