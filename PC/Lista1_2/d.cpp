#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    queue<int> cartas;
    for(int i=1; i<=n; i++)
        cartas.push(i);
    while(cartas.size() >= 2){
        printf("%d ", cartas.front());
        cartas.pop();
        cartas.push(cartas.front());
        cartas.pop();
    }
    printf("\n");
    printf("%d\n", cartas.front());
    return 0;
}