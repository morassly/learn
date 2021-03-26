/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        ListNode *fast = newhead, *low = newhead;

        while (n--)
            fast = fast->next;
        while (fast->next)
        {
            fast = fast->next;
            low = low->next;
        }

        low->next = low->next->next;
        return newhead->next;
    }
};