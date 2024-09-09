#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char **data;
    int size;
    int capacity;
} Result;

void addResult(Result *res, char *str) {
    if (res->size >= res->capacity) {
        res->capacity *= 2;
        res->data = realloc(res->data, res->capacity * sizeof(char *));
    }
    res->data[res->size++] = strdup(str);
}

bool contains(char **arr, int size, char *str) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], str) == 0) {
            return true;
        }
    }
    return false;
}

void bt(int i, char *s, int len, char **arr, int arrSize, char *cur, Result *res) {
    if (i == len) {
        addResult(res, cur);
        return;
    }
    for (int j = i; j < len; j++) {
        char t[101];
        strncpy(t, s + i, j - i + 1);
        t[j - i + 1] = '\0';
        if (contains(arr, arrSize, t)) {
            int origLen = strlen(cur);
            if (origLen > 0) strcat(cur, " ");
            strcat(cur, t);
            bt(j + 1, s, len, arr, arrSize, cur, res);
            cur[origLen] = '\0';  // backtrack
        }
    }
}

char **wordBreak(char *s, char **wordDict, int wordDictSize, int *returnSize) {
    Result res = {malloc(10 * sizeof(char *)), 0, 10};
    char cur[1000] = "";
    bt(0, s, strlen(s), wordDict, wordDictSize, cur, &res);
    *returnSize = res.size;
    return res.data;
}