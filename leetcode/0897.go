package leetcode

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func increasingBST(root *TreeNode) *TreeNode {
	dummy := &TreeNode{Val: 0}
	cur := dummy
	var inorder func(node *TreeNode)
	inorder = func(node *TreeNode) {
		if node == nil {
			return
		}
		inorder(node.Left)

		cur.Right, node.Left = node, nil
		cur = node

		inorder(node.Right)
	}
	inorder(root)
	return dummy.Right
}
