#include <stdio.h>
#include "stdlib.h"
#include "Compressor.h"
#include "string.h"
int main() {
    struct Stack* stack = malloc(sizeof(Stack));
    init(stack);
    textToStack(stack);
    int i = 0;

    struct Words* words = textToWord(stack, NULL, &i);
    int j = 0;
    struct Pair* dictionary = createDictionary(words, i, &j);
    char* soursePath = calloc(2048, sizeof(char));
    char* outPath = calloc(2048, sizeof(char));
    printf("Set PATH of sourseFile\n");
    scanf("%s", soursePath,2048);
    printf("Set PATH of outFile\n");
    scanf("%s", outPath,2048);

    replaceWordWithPairInDictionaryInFile
    (soursePath,
        outPath,
        dictionary, j);
    free(outPath);
    free(soursePath);

    return 0;
}
