package leetcode

import "sort"

func minPairSum(nums []int) int {
	sort.Ints(nums)
	ret, n := 0, len(nums)
	for i := 0; i < n/2; i++ {
		ret = max(ret, nums[i]+nums[n-1-i])
	}
	return ret
}
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
