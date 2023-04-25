#include "stdlib.h"
#include "stdio.h"
char isAnswer(struct Node* node);
struct Node* game(struct Node* node,FILE* file);
void log(FILE*file,char* string,int* i);
int isNeedInt(int min,int max,int value);
int setArraySize(int a,int max);
FILE * copyFile();
void freeTree(struct Node* root);
