package leetcode

func findPeakElement(nums []int) int {
	l, r := 0, len(nums)-1
	for l < r {
		if mid := (r-l)/2 + l; nums[mid] <= nums[mid+1] {
			l = mid + 1
		} else {
			r = mid
		}
	}
	return l
}
