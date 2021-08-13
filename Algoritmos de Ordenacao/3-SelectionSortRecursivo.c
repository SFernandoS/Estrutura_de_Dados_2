#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 10
#define MAX_NUM 100
#define MIN_NUM 0

void selectionSortRecursivo(int *array, int left, int right);
bool less(int a, int b);
void exch(int *a, int *b);


int main(){
    int array[LENGTH];
    for(int i=0; i<LENGTH; i++){
        array[i] = rand() % (MAX_NUM + 1 - MIN_NUM) + MIN_NUM;
    }

    selectionSortRecursivo(array, 0, LENGTH);

    for(int i=0; i<LENGTH; i++)
        printf("%d\n", array[i]);
    
    return 0;
}

void selectionSortRecursivo(int *array, int left, int right){
    if(left == right)
        return;

    int min = left;
    for(int j = left + 1; j < right; j++){
        if(less(array[j],array[min]))
            min = j;
    }

    exch(&array[min], &array[left]);
    selectionSortRecursivo(array, left + 1, right);
}

bool less(int a, int b){
    return (a < b);
}

void exch(int *a, int *b){
    int aux = *b;
    *b = *a;
    *a = aux;
}

