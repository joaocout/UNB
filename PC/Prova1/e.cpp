#include <bits/stdc++.h>
using namespace std;

vector  < pair<int,int> > somadosdigitos(100000, make_pair(0, 0));

int main () {

	int i;
    for(i=0; i<100000; i++){
        
        char aux[30];
        sprintf(aux, "%d", i+1);
        
        int j;
        for(j=0; j<strlen(aux); j++){
            int temp = aux[j] - '0';
            somadosdigitos[i].first += temp;
        }
        somadosdigitos[i].second = i+1;
    }

    sort(somadosdigitos.begin(), somadosdigitos.end());
    
    int n;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        int cont = 0;    
        auto auxx = lower_bound(somadosdigitos.begin(), somadosdigitos.end(), make_pair(x,x));
        while(auxx->first == x){
            if((auxx->second >= l) && (auxx->second <= r))
                cont++;
            auxx++;
        }
        printf("%d\n", cont);
    }
    return 0;
}
