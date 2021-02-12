#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 10
#define MAX_NUM 100
#define MIN_NUM 0

void bubbleSort(int *array, int left, int right);
bool less(int a, int b);
void exch(int *a, int *b);
void cmpExch(int *a, int *b);


int main(){
    int array[LENGTH];
    for(int i=0; i<LENGTH; i++){
        array[i] = rand() % (MAX_NUM + 1 - MIN_NUM) + MIN_NUM;
    }

    bubbleSort(array, 0, LENGTH);

    for(int i=0; i<LENGTH; i++)
        printf("%d\n", array[i]);
    
    return 0;
}

void bubbleSort(int *array, int left, int right){

    for(int i = left + 1; i < right; i++)
        for(int j = left; j < right; j++)
            cmpExch(&array[j], &array[j+1]);
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
    if(less(*b, *a))
        exch(a, b);
}

