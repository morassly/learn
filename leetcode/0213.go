package leetcode

func rob(nums []int) int {
	n := len(nums)
	if n == 1 {
		return nums[0]
	}
	if n == 2 {
		return max(nums[0], nums[1])
	}
	f1, f2, s1, s2 := 0, 0, nums[0], nums[1]
	for i := 1; i < n-1; i++ {
		f1, s1 = s1, max(nums[i]+f1, s1)
		f2, s2 = s2, max(nums[i+1]+f2, s2)
	}
	return max(s1, s2)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
