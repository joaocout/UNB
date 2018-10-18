#include <bits/stdc++.h>
using namespace std;

int main () {

	int n, m;
	cin >> n >> m;

	int a[n];
	
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	sort(a, a+n);
	
	for(int i=0; i<m; i++){
		int x;
		scanf("%d", &x);
		auto u = upper_bound(a, a+n, x);
		printf("%ld ", (u-a));
	}
	printf("\n");
	return 0;
}