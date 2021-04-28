class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode* ans = new ListNode(0);
        ListNode* res = ans;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                ans->next = l1;
                ans = ans->next;
                l1 = l1->next;
            } else {
                ans->next = l2;
                ans = ans->next;
                l2 = l2->next;
            }
        }
        if (l1 == nullptr) {
            ans->next = l2;
        } else {
            ans->next = l1;
        }
        return res->next;
    }
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        int mid = l + (r - l) / 2;

        ListNode* left = merge(lists, l, mid);
        ListNode* right = merge(lists, mid + 1, r);
        return mergeTwoLists(right, left);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        else if (lists.size() == 1)
            return lists[0];
        else if (lists.size() == 2)
            return mergeTwoLists(lists[0], lists[1]);
        else {
            return merge(lists, 0, lists.size() - 1);
        }
        return nullptr;
    }
};