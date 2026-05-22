class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Move the second pointer n step forward,
        // then start moving the first and second pointer together
        // When the second pointer hit the end, the first pointer
        // is pointing at the nth node
        ListNode *first = head, *second = head;
        while (n--) second = second->next;

        int count = 0;

        while (second != nullptr) {
            ++count;
            first = first->next;
            second = second->next;
        }

        // Now, the first pointer points to the nth from end node
        ListNode *nth_minus_1 = head;
        if (first == head) return first->next;
        else {
            count -= 1;
            while (count--) nth_minus_1 = nth_minus_1->next;
            nth_minus_1->next = first->next;
        }


        return head;
    }
};
