package leetcode

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func minDiffInBST(root *TreeNode) int {
	ans, pre := 10000000, -1
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		if pre == -1 {
			pre = root.Val
		} else {
			if ans > (root.Val - pre) {
				ans = root.Val - pre
			}
			pre = root.Val
		}
		dfs(root.Right)
	}
	dfs(root)
	return ans
}
