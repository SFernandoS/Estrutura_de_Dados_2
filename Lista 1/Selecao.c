#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 10
#define MAX_NUM 100
#define MIN_NUM 0

void selectionSort(int *array, int left, int right);
bool less(int a, int b);
void exch(int *a, int *b);


int main(){
    int array [1001];
    int i = 0;

    
    while(scanf("%d", &array[i]) != EOF){
        i++;
    }

    selectionSort(array, 0, i);

    for(int j = 0; j < i; j++)
        printf("%d ", array[j]);
    printf("\n");
    
    return 0;
}

void selectionSort(int *array, int left, int right){
    int min;

    for(int i = left; i< right; i++){
        min = i;
        for(int j = i + 1; j < right; j++){
            if(less(array[j],array[min]))
                min = j;
        }
        exch(&array[min], &array[i]);
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
