package leetcode

func removeDuplicates2(nums []int) int {
	n := len(nums)
	if n <= 2 {
		return n
	}
	l := 2
	for r := 2; r < n; r++ {
		if nums[l-2] != nums[r] {
			nums[l] = nums[r]
			l++
		}
	}
	return l
}