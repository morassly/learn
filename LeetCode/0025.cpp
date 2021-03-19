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
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1 || head == nullptr)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        int cnt = 0;
        while (cur != nullptr)
        {
            cnt++;
            cur = cur->next;
        }
        cur = head;
        for (int i = 0; i < cnt / k; i++)
        {
            for (int j = 1; j < k; j++)
            {
                ListNode *next = cur->next;
                cur->next = next->next;
                next->next = pre->next;
                pre->next = next;
            }
            pre = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};