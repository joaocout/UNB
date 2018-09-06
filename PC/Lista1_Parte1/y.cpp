#include <bits/stdc++.h>
using namespace std;

int main (){
	int a, b;
	scanf("%d %d", &a, &b);
	char maxnum[10];
	int max=0;
	int i;
	char aux[10];
	sprintf(aux, "%d", a);
	strcpy(maxnum, aux);
	for(i=a; i<=b; i++){
		sprintf(aux, "%d", i);
		int j = 0;
		int auxx=0;
		while(aux[j] != '\0'){
			if(aux[j] == '0' || aux[j] == '6'|| aux[j] == '9')
				auxx++;
			else if(aux[j]=='8')
				auxx=auxx+2;
			j++;
		}
		if(auxx>max){
			max=auxx;
			strcpy(maxnum, aux);
		}
	}
	printf("%s\n", maxnum);
	return 0;
}