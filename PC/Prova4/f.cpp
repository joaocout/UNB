#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main () {
    int n;
    cin >> n;
    
    long long int f[n+1];

    for(int i=0; i<=n; i++){
        if(i==0) f[i] = 0;
        else if(i==1) f[i] = 1;
        else if(i==2) f[i] = 0;
        else f[i] = ((f[i-1])%MOD + (f[i-2])%MOD)%MOD;
    }
    printf("%lld\n", f[n]);
    return 0;
}