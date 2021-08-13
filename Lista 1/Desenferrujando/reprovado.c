#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){ 
    char name[21], disapprovedName[21] ;
    int problemsSolved, disapprovedProblems, instances, instanceDisapproved = 0;

    scanf("%d",&instances);
    scanf(" %s %d", disapprovedName, &disapprovedProblems);

    for(int i = 1; i < instances; i++){
        scanf(" %s %d", name, &problemsSolved);
        if(problemsSolved < disapprovedProblems){
            strcpy(disapprovedName, name);
            disapprovedProblems = problemsSolved;
            instanceDisapproved = i;
        }
        else if(problemsSolved == disapprovedProblems){
            if(strcmp(name, disapprovedName) > 0){
                strcpy(disapprovedName, name);
                disapprovedProblems = problemsSolved;
                instanceDisapproved = i;
            }
        }
    }

    printf("Instancia %d \n", instanceDisapproved);
    printf("%s \n", disapprovedName);
}