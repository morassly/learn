package leetcode

func strangePrinter(s string) int {
	n := len(s)
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}

	for i := range dp {
		dp[i][i] = 1
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			dp[i][j] = 1 + dp[i+1][j]
			for k := i + 1; k <= j; k++ {
				if s[i] == s[k] {
					if dp[i][j] > dp[i][k-1]+dp[k+1][j] {
						dp[i][j] = dp[i][k-1] + dp[k+1][j]
					}
				}
			}
		}
	}
	return dp[0][n-1]
}
