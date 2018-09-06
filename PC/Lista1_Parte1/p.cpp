#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, a;
    cin >> n >> a;
    int resto = n%500;
    if(resto<=a)
        printf("Sim\n");
    else
        printf("Nao\n");
    return 0;
}