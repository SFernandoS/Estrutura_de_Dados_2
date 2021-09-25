#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void insertionSortSimple(int *array, int left, int right);
bool less(int a, int b);
void exch(int *a, int *b);
void cmpExch(int *a, int *b);

int main(){
    int array [1001];
    int i = 0;

    
    while(scanf("%d", &array[i]) != EOF){
        i++;
    }
    i--;

    insertionSortSimple(array, 0, i);

    for(int j = 0; j <= i; j++)
        printf("%d ", array[j]);
    printf("\n");
}

void insertionSortSimple(int *array, int left, int right){

    for(int i= left + 1; i <= right; i++)
        for(int j = i; j > left; j--)
            cmpExch(&array[j],&array[j-1]);
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

