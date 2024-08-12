int sortFunc(const void* a, const void* b) {
    return *((int*)a) - *((int*)b);
}

void helper(int* candidates, int candidatesSize, int target, int index, int* current, int currentLength, int* returnSize, int** returnColumnSizes, int*** answer) {
    int prevCan = 0;
    for (int i = index; i < candidatesSize; i++) {
        if (candidates[i] == target) {
            (*returnSize)++;
            *answer = (int**)realloc(*answer, (*returnSize) * sizeof(int*));
            (*answer)[(*returnSize) - 1] = (int*)malloc((currentLength+1) * sizeof(int));
            memcpy((*answer)[(*returnSize) - 1], current, currentLength * sizeof(int));
            (*answer)[(*returnSize) - 1][currentLength] = candidates[i];
            (*returnColumnSizes) = (int*)realloc((*returnColumnSizes), (*returnSize) * sizeof(int));
            (*returnColumnSizes)[(*returnSize) - 1] = currentLength + 1;
            break;
        }
        else if (candidates[i] <= (target / 2) && candidates[i] != prevCan) {
            current[currentLength] = candidates[i];
            helper(candidates, candidatesSize, target - candidates[i], i + 1, current, currentLength + 1, returnSize, returnColumnSizes, answer);
            prevCan = candidates[i];
        }
        else if (candidates[i] > target) break;
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(candidates, candidatesSize, sizeof(int), sortFunc);
    int* current = (int*)malloc(100*sizeof(int));
    int currentLength = 0;
    int** answer = (int**)malloc(sizeof(int*));
    (*returnColumnSizes) = (int*)malloc(sizeof(int));
    
    (*returnSize) = 0;
    helper(candidates, candidatesSize, target, 0, current, currentLength, returnSize, returnColumnSizes, &answer);
    
    free(current);
    return answer;
}