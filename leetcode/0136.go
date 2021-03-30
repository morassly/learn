package leetcode

func singleNumber(nums []int) int {
	ans := 0
	for _, i := range nums {
		ans ^= i
	}
	return ans
}
