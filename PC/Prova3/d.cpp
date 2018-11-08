#include <bits/stdc++.h>
using namespace std;

#define pii pair<long long, int>
#define INF 1e18

vector<vector<pii>> graph(100);

long long tempo[100];

void init (){
	for(int i=0; i<100; i++) tempo[i] = INF;
}

void dijkstra(int start){
	
	init();

	tempo[start] = 0;
	
	priority_queue <pii, vector<pii>, greater<pii>> pq;
	pq.emplace(tempo[start], start);

	while(pq.size()){
		
		int u = pq.top().second;
		pq.pop();

		for(auto edge: graph[u]){
			int v, w;
			tie(v, w) = edge;
			if(tempo[v] > tempo[u] + w){
				tempo[v] = tempo[u] + w;
				pq.emplace(tempo[v], v);
			}
		}
	}
}



int main () {

	int n, m;
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].emplace_back(b, 1);
		graph[b].emplace_back(a, 1);
	}
	
	int s, t;
	cin >> s >> t;
	
	dijkstra(s);
	long long result[n];
	for(int i=0; i<n; i++) result[i] = tempo[i];
	dijkstra(t);
	for(int i=0; i<n; i++) result[i] += tempo[i];

	long long max = 0;
	for(int i=0; i<n; i++)
		if(result[i]>max)
			max=result[i];
	cout << max << endl;
	return 0;
}