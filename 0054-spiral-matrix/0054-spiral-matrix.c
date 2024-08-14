#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int top = 0;
    int bottom = matrixSize - 1;
    int right = *matrixColSize - 1;
    int left = 0;
    int *res = (int*)malloc(matrixSize * (*matrixColSize) * sizeof(int));
    *returnSize = 0;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            res[(*returnSize)++] = matrix[top][i];
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            res[(*returnSize)++] = matrix[i][right];
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                res[(*returnSize)++] = matrix[bottom][i];
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                res[(*returnSize)++] = matrix[i][left];
            }
            left++;
        }
    }

    return res;
}