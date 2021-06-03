package leetcode

func findMaxLength(nums []int) int {
	mp := map[int]int{0: -1}
	presum, ans := 0, 0
	for i, num := range nums {
		if num == 1 {
			presum++
		} else {
			presum--
		}
		if index, ok := mp[presum]; ok {
			if ans < i-index {
				ans = i - index
			}
		} else {
			mp[presum] = i
		}
	}
	return ans
}
