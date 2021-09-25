#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void mergeSort(int *array, int left, int right);
void merge(int *array, int left, int right1, int right2);
bool lessEquals(int a, int b);
int nmru(int *array, int left, int);
int binarySearch(int *array, int left, int right,int search);


int main(){
    int array[200000];
    int entrada = 0;
    int aux, i = 0;
    int iDoVetor = 1;
    int j = 0;
    int repetidos;

    scanf("%d", &entrada);

    scanf("%d", &array[0]);
    for(int i = 1; i<entrada; i++){
        scanf("%d",&aux);
        if(!binarySearch(array, 0, iDoVetor, aux)){
            array[iDoVetor] = aux;
            iDoVetor ++;
        }
    }

   if((iDoVetor%2) != 0){
        array[iDoVetor] = 1000000000;
        iDoVetor++;
    }

    mergeSort(array, 0, iDoVetor - 1);
    repetidos = nmru(array, 0, iDoVetor - 1);
    mergeSort(array, 0, (iDoVetor - 1) + (iDoVetor - 1)/2 - repetidos);

j = 0;

for(int j = 0; j < (iDoVetor + (iDoVetor)/2 - repetidos);){
    printf("%d ", array[j]);
    j = j + 3;
}

    printf("\n");

    printf("Elementos: %d\n", (iDoVetor + (iDoVetor)/2 - repetidos) - 1);

}

int nmru(int *array, int left, int right){
    int j = 1; 
    int aux;
    int repetidos = 0;

    for(int i = 0; i < (right + (right)/2); i++){
        aux = array[i] + array[i + 1];
         if(!binarySearch(array, 0, (right + j), aux)){
            array[right + j] = aux;
            repetidos ++;
            j++;
         }
            i++;
    }
    return repetidos;
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

bool lessEquals(int a, int b){
    if(a <= b)
        return true;
    else
        return false;
}