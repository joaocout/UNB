#include <bits/stdc++.h>
using namespace std;

int main () {
    char a[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};
    string s, p;
    cin >> s;
    cin >> p;
    int j=0;
    while(s[j]!='\0'){
        int achou=0, k=0;
        while(!achou){
            if(a[k]==s[j]){
                achou=1;
                printf("%c", p[k]);
            }
            k++;
        }
        j++;
    }
    printf("\n");
    return 0;
}