#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LENGTH_MAX 64

void readArray(int *array, int *lengthArray);
void mergeSort(int *array, int left, int right);
void merge(int *array, int left, int right1, int right2);
bool lessEquals(int a, int b);

int main(){
    int array[LENGTH_MAX];
    int lengthArray = 0;

    for(int i = 0; i < 8; i++)
        readArray(array, &lengthArray);

    mergeSort(array, 0, lengthArray - 1);

    for(int i = 0; i < lengthArray; i++)
        printf("%d ", array[i]);

    printf("\n");
    return 0;
}

void readArray(int *array,int *lengthArray){
    int auxArray[8];
    int quantity;
    int j = 0;

    scanf("%d",&quantity);
    *lengthArray += quantity;

    for(int i = 0; i < quantity; i++)
        scanf("%d",&auxArray[i]);
    
    for(int i = (*lengthArray - quantity); i < *lengthArray; i++)
        array[i] = auxArray[j++];

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
}

bool lessEquals(int a, int b){
    if(a <= b)
        return true;
    else
        return false;
}



