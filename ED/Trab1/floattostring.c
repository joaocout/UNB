#include <stdio.h>

int tamfloat(float a){
    int size = 0;
    if(a==0) return 1;
    else if(a<0){
        size++; /*simbolo -*/
        a = -a;
    }
    int ia = a;
    if(ia==a){
        while(a>=1){
            size++;
            a = a/10;
        }
    }
    else{
        size++; /* simbolo . ou ,*/
        while(a!=ia){
            a = a*10;
            ia = a;
        }
        while(a>=1){
            size++;
            a = a/10;
        }
    }
    return size;
}

/*char* floattostring(float a){
    int ia = a;
    if()
}*/

int main () {
    float a;
    scanf("%f", &a);
    printf("%d\n", tamfloat(a));
    return 0;
}