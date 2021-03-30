package leetcode

func countBits(num int) []int {
	dp := make([]int, num+1)
	for i := 1; i <= num; i++ {
		dp[i] = dp[i&(i-1)] + 1
	}
	return dp
}
