package leetcode

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	s := make([][]int, 2)
	for i := range s {
		s[i] = make([]int, 0)
	}
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, f int) {
		if root == nil {
			return
		}
		if root.Left == nil && root.Right == nil {
			s[f] = append(s[f], root.Val)
		} else {
			dfs(root.Left, f)
			dfs(root.Right, f)
		}
	}
	dfs(root1, 0)
	dfs(root2, 1)
	if len(s[0]) != len(s[1]) {
		return false
	}
	for i, v := range s[0] {
		if v != s[1][i] {
			return false
		}
	}
	return true
}
