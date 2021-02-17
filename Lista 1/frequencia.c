# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

void insertionSort(int *array, int left, int right);
bool less(int a, int b);
void exch(int *a, int *b);
void cmpExch(int *a, int *b);
int countsNumberStudents(int *students, int number);

int main(){
    int number;
    int *students;

    scanf("%d",&number);
    students = malloc(number*sizeof(int));

    for(int i = 0; i < number; i++)
        scanf("%d",&students[i]);

    insertionSort(students, 0, number - 1);
    printf("%d \n", countsNumberStudents(students, number));

}
 int countsNumberStudents(int *students, int number){
     int count = 1;

    for(int i = 1; i < number; i++){
        if(students[i] != students[i -1])
            count++;
    }
    return count;
 }

void insertionSort(int *array, int left, int right){
 int tmp, j;

    for(int i = right; i > left; i--)
        cmpExch(&array[i], &array[i - 1]);
     
    for(int i = left + 2; i<= right; i++){
        j = i; tmp = array[j];
        while(less(tmp, array[j - 1])){
            array[j] = array[j - 1]; j--;
        }
        array[j] = tmp;
    }
}


bool less(int a, int b){
    return (a < b);
}

void exch(int *a, int *b){
    int aux = *b;
    *b = *a;
    *a = aux;
}

void cmpExch(int *a, int *b){
    if(less(*a, *b))
        exch(a, b);
}

