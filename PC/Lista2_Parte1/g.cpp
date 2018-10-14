#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
int primoate[MAX];

int main () {
	vector<int> marcacao(MAX, 1);
	for(int i=2; i<MAX; i++){
		if(marcacao[i]==1){
			primoate[i] = primoate[i-1] + 1;
			for(int m = i+i; m<MAX; m+=i)
				marcacao[m] = 0;
		}
		else primoate[i] = primoate[i-1];
	}
	int q;
	scanf("%d", &q);
	for(int i=0; i<q; i++){
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", primoate[r] - primoate[l-1]);
	}
	return 0;
}