#include <stdio.h>
#include "String.h"
int main(int argc,char **argv) {
    printArray(argv,argc);
    char** newArgv = copy(argv,argc);
    insertSort(newArgv,argc);
    printf("\n");
    printArray(newArgv,argc);
    freeArray(newArgv,argc);
    int k = 0;
    scanf("%d",&k);
}
