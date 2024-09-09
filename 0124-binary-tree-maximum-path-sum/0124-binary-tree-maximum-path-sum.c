#define max(a, b) ((a) > (b) ? (a) : (b))

int dfs(struct TreeNode* node, int* max_sum) {

    if (!node) return 0;

    int left_sum = dfs(node->left, max_sum);
    int right_sum = dfs(node->right, max_sum);
    left_sum = max(left_sum, 0);
    right_sum = max(right_sum, 0);

    *max_sum = max(*max_sum, node->val + left_sum+right_sum);
    return node->val + max(left_sum, right_sum);

}

int maxPathSum(struct TreeNode* root) {
    
    int max_sum = INT_MIN;
    dfs(root, &max_sum);
    return max_sum;

}