#include <bits/stdc++.h>
using namespace std;


int main () {
    int n;
    scanf("%d", &n);

    string amigos[n];
    for(int i=0; i<n; i++)
        cin >> amigos[i];

    set<string> aux;
    vector <string> resposta;

    resposta.push_back(amigos[n-1]);
    aux.insert(amigos[n-1]);
    string temp = amigos[n-1];

    for(int j=n-2; j>=0; j--){
        if(amigos[j]!=temp && aux.count(amigos[j])==0){
            resposta.push_back(amigos[j]);
            aux.insert(amigos[j]);
            temp = amigos[j];
        }
    }
    
    for(int i=0; i<resposta.size(); i++)
        cout << resposta[i] << endl;
    return 0;
}