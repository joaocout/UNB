#include <bits/stdc++.h>
using namespace std;
#define INF 1e9


int dist[100][100];

void init () {
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++){
			if(i==j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
}

void floyd(int n){

    for(int k=0; k<n; k++){

        for(int i=0; i<n; i++){

            if(k==i) continue;

            for(int j=0; j<n; j++){

                if(i==j||j==k) continue;

                if(dist[i][j] > dist[i][k]+dist[k][j])
                	dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }
}

int main () {
	
	init();
	
	int n, m;
	cin >> n >> m;

	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		dist[a][b]=1;
	}
	floyd(n);
	
	double soma = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			soma+=dist[i][j];
		}
	}
	double resp = soma/(n*(n-1));
	printf("%.8lf\n", resp);
	return 0;
}