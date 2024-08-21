int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int totalSubsets = 1 << numsSize;
    *returnSize = totalSubsets;
    *returnColumnSizes = (int*)malloc(totalSubsets * sizeof(int));
    int** res = (int**)malloc(totalSubsets * sizeof(int*));

    for (int i = 0; i < totalSubsets; ++i) {
        int subsetSize = 0;
        for (int j = 0; j < numsSize; ++j) {
            if (i & (1 << j)) {
                subsetSize++;
            }
        }
        (*returnColumnSizes)[i] = subsetSize;
        res[i] = (int*)malloc(subsetSize * sizeof(int));
        int index = 0;
        for (int j = 0; j < numsSize; ++j) {
            if (i & (1 << j)) {
                res[i][index++] = nums[j];
            }
        }
    }
    return res;
}