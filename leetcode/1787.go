package leetcode

const (
	INF = 0x3f3f3f3f
	N   = 1024
)

func minChanges(nums []int, k int) int {
	n, dp := len(nums), make([]int, N)
	for i := range dp {
		dp[i] = INF
	}
	dp[0] = 0
	ans, minv := 0, INF
	for i := 0; i < k; i++ {
		cnt, len, maxv := make(map[int]int), 0, 0
		for j := i; j < n; j += k {
			cnt[nums[j]]++
			len++
			maxv = max(maxv, cnt[nums[j]])
		}
		ans += len - maxv
		minv = min(minv, maxv)

		dp1 := make([]int, N)
		for i := range dp {
			dp1[i] = INF
		}
		for j := 0; j < N; j++ {
			for x, cntx := range cnt {
				dp1[j] = min(dp1[j], dp[j^x]+len-cntx)
			}
		}
		dp = dp1
	}
	return min(dp[0], ans+minv)
}
func min(i, j int) int {
	if i > j {
		return j
	}
	return i
}
func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}
