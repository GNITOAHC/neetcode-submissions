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
    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = nullptr;

        while (curr != nullptr) {
            next = curr->next;  // Store next node
            curr->next = prev;  // Reverse current node's pointer
            prev = curr;        // Move pointers one position forward
            curr = next;
        }
        return prev; // New head of the reversed list
    }

    void reorderList(ListNode* head) {
        /*
         * If init
         *  - fast = head: slow will end at second half's first node
         *  - fast = head->next, slow will end at first half's tail node
         */
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next; // second half's starting node
        slow->next = nullptr; // divide the linked list

        second = this->reverse(second); // reverse second half

        /*
         *  Merge first half and reversed second half alternately
         */
        ListNode* first = head;
        while(second != nullptr) {
            ListNode* next_f = first->next;
            ListNode* next_s = second->next;
            first->next = second;
            second->next = next_f;
            first = next_f;
            second = next_s;
        }
    }
};
