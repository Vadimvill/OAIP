#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "string.h"
struct Car* createCarArray(int size) {
    struct Car* array = malloc(sizeof(struct Car) * size);
    return array;
}
static char* colors[] = {
        "green",
        "red",
        "black",
};
void deleteCar(struct Car* cars, int* size, int index) {
    if (index < 0 || index >= *size) {
        printf("Error\n");
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        cars[i] = cars[i + 1];
    }
    printf("%d", (*size)-1);
    free(cars[(*size) - 1].name);
    (*size)--;
    realloc(cars, sizeof(struct Car) * *size);
}
void printArrayStructs(struct Car* cars, int size) {
    int bool = 0;
    for (int i = 0;i < size;i++) {
        if (cars->init == 0) {
            bool = 0;
            printf("Init all cars\n");
            break;
        }
        bool = 1;
    }
    if (bool) {
        for (int i = 0;i < size;i++) {
            printf("%d.", i + 1);
            printf("coast is : %d, ", cars[i].coast);
            printf("max speed is : %f, ", cars[i].maxSpeed);
            printf("color is : %s, ", colors[cars->color]);
            printf("name is : %s\n", cars[i].name);
        }
    }
}
void selectionSortCoast(struct Car* cars, int n) {
    int end = n - 1;
    for (int i = 0;i < n;i++) {
        int maxInd = 0;
        for (int j = 0;j <= end;j++) {
            if (cars[maxInd].coast <= cars[j].coast) {
                maxInd = j;
            }
        }
        struct Car temp = cars[maxInd];
        cars[maxInd] = cars[end];
        cars[end] = temp;
        end--;
    }
}
void selectionSortMaxSpeed(struct Car* cars, int n) {
    int end = n - 1;
    for (int i = 0;i < n;i++) {
        int maxInd = 0;
        for (int j = 0;j <= end;j++) {
            if (cars[maxInd].maxSpeed <= cars[j].maxSpeed) {
                maxInd = j;
            }
        }
        struct Car temp = cars[maxInd];
        cars[maxInd] = cars[end];
        cars[end] = temp;
        end--;
    }
}
int setArraySize(int a) {
    while ((scanf_s("%d", &a)) != 1 || getchar() != '\n') {
        printf("Error\n");
        rewind(stdin);
    }
    if (a <= 0) {
        printf("Error\n");
        rewind(stdin);
        a = setArraySize(a);
        return a;
    }
    else return a;
}
void selectionSortMaxSpeedandCoast(struct Car* cars, int n) {
    int end = n - 1;
    for (int i = 0;i < n;i++) {
        int maxInd = 0;
        for (int j = 0;j <= end;j++) {
            if (cars[maxInd].maxSpeed < cars[j].maxSpeed) {
                maxInd = j;
            }
            else if (cars[maxInd].maxSpeed == cars[j].maxSpeed) {
                if (cars[maxInd].coast <= cars[j].coast) maxInd = j;
            }
        }
        struct Car temp = cars[maxInd];
        cars[maxInd] = cars[end];
        cars[end] = temp;
        end--;
        maxInd = 0;
    }
}
struct Car initCar(struct Car car) {
    printf("Set coast\n");
    int newCoast = 0;
    newCoast = setArraySize(newCoast);
    rewind(stdin);
    car.coast = newCoast;
    printf("Set name\n");
    char* str = malloc(sizeof(char) * 255);
    fgets(str, 255, stdin);
    car.name = str;
    printf("Set max speed\n");
    float newSpeed = 0;
    newSpeed = setArraySize(newSpeed);
    car.maxSpeed = newSpeed;
    int color = 0;
    while (1) {
        printf("Select color\n 1-green || 2-red || 3-black");
        scanf_s("%d", &color);
        if (color <= 3 && color >= 1) {
            car.color = color - 1;
            break;
        }
    }
    car.init = 1;
    return car;
}
struct Car* initAllCars(struct Car* cars, int size) {
    for (int i = 0;i < size;i++) {
        cars[i] = initCar(cars[i]);
    }
    return cars;
}
