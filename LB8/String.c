#include "stdlib.h"
#include "stdio.h"
#include "String.h"
void printArray(char** str,int n){
    for(int i = 1;i<n;i++){
        printf("%s",str[i]);
        printf("\n");
    }
}
char** copy(char** argv,int args){
    char** newArgv = malloc(sizeof (char *) * args);
    for(int i = 0;i<args;i++){
        newArgv[i] = malloc(sizeof (char) * length(argv[i]));
        int j = 0;
        for(;j< length(argv[i])+1;j++){
            newArgv[i][j] = argv[i][j];
        }

    }
    return newArgv;
}
void freeArray(char** array,int args){
    for(int i = args-1;i>=0;i--){
        free(array[i]);
    }
    free(array);
}
int length(char* str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}
void insertSort(char** array,int n){
    for(int i = 2;i<n;i++){
        if(length(array[i]) > length(array[i-1])){
            for(int j = i;j>1;j--){
                if(length(array[j]) > length(array[j-1])){
                    char* p = array[j];
                    array[j] = array[j-1];
                    array[j-1] = p;
                }
            }
        }
    }
}
void insert(char** array,int n){
   int i = 1;
   int j = n-1;
    while (i!=j){
        char* p = array[j];
        array[j] = array[i];
        array[i] = p;
        i++;
        j--;
    }
}