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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode *cur;
        if (list1->val < list2->val) {
            cur = list1;
            list1 = list1->next;
        } else {
            cur = list2;
            list2 = list2->next;
        }
        ListNode *head = cur;

        while (list1 != nullptr && list2 != nullptr) {
            ListNode *smaller = list1->val < list2->val ? list1 : list2;
            cur->next = smaller;
            cur = cur->next;
            if (list1->val < list2->val) list1 = list1->next;
            else list2 = list2->next;
        }

        cur->next = list1 != nullptr ? list1 : list2; // append remain

        return head;
    }
};
