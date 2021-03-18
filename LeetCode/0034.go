package leetcode

func searchRange(nums []int, target int) []int {
	low := binary(nums, target, false)
	up := binary(nums, target, true)
	if low == up {
		return []int{-1, -1}
	}
	return []int{low, up - 1}
}

func binary(a []int, x int, flag bool) int {
	l, r := 0, len(a)

	for l < r {
		mid := l + (r-l)/2
		if a[mid] <= x {
			if !flag && a[mid] == x {
				r = mid
			} else {
				l = mid + 1
			}
		} else {
			r = mid
		}
	}
	return l
}
