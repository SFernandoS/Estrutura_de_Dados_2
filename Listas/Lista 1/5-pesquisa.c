#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Mapa
{
	int code;
	char string[16];	
}Mapa;

void insertionSort(Mapa *array, int left, int right);
int binarySearch(int search, Mapa *map, int left, int right);
bool less(int a, int b);
bool lessMap(Mapa a, Mapa b);
bool lessEquals(int a, int b);
void exch(Mapa *a, Mapa *b);
void cmpExch(Mapa *a, Mapa *b);

int main(int argc, char const *argv[])
{
	int lines, search;
	int aux;

	scanf("%d",&lines);

	Mapa *map = malloc(lines*sizeof(Mapa)); 

	for (int i = 0; i < lines; i++){
		scanf("%d",&map[i].code);
		scanf(" %s",map[i].string);
	}

	insertionSort(map, 0, lines - 1);

	while(scanf("%d", &search) != EOF){
		//aux = binarySearch(search,map, 0, lines-1);
        aux = 0;
		if(aux == - 1){
			printf("undefined\n");
		}else{
			printf("%s\n", map[aux].string);		
		}
	}
	return 0;
}

void insertionSort(Mapa *map, int left, int right){
 int j;
 Mapa tmp;

    for(int i = right; i > left; i--)
        cmpExch(&map[i], &map[i - 1]);
     
    for(int i = left + 2; i<= right; i++){

        j = i; tmp = map[j];

        while(less(tmp.code, map[j - 1].code)){

            map[j] = map[j - 1]; j--;
        }
        map[j] = tmp;
    }
}


void exch(Mapa *a, Mapa *b){
    Mapa aux = *b;
    *b = *a;
    *a = aux;
}

void cmpExch(Mapa *a, Mapa *b){
    if(lessMap(*a, *b))
        exch(a, b);
}

int normalSearch(int search,Mapa *map,int left,int right) {
    for(int i = left; i <= right; i++)
        if(map[i].code == search)
            return i;
        return -1;
  }

int binarySearch(int search,Mapa *map,int left,int right) {
    if(left >= right) return -1;
    
    int mid=(left+right)/2;

    if(less(map[mid].code, search))
        return normalSearch(search,map,mid+1,right);
    else if(lessEquals(map[mid].code, search))
        return mid;
    else
        return normalSearch(search,map,left,mid-1);
}

bool lessMap(Mapa a, Mapa b){
    return (a.code < b.code);
}

bool less(int a, int b){
    return (a < b);
}

bool lessEquals(int a, int b){
    return (a <= b);
}

