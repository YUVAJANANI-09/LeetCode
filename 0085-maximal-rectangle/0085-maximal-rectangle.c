#include <stdlib.h>
#include <stdio.h>

int largestRectangleArea(int* heights, int heightsSize) {
    int ans = 0;
    int stack[heightsSize + 1];
    int top = -1;

    for (int i = 0; i <= heightsSize; ++i) {
        while (top >= 0 && (i == heightsSize || heights[stack[top]] > heights[i])) {
            int h = heights[stack[top--]];
            int w = top < 0 ? i : i - stack[top] - 1;
            ans = ans > h * w ? ans : h * w;
        }
        stack[++top] = i;
    }

    return ans;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0)
        return 0;

    int ans = 0;
    int hist[*matrixColSize];

    for (int i = 0; i < *matrixColSize; ++i)
        hist[i] = 0;

    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < *matrixColSize; ++j)
            hist[j] = matrix[i][j] == '0' ? 0 : hist[j] + 1;
        ans = ans > largestRectangleArea(hist, *matrixColSize) ? ans : largestRectangleArea(hist, *matrixColSize);
    }

    return ans;
}