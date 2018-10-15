#include <bits/stdc++.h>
using namespace std;

int primetest(long long n){
	if(n==1) return 0;
	if(n%2==0){
		if(n==2) return 1;
		else return 0;
	}
	else{
		for(long long int i=3; i*i<=n; i+=2){
			if(n%i==0) return 0;
		}
		return 1;
	}
}

int main () {
	long long int x;
	cin >> x;
	while(primetest(x)==0){
		if(x%2==0) x++;
		else if(x%2==1) x+=2;
	}
	cout << x << endl;
}