package leetcode

func removeElement(nums []int, val int) int {
	n := len(nums)
	for i := 0; i < n; i++ {
		for nums[i] == val && n > i {
			n--
			nums[i] = nums[n]
		}
	}
	return n
}
