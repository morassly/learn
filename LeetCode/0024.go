package leetcode

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
	dummynode := &ListNode{Val: 0, Next: head}
	pre := dummynode

	for head != nil && head.Next != nil {
		next := head.Next
		head.Next = next.Next
		next.Next = pre.Next
		pre.Next = next
		pre = head
		head = head.Next
	}
	return dummynode.Next
}
