#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int tb[1000000];

int dp(long long int x){
    if(x==0) return 0;
    if(x==1) return 1;
    if(x==2) return 1;
    if(tb[x]!=-1) return tb[x];

    tb[x] = (dp(x-1)%MOD + ((dp(x-2))%MOD + (dp(x-3))%MOD)%MOD)%MOD;
    return tb[x];
}

int main () {
    memset(tb, -1, sizeof(tb));
    int n;
    cin >> n;
    cout << dp(n) << endl;
    return 0;
}