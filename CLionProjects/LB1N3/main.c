#include <stdio.h>

int main() {
    double a = 0.00000000001, b = 0.00000000001,c = 0.00000000001;
    printf("Set values\n");
    if(scanf("%lf",&a)&&scanf("%lf",&b)&&scanf("%lf",&c)){
        int a1 = (int)a;
        int b1 = (int)b;
        int c1 = (int)c;
        if(a/a1 ==1 || a==0){
            printf("First value\n");
        }
        if(b/b1 ==1|| b==0){
            printf("Second value\n");
        }
        if(c/c1 ==1|| c==0){
            printf("Third value\n");
        }
    } else

        printf("ERROR");
    return 0;
}
