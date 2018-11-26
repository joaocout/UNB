#include <stdio.h>
#include <string.h>
char bin[20];

void binario(int n){
	int i=0;
	do{
		bin[i] = (n%2) + '0';
		i++;
		n = n/2;
	}
	while(n>0);
	
	for(i=strlen(bin)-1; i>=0; i--) printf("%c", bin[i]);
	for(i=0; i<15; i++) bin[i] = '\0';
}

int main () {
	int start, end;
	scanf("%d %d", &start, &end);
	puts("");
	
	int i;
	for(i=start; i<=end; i++){
		printf("%d = ", i);
		binario(i);
		printf("\n");
	}
	return 0;
}
