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
    if (!root) {
        return NULL;
    }
    struct Node *head, *tail, *prev;
    prev = head = root;
    struct Node nul = {};
    head->next = &nul;
    tail = &nul;
    while (head) {
        if (head == &nul) {
            tail->next = head;
            tail = head;
            prev->next = NULL;
            if (prev == &nul) {
                break;
            }
        }
        if (head->left) {
            tail->next = head->left;
            tail = head->left;
        }
        if (head->right) {
            tail->next = head->right;
            tail = head->right;
        }
        prev = head;
        head = head->next;    
    }
	
    return root;
	
}