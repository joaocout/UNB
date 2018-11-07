#include <bits/stdc++.h>
#define INFI 1e9

using namespace std;


int d[20001];
int visited[20001];
vector<vector<pair<int,int>>> graph(20001);


void dijkstra(int start){

    for(int i=0; i<20001; i++){
        if(i!=start) d[i] = INFI;
        else d[i] = 0;
    }

    priority_queue < pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push(make_pair(d[start], start));
    /*first = distancia do vertice ao s*/
    /*numero do vertice*/
    
    while(pq.size()){
        
        int u = pq.top().second;    
        pq.pop();

        for(pair<int,int> edge : graph[u]){
            int v, w;
            tie(v, w) = edge;
            
            if(d[v] > d[u] + w){ 
                d[v] = d[u] + w;
                pq.push(make_pair(d[v], v));
            }
        }
    }
}

int main () {
    int n, m;
    cin >> n >> m;
    int s, q;
    cin >> s >> q;

    /*first = vertice destino*/
    /*second = peso da aresta*/

    for(int i=0; i<m; i++){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        graph[a].push_back(make_pair(b, w));
        graph[b].push_back(make_pair(a, w));
    }

    dijkstra(s);

    for(int i=0; i<q; i++){
        int x;
        scanf("%d", &x);
        printf("%d\n", d[x]);
    }
    return 0;
}