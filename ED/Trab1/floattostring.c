#include <stdio.h>
#include <string.h>

void floattostring (float num, char* aux){
    int negativo=0;
    if(num<0) {
        negativo=1;
        aux[0] = '-';
        num = -num;
    }
    int inum = num, i = negativo;
    if(inum==num){/*sem casa fracionaria*/
        while(num>=1){
            aux[i] = (inum%10) + '0';
            num = num/10;
            inum = num;
            i++;    
        }
    }
    /*inverter string*/
    char temp[strlen(aux)];
    for(i=negativo; i<strlen(aux); i++)
        temp[i-negativo] = aux[strlen(aux)-1-i+negativo];
    
    for(i=negativo; i<strlen(aux); i++)
        aux[i] = temp[i-negativo];
}

int main () {
    float num;
    char string[100];
    scanf("%f", &num);
    floattostring(num, string);
    printf("%s\n", string);
    return 0;
}