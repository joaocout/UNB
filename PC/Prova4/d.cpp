#include <bits/stdc++.h>
using namespace std;

int tb[101][10001];

int main () {
    int n, k;
    cin >> n >> k;
    
    int d[n+1], p[n+1];
    for(int i=1; i<=n; i++){
        scanf("%d", &d[i]);
    }
    for(int i=1; i<=n; i++){
        scanf("%d", &p[i]);
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            
            if(p[i]<=j)
                tb[i][j] = max(tb[i-1][j], tb[i-1][j-p[i]]+d[i]);
            
            else tb[i][j] = tb[i-1][j];
        }
    }
    cout << tb[n][k] << endl;
    return 0;
}