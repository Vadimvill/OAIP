#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Tree.h"
#include "time.h"
#include "Game.h"

#define STRINGSIZE 2048

struct Node *createNode(char *text) {
    struct Node *node = malloc(sizeof(struct Node));
    node->text = text;
    node->right = NULL;
    node->left = NULL;
    return node;
}

struct Node *readTreeFromFile(FILE *f) {
    char *buffer = malloc(sizeof(char) * 2048);
    if (!fgets(buffer, 2048, f)) {
        return NULL;
    }
    buffer[strlen(buffer) - 1] = '\0';
    if (strcmp(buffer, "NULL") == 0) {
        return NULL;
    }
    struct Node *root = createNode(buffer);
    root->left = readTreeFromFile(f);
    root->right = readTreeFromFile(f);
    return root;
}

void writeTreeToFile(FILE *f, struct Node *root) {
    if (root == NULL) {
        fprintf(f, "NULL\n");
        return;
    }
    fprintf(f, "%s\n", root->text);
    writeTreeToFile(f, root->left);
    writeTreeToFile(f, root->right);
}

char isAnswer(struct Node *node) {
    if (node->left == NULL && node->right == NULL) return 1;
    return 0;
}

struct Node *game(struct Node *node, FILE *file) {
    int answer = -1;
    printf("%s ?\n", node->text);
    if (isAnswer(node)) {
        answer = setArraySize(answer, 2);
        log(file, NULL, &answer);
        rewind(stdin);
        if (answer == 1) {
            printf("cool\n");
            return NULL;
        } else {
            printf("I dont now answer\n");
            printf("Tell me Answer\n");
            char *stringAn = malloc(sizeof(char) * STRINGSIZE);
            fgets(stringAn, STRINGSIZE, stdin);
            stringAn[strlen(stringAn) - 1] = '\0';
            log(file, stringAn, NULL);
            printf("What different between this object\n");
            char *string = malloc(sizeof(char) * STRINGSIZE);
            fgets(string, STRINGSIZE, stdin);
            string[strlen(string) - 1] = '\0';
            log(file, string, NULL);
            struct Node *node1 = createNode(stringAn);
            struct Node *node2 = createNode(node->text);
            node->text = string;
            node->right = node1;
            node->left = node2;
            return NULL;
        }
    } else {
        answer = setArraySize(answer, 2);
        log(file, NULL, &answer);
        rewind(stdin);
        if (answer == 1) return node->right;
        else return node->left;
    }
}

void saveTree(struct Node *root, FILE *file) {
    if (root == NULL) {
        fprintf(file, "NULL ");
        return;
    }
    fprintf(file, "%s ", root->text);
    saveTree(root->left, file);
    saveTree(root->right, file);
}

void log(FILE *file, char *string, int *i) {
    fseek(file, 0, SEEK_END);
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    char buffer[26];
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    if (i == NULL) fprintf(file, "Пользователь ввёл : %s : TIME : %s : \n", string, buffer);
    else if (string == NULL) fprintf(file, "Пользователь ввёл : %d : TIME : %s : \n", *i, buffer);

}

int setArraySize(int a, int max) {
    while ((scanf("%d", &a)) != 1 || getchar() != '\n') {
        printf("Error\n");
        rewind(stdin);
    }
    if (a < 0 || a > max) {
        printf("Error\n");
        rewind(stdin);
        a = setArraySize(a, max);
    } else return a;
}

FILE *copyFile() {
    FILE *file = fopen("C:\\Users\\botme\\AkinatorC\\logger.txt", "r");
    FILE *file2 = fopen("C:\\Users\\botme\\AkinatorC\\logger2.txt", "w");
    char *buffer = malloc(sizeof(char) * 2048);
    while (fgets(buffer, 2048, file) != 0) {
        fprintf(file2, "%s", buffer);
    }
    fclose(file2);
    fclose(file);
    file = fopen("C:\\Users\\botme\\AkinatorC\\logger.txt", "w");
    file2 = fopen("C:\\Users\\botme\\AkinatorC\\logger2.txt", "r");
    while (fgets(buffer, 2048, file2) != 0) {
        fprintf(file, "%s", buffer);
    }
    fclose(file2);
    remove("C:\\Users\\botme\\AkinatorC\\logger2.txt");
    free(buffer);
    return file;
}

void freeTree(struct Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root->text);
    free(root);
}





