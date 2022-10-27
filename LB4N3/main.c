#include <stdio.h>
#include "stdlib.h"
#include "time.h"
int maxOfArray(int arrayOfFloat[],int n);
float SetValue(float a);
int RandomSetArray(int array[100][100],int col,int row);
int SetArray(int array[100][100],int col,int row);
void PrintArray(int array[100][100],int col,int row);
void xFunction(int array[100][100],int col,int row);
float SetArraySize(float a);
int ChooseSetArray(int array[100][100],int col,int row);
int main() {
    int col = 0;
    int row = 0;
    int array[100][100];
    printf("Set count of row\n");
    row = SetArraySize(row);
    col = row;
    array[100][100] = ChooseSetArray(array,col,row);
    PrintArray(array,col,row);
    xFunction(array,col,row);
}
int maxOfArray(int arrayOfFloat[],int n){
    int max = arrayOfFloat[0];
    for(int i = 0;i<n;i++){
        if(max < arrayOfFloat[i]){
            max = arrayOfFloat[i];
        }
    }
    return max;
}
float SetValue(float a){
    while (scanf("%f",&a) !=1 || getchar() !='\n'){
        printf("Error\n");
        rewind(stdin);
    }
    return a;
}
int SetArray(int array[100][100],int col,int row){
    for(int i = 0;i < row;i++){
        printf("Set %d line\n",i+1);
        for(int j = 0;j<col;j++){
            array[i][j] = SetValue(array[i][j]);
        }
    }
    return array[100][100];
}
void PrintArray(int array[100][100],int col,int row){
    for(int i = 0;i < row;i++){
        for(int j = 0;j<col;j++){
            printf("%d",array[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}
void xFunction(int array[100][100],int col,int row){
    int arrayOfValue[100];
    float x = col;
    int valueOfLine = x/2+0.5;
    int n = 0;
    int b = 0;
    for(int i = 0;i<valueOfLine;i++){
        for(int j = b;j<x;j++){
            arrayOfValue[n] = array[i][j];
            n++;
        }
        b++;
        x--;
    }
    printf("%d", maxOfArray(arrayOfValue,n));
}
float SetArraySize(float a){
    while ((scanf("%f",&a)) !=1 || getchar() !='\n'){
        printf("Error\n");
        rewind(stdin);
    }
    if(a>99 || a<=0){
        printf("Error\n");
        rewind(stdin);
        a = SetArraySize(a);
    } else return a;
}
int ChooseSetArray(int array[100][100],int col,int row){
    while (2!=1){
        char line[2];
        printf("random(1) or not-random(2)\n");
        scanf("%s",&line);
        if(line[0] == '1'){
            array[100][100] = RandomSetArray(array,col,row);
            return array[100][100];
        } else if(line[0] == '2'){
            array[100][100] = SetArray(array,col,row);
            return array[100][100];
        } else printf("Error\n");

    }
}
int RandomSetArray(int array[100][100],int col,int row){
    srand(time(NULL));
    for(int i = 0;i < row;i++){
        for(int j = 0;j<col;j++){
            array[i][j] = rand() % 101 - 27;
        }
    }
    return array[100][100];

}
