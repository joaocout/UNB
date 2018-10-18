#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;
	cin >> n;

	vector<int> div;
	for(int i=1; i*i<=n; i++){
		if(n%i==0){
			int a = n/i;
			div.push_back(i);
			if(i!=a) div.push_back(a); 
		}
	}
	sort(div.begin(), div.end());
	int x, y, min=1000000000;
	for(int i=0; i<div.size(); i++){
		if((div[i]-(n/div[i])) < min && (div[i]-(n/div[i]))>=0){
			x = div[i];
			y = n/div[i];
			min = div[i]-(n/div[i]);
		}
	}
	if(x<=y) printf("%d %d\n", x, y);
	else printf("%d %d\n", y, x);
	return 0;
}