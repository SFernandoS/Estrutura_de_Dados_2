#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void mergeSort(int *array, int left, int right);
void merge(int *array, int left, int right1, int right2);
void intercala1 (int p, int q, int r, int *v);
void intercala(int *aux, int *arrayA, int *arrayB, int rightA, int rightB);
bool lessEquals(int a, int b);

int main(){

    int oneOrTwo;
    int countPlates = 0;
    int rightPlates = 0;
    int first = 1;
    int quantity;
    int *aux, *plates, *aux2;
  
    plates = (int *)malloc(sizeof(int)*(110));
    aux2 = (int *)malloc(sizeof(int)*(110));
    aux = (int *)malloc(sizeof(int)*(1000000));

    while(scanf("%d", &oneOrTwo) != EOF)
    {
        
        if (oneOrTwo == 1)
        {
            scanf(" %d", &aux[countPlates]);
            countPlates++;           
        }
        else
        {
            if (first)
            {
                mergeSort(aux, 0, countPlates - 1);
                plates = aux;
                first = 0;
            }
            else{
                mergeSort(aux, 0, countPlates - 1);
                intercala(aux2, aux, plates, countPlates - 1, rightPlates -1);
                plates = aux2;
            }

            rightPlates += countPlates; 
            countPlates = 0;

            aux = (int *)malloc(sizeof(int)*(1000000));
            aux2 = (int *)malloc(sizeof(int)*(110));

            scanf("%d", &quantity);

            for (int i = 0; i < quantity; i++)
            {
                printf("%d ", plates[i]);
            }
            printf("\n");
        }
    }

    return 0;
}

void mergeSort(int *array, int left, int right){

    if(left>=right){
        return;
    }

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

    while(i <= right1 && j <= right2 && k < 100)
        if(lessEquals(array[i], array[j]))
            aux[k++] = array[i++];
        else
            aux[k++] = array[j++];

    while(i <= right1 && k < 100)
        aux[k++] = array[i++];
    while(j <= right2 && k < 100)
        aux[k++] = array[j++];

    k = 0;
    for(int i = left; i <= right2; i++)
        array[i] = aux[k++];
    free(aux);
}

void intercala(int *aux, int *arrayA, int *arrayB, int rightA, int rightB){
    int leftAux = 0, leftA = 0, leftB = 0;
    int iA = 0, iB = 0, iAux = 0;
    int righAux = 0;

    while(iA <= rightA && iB <= rightB)
    {
        if(iAux > 100)
            break;
        if(lessEquals(arrayA[iA],arrayB[iB]))
            {aux[iAux] = arrayA[iA]; iAux++; iA++;}
        else
            {aux[iAux] = arrayB[iB]; iAux++;iB++; }
   }

   while(iA <= rightA){
        aux[iAux++] = arrayA[iA++];
        if(iAux > 100)
            break;
   }
    while(iB <= rightB){
        aux[iAux++] = arrayB[iB++];
        if(iAux > 100)
            break;
    }

    free(arrayA);
    free(arrayB);
}

bool lessEquals(int a, int b){
    if(a <= b)
        return true;
    else
        return false;
}
