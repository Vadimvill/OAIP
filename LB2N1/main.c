#include <stdio.h>

int main() {
    float countOfPeople = 0;
    float countOfPeople3Ears = 0;
    float n = 0;
    int years = 0;
    int flag = 0;
    printf("Set count""\n");
    if(scanf("%f",&countOfPeople)&& countOfPeople >0){
        int a = (int) countOfPeople;
        if(countOfPeople/a != 1){
            printf("ERROR\n");

        }

    } else printf("ERROR\n");
    printf("Set n""\n");
    if(scanf("%f",&n)&& n >0){
        int a = (int) n;
        if(n/a != 1){
            printf("ERROR\n");
            flag = 1;
        } else {
            flag = 1;
        }

    } else printf("ERROR");
    countOfPeople3Ears = countOfPeople*3;
    while (flag == 1&& countOfPeople3Ears>=countOfPeople){

        countOfPeople = countOfPeople + countOfPeople/n;
        years++;

    }
    printf("Years = %d",years);



    return 0;
}
