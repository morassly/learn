package leetcode

func missingNumber(nums []int) int {
	ans := len(nums)
	for i, n := range nums {
		ans = ans ^ i ^ n
	}
	return ans
}
