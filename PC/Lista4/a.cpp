#include <bits/stdc++.h>
#define pair<int,int> pii
#define INFI 1e9
using namespace std;

int d[20001];
int visited[20001];
vector<vector<pii>> graph(20001);


void djikstra(int start){
    queue <pii>;
    visited[start] = 1;

    for(int i=0; i<20001; i++){
        if(i!=s) d[i] = INFI;
        else d[i] = 0;
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
        scanf("%d %d %d", &a, &b, &c);
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