#include "stdio.h"
#include "stdlib.h"
#include "Compressor.h"
#include "string.h"
int push(struct Stack* stack, char* data) {
    if (stack == NULL) {
        return -1;
    }
    struct Node* newNode = malloc(sizeof(Node));
    newNode->name = data;
    newNode->next = stack->top;
    stack->top = newNode;
    return 1;
}
void init(struct Stack* s) {
    s->top = NULL;
}
char* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("StackIsEmpy\n");
        return NULL;
    }
    char* data = stack->top->name;
    struct Node* tmp = stack->top;
    stack->top = stack->top->next;
    free(tmp);
    return data;
}
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

char isHasPairWithWord(const struct Pair* dictionary, int j, char* word)
{
    for (int i = 0; i < j; i++)
        if (strcmp(dictionary[i].word1, word) == 0 || strcmp(dictionary[i].word2, word) == 0)
            return 1;

    return 0;
}

struct Pair* createDictionary(struct Words* words, int i, int* j) {
    struct Pair* dictionary = NULL;
    *j = 0;

    for (int m = 0;m < i;m++) {
        if (isHasPairWithWord(dictionary, *j, words[m].word))
            continue;

        int profit = 0;
        char* pairWord = NULL;

        for (int b = m + 1;b < i;b++) {
            if (isHasPairWithWord(dictionary, *j, words[b].word))
                continue;

            size_t startSize = (strlen(words[m].word) * words[m].count) + (strlen(words[b].word) * words[b].count);
            size_t endSize = (strlen(words[m].word) * words[b].count) + (strlen(words[b].word) * words[m].count);
            int currentProfit = startSize - endSize;

            if (currentProfit > profit)
            {
                profit = currentProfit;
                pairWord = words[b].word;
            }
        }

        if (pairWord != NULL)
        {
            (*j)++;

            if (dictionary == NULL)
                dictionary = malloc(sizeof(struct Pair));
            else
                dictionary = realloc(dictionary, sizeof(struct Pair) * (*j));

            dictionary[*j - 1].word1 = words[m].word;
            dictionary[*j - 1].word2 = pairWord;
        }
    }
    return dictionary;
}
void writeKeysInFile(struct Pair* dictionary, int j, FILE* file) {
    for (int i = 0;i < j;i++) {
        fprintf(file, "%s %s\n", dictionary[i].word1, dictionary[i].word2);
    }
    fprintf(file, "%c", '\n');

}
struct Words* textToWord(struct Stack* stack, struct Words* words, int* i) {
    *i = 1;
    words = malloc(sizeof(struct Words) * (*i));
    words[(*i) - 1].word = pop(stack);
    words[(*i) - 1].count = 1;
    while (stack->top != NULL) {
        int bool = 1;
        char* temp = pop(stack);
        for (int j = 0;j < (*i);j++) {
            if (strcmp(temp, words[j].word) == 0) {
                free(temp);
                bool = 0;
                words[j].count++;
                break;
            }
        }
        if (bool) {
            (*i)++;
            words = realloc(words, sizeof(struct Words) * (*i));
            words[(*i) - 1].word = temp;
            words[(*i) - 1].count = 1;
        }
    }
    return words;
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

char* findPairInDictionary(struct Pair* dictionary, int j, char* word)
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

void replaceWordsInStringWithPairsInFile(FILE* file, char* string, struct Pair* dictionary, int j)
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

void replaceWordWithPairInDictionaryInFile(const char* sourceFilePath, const char* outFilePath, struct Pair* dictionary, int j)
{
    FILE* sourceFile = fopen(sourceFilePath, "rt");
    FILE* file = fopen(outFilePath, "wt");

    writeKeysInFile(dictionary, j, file);

    char* string = calloc(2048, sizeof(char));

    while (fgets(string, 2048 * sizeof(char), sourceFile) != 0)
        replaceWordsInStringWithPairsInFile(file, string, dictionary, j);

    free(string);

    fclose(sourceFile);
    fclose(file);
}

void countWordsWithStack(char* string, struct Stack* stack)
{
    unsigned int i = 0;

    while (string[i] != '\n' && string[i] != '\0')
    {
        while (isSperator(string[i]))
            i++;

        if (string[i] == '\n' || string[i] == '\0')
            continue;

        unsigned int lexemStartPos = i;

        while (isSperator(string[i]) == 0)
            i++;

        size_t lexemSize = sizeof(char) * (i - lexemStartPos + 1);
        char* lexem = malloc(lexemSize);

        strncpy_s(lexem, lexemSize, string + lexemStartPos, lexemSize - 1);

        if (isWord(lexem))
            push(stack, lexem);
        else
            free(lexem);
    }
}

void textToStack(struct Stack* stack) {
    FILE* file = fopen("C:\\Users\\botme\\Compressor\\text1original.txt", "r");

    char* string = calloc(2048, sizeof(char));

    while (fgets(string, 2048 * sizeof(char), file) != 0)
        countWordsWithStack(string, stack);

    free(string);

    if (ferror(file) != 0)
    {
        perror("File reading error");
        exit(-1);
    }

    fclose(file);
}
