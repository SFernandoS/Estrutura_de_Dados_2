#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Mapa
{
    unsigned int code;
    char string;    
}Mapa;

int separa(long int *v, int l, int r);
void quicksort(long int *v, int l, int r);
void quickselect (long int *v, int p, int l, int r);

int main(){
    
    int i = 0;
    Mapa *map = malloc(10000000*sizeof(Mapa)); 

      while(scanf("%d",&map[i].code) != EOF){
        scanf(" %c",&map[i].string);
        i++;
      }  
        
    mergeSort(map, 0, i - 1);

    printf("%c",map[0].string);
    for (int j = 1; j < i; ++j)
        if(map[j].code != map[j - 1].code)
            printf("%c",map[j].string);

    printf("\n");

    return 0;
}

int separa(long int *v, int l, int r){

    long int c = v[r];
    int j=l;
    
    for(int k = l;k<r;k++){
        if(lesseq (v[k],c)){
            exch(v[k],v[j]);
            j++;
        }

    }

    exch(v[j],v[r]);

    return j;
}

void quicksort(long int *v, int l, int r){

    int j;

    if(r<=l) return;

    cmpexch(v[(l+r)/2],v[r]);
        cmpexch(v[l],v[(l+r)/2]);
            cmpexch(v[r],v[(l+r)/2]);
        

    j=separa(v,l,r);

    quicksort(v,l,j-1);

    quicksort(v,j+1,r);

}

void quickselect (long int *v, int p, int l, int r){

    int j = separa(v,l,r);
    
    if (j==p){
        
        return;

    }
    
    if(j<p){
    
        quickselect(v,p,j+1,r);
        
    }else{

        quickselect(v,p,l,j-1);

    }
}