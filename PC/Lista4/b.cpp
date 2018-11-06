#include <bits/stdc++.h>
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

    int dt, w;
    int u, v;

    while(pq.size()){
        tie(dt, u) = pq.top();
        pq.pop();

        for(pair<int,int> edge : graph[u]){
            tie(v, w) = edge;
            if(d[v] > d[u] + w){ 
                d[v] = d[u] + w;
                pq.push(make_pair(d[v], v));
                }
        }
    }
}

int main () {
    
    return 0;
}