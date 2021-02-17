#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 10

bool binarySearch(int search, int *array, int left, int right);
bool normalSearch(int search,int *array,int left,int right);
bool less(int a, int b);
bool lessEquals(int a, int b);

int main(){
    int array[LENGTH] = {0 , 7, 9, 10, 11, 12, 13, 14, 15, 47};
    int search;

    for(int i = 0; i <LENGTH; i++)
        printf("%d\n", array[i]);

    while(scanf("%d", &search) != EOF)
        if(binarySearch(search, array, 0, LENGTH - 1))
            printf("true\n");
        else
            printf("false\n");
}

bool normalSearch(int search,int *array,int left,int right) {
    for(int i = left; i <= right; i++)
        if(array[i] == search)
            return true;
        return false;
  }

bool binarySearch(int search,int *array,int left,int right) {
    if(left >= right) return -1;

    int mid=(left+right)/2;

    if(less(array[mid], search))
        return normalSearch(search,array,mid+1,right);
    else if(lessEquals(array[mid], search))
        return true;
    else
        return normalSearch(search,array,left,mid-1);
}

bool less(int a, int b){
    return (a < b);
}

bool lessEquals(int a, int b){
    return (a <= b);
}









