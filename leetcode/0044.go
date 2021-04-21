package leetcode

func isMatch3(s string, p string) bool {
	m, n := len(s), len(p)
	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}
	dp[0][0] = 1
	for j := 1; j <= n; j++ {
		if p[j-1] == '*' {
			dp[0][j] = 1
		} else {
			break
		}
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if p[j-1] == '*' {
				dp[i][j] = dp[i-1][j] | dp[i][j-1]
			} else if p[j-1] == '?' || s[i-1] == p[j-1] {
				dp[i][j] = dp[i-1][j-1]
			}
		}
	}
	return dp[m][n] == 1
}
