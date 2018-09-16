#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    int cartas[n];
    long long bob=0, alice=0;

    int i;
    for(i=0; i<n; i++){
        scanf("%d", &cartas[i]);
    }
    sort(cartas, cartas+n);
    for(i=n-1; i>=0; i--){
        if(i%2==0) bob+=cartas[i];
        else alice+=cartas[i];
    }
    printf("%lld\n", abs(alice-bob));
    return 0;
}
