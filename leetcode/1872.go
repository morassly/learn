package leetcode

func stoneGameVIII(stones []int) int {
	n := len(stones)
	for i := 1; i < n; i++ {
		stones[i] += stones[i-1]
	}
	ans := stones[n-1]
	for i := n - 2; i > 0; i-- {
		if ans < (stones[i] - ans) {
			ans = stones[i] - ans
		}
	}
	return ans
}
