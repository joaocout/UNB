#include <stdio.h>
#include "funcoes.h"
#include <string.h>
int main (){
    double a;
    char b[100];
    scanf("%lf", &a);
    doubletostring(a, b);
    printf("%s\n", b);
    printf("%d\n", strlen(b));
    return 0;
}