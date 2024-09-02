/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;
    struct ListNode* prev = dummy;

    struct ListNode* greater = (struct ListNode*)malloc(sizeof(struct ListNode));
    greater->val = 0; 
    greater->next = NULL;
    struct ListNode* last = greater;

    while(head != NULL) {
        if(head->val < x) {
            prev->next = head;
            prev = prev->next;
        } else {
            last->next = head;
            last = last->next;
        }
        head = head->next;
    }
    last->next = NULL;
    prev->next = greater->next;

    struct ListNode *newHead = dummy->next;
    free(dummy);
    free(greater); 
    
    return newHead;
}