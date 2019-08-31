/*
Nome : JOAO PEDRO ASSUNCAO COUTINHO
Matricula : 18/0019813

Este eh o arquivo principal do programa, possui a funcao main e a funcao Bron_Kerbosch.
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <set>
#include "functions.hpp"

using namespace std;


void Bron_Kerbosch(set<int> R, set<int> P, set<int> X, vector<vector<int>> graph){

    if(P.empty() && X.empty()){
        cout << "Maximal Clique found: ";
        for(int e : R)
            cout << e << " ";
        cout << endl;
    }

    auto it = P.begin();
    while(!P.empty()){

        int v = *it;
        set<int> temp;      //temp = {v}
        temp.insert(v);
        
        set<int> Nv;        //Nv = N(v)
        for(int e : graph[v])
            Nv.insert(e);   
        
        Bron_Kerbosch(simple_union(R, temp), simple_intersection(P, Nv), simple_intersection(X, Nv), graph);
        P = simple_difference(P, temp);
        X = simple_union(X, temp);

        if(!P.empty()) it = P.begin();

    }
}


int main () {

    string file_name;
    cout << "Enter the input file name: ";
    cin >> file_name;

    ifstream input_file;
    input_file.open(file_name.c_str());

    if(input_file.fail()){
        cout << "Error opening the file / file doesn't exist" << endl;
    }
    else{

        string line;
        bool first_valid_input = false;
        int height, width, edges;

        //primeiro encontramos o primeiro input, para declarar o grafo corretamente
        while(!first_valid_input && getline(input_file, line)){

            if(line[0] != '%'){             //se a linha n for um comentario

                if(first_valid_input == false){ //se o primeiro input (que nao seja um comentario) nao tenha sido lido ainda
                    first_valid_input = true;
                    stringstream stream(line);   //transformando a string 'line' em um stream
                    stream >> height >> width >> edges;
                }

            }

            line.clear();

        }

        vector<vector<int>> dolphins(height+1);
        //depois lemos as conexoes
        while(getline(input_file, line)){   //ate o fim do arquivo
            int a, b;
            stringstream stream(line);
            stream >> a >> b;
            
            //o grafo nao eh direcionado, entao ha conexao nas duas direcoes
            dolphins[a].push_back(b);
            dolphins[b].push_back(a);

            line.clear();
        
        }
        cout << endl;

        /*------------------------------------------*/
        /*grau de todos os vertices*/
        cout << "DEGREE OF EACH VERTEX" << endl;
        for(int i = 1; i <= height; i++){  //golfinhos enumerados de 1 a 62
            cout << "degree(" << i << ") = " << dolphins[i].size() << endl;
        }
        cout << endl;

        /*------------------------------------------*/
        /*cliques maximais*/
        cout << "ALL MAXIMAL CLIQUES" << endl;
        set<int> r;
        set<int> p;
        set<int> x;

        for(int i = 1; i <= height; i++){
            p.insert(i);    //inicializando p com todos os vertices
        }
        Bron_Kerbosch(r, p, x, dolphins);
        cout << endl;

        /*--------------------------------------------*/
        /*coeficiente de aglomeracao de todos os vertices*/
        double global_clustering = 0;
        cout << "LOCAL CLUSTERING COEFFICIENT" << endl;
        for(int i = 1; i <= height; i++){  //para cada vertice (v) do grafo
            cout << "c(" << i << ") = ";
            int t = 0;
            
            bool tab[height][width];
            for(int ii = 0; ii<height; ii++) for(int jj = 0; jj<width; jj++)
                tab[ii][jj] = false;

            for(long unsigned int j = 0; j < dolphins[i].size(); j++){   //para cada vertice (a) adjacente a (v)
                for(long unsigned int k = 0; k < dolphins[i].size(); k++){    //para cada vertice (b) adjacente a (v)
                    if(!tab[j][k] && j!=k){                             //se um triangulo ainda nao foi encontrado
                        if(find_in_vector(dolphins[i][j], dolphins[dolphins[i][k]])){    //se a for encontrado dentre os adjacente a b
                            tab[j][k] = true;                     
                            tab[k][j] = true;                       //marcamos na tabela para avisar que ja foi encontrado
                            t++;                                    //um triangulo formado pelos vertices a, b e v
                        }
                    }
                }
            }
            int temp = dolphins[i].size();
            if(temp*(temp-1)!=0 && 2*t!=0){
                double aa = 2*t;
                double bb = temp * (temp-1);
                printf("%.3lf\n", aa/bb);
                global_clustering += aa/bb;
            }
            else
                cout << 0 << endl;

        }
        cout << endl;
        global_clustering = global_clustering / height;


        /*-------------------------------------*/
        /*coeficiente de aglomeracao global*/
        cout << "AVERAGE CLUSTERING COEFFICIENT" << endl;
        cout << "C = " << global_clustering << endl;


        input_file.close();

    }

    return 0;

}