/*
ALUNO : JOAO PEDRO ASSUNCAO COUTINHO
MATRICULA : 18/0019813
github.com/joaocout
*/

/*
O programa pula todos os comentarios (linhas iniciadas com '%')
independentemente da linha em que estao escritos.
*/

/*
O primeiro input nao comentado deve ser composto por tres inteiros
responsaveis por descrever quantas arestas e vertices o grafo possui
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


void bron_kerbosch(vector<int> r, vector<int> p, vector<int> x, vector<vector<int>> graph){



}


int main () {

    string file_name;
    cout << "Enter the  input file name: ";
    cin >> file_name;

    ifstream input_file;
    input_file.open(file_name);

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

        vector<vector<int>> dolphins(height + 1);

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

        
        /*grau de todos os vertices*/
        cout << "DEGREE OF EACH VERTEX" << endl;
        for(int i = 1; i < height+1; i++){  //golfinhos enumerados de 1 a 62
            cout << "degree(" << i << ") = " << dolphins[i].size() << endl;
        }

        /*cliques maximais*/
        cout << "ALL MAXIMAL CLIQUES" << endl;
        vector<int> r;
        vector<int> p;
        vector<int> x;
        for(int i = 1; i<=height; i++){
            p.push_back(i);    //inicializando com todos os vertices
        }

        bron_kerbosch(r, p, x, dolphins);
        


        input_file.close();

    }

    return 0;
}