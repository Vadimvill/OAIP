#include <stdio.h>
#include "string.h"
#include "stdlib.h"
#include "struct.h"
void task(){
    int size = 0;
    struct Car* cars = NULL;
    int select = -1;
    int car = 0;
    int bool = 1;
    int index;
    while (bool){
        rewind(stdin);
        printf("Select option\n 1-Create array || 2-Init car || 3-Print cars || 4-Sort coast || 5-Sort max speed ||"
               "6-Delete car || 7-Init all cars || 8-Sort coast and speed || 9-Exit\n");
        select = setArraySize(select);
        switch (select) {
            case 1:
                printf("Set size\n");
                size = setArraySize(size);
                cars = createCarArray(size);
                break;
            case 2:
                printf("Set car\n");
                car = setArraySize(car);
                if(car > size) printf("Exeption\n");
                else cars[size-1] = initCar(cars[size-1]);
                break;
            case 3:
                printArrayStructs(cars,size);
                break;
            case 4:
                selectionSortCoast(cars,size);
                break;
            case 5:
                selectionSortMaxSpeed(cars,size);
                break;
            case 6:
                printf("Set index");
                index = setArraySize(index);
                deleteCar(cars,&size,index-1);
                break;
            case 7:
                cars = initAllCars(cars,size);
                break;
            case 8:
                selectionSortMaxSpeedandCoast(cars,size);
                break;
            case 9:
                bool = 0;
                break;
            default:
                printf("Exeption\n");
        }
        select = -1;
    }
    free(cars);
}
int main() {
    task();
    return 0;
}

