#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    pair<string,int> matriculas[n];
    int i;
    for(i=0; i<n; i++){
        cin >> matriculas[i].first;
    }
    int j;
    int k=0;
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            int temp = matriculas[i].first[k];
            int tempp = matriculas[j].first[k];
            if(temp>tempp){
               matriculas[i].second++;
               k=0;
            }
            else if (tempp>temp){
               matriculas[j].second++;
               k=0;
            }
            else if (temp == tempp){
                k++;
                j--;
            }
        }
    }
    for(i=0; i<n; i++)
        printf("%d ", matriculas[i].second);
    printf("\n");
    return 0;
}