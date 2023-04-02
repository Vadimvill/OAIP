#include "stdlib.h"
#include "string.h"
#include "stdio.h"
typedef struct Pair {
    char* word1;
    char* word2;
} Pair;
char* findPairInDictionary(Pair* dictionary, int j, char* word);
char isSperator(char c);
Pair* createDictionary(FILE* keyFile, int* i);
void replaceWordWithPairInDictionaryInFile(const char* sourceFilePath, const char* outFilePath);
char isLetter(char c);
char isWord(char* lexem);