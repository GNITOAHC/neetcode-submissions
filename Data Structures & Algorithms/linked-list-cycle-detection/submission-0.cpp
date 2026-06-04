/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode *fast = head, *slow = head;

        // make sure fast != slow in first round
        if (fast != nullptr && fast->next != nullptr) {
            fast = fast->next;
        } else return false;

        while (fast != nullptr && fast->next != nullptr) {
            if (fast == slow) return true;

            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};
