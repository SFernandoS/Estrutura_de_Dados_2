#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 10
#define MAX_NUM 100
#define MIN_NUM 0

void insertionSort(int *vetor, int left, int right);
bool less(int a, int b);
void exch(int *a, int *b);
void cmpExch(int *a, int *b);

int main(){
    int array[LENGTH];

    for(int i=0; i<LENGTH; i++){
        array[i] = rand() % (MAX_NUM + 1 - MIN_NUM) + MIN_NUM;
    }

    insertionSort(array, 0, LENGTH - 1);

    for(int i=0; i<LENGTH; i++)
        printf("%d\n", array[i]);
    
    return 0;
}

void insertionSort(int *array, int left, int right){
    int tmp, j;

    for(int i = right; i > left; i--)
        cmpExch(&array[i], &array[i - 1]);
     
    for(int i = left + 2; i<= right; i++){
        j = i; tmp = array[j];
        while(less(tmp, array[j - 1])){
            array[j] = array[j - 1]; j--;
        }
        array[j] = tmp;
    } 
}

bool less(int a, int b){
    return (a < b);
}

void exch(int *a, int *b){
    int aux = *b;
    *b = *a;
    *a = aux;
}

void cmpExch(int *a, int *b){
    if(less(*a, *b))
        exch(a, b);
}

