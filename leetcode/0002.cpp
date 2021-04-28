/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode *p = l1, *q = l2, *curr = ans;
        int carry = 0;
        while (p != nullptr || q != nullptr) {
            int x = (p == nullptr) ? 0 : p->val;
            int y = (q == nullptr) ? 0 : q->val;
            int temp = x + y + carry;
            carry = temp / 10;
            curr->next = new ListNode(temp % 10);
            curr = curr->next;
            if (p != nullptr) p = p->next;
            if (q != nullptr) q = q->next;
        }
        if (carry) curr->next = new ListNode(carry);

        return ans->next;
    }
};