#include <bits/stdc++.h>
using namespace std;


int primetest(int n){
	if(n==1) return 0;
	if(n%2==0){
		if(n==2) return 1;
		else return 0;
	}
	else{
		for(int i=3; i*i<=n; i+=2){
			if(n%i==0) return 0;
		}
		return 1;
	}
}


int main () {
	int x;
	scanf("%d", &x);
	double n = (x-2)/2;
	int in = n;
	if(in!=n) printf("0\n");
	else{
		if(primetest(n)==1 && primetest(n+2)==1) printf("1\n");
		else printf("0\n");
	}
	return 0;
}

/*
x = 2n+2
x-2 = 2n
(x-2)/2 = n
*/