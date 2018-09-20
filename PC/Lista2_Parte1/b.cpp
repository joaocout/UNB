#include <bits/stdc++.h>
using namespace std;

long div(long long x) {
	long long resp = 0;
	for(long long a=1; (a*a)<=x; a++){
		if(x%a == 0){
			long long b = x/a;
			if(b==a) resp++;
			else resp+=2;
		}
	}
	return resp;
}

int main () {
	long long q;
	cin >> q;
	for(long long i=0; i<q; i++){
		long long x;
		cin >> x;
		cout << div(x) << endl;
	}
	return 0;
}
