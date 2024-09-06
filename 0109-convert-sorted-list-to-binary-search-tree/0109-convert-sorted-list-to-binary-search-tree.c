/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedListToBST(struct ListNode* head){
    if(head==NULL){ return NULL;}
    if(head->next==NULL){
        struct TreeNode* root=malloc(sizeof(struct TreeNode));
        root->val=head->val;
        root->left=root->right=NULL;
        return root;
    }
    struct ListNode *slow=head,*fast=head;
    struct ListNode *mid=slow;
    while(fast && fast->next)
    {
        mid=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    struct TreeNode*root=malloc(sizeof(struct TreeNode));
    root->val=slow->val;
    mid->next=NULL;
    root->left=sortedListToBST(head);
    root->right=sortedListToBST(slow->next);
    return root;
}