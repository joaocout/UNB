#include <stdio.h>
#include "funcoes.h"
#include "pilha.h"

int main () {
    double x;
    scanf("%lf", &x);
    char b[100];
    doubletostring(x, b);
    return 0;


}