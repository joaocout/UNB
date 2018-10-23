#include <bits/stdc++.h>
using namespace std;

int dist[1000001];
vector <vector <int>> graph(1000001);
int visited[1000001];

void bfs(int start){
	
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	visited[start] = 1;

	while(q.size()){
		int u = q.front();
		q.pop();
		for(int w: graph[u]){
			if(!visited[w]){
				q.push(w);
				visited[w] = 1;
			}
			if(dist[u]+1 < dist[w]) dist[w] = dist[u] + 1;
		}
	}

}

int main () {

	for(int i=0; i<100000; i++) dist[i] = 1000000000;

	int n, m, k, q;
	scanf("%d %d", &n, &m);
	scanf("%d %d", &k, &q);

	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	bfs(k);

	for(int i=0; i<q; i++){
		int x;
		scanf("%d", &x);
		if(dist[x]==1000000000) printf("infinito\n");
		else printf("%d\n", dist[x]);
	}
	return 0;
}