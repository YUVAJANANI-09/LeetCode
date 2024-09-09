/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
	if (!root || !root->left)
        return root;
    
    root->left->next = root->right;
    root->right->next = root->next ? root->next->left : NULL;
    connect(root->left);
    connect(root->right);
    
    return root;
}