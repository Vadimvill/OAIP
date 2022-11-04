//
// Created by botme on 11/3/2022.
//
#include "stdlib.h"
#include "stdio.h"
#ifndef LB5N2_ARRAY_H
#define LB5N2_ARRAY_H
int setArraySize(int a);
int setValue(int a);
int length(int *array);
int** initializationArray(int** array,int countOfLine);
int* dublicateElement(int *array, int indexOfElement);
int maxOfArray(int *array);
int** dublicateK(int** array,int k,int countOfLine);
void printArray(int** array,int countOfLine);
#endif //LB5N2_ARRAY_H
int** dublicateK(int** array,int k,int countOfLine){
    for(int i = 0;i<countOfLine;i++){
        for(int j = 0;j< length(array[i]);){
            if(array[i][j]>k){
                array[i] = dublicateElement(array[i],j);
                j+=2;
            }
        }
    }
    return array;
}
void printArray(int** array,int countOfLine){
    for(int i = 0;i<countOfLine;i++){
        for(int j = 0;j< length(array[i]);j++){
            printf("%5d",array[i][j]);
        }
        printf("\n");
    }
}
int setArraySize(int a){
    while ((scanf("%d",&a)) !=1 || getchar() !='\n'){
        printf("Error\n");
        rewind(stdin);
    }
    if(a<=0){
        printf("Error\n");
        rewind(stdin);
        a = setArraySize(a);
    } else return a;
}
int** initializationArray(int** array,int countOfLine){
    for(int i = 0;i<countOfLine;i++)
    {
        array[i] = malloc(sizeof (int));
    }
    for(int i = 0;i< countOfLine;i++){
        printf("Set %d line,to finish typing, enter 0\n", i+1);
        int blocks = 1;
        while (1){
            array[i] = realloc(array[i],sizeof(int)* blocks);
            array[i][blocks-1] = setValue(0);
            if(array[i][blocks-1] == 0){
                break;
            }
            blocks++;
        }

    }
    return array;
}
int setValue(int a){
    while (scanf("%d",&a) !=1 || getchar() !='\n'){
        printf("Error\n");
        rewind(stdin);
    }
    if(a < 0){
        printf("error\n");
        a = setValue(a);
    }
    return a;
}
int length(int *array){
    int count = 0;
    int i = 0;
    while (1){
        if(array[i] == 0){
            break;
        }
        i++;
        count++;
    }
    return count;
}
int* dublicateElement(int *array, int indexOfElement){
    array = realloc(array,(length(array)+2)*sizeof (int));
    for(int i = length(array)+1;i>indexOfElement;i--){
        array[i] = array[i-1];
    }
    return array;
}
int maxOfArray(int *array){
    int max = array[0];
    for(int i = 0;i<length(array);i++){
        if(max < array[i]){
            max = array[i];
        }
    }
    return max;
}


