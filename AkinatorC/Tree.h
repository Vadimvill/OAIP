#include "stdio.h"

typedef struct Node {
    char* text;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(char* text);
void writeTreeToFile(FILE *f,struct Node *root);
struct Node* readTreeFromFile(FILE *f);