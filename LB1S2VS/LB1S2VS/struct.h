enum Color {
    green,
    red,
    black,
};
struct Car {
    enum Color color;
    float maxSpeed;
    int coast;
    char* name;
    int init;
};
struct Car* createCarArray(int size);
struct Car* test();
void printArrayStructs(struct Car* cars, int size);
void initCar(struct Car* car,int index);
void selectionSortMaxSpeed(struct Car* cars, int n);
void selectionSortCoast(struct Car* cars, int n);
struct Car* initAllCars(struct Car* cars, int size);
struct Car* deleteCar(struct Car* cars, int* size, int index);
void selectionSortMaxSpeedandCoast(struct Car* cars, int n);
int setArraySizeInt(int a);
float setArraySizeFloat(float a);
