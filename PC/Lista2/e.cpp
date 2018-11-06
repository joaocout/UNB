#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int main () {

	int m, n;
	cin >> m >> n;
	set<int> div[MAX];
	for(int i=1; i<MAX; i++){
		for(int m=i; m<MAX; m+=i){
			if(i<=n) div[m].insert(i);
		}
	}
	/*
	1 2 4 
	1 3
	1 5
	1 2 3 6
	1 2 3 6 9 18
	*/
	int x[m], y[m];
	for(int i=0; i<m; i++){
		cin >> x[i] >> y[i];
		int resp = div[x[i]].size();
		for(int u = i-y[i]; u<i; u++){

		}
	}
	return 0;

}