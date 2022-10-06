#include <stdio.h>

float maxOfArray(float arrayOfFloat[],int n);
float Sum(float arrayOfFloat[],int n);
int main() {
    float arrayFloat[100];
    printf("Set length of array\n");
    int n = 0;
    if(scanf("%d",&n)&& n>0 && n<100){

        for(int i = 0;i<n;i++){
            printf("Set value %d\n",i);
            if(scanf("%f",&arrayFloat[i])){

            } else
            {
                printf("ERROR");
                return 0;
            }
        }
    }
    else{
        printf("ERROR");
    }
    float max = maxOfArray(arrayFloat,n);
    printf("max = %f",max);
    float sum = Sum(arrayFloat,n);
    printf("sum = %f",sum);

    return 0;
}

float maxOfArray(float arrayOfFloat[],int n){
    float max = arrayOfFloat[0];
    for(int i = 0;i<n;i++){
        if(max < arrayOfFloat[i]){
            max = arrayOfFloat[i];
        }
    }
    return max;
}
float Sum(float arrayOfFloat[],int n){
    float sum = 0;
    int boolean = 1;
    for(int i = 0;i<n;i++){
        if(arrayOfFloat[i]>0){
            for(int j = i+1;j<n;j++){
                if(arrayOfFloat[j]<0){
                    sum+=arrayOfFloat[j];
                } else
                {
                    boolean = 0;
                    break;
                }
            }
            break;
        }
    }
    if(boolean == 1){
        sum = 0;
    }
    return sum;
}
