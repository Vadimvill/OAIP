#include <stdio.h>
#include "stdlib.h"

#include "Decompressor.h"

int main() {
    printf("Set PATH to comressed file\n");
    char* compPath = calloc(2048, sizeof(char));
    scanf("%s", compPath,2048);
    char* outPath = calloc(2048, sizeof(char));
    printf("Set PATH to output file\n");
    scanf("%s", outPath,2048);
    replaceWordWithPairInDictionaryInFile(compPath, outPath);
    free(compPath);
    free(outPath);

}
