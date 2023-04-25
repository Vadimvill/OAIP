#include <stdio.h>
#include "string.h"
#include "Tree.h"
#include "stdlib.h"
#include "locale.h"
#include "Game.h"
int main() {
    FILE * logger = copyFile();
    FILE * file = fopen("C:\\Users\\botme\\AkinatorC\\save.txt","r");
    struct Node* root = readTreeFromFile(file);
    fclose(file);
    printf("1 - yes, 0 - no\n");
    while (1){
            struct Node* temp = root;
            do{
                temp = game(temp,logger);
            } while (temp !=NULL);
        printf("Set 0 to continue, set 1 to exit and save, set 2 to exit\n");
        int i = -1;
        i = setArraySize(i,3);
        log(file,NULL,&i);
        if(i == 1) {
            FILE * file = fopen("C:\\Users\\botme\\AkinatorC\\save.txt","w");
            writeTreeToFile(file,root);
            fclose(file);
            break;
        } else if (i == 2){
            fclose(file);
            break;
        }

    }
    freeTree(root);;
    fclose(logger);
    return 0;
}
