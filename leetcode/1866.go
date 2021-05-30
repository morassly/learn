package leetcode

func rearrangeSticks(n int, k int) int {
	dp := make([]int, k+1)
	dp[0] = 1
	for i := 0; i < n; i++ {
		for j := k; j > 0; j-- {
			dp[j] = (i*dp[j] + dp[j-1]) % 1000000007
		}
		dp[0] = 0
	}
	return dp[k]
}
