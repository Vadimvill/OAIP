#include <stdio.h>

int main() {
    float arrayFloat[100];

    printf("Set length of array\n");
    int n = 0;
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
    int count = 0;
    for(int i = 0;i<n;i++){
        int boolean = 1;
        for(int j = i+1;j<n;j++){
            if(arrayFloat[i] == arrayFloat[j]){
                boolean = 0;
                break;
            }

        }
        if(boolean == 1){
            count++;
        }
    }
    printf("Count = %d",count);
}
