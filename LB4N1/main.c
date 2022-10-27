#include <stdio.h>
#include "stdlib.h"
#include "time.h"
float SetValue(float a);
int SetArray(int array[100][100],int row,int col);
void PrintArray(int array[100][100],int col,int row);
int countNullRow(int array[100][100],int col,int row);
int ChooseSetArray(int array[100][100],int col,int row);
int RandomSetArray(int array[100][100],int col,int row);
float SetArraySize(float a);
int main() {
    int col = 0;
    int row = 0;
    int count = 0;
    int array[100][100];
    printf("Set count of row\n");
    row = SetArraySize(row);
    printf("Set count of col\n");
    col = SetArraySize(col);
    array[100][100] = ChooseSetArray(array,col,row);
    PrintArray(array,col,row);
    printf("Count = %d", countNullRow(array,col,row));
}
float SetValue(float a){
    while (scanf("%f",&a) !=1 || getchar() !='\n'){
        printf("Error\n");
        rewind(stdin);
    }
    return a;
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
int countNullRow(int array[100][100],int col,int row){
    int count = 0;
    for(int i = 0;i<col;i++){
        int boolean = 0;
        for(int j = 0;j<row;j++){
            if(array[j][i] == 0){
                boolean = 1;
                break;
            }
        }
        if(boolean){

        } else count++;
    }
    return count;
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
            array[i][j] = rand() % 6 - 5;
        }
    }
    return array[100][100];
}

