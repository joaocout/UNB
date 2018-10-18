#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;
	cin >> n;
	int soma;
	if(n==1) soma=0;
	else soma=1;
	for(int i=2; i*i<=n; i++){
		if(n%i==0){
			int a = n/i;
			soma+=i;
			if(i!=a) soma+=a; 
		}
	}
	if(soma==n) printf("1\n");
	else printf("0\n");
	return 0;
}