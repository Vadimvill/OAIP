#include <stdio.h>
#include "stdlib.h"
#include "array.h"
int setArraySize(int a);
float setValue(float a);
void printArray(float *array,int *n);
void setArray(float *array,int *n);
void deleteValue(float *array,int *n);
void removeValueAt(float *array, int *n, int index);
int main() {
    int *n = malloc(sizeof(int));
    *n = setArraySize(0);
    float *array = malloc(sizeof(float) * *n);
    setArray(array,n);
    printArray(array,n);
    deleteValue(array,n);
    printArray(array,n);
}
