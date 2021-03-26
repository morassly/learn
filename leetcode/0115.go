package leetcode

func numDistinct(s string, t string) int {
	m, n := len(s), len(t)
	if n > m {
		return 0
	}
	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
		dp[i][0] = 1
	}

	for i := 1; i <= m; i++ {
		for j := 1; j <= i && j <= n; j++ {
			dp[i][j] = dp[i-1][j]
			if s[i-1] == t[j-1] {
				dp[i][j] += dp[i-1][j-1]
			}
		}
	}
	return dp[m][n]
}
