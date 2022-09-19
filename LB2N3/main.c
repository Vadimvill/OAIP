#include <stdio.h>

int main() {
    printf("Set values\n");
    int a = 0,b = 0;
    int boolean = 0;
    if(scanf("%d",&a)&& a>0){
        boolean++;
    } else printf("ERROR");
    if(scanf("%d",&b)&& b>0){
        boolean++;
    } else printf("ERROR");
    if(boolean == 2){
        while (a !=0&&b!=0){
            if(a > b){
                a = a%b;
            }
            else b = b%a;
        }
        int result = a+b;
        printf("%d",result);
    }

    return 0;
}
