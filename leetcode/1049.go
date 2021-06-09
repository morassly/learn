package leetcode

func lastStoneWeightII(stones []int) int {
	sum := 0
	for _, v := range stones {
		sum += v
	}
	m := sum / 2
	dp := make([]int, m+1)
	for _, weight := range stones {
		for j := m; j >= weight; j-- {
			dp[j] = max(dp[j], dp[j-weight]+weight)
		}
	}
	return sum - 2*dp[m]
}
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
