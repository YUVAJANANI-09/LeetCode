void reverse(struct ListNode** startNode, struct ListNode* currentNode, int left, int right, int currentIndex) {
    if (currentIndex == right) return;
    if (currentIndex == left) *startNode = currentNode;
    
    currentNode = currentNode->next;
    currentIndex++;
    reverse(startNode, currentNode, left, right, currentIndex);

    if (currentIndex > (left + right) / 2) {
        int temp = currentNode->val;
        currentNode->val = (*startNode)->val;
        (*startNode)->val = temp;
        *startNode = (*startNode)->next;
    }
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode* startNode = head;
    int currentIndex = 1;
    reverse(&startNode, startNode, left, right, currentIndex);
    return head;
}