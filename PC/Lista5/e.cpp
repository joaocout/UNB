#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int tab[1000001];

int dp(long long int x){
    
    if(tab[x]!=-1) return tab[x];
    if(x==0) return 1;
    if(x==1) return 0;

    tab[x] = ((x-1)%MOD * (dp(x-1)%MOD + dp(x-2)%MOD)%MOD)%MOD; 
    return tab[x];
}

int main () {
    memset(tab, -1, sizeof(tab));
    int n;
    cin >> n;
    cout << dp(n) << endl;
    return 0;
}