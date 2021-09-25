#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void mergeSort(int *array, int right);
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
    aux = (int *)malloc(sizeof(int)*(100000));

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
                mergeSort(aux, countPlates - 1);
                plates = aux;
                first = 0;
            }
            else{
                mergeSort(aux, countPlates - 1);
                intercala(aux2, aux, plates, countPlates - 1, rightPlates -1);
                plates = aux2;
            }

            rightPlates += countPlates; 
            countPlates = 0;

            aux = malloc(sizeof(int)*(100000));

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

void mergeSort(int *v, int n)
{
   int b = 1;
   while (b < n && b < 100) {
      int p = 0;
      while (p + b < n && p + b < 100) {
         int r = p + 2*b;
         if (r > n) r = n;
         intercala1(p, p+b, r, v);
         p = p + 2*b; 
      }
      b = 2*b;
   }
}

void intercala(int *aux, int *arrayA, int *arrayB, int rightA, int rightB){
    aux = (int *) malloc(sizeof(int)*(110));
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
    free(aux);
}

void intercala1 (int p, int q, int r, int *v) 
{
   int *w;                                 
   w = malloc ((110) * sizeof (int));     
   int i = p, j = q;                       
   int k = 0;                              

   while (i < q && j < r) {  
        if(k > 100)
            break;
      if (v[i] <= v[j])  w[k++] = v[i++];  
      else  w[k++] = v[j++];               
   }                                       
   while (i < q){
        if(k > 100)
            break;
        w[k++] = v[i++];
    }         
   while (j < r){
        if(k > 100)
            break;
        w[k++] = v[j++];
   }         
   for (i = p; i < r; ++i)  v[i] = w[i-p];
   free (w);                              
}

bool lessEquals(int a, int b){
    if(a <= b)
        return true;
    else
        return false;
}
