
#include "stdlib.h"
#include "stdio.h"
int setArraySize(int a);
int setValue(int a);
void printArray(int** array,int col,int row);
int** initializationArray(int** array,int col,int row);
int** findPoint(int **array,int *col,int *row);
int** del(int** array,int *col,int *row,int i,int j);
#ifndef LB5N3_ARRAY_H
#define LB5N3_ARRAY_H
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
int** initializationArray(int** array,int col,int row){
    for(int i = 0;i<row;i++)
    {
        array[i] = malloc(sizeof (int) * col);
        for(int j = 0;j<col;j++){
            array[i][j] = setValue(0);
        }
    }
    return array;
}
int setValue(int a){
    while (scanf("%d",&a) !=1 || getchar() !='\n'){
        printf("Error\n");
        rewind(stdin);
    }
    return a;
}
void printArray(int** array,int col,int row){
    for(int i = 0;i<row;i++){
        for(int j = 0;j< col;j++){
            printf("%5d",array[i][j]);
        }
        printf("\n");
    }
}
int** findPoint(int **array,int *col,int *row){
    for(int i = 0;i<*col;i++){
        int countOfMin = 0;
        int countOfMax = 0;
        int min = array[0][i];
        int rowInd = 0;
        for(int j = 0;j<*row;j++){
            if(array[j][i] < min){
                min = array[j][i];
                rowInd = j;
                countOfMin = 0;
            } else if(array[j][i] == min){
                countOfMin++;
            }
        }
        int max = array[rowInd][0];
        for(int b = 0;b<*col;b++){
            if(array[rowInd][b] > max){
                max = array[rowInd][b];
                countOfMax = 0;
            } else if(array[rowInd][b] == max){
                countOfMax++;
            }
        }
        if(max == min && countOfMax <2 && countOfMin <2){
            array = del(array,col,row,i,rowInd);
            return array;
        }
    }
    return array;
}


int** del(int** array,int *col,int *row,int i,int j){
    for(int a = 0;a<*row;a++){
        for(int b = i;b<(*col);b++){
            array[a][b] = array[a][b+1];
        }
    }
    for(int a = 0;a<(*col);a++){
        for(int b = j;b<(*row)-1;b++){
            array[b][a] = array[b+1][a];
        }
    }
    for(int i = 0;i<(*row);i++){
        array[i] = realloc(array[i],sizeof(int) * ((*row)-1));
    }
    (*col)--;
    array = realloc(array,sizeof(int*) * ((*row)-1));
    (*row)--;
    return array;
}




#endif //LB5N3_ARRAY_H
