#include <stdio.h>
#include "stdlib.h"
#include "array.h"
int main() {
    printf("Set count of row");
    int row = setArraySize(0);
    printf("Set count of row");
    int col = setArraySize(0);
    int **array = malloc(sizeof (int*) *row);
    array = initializationArray(array,col,row);
    printArray(array,col,row);
    array = findPoint(array,&col,&row);
    printArray(array,col,row);
    return 0;
}
