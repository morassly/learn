package leetcode

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseKGroup(head *ListNode, k int) *ListNode {
	if k == 1 || head == nil {
		return head
	}

	dummynode := &ListNode{Val: -1}
	dummynode.Next = head
	pre, cur, cnt := dummynode, head, 0

	for cur != nil {
		cnt++
		cur = cur.Next
	}
	cur = head
	for i := 0; i < cnt/k; i++ {
		for j := 1; j < k; j++ {
			next := cur.Next
			cur.Next = next.Next
			next.Next = pre.Next
			pre.Next = next
		}
		pre = cur
		cur = cur.Next
	}
	return dummynode.Next
}
