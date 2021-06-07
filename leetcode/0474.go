package leetcode

func findMaxForm(strs []string, m int, n int) int {
	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}

	for i := range strs {
		a, b := 0, 0
		for c := range strs[i] {
			if strs[i][c] == '0' {
				a++
			} else {
				b++
			}
		}

		for j := m; j >= a; j-- {
			for k := n; k >= b; k-- {
				dp[j][k] = max(dp[j][k], dp[j-a][k-b]+1)
			}
		}
	}
	return dp[m][n]
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
