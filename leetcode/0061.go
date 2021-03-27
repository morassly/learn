package leetcode

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	n, cur := 1, head
	for ; cur.Next != nil; n++ {
		cur = cur.Next
	}
	pre := n - k%n
	if pre == n {
		return head
	}
	cur.Next = head
	for ; pre > 0; pre-- {
		cur = cur.Next
	}
	ans := cur.Next
	cur.Next = nil
	return ans
}
