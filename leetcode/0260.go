package leetcode

func singleNumber(nums []int) []int {
	tmp := 0
	for _, num := range nums {
		tmp ^= num
	}
	tmp &= -tmp
	ans := []int{0, 0}
	for _, num := range nums {
		if num&tmp == 0 {
			ans[0] ^= num
		} else {
			ans[1] ^= num
		}
	}
	return ans
}
