#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Mapa
{
    unsigned int code;
    char string;    
}Mapa;

void mergeSort(Mapa *map, int left, int right);
void merge(Mapa *map, int left, int right1, int right2);
bool less(int a, int b);
int hashN(int n);

int main(int argc, char const *argv[])
{
    int i = 0;
    int vetorHash[1048583];
    char ignora;
    int c;
    int t;
    Mapa *map = malloc(10000000*sizeof(Mapa)); 

    while(scanf("%d",&c) == 1){
        int t = hashN(c);

        if(vetorHash[t] != c){
            vetorHash[hashN(c)] = c;
            map[i].code = c;
            scanf(" %c",&map[i].string);
            i++;
        }
        else
            scanf(" %c", &ignora);
    }  
        
    mergeSort(map, 0, i - 1);

    for (int j = 0; j < i; ++j)
        printf("%c",map[j].string);
           
    printf("\n");

    return 0;
}

int hashN(int n){
    return n % 1048583;
}

void mergeSort(Mapa *map, int left, int right){

    if(left>=right){
        return;
    }

    int mid = (left + right)/2;
    mergeSort(map,left,mid);
    mergeSort(map,mid + 1, right);
    merge(map,left,mid,right);
}

void merge(Mapa *map, int left, int right1, int right2){
    Mapa *aux = malloc(sizeof(Mapa)*(right2 - left + 1));
    int k = 0;
    int i = left;
    int j = right1 + 1;

    while(i <= right1 && j <= right2)
        
        if(map[i].code < map[j].code)
            aux[k++] = map[i++];
        else
            aux[k++] = map[j++];

    while(i <= right1)
        aux[k++] = map[i++];
    while(j <= right2)
        aux[k++] = map[j++];

    k = 0;
    for(int i = left; i <= right2; i++)
        map[i] = aux[k++];
    free(aux);
}


