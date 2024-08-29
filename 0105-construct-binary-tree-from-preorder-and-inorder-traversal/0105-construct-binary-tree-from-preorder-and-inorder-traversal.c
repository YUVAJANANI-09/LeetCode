/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildSubTree(int* preorder, int* inorder, int inorder_start, int inorder_end, int* preorder_index) {
    if (inorder_start > inorder_end)
        return NULL;

    int search_val = preorder[(*preorder_index)++];
    int i;
    for (i = inorder_start; i <= inorder_end; i++) {
        if (inorder[i] == search_val)
            break;
    }

    struct TreeNode* new_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    new_node->val = search_val;
    new_node->left = NULL;
    new_node->right = NULL;

    new_node->left = buildSubTree(preorder, inorder, inorder_start, i - 1, preorder_index);
    new_node->right = buildSubTree(preorder, inorder, i + 1, inorder_end, preorder_index);

    return new_node;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preorder_index = 0;
    return buildSubTree(preorder, inorder, 0, inorderSize - 1, &preorder_index);
}