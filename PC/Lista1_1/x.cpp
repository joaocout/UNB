#include<bits/stdc++.h>
using namespace std;

int par(int* vet, int n){
	int i;
	for(i=0; i<n; i++){
		if(vet[i]%2!=0)
			return 0;
	}
	for(i=0; i<n; i++)
		vet[i] = vet[i]/2;
	return 1;
}

int main () {
	int n;
	scanf("%d", &n);
	int i, vet[n];
	for(i=0; i<n; i++)
		scanf("%d", &vet[i]);
	int count=0;
	int r=1;
	while(r == 1){
		r = par(vet, n);
		if(r==1)
			count++;
	}
	printf("%d\n", count);
	return 0;
}