#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10
#define MAX_NUM 100
#define MIN_NUM 0

void insertionSortH(int *array, int left, int right, int jump);
void shellSort(int *array, int left, int right);
int less(int interim, int stance);

int main(int argc, char const *argv[])
{
	int array[LENGTH];

    for(int i=0; i<LENGTH; i++){
        array[i] = rand() % (MAX_NUM + 1 - MIN_NUM) + MIN_NUM;
    }

    shellSort(array, 0, LENGTH - 1);

    printf("\n");
    
    for(int i=0; i<LENGTH; i++)
        printf("%d ", array[i]);

	printf("\n");

	return 0;
}

void insertionSortH(int *array, int left, int right, int jump){

	for (int i = left + jump; i <= right; i++)
	{
		int aux = i;
		int interim = array[i];

		while(aux >= left + jump && less(interim, array[aux-jump]))
			{
				array[aux] = array[aux - jump];
				aux -= jump;
			}
		array[aux] = interim;
	}
}

void shellSort(int *array, int left, int right){
	int jump;
	for (jump = 1 ; jump <= (right - left)/9; jump = 3 * jump + 1);
		
	for ( ;jump > 0; jump = jump/3)
		insertionSortH(array, left, right, jump);
}

int less(int interim, int stance){
	if (interim < stance) return 1;
	return 0;
}