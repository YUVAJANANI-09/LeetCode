bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int r = 0;
    int c = *matrixColSize - 1;
    while(r < matrixSize && c >= 0) {
        if(target == matrix[r][c])
            return true;
     
        else if(matrix[r][c] > target)
            c--;
        
        else 
            r++;
    }
    return false;     
}