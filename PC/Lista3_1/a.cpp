#include <bits/stdc++.h>
using namespace std;

int teste(long long n, long long x){
    long long soma = (n*(n+1))/2;
    if(soma>x) return 1;
    else return 0;
}

int main () {
    long long int x;
    scanf("%lld", &x);
    
    long long int n;
    n = (sqrt(8*x + 1) -1)/2;
    if(teste(n, x)) printf("%lld\n", n);
    else printf("%lld\n", n+1);
    return 0;
}