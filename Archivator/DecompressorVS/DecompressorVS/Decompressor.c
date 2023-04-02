#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "Decompressor.h"
Pair* createDictionary(FILE* keyFile, int* i) {
    char* string = calloc(2048, sizeof(char));
    (*i) = 1;
    Pair* dictionary = malloc(sizeof(Pair));
    while ((fgets(string, 2048 * sizeof(char), keyFile) != 0)) {
        if (string[0] == '\n')
            break;


        int b = 0;
        while (!isSperator(string[b])) {
            b++;
        }
        dictionary[(*i) - 1].word1 = malloc(sizeof(char) * (b + 1));
        strncpy_s(dictionary[(*i) - 1].word1, b + 1, string, b);
        b++;
        int j = b;
        while (string[b] != '\n') {
            b++;
        }
        dictionary[(*i) - 1].word2 = malloc(sizeof(char) * (b - j + 1));
        strncpy_s(dictionary[(*i) - 1].word2, b - j + 1, string + j, b - j);
        (*i)++;
        dictionary = realloc(dictionary, sizeof(Pair) * (*i));
    }
    dictionary = realloc(dictionary, sizeof(Pair) * ((*i) - 1));
    (*i)--;
    return dictionary;
}
void replaceWordsInStringWithPairsInFile(FILE* file, char* string, Pair* dictionary, int j)
{
    unsigned int i = 0;

    while (string[i] != '\n' && string[i] != '\0')
    {
        unsigned int startPos = i;

        while (isSperator(string[i]))
            i++;

        fwrite(string + startPos, sizeof(char), i - startPos, file);

        if (string[i] == '\n' || string[i] == '\0')
            break;

        unsigned int lexemStartPos = i;

        while (isSperator(string[i]) == 0)
            i++;

        size_t lexemSize = sizeof(char) * (i - lexemStartPos + 1);
        char* lexem = malloc(lexemSize);

        strncpy_s(lexem, lexemSize, string + lexemStartPos, lexemSize - 1);

        char isReplaced = 0;

        if (isWord(lexem)) {
            char* pair = findPairInDictionary(dictionary, j, lexem);

            if (pair != NULL) {
                isReplaced = 1;
                fprintf(file, "%s", pair);
            }
        }

        if (isReplaced != 1)
            fprintf(file, "%s", lexem);

        free(lexem);
    }

    if (string[i] == '\n')
        fputc('\n', file);
}
void replaceWordWithPairInDictionaryInFile(const char* sourceFilePath, const char* outFilePath)
{
    FILE* sourceFile = fopen(sourceFilePath, "rt");
    FILE* file = fopen(outFilePath, "wt");
    Pair* dictionary = malloc(sizeof(Pair));
    int i = 0;
    dictionary = createDictionary(sourceFile, &i);

    char* string = calloc(2048, sizeof(char));

    while (fgets(string, 2048 * sizeof(char), sourceFile) != 0)
        replaceWordsInStringWithPairsInFile(file, string, dictionary, i);

    free(string);

    fclose(sourceFile);
    fclose(file);
}
char* findPairInDictionary(Pair* dictionary, int j, char* word)
{
    for (int i = 0; i < j; i++)
    {
        if (strcmp(dictionary[i].word1, word) == 0)
            return dictionary[i].word2;
        if (strcmp(dictionary[i].word2, word) == 0)
            return dictionary[i].word1;
    }

    return NULL;
}
char isSperator(char c)
{
    static char separators[] = " ,.!?*+-=/|<>\"\'\\";

    for (int i = 0; i < sizeof(separators) / sizeof(char); i++)
        if (c == separators[i])
            return 1;

    return 0;
}

char isLetter(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

char isWord(char* lexem)
{
    for (int i = 0; lexem[i] != '\0'; i++)
        if (isLetter(lexem[i]) == 0)
            return 0;

    return 1;
}