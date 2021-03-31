package leetcode

func candy(ratings []int) int {
	n := len(ratings)
	dp := make([]int, n)
	for i := 0; i < n; i++ {
		if i > 0 && ratings[i] > ratings[i-1] {
			dp[i] = dp[i-1] + 1
		} else {
			dp[i] = 1
		}
	}
	ans := 0
	for i := n - 1; i >= 0; i-- {
		if i < n-1 && ratings[i] > ratings[i+1] && dp[i] <= dp[i+1] {
			dp[i] = dp[i+1] + 1
		}
		ans += dp[i]
	}
	return ans
}
