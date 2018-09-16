#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int x[n], y[n], z[n];
    int somax=0, somay=0, somaz=0;
    
    int i;
    for(i=0; i<n; i++){
        scanf("%d %d %d", &x[i], &y[i], &z[i]);
        somax += x[i];
        somay += y[i];
        somaz += z[i];
    }
    int a = somax + somay + somaz;
    if(a == 0) printf("YES\n");
    else printf("NO\n");
    return 0;
}
