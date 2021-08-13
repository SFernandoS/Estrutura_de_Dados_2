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

void mergeSort(int *array, int left, int right);
void merge(int *array, int left, int right1, int right2);
int binarySearch(int *array, int left, int right,int search);
int lessEquals(int a, int b);

int main(){
    int quantidade;
    int *numerosProibidos;
    int entrada;

    scanf("%d",&quantidade);
    numerosProibidos =(int*)malloc(quantidade*sizeof(int));

    for(int i=0; i<quantidade; i++)
        scanf("%d",&numerosProibidos[i]);

    mergeSort(numerosProibidos, 0, quantidade - 1);

    while(scanf("%d",&entrada) != EOF){
        if(binarySearch(numerosProibidos, 0, quantidade - 1, entrada))
            printf("sim\n");
        else
            printf("nao\n");
    }
    
    free(numerosProibidos);
    return 0;
}

void mergeSort(int *array, int left, int right){
    if(left>=right)
        return;

    int mid = (left + right)/2;
    mergeSort(array,left,mid);
    mergeSort(array,mid + 1, right);
    merge(array,left,mid,right);
}

void merge(int *array, int left, int right1, int right2){
    int *aux = malloc(sizeof(int)*(right2 - left + 1));
    int k = 0;
    int i = left;
    int j = right1 + 1;

    while(i <= right1 && j <= right2)
        if(lessEquals(array[i], array[j]))
            aux[k++] = array[i++];
        else
            aux[k++] = array[j++];

    while(i <= right1)
        aux[k++] = array[i++];
    while(j <= right2)
        aux[k++] = array[j++];
    k = 0;
    for(int i = left; i <= right2; i++)
        array[i] = aux[k++];
    
    free(aux);
}

int binarySearch(int *array, int left, int right, int search) 
{ 
    while (left <= right) { 
        int mid = left + (right - left) / 2;  
        if (array[mid] == search) 
            return 1; 
  
        if (array[mid] < search) 
            left = mid + 1; 
        else
            right = mid - 1; 
    } 
  
    return 0; 
} 

int lessEquals(int a, int b){
    return (a <= b);
}
