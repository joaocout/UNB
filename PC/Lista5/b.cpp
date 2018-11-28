#include <bits/stdc++.h>
using namespace std;

int tab[1001][1001];

int main () {

    int w, n;
    cin >> w >> n;
    
    int peso[n];
    int valor[n];

    for(int i=0; i<n; i++) scanf("%d", &peso[i]);
    for(int i=0; i<n; i++) scanf("%d", &valor[i]);

    for(int i=1; i<=n; i++){

        for(int j=1; j<=w; j++){

            if(peso[i-1]<=j){
                tab[i][j] = max(tab[i-1][j], tab[i-1][j-peso[i-1]]+valor[i-1]);
            }

            else tab[i][j] = tab[i-1][j];
        }
    }

    cout << tab[n][w] << endl;

    return 0;
}
