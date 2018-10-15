#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long fat[1000001];

int main () {
	
	for(int i=0; i<=1000000; i++){
		if(i==0||i==1) fat[i] = 1;
		else fat[i] = ((i%MOD) * (fat[i-1]%MOD))%MOD;
	}

	int q;
	cin >> q;
	for(int i=0; i<q; i++){
		int x;
		cin >> x;
		cout << fat[x] << endl;
	}
	return 0;
}