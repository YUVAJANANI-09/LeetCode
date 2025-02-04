typedef struct {
    char set[26], *str;
} anagram;

int cmp(const void* a, const void* b){
    return memcmp((*(anagram*) a).set, (*(anagram*) b).set, 26);
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    anagram* angs = malloc(sizeof(anagram) * strsSize);
    char*** ret = malloc(sizeof(char**) * strsSize);

    for (int i = 0; i < strsSize; ++i)
    { 
        angs[i].str = strs[i];
        memset(angs[i].set, 0, 26);
        for (char* j = angs[i].str; *j ; ++j) ++(angs[i].set[*j - 'a']);
    }

    qsort(angs, strsSize, sizeof(anagram), cmp);

    *returnColumnSizes = calloc(strsSize, sizeof(int));
    *returnSize = 1;
    (*returnColumnSizes)[0] = 1;
    ret[0] = malloc(sizeof(char*) * strsSize);
    ret[0][0] = strdup(angs[0].str);
    
    for (int i = 1; i < strsSize; ++i)
    {
        if (!memcmp(angs[i].set, angs[i - 1].set, 26)) ret[(*returnSize) - 1][(*returnColumnSizes)[(*returnSize) - 1]++] = strdup(angs[i].str);
        else 
        {
            ret[(*returnSize) - 1] = realloc(ret[(*returnSize) - 1], (*returnColumnSizes)[(*returnSize) - 1] * sizeof(char*));
            ret[(*returnSize)] = malloc(sizeof(char*) * (strsSize - i));
            ret[(*returnSize)][(*returnColumnSizes)[(*returnSize)++]++] = strdup(angs[i].str);
        }
    }

    ret = realloc(ret, (*returnSize) * sizeof(char**));
    free(angs);

    return ret;
}
