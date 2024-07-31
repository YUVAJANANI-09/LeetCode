void dfs(int** grid, int i, int j, int rows, int cols)
{
    if (i < 0 || j <0 || i >= rows || j >= cols) {
        return;
    }
    if (grid[i][j] == 1)
        return;
    grid[i][j] = 1;
    dfs(grid,i-1,j,rows,cols);
    dfs(grid,i+1,j,rows,cols);
    dfs(grid,i,j-1,rows,cols);
    dfs(grid,i,j+1,rows,cols);
}
void flood(int** grid, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || j == 0 || i == rows -1 || j == cols - 1) {
                if (grid[i][j] == 0) {
                    dfs(grid,i,j,rows,cols);
                }
            }
        }
    }
}
int closedIsland(int** grid, int gridSize, int* gridColSize){

    int rows = gridSize;
    int cols = gridColSize[0];
    flood(grid,rows,cols); 
    printf("after flood\n");
    int total = rows * cols;
    int *parent = (int*) malloc(sizeof(int) * total);
    int *size = (int*) malloc(sizeof(int) * total);

    for (int i = 0; i < total; i++) {
        parent[i] = -1;
        size[i] = 1;
    }
    int r[] = {-1,1,0,0};
    int c[] = {0,0,-1,1};

    for (int i = 1; i < rows - 1; i++) {
        for (int j = 1; j < cols - 1; j++) {
            if (grid[i][j] == 0) {
                int first = i * cols + j;
                parent[first] = first;
                for (int k = 0; k < 4; k++) {
                    int x = i + r[k];
                    int y = j + c[k];
                    if (i < 0 || j <0 || i >= rows || j >= cols) {
                            continue;
                    }
                    if (grid[x][y] == 0) {
                        int second = x * cols + y;
                        funion(first, second, parent,size);
                        for (int i = 0; i < total; i++) {
                            if((i+1)%cols==0)printf("\n");
                        }
                        printf("\n\n");
                    }

                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i < total; i++) {
        if (parent[i] == i) {
            count++;
        }
    }
    
    return count;

}
int findparent(int a,int *parent)
{
    if (parent[a] == a) {
        return a;
    }
    return parent[a] = findparent(parent[a], parent);
}
void funion(int a,int b, int* parent, int* size)
{
    if(parent[b] == -1)
        parent[b] =b;

    a = findparent(a,parent);
    b = findparent(b,parent);

    if(a == b) {
        return;
    }
    else if (size[a] < size[b]) {
        parent[a] = b;
        size[b] += size[a];
    }

    else {
        parent[b] = a;
        size[a] += size[b];
    }
}