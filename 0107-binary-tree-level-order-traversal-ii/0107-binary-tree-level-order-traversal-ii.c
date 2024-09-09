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
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
void enqueue(struct TreeNode** queue, int* front, int* rear) {
    if (queue[*front]->right) {
        queue[*rear] = malloc(sizeof(struct TreeNode));
        queue[(*rear)++] = queue[*front]->right;
    }
    if (queue[*front]->left) {
        queue[*rear] = malloc(sizeof(struct TreeNode));
        queue[(*rear)++] = queue[*front]->left;
    }
    (*front)++;
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int** ans = malloc(2000 * sizeof(int*));
    (*returnColumnSizes) = malloc(2000 * sizeof(int));
    if (root == NULL) {
        *returnSize = 0;
        (*returnColumnSizes)[0] = 0;
        return ans;
    }
    struct TreeNode** queue = malloc(2000 * sizeof(struct TreeNode*));
    int* widths = malloc(2000 * sizeof(int));
    int width = 1;
    int depth = 0;
    int front = 0;
    int rear = 0;
    int idx = 0;

    queue[rear] = malloc(sizeof(struct TreeNode));
    queue[rear++] = root;
    while (width) {
        width = rear - front;
        widths[depth++] = width;
        for (int i = 0; i < width; i++)
            enqueue(queue, &front, &rear);
    }
    depth -= 2;
    rear--;

    while (depth >= 0) {
        ans[idx] = malloc(widths[depth] * sizeof(int));
        for (int i = 0; i < widths[depth]; i++) {
            ans[idx][i] = queue[rear--]->val;
        }
        (*returnColumnSizes)[idx++] = widths[depth--];
    }

    free(widths);
    ans = realloc(ans, idx * sizeof(int*));
    (*returnColumnSizes) = realloc((*returnColumnSizes), idx * sizeof(int));
    *returnSize = idx;
    return ans;
}