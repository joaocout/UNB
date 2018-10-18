#include <bits/stdc++.h>
using namespace std;
vector<int> ratos;
vector<int> visited (1000000, 0);

void dfs(int x, vector<vector<int>> graph){
	visited[x] = 1;
	for()
}

int main () {
	int n, m;
	cin >> n >> m;
	char mapa[n][m];
	for(int i=0; i<n; i++)
		cin >> mapa[i];
	
	vector<vector<int>> graph(n*m);
	int tom;
	vector<int> ratos;
	for(int i=0; i<n; i++){
		
		for(int j=0; j<m; j++){

			int a = mapa[i][j];
				
			if(mapa[i][j]=='*') tom = (i*m)+j;

			else if(a>=97 && a<=122) ratos.push_back((i*m)+j);

			if(mapa[i][j]!='#'){

				if(i!=0 && mapa[i-1][j]!='#') graph[(i*m)+j].push_back(((i-1)*m)+j);
			
				if(i!=n-1 && mapa[i+1][j]!= '#') graph[(i*m)+j].push_back(((i+1)*m)+j);
			
				if(j!=0 && mapa[i][j-1]!='#') graph[(i*m)+j].push_back((i*m)+j-1);
			
				if(j!=m-1 && mapa[i][j+1]!='#') graph[(i*m)+j].push_back((i*m)+j+1);
			}
		}
	}

	return 0;

}