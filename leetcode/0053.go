package leetcode

func maxSubArray(nums []int) int {
	mx, ans := 0, nums[0]
	for _, num := range nums {
		if mx+num > num {
			mx += num
		} else {
			mx = num
		}
		if ans < mx {
			ans = mx
		}
	}
	return ans
}
