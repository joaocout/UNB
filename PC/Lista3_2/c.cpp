#include <bits/stdc++.h>
using namespace std;

int visited[250000];

vector <vector <int>> graph(250000);

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while(q.size()){
        int u = q.front();
        q.pop();
        for(int w: graph[u]){
            if(!visited[w]){    
                q.push(w);
                visited[w] = 1;
            }
        }
    }
}

int main () {
    int n, m;
    cin >> n >> m;
    
    char mapa[n][m];

    //ler mapa
    for(int i=0; i<n; i++) scanf("%s", mapa[i]);
    
    //montar grafo
    for(int i=0; i<n; i++) for(int j=0; j<m; j++){
        
        if(mapa[i][j]=='#') visited[(i*m)+j] = 1;
        
        else if(mapa[i][j]=='.'){
            
            //graph[(i*m)+j].push_back((i*m)+j);
            
            if(i!=0 && mapa[i-1][j]!='#') graph[(i*m)+j].push_back(((i-1)*m)+j);
            
            if(i!=n-1 && mapa[i+1][j]!='#') graph[(i*m)+j].push_back(((i+1)*m)+j);
            
            if(j!=0 && mapa[i][j-1]!='#') graph[(i*m)+j].push_back((i*m)+j-1);
            
            if(j!=m-1 && mapa[i][j+1]!='#') graph[(i*m)+j].push_back((i*m)+j+1);
        }
    }

    int r=0;
    for(int i=0; i<n*m; i++){
        if(visited[i]==0){
            bfs(i);
            r++;
        }
    }
        
    printf("%d\n", r);

    return 0;
}