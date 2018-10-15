#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    int i;
    set<int>torre;
    for(i=0; i<n; i++){
        int temp;
        scanf("%d", &temp);
        torre.insert(temp);
    }
    cout << torre.size() << endl;
    return 0;
}