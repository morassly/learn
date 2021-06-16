package leetcode

func PredictTheWinner(nums []int) bool {
	n := len(nums)
	dp := make([]int, n)
	for i, j := range nums {
		dp[i] = j
	}

	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			dp[j] = max(nums[i]-dp[j], nums[j]-dp[j-1])
		}
	}
	return dp[n-1] >= 0
}
func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}
