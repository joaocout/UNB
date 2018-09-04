[...]

## ED: Soma de prefixos
1 - Montar o vetor de "somas" uma única vez - de preferência antes das consultas;
        int somas(int* v, int n){
            somas[0] = v[0];
            for(int i=1; i<n; i++){
                somas[i] = somas[i-1] + v[i];            
            }
        }

2 - Elaborar uma função para consultar com base em intervalos [l+1, r];
Cuidade com o caso em que l = 0;
        int consulta(int l, int r){
            if(!l)
                return somas[r];
            else
                return somas[r] - somas[l-1];
        }
OBS: a complexidade é O(1), já que somente é contabilizado o tempo de consulta;


#ED: Delta Encoding
-variações(derivada de primeira ordem);
-vetor de diferenças(Complexidade O(n));
-função de atualização do vetor de variaçẽos;
            void update(int l, int r, int valor, int n){
                if(r+1 < n)
                    delta[r+1] = delta[r+1] - valor;
                delta[l] = delta[l] + valor;
            }
-para voltar ao vetor utilizado para construir o vetor delta, basta fazer um vetor de somas utilizando o vetor delta;
        void reverse(){
            rev[0] = delta[0];
            for(int i=0; i<n; i++){
                rev[i] = rev[i-1] + delta[i];            
            }
        }

//
