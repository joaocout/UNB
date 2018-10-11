#include <stdio.h>
#include <math.h>
#include <string.h>

double stringtofloat(char* string){
	int comvirgula=0, posvirgula, negativo=0;
	if(string[0]=='-'){
		negativo = 1;
		string[0] = '0';	
	}
	for(int i=0; i<strlen(string); i++){
		if(string[i]=='.' || string[i]==','){
			comvirgula=1;
			posvirgula=i;
		}
	}
double a = 0;
	if(!comvirgula){
		for(int i=0; i<strlen(string); i++)
			a += (string[i]-'0') * pow(10, strlen(string)-i-1);		
	}
	else{
		for(int i=0; i<posvirgula; i++){
			double temp = string[i] - '0';
			a += temp * pow(10, posvirgula-1-i);
		}
		for(int i= posvirgula+1; i<strlen(string); i++){
			double temp = string[i] - '0';
			a += temp * pow(10, posvirgula-i);
		}
	}
	if(negativo) return a;
	else return a;
}


int main () {
	char a[100];
	scanf("%s", a);
	printf("em float: %f\n", stringtofloat(a)); 
	return 0;
}
