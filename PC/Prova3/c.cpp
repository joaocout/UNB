#include <bits/stdc++.h>
using namespace std;

#define pii pair<long long, int>
#define INF 1e18

vector<vector<pii>> graph(20000);

long long tempo[20000];

void init (){
	for(int i=0; i<20000; i++) tempo[i] = INF;
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

	int n, m, s, t;
	cin >> n >> m >> s >> t;

	for(int i=0; i<m; i++){
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		graph[a].push_back(make_pair(b, w));
		graph[b].push_back(make_pair(a, w));
	}

	dijkstra(s);
	if(tempo[t]>=INF) cout << "-1" << endl;
	else cout << tempo[t] << endl;
	return 0;
}