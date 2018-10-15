#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, q;
    scanf("%d %d", &n, &q);
    vector<int> vet;

    int i;
    for(i=0; i<n; i++){
        int aux;
        scanf("%d", &aux);
        vet.push_back(aux);
    }
    sort(vet.begin(), vet.end());
    for(i=0; i<q; i++){
        int x;
        scanf("%d", &x);
        auto low = lower_bound(vet.begin(), vet.end(), x);
        if(x > (*(vet.begin()+n-1)))
            printf("-1\n");
        else
            printf("%d\n", *low);
    }
    return 0;
}