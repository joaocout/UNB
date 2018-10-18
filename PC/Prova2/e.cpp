#include <bits/stdc++.h>
using namespace std;

int n, m;
char mapa[1000][1000];
int visited[1000000];
vector< vector<int> > graph(1000000);

int bfs(int start){
	
	queue< pair<int,int> > q;
	q.push( make_pair(start, 0) );
	visited[start]=1;

	while(q.size()){
		pair<int, int> u = q.front();
		q.pop();
		for(int w: graph[u.first]){
			if(!visited[w]){
				q.push( make_pair(w, u.second + 1) );
				visited[w] = 1;
				if(mapa[w/m][w%m]>='a'&& mapa[w/m][w%m]<='z')
					return u.second + 1;
			}
		}
	}
	return -1;

}

int main () {
	
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> mapa[i];
	
	int tom;
	for(int i=0; i<n; i++){
		
		for(int j=0; j<m; j++){
		
			if(mapa[i][j]=='*') tom = (i*m)+j;

			if(mapa[i][j]!='#'){

				if(i!=0 && mapa[i-1][j]!='#') graph[(i*m)+j].push_back(((i-1)*m)+j);
			
				if(i!=n-1 && mapa[i+1][j]!= '#') graph[(i*m)+j].push_back(((i+1)*m)+j);
			
				if(j!=0 && mapa[i][j-1]!='#') graph[(i*m)+j].push_back((i*m)+j-1);
			
				if(j!=m-1 && mapa[i][j+1]!='#') graph[(i*m)+j].push_back((i*m)+j+1);
			}
		}
	}
	printf("%d\n", bfs(tom));

	return 0;

}