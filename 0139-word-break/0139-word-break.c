#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Solution {
    bool (*memoRecursiveSolution)(char*, int, char**, int*);
    bool (*wordBreak)(char*, char**);
};

bool memoRecursiveSolution(char* s, int i, char** dic, int wordDictSize,
                           int* memo) {
    if (i == strlen(s))
        return true;
    if (memo[i] != -1)
        return memo[i];

    bool ans = false;
    for (int j = 0; j < wordDictSize; j++) {
        if (strncmp(s + i, dic[j], strlen(dic[j])) == 0)
            ans = ans || memoRecursiveSolution(s, i + strlen(dic[j]), dic,
                                               wordDictSize, memo);
    }
    memo[i] = ans;
    return ans;
}

bool wordBreak(char* s, char** dic, int wordDictSize) {
    int* memo = (int*)malloc((strlen(s) + 1) * sizeof(int));
    for (int i = 0; i <= strlen(s); i++) {
        memo[i] = -1;
    }
    int indexOfs = 0;
    bool result = memoRecursiveSolution(s, indexOfs, dic, wordDictSize, memo);
    free(memo);
    return result;
}