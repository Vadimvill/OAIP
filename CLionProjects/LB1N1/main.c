#include <stdio.h>
#include <math.h>

int main() {
    float firstKatet = 0;
    float secondKatet = 0;
    float area = 0;float hypotynoze = 0;
    printf("Set first katet\n");
    if(scanf("%f",&firstKatet)&& firstKatet>0){
        printf("Set second katet\n");
        if(scanf("%f",&secondKatet)&& secondKatet > 0){
            hypotynoze = sqrtf(firstKatet*firstKatet + secondKatet*secondKatet);
            area = (firstKatet*secondKatet)/2;
            printf("hyp=%.2f\n",hypotynoze);
            printf("area = %.2f",area);
        } else{
            printf("ERROR");
        }
    } else
    {
        printf("ERROR");
    }
}
