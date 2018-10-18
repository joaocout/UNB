#include <bits/stdc++.h>
using namespace std;

int f(long long x){
	
	char aux[19];
	sprintf(aux, "%lld", x);

	int somadosdigitos=0;
	for(int i=0; i<strlen(aux); i++)
		somadosdigitos += aux[i] - '0';

	return somadosdigitos;
}

long long bsearch(long long n, long long y){
	long long l=1, r=n, mid;
	
	while(l<=r){
		mid = (l+r)/2;
		if(mid-f(mid) < y) l=mid+1;
		else if(mid-f(mid) >= y){
			if((mid-1)-f(mid-1) >= y) r = mid-1;
			else return mid;
		}
	}
	return n+1;
}

int main () {
	long long n, y;
	scanf("%lld %lld", &n, &y);
	cout << n-bsearch(n, y)+1 << endl;
	return 0;
}