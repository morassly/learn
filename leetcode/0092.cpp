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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *dummynode = new ListNode(-1);
        dummynode->next = head;
        ListNode *pre = dummynode;
        for (int i = 0; i < left - 1; i++) pre = pre->next;

        ListNode *cur = pre->next;
        for (int i = 0; i < right - left; i++) {
            ListNode *next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummynode->next;
    }
};