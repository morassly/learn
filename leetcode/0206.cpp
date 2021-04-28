/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution1 {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) return head;
        ListNode *pre = NULL;
        ListNode *curr = head;
        while (curr != nullptr) {
            ListNode *temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }

        return pre;
    }
};
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
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) return head;
        ListNode *pre = new ListNode(-1);
        pre->next = head;
        ListNode *curr = head;
        while (curr->next != nullptr) {
            ListNode *next = curr->next;
            curr->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }

        return pre->next;
    }
};