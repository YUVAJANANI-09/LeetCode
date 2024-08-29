/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int funheight(struct TreeNode* root){
    if(!root){return 0;}

    int tl = funheight(root->left);
    int tr = funheight(root->right);
    return tl > tr ? (tl+1):(tr+1);
}

void funL(struct TreeNode* root, int level, int* ret, int* cnt){
    if(!root){return;}
    if(level == 0){
        ret[(*cnt)++] = root->val;
    }else{
        funL(root->left, level-1, ret, cnt);
        funL(root->right, level-1, ret, cnt);
    }
    return;
}

void funR(struct TreeNode* root, int level, int* ret, int* cnt){
    if(!root){return;}
    if(level == 0){
        ret[(*cnt)++] = root->val;
    }else{
        funR(root->right, level-1, ret, cnt);
        funR(root->left, level-1, ret, cnt);
    }
    return;
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int th = funheight(root);
    int** ret = (int**)calloc(th, sizeof(int*));
    *returnSize = th;
    (*returnColumnSizes) = (int*)calloc(th, sizeof(int));
    for(int i= 0;i<th; i++){
        int cnt = 0;
        ret[i] = (int*)calloc(1<<i, sizeof(int));
        if(i%2){//odd
            funR(root, i, ret[i], &cnt);
        }else{
            funL(root, i, ret[i], &cnt);
        }
        (*returnColumnSizes)[i] = cnt;
    }
    return ret;
}