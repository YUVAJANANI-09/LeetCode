/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
        struct ListNode *dummy = malloc(sizeof(struct ListNode));
        dummy->next = head;
        dummy->val = 0;
        struct ListNode *prev = dummy , *curr = head;

        while(curr)
        {
            struct ListNode *next_node = curr->next;
            while(next_node && curr->val == next_node->val)
            {
                struct ListNode *temp = next_node->next;
                // delete next_node;
                next_node = temp;
            }

            if(curr->next != next_node)
            {
                prev->next = next_node;
                // delete curr;
            }
            else
            {
                prev = curr;

            }
            curr = next_node;
        }
        return dummy->next;
}