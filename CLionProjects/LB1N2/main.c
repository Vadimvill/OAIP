#include <stdio.h>


int main() {

    float number[] = {-1,-1,-1,-1,-1,-1};
    int sum1 = 0;
    int sum2 = 0;
    printf("Set number");
    int boolean = 1;
    for(int i = 0;i<6;i++){
        scanf("%f",&number[i]);
        float a = (int) number[i];
        if(number[i] == 0){

        }
        else
        {
            if(number[i]/a !=1 || number[i]<0 || number[i] > 9){
                printf("ERROR");
                boolean = 0;
                break;
            }
        }

    }
    if(boolean == 1){
        for(int i =0;i<3;i++){
            sum1+=number[i];
        }
        for(int i =3;i<6;i++){
            sum2+=number[i];
        }
        if(sum1 == sum2){
            printf("You lucky");
        } else{
            printf("You unlucky");
        }

    } else{

    }


    return 0;
}


