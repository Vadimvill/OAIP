//
// Created by botme on 11/3/2022.
//
int setArraySize(int a);
float setValue(float a);
void printArray(float *array,int *n);
void setArray(float *array,int *n);
void deleteValue(float *array,int *n);
void removeValueAt(float *array, int *n, int index);
#include "stdio.h"
#include "stdlib.h"
#ifndef LB5N1_ARRAY_H
#define LB5N1_ARRAY_H

int setArraySize(int a){
    printf("Set count of value");
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
void setArray(float *array,int *n){
    for(int i = 0;i<*n;i++){
        array[i] = setValue(array[i]);
    }
}
void printArray(float *array,int *n){
    for(int i = 0;i < *n;i++){
        printf("%f",array[i]);
        printf(" ");
    }
    printf("\n");
}
float setValue(float a){
    while (scanf("%f",&a) !=1 || getchar() !='\n'){
        printf("Error\n");
        rewind(stdin);
    }
    return a;
}
void deleteValue(float *array,int *n){
    for(int i = 0;i<*n;i++){
        for(int j = i;j<*n;j++){
            if(array[i] > array[j]){
                removeValueAt(array,n,j);
                j = i;
            }
        }
    }
    realloc(array,*n);
}
void removeValueAt(float *array, int *n, int index) {
    for (int i = index; i < *n; i++) {
        array[i] = array[i + 1];
    }
    (*n)--;
}

#endif //LB5N1_ARRAY_H
