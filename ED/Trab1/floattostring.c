#include <stdio.h>
#include <string.h>

void floattostring (double num, char* string){
    int negativo=0;
    if(num<0) {
        negativo=1;
        string[0] = '-';
        num = -num;
    }
    int posvirgula=negativo, comvirgula=0;
    int inum = num, i = negativo;


    if(inum==num){/*sem parte fracionaria*/
        while(num>=1){
            string[i] = (inum%10) + '0';
            num = num/10;
            inum = num;
            i++;    
        }
    }

    else{/*com parte   fracionaria*/
        comvirgula = 1;
        double temp = num;
        while(temp>=1){
            temp = temp/10;
            posvirgula++;
        }
        while(inum!=num){
            num=num*10;
            inum=num;
        }
            printf("num sem virgula: %f\n", num);
        while(num>=1){
            string[i] = (inum%10) + '0';
            num = num/10;
            inum = num;
            i++;    
        }
    }

    /*inverter string*/
    char temp[strlen(string)];
    if(!negativo){
        for(i=0; i<strlen(string); i++){
            
        }
    }
    for(i=negativo; i<strlen(string); i++)
        temp[i-negativo] = string[strlen(string)-1-i+negativo];
    printf("%s\n", temp);
    if(!comvirgula){
        for(i=negativo; i<strlen(string); i++)
            string[i] = temp[i-negativo];    
    }
    else{
        int j=0;
        for(i=negativo; i<strlen(temp); i++){
            if(j==posvirgula){
                string[j] = ',';
                j++;
            }
            string[j] = temp[i-negativo];
            j++;
        }
    }
}

int main () {
    float num;
    char string[100];
    scanf("%f", &num);
    floattostring(num, string);
    printf("%s\n", string);
    return 0;
}