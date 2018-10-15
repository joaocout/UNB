#include <bits/stdc++.h>
using namespace std;
int vit[100];

int main  () {
	int n;
	scanf("%d", &n);
	int pok[n];
	int i, j;
	int vivo[100];
	for(i=0; i<n; i++){
		scanf("%d", &pok[i]);
		vivo[i] = 1;
	}

	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			if(pok[i]>pok[j] && vivo[j]==1 && vivo[i]==1){
				vit[i]++;
				vivo[j] = 0;

			}
			else if(pok[j]>pok[i] && vivo[j]==1 && vivo[i]==1){
				vit[j]++;
				vivo[i] = 0;
				i++;
			}
		}
	}
	for(i=0; i<n; i++)
		printf("%d ", vit[i]);
	return 0;
}