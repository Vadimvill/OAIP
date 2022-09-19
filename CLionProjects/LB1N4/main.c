#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Rus");
    char line [10];
    char winter [10] = {'W','i','n','t','e','r'};
    char spring[10] = {'S','p','r','i','n','g'};
    char summer[10] = {'S','u','m','m','e','r'};
    char autumn[10] = {'A','u','t','u','m','n'};
    int boolean = 1;
    int flag = 1;
    while (1==1){
        printf("Chose (Winter,Spring,Summer,Autumn)\n");
        scanf("%s",&line);
        for(int i = 0;i<7;i++){
            if(line[i]==winter[i]){

            } else{
                boolean = 0;
                break;
            }
        }
        if(boolean == 1){
            flag = 0;
            printf("December\nJanuary\nFebruary\n");
        }
        boolean = 1;
        for(int i = 0;i<7;i++){
            if(line[i]==spring[i]){

            } else{
                boolean = 0;
                break;
            }
        }
        if(boolean == 1){
            flag = 0;
            printf("March\nApril\nMay\n");
        }
        boolean = 1;
        for(int i = 0;i<7;i++){
            if(line[i]==summer[i]){

            } else{
                boolean = 0;
                break;
            }
        }
        if(boolean == 1){
            flag = 0;
            printf("June\nJuly\nAugust\n");
        }
        boolean = 1;
        for(int i = 0;i<7;i++){
            if(line[i]==autumn[i]){

            } else{
                boolean = 0;
                break;
            }
        }
        if(boolean == 1){
            flag = 0;
            printf("September\nOctober\nNovember\n");
        }
        if(flag == 1){
            printf("ERROR,try again\n");
        }
        boolean = 1;
        flag = 1;

    }

}
