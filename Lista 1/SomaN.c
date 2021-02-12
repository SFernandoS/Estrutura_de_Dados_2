#include <stdio.h>
#include <stdlib.h>

int main(){
    int repetitions,input, sun = 0;

    scanf("%d",&repetitions);

    for(int i=0; i < repetitions; i++){
        scanf("%d",&input);
        sun += input;
    }

    printf("%d\n", sun);
    return 0;
}