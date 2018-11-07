#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define INF 1e9

int d[101][101];

void initd(){
    for(int i=1; i<=100; i++)
        for(int j=1; j<=100; j++){
            if(i==j) d[i][j] = 0;
            else d[i][j] = 0;
        }
}

void floydwarshall(int n){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            if(i!=k){
                for(int j=1; j<=n; j++){
                    if(j!=i && j!=k){
                        if(d[i][j] < d[i][k] + d[k][j]){
                            d[i][j] = d[i][k] + d[k][j];
                        }
                    }
                }
            }
        }
    }
}

int main () {

    initd();

    int n, m;
    cin >> n >> m;

    for(int a=0; a<m; a++){
        int i, j, h;
        scanf("%d %d %d", &i, &j, &h);
        d[i][j] = h;
        d[j][i] = h;
    }
    floydwarshall(n);
    int k;
    cin >> k;
    for(int a=0; a<k; a++){
        int i, j;
        scanf("%d %d", &i, &j);
        printf("%d\n", d[i][j]);
    }
    return 0;
}