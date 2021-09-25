#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int separa(long int *v, int l, int r);
void quicksort(long int *v, int l, int r);
void quickselect (long int *v, int p, int l, int r);



int main(){

    long int *v;
    int o;
    int i = 0;
    int t;
    
    v = malloc(sizeof(long int)*(1000000));

    while (scanf("%d", &o)!= EOF)
    {
        if(o == 1){
            
            scanf("%ld", &v[i]);
            i++;
        
        }else if(o == 2){

            scanf("%d", &t);

            quickselect(v,t-1,0,i-1);
            
            quicksort(v,0,t-1);
            
            for (int j = 0; j < t; j++)
            {
                printf("%ld ", v[j]);
            }

            printf("\n");

        }
    
    } 

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