#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *array, int left, int right);
void merge(int *array, int left, int right1, int right2);
int lessEquals(int a, int b);

int main(){

    int repetitions;
    int input[1000000];
    
    scanf("%d", &repetitions);

    while(repetitions != 0){
        for(int i = 0; i < repetitions; i++){
            scanf("%d", &input[i]);
        }

        mergeSort(input, 0, repetitions - 1);

        int bigger = 0;
        int incident = -1;

        int sentinel = 1;

        for ( int i = 1 ; i <= repetitions ; i++ ) {
        if ( i < repetitions && input[i] == input[i-sentinel] )
            sentinel++;
        else if ( sentinel > incident ) {
            bigger = input[i-1];
            incident = sentinel;
            }
        }

        printf("%d\n", bigger);
        scanf("%d", &repetitions);
    }
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

int lessEquals(int a, int b){
    return (a <= b);
}
