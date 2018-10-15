#include <bits/stdc++.h>
using namespace std;

int main () {
    string a, b;
    cin >> a >> b;
    string result = a + b;
    int aux = stoi(result);
    double semfrac, comfrac;
    comfrac = sqrt(aux);
    semfrac = floor(comfrac);
    if(ceil(comfrac-semfrac)==1)
        printf("Nao\n");
    else
        printf("Sim\n");
    return 0;
}