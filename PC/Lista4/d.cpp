#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int max (int a, int b){
    if(a>=b) return a;
    else return b;
}

int hmax[101][101];

void floyd(int n){

    for(int k=1; k<=n; k++){

        for(int i=1; i<=n; i++){

            if(k==i) continue;

            for(int j=1; j<=n; j++){

                if(i==j||j==k) continue;

                if(hmax[i][j] > max(hmax[i][k], hmax[k][j]))
                    hmax[i][j] = max(hmax[i][k], hmax[k][j]);
            }
        }
    }
}

void init(){
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            if(i!=j) hmax[i][j] = INF;
            else hmax[i][j] = 0;
        }
    }
}

int main () {
    int n, m;
    scanf("%d %d", &n, &m);

    init();

    for(int a=0; a<m; a++){
        int i, j, h;
        scanf("%d %d %d", &i, &j, &h);
        hmax[i][j] = h;
        hmax[j][i] = h;
    }

    floyd(n);

    int k;
    scanf("%d", &k);
    for(int a=0; a<k; a++){
        int i, j;
        scanf("%d %d", &i, &j);
        printf("%d\n", hmax[i][j]);
    }
    return 0;
}