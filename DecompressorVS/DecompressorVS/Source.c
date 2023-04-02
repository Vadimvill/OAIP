#include <stdio.h>
#include "stdlib.h"

#include "Decompressor.h"

int main() {
    printf("Set PATH to comressed file\n");
    char* compPath = calloc(2048, sizeof(char));
    scanf("%s", compPath);
    char* outPath = calloc(2048, sizeof(char));
    printf("Set PATH to output file\n");
    scanf("%s", outPath);
    replaceWordWithPairInDictionaryInFile(compPath, outPath);
    free(compPath);
    free(outPath);

}
