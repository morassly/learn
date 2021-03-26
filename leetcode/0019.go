package leetcode

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	dummynode := &ListNode{Val: 0}
	dummynode.Next = head
	fast, low := dummynode, dummynode
	for ; n > 0; n-- {
		fast = fast.Next
	}
	for fast.Next != nil {
		fast = fast.Next
		low = low.Next
	}
	low.Next = low.Next.Next
	return dummynode.Next
}
