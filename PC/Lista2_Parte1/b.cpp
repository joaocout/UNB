#include <bits/stdc++.h>
using namespace std;
long long qntdiv[1000001];

int main () {
	for(long long i=1; i<=1000000; i++){
		for(long long m=i; m<=1000000; m+=i){
			qntdiv[m]++;
		}
	}
	long long q;
	scanf("%lld", &q);
	for(long long i=0; i<q; i++){
		long long x;
		scanf("%lld", &x);
		printf("%lld\n", qntdiv[x]);
	}
	return 0;
}
