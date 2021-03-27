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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        int n = 1;
        ListNode *cur = head;
        while (cur->next != nullptr)
        {
            n++;
            cur = cur->next;
        }
        int pre = n - k % n;
        if (pre == n)
        {
            return head;
        }
        cur->next = head;
        while (pre--)
        {
            cur = cur->next;
        }
        ListNode *ans = cur->next;
        cur->next = nullptr;
        return ans;
    }
};