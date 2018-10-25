#include <bits/stdc++.h>
using namespace std;

int visited[100001];
int x;

int bfs(int start){
    
    queue <pair<int,int>> q;
    q.push(make_pair(start, 0));
    int cliques=0;
    
    while(q.size()){
        
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        if(!visited[u]){
            visited[u] = 1;
            if(u==x) return v;
            if(u-3>=1) q.push(make_pair(u-3, v+1));
            if(u*2<=100000) q.push(make_pair(u*2, v+1)); 
        }
    }
    return -1;
}

int main () {
    int n;
    scanf("%d %d", &n, &x);
    cout << bfs(n) << endl;
    return 0;
}