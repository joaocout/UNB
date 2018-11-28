#include <stdio.h>
#include <string.h>

void binario(int n, int bin){
	char num[20] = "\0";
	int i=0;
	do{
		num[i] = (n%2) + '0';
		i++;
		n = n/2;
	}
	while(n>0);
	
	int aa;
	if(bin) aa = 8;
	else aa = 4;
	for(int j=0; j<aa-strlen(num); j++) printf("0");

	for(i=strlen(num)-1; i>=0; i--) printf("%c", num[i]);
}


void bcd(int n){
	char aux[50] = "\0";
	sprintf(aux, "%d", n);
	printf("begin\n");
	if(strlen(aux)==1){
		printf("\tbcd1 = 4'b0000;\n");
		printf("\tbcd0 = 4'b");
		binario(aux[0]-'0', 0);
		printf(";\n");
		
	}
	else{
		printf("\tbcd1 = 4'b");
		binario(aux[0]-'0', 0); puts(";");
		printf("\tbcd0 = 4'b");
		binario(aux[1]-'0', 0); puts(";");
	}
	printf("\tend\n");
}

int main () {
	int start, end;
	scanf("%d %d", &start, &end);
	puts("");
	
	int i;
	for(i=start; i<=end; i++){
		printf("8'b");
		binario(i, 1); printf(": ");
		bcd(i);
		puts("");
	}
	return 0;
}