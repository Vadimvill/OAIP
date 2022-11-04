#include <stdio.h>
#include "stdlib.h"
#include "array.h"
int main() {
    printf("Set Value of line");
    int countOfLine = setArraySize(0);
    int **array = malloc(sizeof (int*)*countOfLine);
    array = initializationArray(array,countOfLine);
    printArray(array,countOfLine);
    printf("Set k\n");
    int K = 0;
    K = setValue(0);
    array = dublicateK(array,K,countOfLine);
    printArray(array,countOfLine);
}
