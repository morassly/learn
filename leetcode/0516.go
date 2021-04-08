package leetcode

func longestPalindromeSubseq(s string) int {
	n := len(s)
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, n)
	}
	for i := n - 1; i >= 0; i-- {
		dp[i][i] = 1
		for j := i + 1; j < n; j++ {
			if s[i] == s[j] {
				dp[i][j] = dp[i+1][j-1] + 2
			} else if dp[i][j-1] > dp[i+1][j] {
				dp[i][j] = dp[i][j-1]
			} else {
				dp[i][j] = dp[i+1][j]
			}
		}
	}
	return dp[0][n-1]
}
