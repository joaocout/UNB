#include <bits/stdc++.h>
using namespace std;

//terminar

#define pii pair<int,int>
#define INF 1e9

int custodeivis[26]; /*taxi*/
int custoandre[26]; /*ober*/
void init(){
    for(int i=0; i<26; i++){
        custodeivis[i] = INF;
        custoandre[i] = INF;
    }
}


vector<vector<pii>> graphtaxi(26);
vector<vector<pii>> graphober(26);

void dijkstra(int start, int deivis){
    
    priority_queue <pii, vector<pii>, greater<pii> > pq;
    init();

    if(deivis){
        custodeivis[start]=0;
        pq.emplace(custodeivis[start], start);
        while(pq.size()){
            int u = pq.top().second;
            pq.pop();
            for(pii edge: graphtaxi[u]){
                int v, w;
                tie(v, w) = edge;
                if(custodeivis[v] > custodeivis[u] + w){
                    custodeivis[v] = custodeivis[u] + w;
                    pq.emplace(custodeivis[v], v);
                }
            }
        }
    }
    else{
        custoandre[start]=0;
        pq.emplace(custoandre[start], start);
        while(pq.size()){
            int u = pq.top().second;
            pq.pop();
            for(pii edge: graphober[u]){
                int v, w;
                tie(v, w) = edge;
                if(custoandre[v] > custoandre[u] + w){
                    custoandre[v] = custoandre[u] + w;
                    pq.emplace(custoandre[v], v);
                }
            }
        }
    }
}




int main  () {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        char a, b, c, d;
        int custo;
        scanf(" %c %c %c %c %d", &a, &b, &c, &d, &custo);
        if(a=='O'){
            graphober[(c-65)].emplace_back(d-65, custo);
            if(b=='B') graphober[(d-65)].emplace_back(c-65, custo);
        }
        else if(a=='T'){
            graphtaxi[(c-65)].emplace_back(d-65, custo);
            if(b=='B') graphtaxi[(d-65)].emplace_back(c-65, custo);
        }
    }

    char andre, deivis;
    scanf(" %c %c", &andre, &deivis);
    
    dijkstra(andre-65, 0);
    dijkstra(deivis-65, 1);

    int result[26];

    for(int i=0; i<26; i++)
        result[i] = custoandre[i] + custodeivis[i];

    for(int i=0; i<26; i++)
        cout << custoandre[i] << " ";
    cout << endl;
    for(int i=0; i<26; i++)
        cout << custodeivis[i] << " ";
    cout << endl;

    for(int i=0; i<26; i++)
        cout << result[i] << " ";
    cout << endl;

    int min = INF;
    for(int i=0; i<26; i++){
        if(result[i]<min)
            min = result[i];
    }

    if(min == INF) cout << "-1" << endl;
    else{
        printf("%d\n", min);
        for(int i=0; i<26; i++){
            if(result[i]==min){
                printf("%c ", i+65);
            }
        }
        printf("\n");
    }
    return 0;
}
