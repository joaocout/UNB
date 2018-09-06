#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
    scanf("%d %d", &n, &m);

    string mat[n];
    int i, j;


    int tem=0;
    int xmin=m-1, xmax=0, ymin=n-1, ymax=0;
    for(i=0; i<n; i++)
        cin >> mat[i];
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(mat[i][j] == '1' && i>=ymax){
                ymax = i;
                tem = 1;
            }
            if(mat[i][j] == '1' && i<=ymin){
                ymin = i;
                tem = 1;
            }
            if(mat[i][j] == '1' && j>=xmax){
                xmax = j;
                tem = 1;
            }
            if(mat[i][j] == '1' && j<=xmin){
                xmin = j;
                tem = 1;
            }
        }
    }
    if(tem) printf("%dx%d\n", xmax-xmin+1, ymax-ymin+1);
    else printf("0x0\n");
    return 0;
}