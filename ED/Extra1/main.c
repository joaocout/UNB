/*
Aluno: JOAO PEDRO ASSUNCAO COUTINHO;
Matricula: 18/0019813;
Turma: A;
Atividade Extra 1 - Estrutura de Dados - UnB;
*/


#include "lista.h"
#include <stdio.h>

int main () {
    t_lista* sorvetes = aloca_lista();
    int a;
    a = inserir(0, 92837, "morango", 5.00, 100, sorvetes);
    if(a)
        printf("erro ao inserir morango\n");
    else
        printf("morango inserido\n");
    a = inserir(1, 12983, "chocolate", 4.00, 200, sorvetes);
    if(a)
        printf("erro ao inserir chocolate\n");
    else
        printf("chocolate inserido\n");
    a = inserir(2, 120837, "creme", 4.00, 50, sorvetes);
    if(a)
        printf("erro ao inserir creme\n");
    else
        printf("creme inserido\n");
    a = inserir(1, 3758, "abacaxi", 7.50, 75, sorvetes);
    if(a)
        printf("erro ao inserir abacaxi\n");
    else
        printf("abacaxi inserido\n");
    a = inserir(4, 129837, "napolitano", 5.00, 20, sorvetes);
    if(a)
        printf("erro ao inserir napolitano\n");
    else
        printf("napoliano inserido\n");
    a = inserir(6, 998374, "limao", 10.00, 15, sorvetes);
    if(a)
        printf("erro ao inserir limao\n");
    else
        printf("limao inserido\n");
    printf("\n");
    t_elemento* aux = sorvetes->primeiro;
    int count=0;
    while(aux!=NULL){
        printf("Posicao %d:\n", count);
        printf("Ha %d potes sabor %s(cod. %d), custando %.2f cada\n", aux->produto->quantidade, aux->produto->nome, aux->produto->codigo, aux->produto->preco);
        count++;
        aux = aux->proximo;
    }
    printf("\n");
    printf("ha %d produtos com codigo par\n", codigospares(sorvetes));
    printf("o preco medio entre todos os produtos eh: %.2f\n", precomedio(sorvetes));
    printf("o menor preco entre os produtos eh: %.2f\n", menorpreco(sorvetes));
    printf("o maior preco entre os produtos eh: %.2f\n", maiorpreco(sorvetes));
    printf("a posicao do produto que possui o maior preco eh: %d\n", posicaomaior(sorvetes));
    printf("o valor total de todos os produtos em estoque eh: %.2f\n", valortotal(sorvetes));
    printf("o produto que possui o cod 120837 eh o sorvete de %s\n", qualproduto(sorvetes, 120837)->nome);
    remove_lista(sorvetes);
    return 0;
}