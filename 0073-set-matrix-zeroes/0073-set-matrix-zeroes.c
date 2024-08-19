void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    bool flag1 = false, flag2 = false;
    int r = matrixSize, c = matrixColSize[0];
    for (int i = 0; i < r; i++) if (matrix[i][0] == 0) flag1 = true;
    for (int j = 0; j < c; j++) if (matrix[0][j] == 0) flag2 = true;
    for (int i = 1; i < r; i++) for (int j = 1; j < c; j++) if (matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
    for (int i = 1; i < r; i++) for (int j = 1; j < c; j++) if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
    if (flag1) for (int i = 0; i < r; i++) matrix[i][0] = 0;
    if (flag2) for (int j = 0; j < c; j++) matrix[0][j] = 0;
}