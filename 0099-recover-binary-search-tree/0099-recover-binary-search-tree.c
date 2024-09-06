void f(struct TreeNode* root, struct TreeNode** n1, struct TreeNode** n2, struct TreeNode** prev)
{
    if(!root)
    {
        return;
    }
    f(root->left, n1, n2, prev);
    if(*prev)
    {
        if((*prev)->val > root->val)
        {
            *n2 = root;
            if(*n1)
            {
                return;
            }
            *n1 = *prev;
        }
    }
    *prev = root;
    f(root->right, n1, n2, prev);
}

void recoverTree(struct TreeNode* root)
{
    struct TreeNode* n1 = NULL;  
    struct TreeNode* n2 = NULL;  
    struct TreeNode* prev = NULL;  
    f(root, &n1, &n2, &prev);
	n1->val ^= n2->val ^= n1->val ^= n2->val;
}