package leetcode

func removeDuplicates(nums []int) int {
	n := len(nums)
	if n == 0 {
		return 0
	}
	ans := 0
	for j := ans; j < n; j++ {
		if nums[ans] != nums[j] {
			ans++
			nums[ans] = nums[j]
		}
	}
	return ans + 1
}
