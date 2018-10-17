#include <bits/stdc++.h>
using namespace std;

double somaate(double n){
    return (n/2) * (n+1);
}

long long bsearch(long long x){
    long long l=1, r=x, mid;
    while(l<=r){
        
        if(l==r) mid = l;
        else mid = (l+r)/2;

        if(somaate(mid)>x) r = mid-1;
        else if(somaate(mid)<x) l = mid+1;
        else if(somaate(mid)==x) return mid;
    }
    return mid;
}

int main (){

    long long x;
    cin >> x;
    
    long long n = bsearch(x);
    if(somaate(n)>x) cout << n << endl;
    else cout << n+1 << endl;
        
    return 0;
}