#include <stdio.h>

int main() {
    float arrayFloat[100];
    float arrayFloatCH[100];

    printf("Set length of array\n");
    int n = 0;
    int k = 1;
    if(scanf("%d",&n) && n>0 && n<100){

    } else{
        printf("ERROR");
        return 0;
    }
    printf("Set values of array\n");
    for(int i = 0;i<n;i++){
        if(scanf("%f",&arrayFloat[i])){

        } else{
            printf("ERROR");
            return 0;
        }
    }
    arrayFloatCH[0] = arrayFloat[0];

    for(int i = 0;i<n;i++){
        int boolean = 1;
       for(int j = 0;j<k;j++){
           if(arrayFloat[i] == arrayFloatCH[j]){
               boolean = 0;
               break;
           }
       }
       if(boolean){
           arrayFloatCH[k] = arrayFloat[i];
           k++;
       }
    }
    for(int i = 0;i<k;i++){
        arrayFloat[i] = arrayFloatCH[i];
    }
    n = k;
    for(int i = 0;i<n;i++){
        printf("%f\n",arrayFloat[i]);
    }


    return 0;
}

