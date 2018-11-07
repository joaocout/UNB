#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define pii pair<int,int>

vector<vector<pii>> graph(40000);

int d[40000];

void dijkstra(int start){
    priority_queue <pii, vector<pii>, greater<pii>> pq;

    for(int i=0; i<40000; i++) d[i] = INF;
    d[start]=0;
    
    pq.push(make_pair(d[start], start));

    while(pq.size()){
    
        int u = pq.top().second;
        pq.pop();
    
        for(pii edge: graph[u]){
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

    char campo[n][m];
    for(int i=0; i<n; i++)
        scanf("%s", campo[i]);


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(campo[i][j]=='A'){
                if(i!=n-1 && campo[i+1][j]!='M') graph[(i*m)+j].push_back(make_pair(((i+1)*m)+j, 5));
                if(j!=m-1 && campo[i][j+1]!='M') graph[(i*m)+j].push_back(make_pair((i*m)+j+1, 5));
            }
            else if(campo[i][j]=='.'){
                if(i!=n-1 && campo[i+1][j]!='M') graph[(i*m)+j].push_back(make_pair(((i+1)*m)+j, 1));
                if(j!=m-1 && campo[i][j+1]!='M') graph[(i*m)+j].push_back(make_pair((i*m)+j+1, 1));   
            }
        }
    }
    dijkstra(0);
    printf("%d\n", d[(n*m)-1]);
    return 0;
}