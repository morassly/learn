func minSkips(dist []int, speed int, hoursBefore int) int {
	n := len(dist)
	dp := make([]int, n+1)
	dp[0] = 0
	for i := 1; i <= n; i++ {
		for j := i; j >= 0; j-- {
			temp := math.MaxInt64 / 2
			if j != i {
				temp = min(temp, ((dp[j]+dist[i-1]-1)/speed+1)*speed)
			}
			if j != 0 {
				temp = min(temp, dp[j-1]+dist[i-1])
			}
			dp[j] = temp
		}
	}
	for j := 0; j <= n; j++ {
		if dp[j] <= speed*hoursBefore {
			return j
		}
	}
	return -1
}
func min(x, y int) int {
	if x > y {
		return y
	}
	return x
}