#include <bits/stdc++.h>
using namespace std;

int vetin[100000], vetout[100000];

int main () {
	int n, m, q;
	cin >> n >> m >> q;
	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		vetout[a]++;
		vetin[b]++;
	}
	for(int i=0; i<q; i++){
		int t,x ;
		scanf("%d %d", &t, &x);
		if(t==1) printf("%d\n", vetout[x]);
		else if(t==2) printf("%d\n", vetin[x]);
	}
	return 0;	
}