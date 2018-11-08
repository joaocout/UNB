#include <bits/stdc++.h>
using namespace std;
#define pii pair<long long,int>
#define INF 1e18

long long d[100000];

vector<vector<pii>> graph(100000);


void dijkstra(int start){

	for(int i=0; i<100000; i++)
		d[i] = INF;

	priority_queue <pii, vector<pii>, greater<pii>> pq;
	d[start] = 0;
	pq.push(make_pair(d[start], start));

	while(pq.size()){
		int u = pq.top().second;
		pq.pop();
		for(auto edge : graph[u]){
			int v, w;
			tie(v,w) = edge;
			if(d[v] > d[u]+w){
				d[v] = d[u]+w;
				pq.push(make_pair(d[v],v));
			}
		}
	}

}

int main (){
	int n, m, s, t;
	cin >> n >> m >> s >>t;
	for(int i=0; i<m; i++){
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		graph[b].push_back(make_pair(a, w));
	}
	dijkstra(s);
	
	int resp = 0;

	for(int i=0; i<n; i++){
		if(d[i] <= t) resp++;
	}


	cout << resp << endl;
	return 0;
}