#include <bits/stdc++.h>
using namespace std;

int main () {
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	int i;
	int soma=0;
	for(i=1; i<=n; i++){
		char aux[5];
		sprintf(aux, "%d", i);
		int j;
		int somadosdigitos=0;
		for(j=0; j<strlen(aux); j++){
			int auxx = aux[j] - '0';
			somadosdigitos+=auxx;
		}
		if(somadosdigitos>=a && somadosdigitos<=b){
			soma+=atoi(aux);
		}
	}
	printf("%d\n", soma);
	return 0;
}