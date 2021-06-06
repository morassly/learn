package leetcode

import (
	"math"
	"math/bits"
)

func minimumXORSum(nums1 []int, nums2 []int) int {
	n := len(nums2)
	dp := make([]int, 1<<n)
	dp[0] = 0
	for mask := 1; mask < (1 << n); mask++ {
		dp[mask] = math.MaxInt32
		for j := 0; j < n; j++ {
			if mask&(1<<j) != 0 {
				dp[mask] = min(dp[mask], dp[mask^(1<<j)]+(nums2[j]^nums1[bits.OnesCount(uint(mask))-1]))
			}
		}
	}
	return dp[(1<<n)-1]
}
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
