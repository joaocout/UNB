#include <bits/stdc++.h>
using namespace std;

int tab[1001][1001];

int main () {

    int w, n;
    cin >> w >> n;
    
    int peso[n+1];
    int valor[n+1];

    for(int i=1; i<n+1; i++) scanf("%d", &peso[i]);
    for(int i=1; i<n+1; i++) scanf("%d", &valor[i]);

    for(int i=1; i<=n; i++){

        for(int j=1; j<=w; j++){

            if(peso[i]<=j){
                tab[i][j] = max(tab[i-1][j], tab[i-1][j-peso[i]]+valor[i]);
            }

            else tab[i][j] = tab[i-1][j];
        }
    }

    for(int i=0; i<n+1; i++){
        for(int j=0; j<w+1; j++){
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
    cout << tab[n][w] << endl;

    return 0;
}
