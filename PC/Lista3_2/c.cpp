#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    string tab[n];

    for(int i=0; i<n; i++) cin >> mapa[i];

    vector <vector <int>> graph(n*m);

    for(int i=0; i<n; i++) for(int j=0; j<m; j++){
        if(mapa[i][j]=='.'){
            mapa[(i*m)+j].push_back((i*m)+j);
            if(i!=0 && tab[i-1][j]!='#') mapa[(i*m)+j].push_back([((i-1)*m)+j]);
            if(i!=n-1 && tab[i+1][j]!='#') mapa[(i*m)+j].push_back([((i+1)*m)+j]);
            if(j!=0 && tab[i][j-1]!='#') mapa[(i*m)+j].push_back([(i*m)+j-1]);
            if(j!=m-1 && tab[i][j+1]!='#') mapa[(i*m)+j].push_back([(i*m)+j+1]);
        }
    }
    

    return 0;
}