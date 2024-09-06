struct TreeNode** creatTrees(int low, int high, int *size)
{ 
    if(low > high)
    {
        struct TreeNode ** out = (struct TreeNode **)malloc(sizeof(struct TreeNode*));
        *size = 1;
        out[0] = NULL;
        return out;
    }
    struct TreeNode ** out = (struct TreeNode **)malloc(2000*sizeof(struct TreeNode*));
    *size = 0;
    for(int i=low; i<=high; i++)
    {
        int leftSize = 0, rightSize = 0;
        struct TreeNode ** leftNodes = creatTrees(low, i-1, &leftSize);
        struct TreeNode ** rightNodes = creatTrees(i+1, high, &rightSize);
        for(int k=0; k<leftSize; k++)
            for(int j=0; j<rightSize; j++)
            {
                out[*size] = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                out[*size]->val = i;
                out[*size]->left = leftNodes[k];
                out[*size]->right = rightNodes[j];
                *size += 1;
            }
    }
    return out;
}
struct TreeNode** generateTrees(int n, int* returnSize){
    return creatTrees(1, n, returnSize);
}