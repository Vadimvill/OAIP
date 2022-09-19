#include <stdio.h>

int main() {
    double PI = 1;
    int flag = 0;
    double a = 3;
    for(int i = 0;i<500;i++){
        double res = 1/a;
        if(flag == 0){
            PI -= res;
            a +=2;
            flag = 1;

        } else{
            PI += res;
            a +=2;
            flag = 0;
        }

    }
    PI = PI *4;
    printf("PI = %lf",PI);
    return 0;
}
