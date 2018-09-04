#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, k;
    scanf("%d %d", &n, &k);
    int horas = 0;
    int usadas =0;
    while(n>0){
        horas++;
        n--;
        usadas++;
        if(usadas == k){
            n++;
            usadas = 0;
        }
    }
    printf("%d\n", horas);
    return 0;
}
