#include <stdio.h>
#include <math.h>
#include <string.h>

float stringtofloat(char* string){
	int comvirgula=0, posvirgula;
	for(int i=0; i<strlen(string); i++){
		if(string[i]=='.' || string[i]==','){
			comvirgula=1;
			posvirgula=i;
			i=strlen(string);
		}
	}
float a = 0;
	if(!comvirgula){
		for(int i=0; i<strlen(string); i++)
			a += (string[i]-'0') * pow(10, strlen(string)-i-1);		
	}
	else{
		int j=0;
		for(int i=0; i<strlen(string); i++){
			if(string[i]==',' || string[i]=='.')
				i++;
			a += (string[i]-'0') * pow(10, posvirgula-j-1);
			j++;
		}
	}
	return a;
}


int main () {
	char a[10];
	scanf("%s", a);
	printf("%f\n", stringtofloat(a)+10);
}