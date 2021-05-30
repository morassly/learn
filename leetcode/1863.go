package leetcode

func subsetXORSum(nums []int) int {
	n, sum := len(nums), 0
	var dfs func(ans, indx int)
	dfs = func(ans, indx int) {
		sum += ans
		for j := indx; j < n; j++ {
			dfs(ans^nums[j], j+1)
		}
	}
	dfs(0, 0)
	return sum
}
