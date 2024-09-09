bool hasCycle(struct ListNode *slow) {
    if(!slow || !slow->next) return false;
    struct ListNode *fast = slow;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}