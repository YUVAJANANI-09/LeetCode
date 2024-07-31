void dfs(char** grid, int i, int j, int gridSize, int* gridColSize){
    if (i < 0 || j < 0 || i >= gridSize || j >= gridColSize[i] || grid[i][j] != '1')
        return ;
    grid[i][j] = '#';
    dfs(grid, i+1, j, gridSize, gridColSize);
    dfs(grid, i-1, j, gridSize, gridColSize);
    dfs(grid, i, j+1, gridSize, gridColSize);
    dfs(grid, i, j-1, gridSize, gridColSize);
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
    int c=0;
    for(int i=0;i<gridSize;i++)
    {
        for(int j=0;j<gridColSize[i];j++)
        {
            if(grid[i][j]=='1')
            {
                dfs(grid,i,j,gridSize,gridColSize);
                c++;
            }
        }
    }
    return c;
}