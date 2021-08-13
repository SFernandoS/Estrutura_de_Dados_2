#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void insertionSort(int *array, int left, int right);
bool less(int a, int b);
void exch(int *a, int *b);
void cmpExch(int *a, int *b);

int main(){
    int array [50001];
    int i = 0;

    
    while(scanf("%d", &array[i]) != EOF){
        i++;
    }
    i--;

    insertionSort(array, 0, i);

    for(int j = 0; j <= i; j++)
        printf("%d ", array[j]);
    printf("\n");
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

