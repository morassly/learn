package leetcode

func jump(nums []int) int {
	n, count := len(nums), 0
	for last, mx, i := 0, 0, 0; i < n-1; i++ {
		if mx < i+nums[i] {
			mx = i + nums[i]
		}
		if last == i {
			last, count = mx, count+1
		}
	}
	return count
}
