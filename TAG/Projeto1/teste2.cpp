#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

bool find_in_vector(int x, vector<int> a){
    for(long unsigned int i = 0; i<a.size(); i++){
        if(a[i] == x) return true;
    }
    return false;
}


int main () {
    
    /*  a 1
        b 2
        c 3
        d 4
        e 5
        f 6
        g 7
        h 8
        i 9
        j 10
    */

    vector<vector<int> > g(11);
    //A
    g[1].push_back(8); //H

    //B
    g[2].push_back(4);  //D
    g[2].push_back(7);  //G
    g[2].push_back(10); //J
    g[2].push_back(3);  //C
    g[2].push_back(9);  //I

    //C
    g[3].push_back(2);  //B
    g[3].push_back(10); //J
    g[3].push_back(6);  //F

    //D
    g[4].push_back(2);  //B

    //E

    //F
    g[6].push_back(3); //C

    //G
    g[7].push_back(2); //B

    //H
    g[8].push_back(1); //A

    //I
    g[9].push_back(2); //B

    //J
    g[10].push_back(2); //B
    g[10].push_back(3); //C


    double global_clustering = 0;

    cout << "CLUSTERING COEFFICIENT" << endl;
        for(int i = 1; i <= 10; i++){  //para cada vertice (v) do grafo
            cout << "c(" << i << ") = ";
            int t = 0;
            
            bool tab[10][10];
            for(int ii = 0; ii<10; ii++) for(int jj = 0; jj<10; jj++)
                tab[ii][jj] = false;

            for(long unsigned int j = 0; j < g[i].size(); j++){   //para cada vertice (a) adjacente a (v)
                for(long unsigned int k = 0; k < g[i].size(); k++){    //para cada vertice (b) adjacente a (v)
                    if(!tab[j][k] && j!=k){                             //se um triangulo ainda nao foi encontrado
                        if(find_in_vector(g[i][j], g[g[i][k]])){    //se a for encontrado dentre os adjacente a b
                            tab[j][k] = true;                     
                            tab[k][j] = true;                       //marcamos na tabela para avisar que ja foi encontrado
                            t++;                                    //um triangulo formado pelos vertices a, b e v
                        }
                    }
                }
            }
            
            int temp = g[i].size();
            if(temp*(temp-1) != 0){
                double aa = 2*t;
                double bb = temp * (temp-1);
                printf("%lf\n", aa/bb);
                global_clustering += aa/bb;
            }
            else
                cout << 0 << endl;

        }
    global_clustering = global_clustering / 10;
    cout << endl;
    cout << "GLOBAL CLUSTERING  COEFFICIENT" << endl;
    cout << "C = " << global_clustering << endl;

    return 0;
}