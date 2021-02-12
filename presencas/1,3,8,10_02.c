/*
Entrada
A entrada é composta por um único caso teste que possui diversas linhas.
A primeira linha possui um número N ( 1 ≤ N ≤ 140000 ) que representa a quantidade de números proibidos existentes.
A segunda linha do caso de teste possui N números Pi ( 0 ≤ Pi ≤ 231 ) representando os números proibidos.
Depois existirão diversas linhas contendo um único número que se quer saber se é proibido ou não.
A entrada termina em EOF.

Saída
Para cada número da consulta deve-se imprimir uma única linha contendo a palavra sim se o número for proibido,
ou nao caso o número não seja proibido.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int quantidade;
    int *numerosProibidos;
    int entrada;
    bool verifica;

    scanf("%d",&quantidade);
    numerosProibidos =(int*)malloc(quantidade*sizeof(int));

    for(int i=0; i<quantidade; i++)
        scanf("%d",&numerosProibidos[i]);

    while(scanf("%d",&entrada) != EOF){
        for(int i=0; i < quantidade; i++){
            if(numerosProibidos[i] == entrada){
                verifica = true;
                break;
            }
            printf("ola");
        }

        if(verifica == true)
            printf("sim\n");
        else
            printf("nao\n");
        verifica = false;
    }

    return 0;
}