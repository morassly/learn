package leetcode

func shipWithinDays(weights []int, D int) int {
	l, r := 0, 0
	for _, each := range weights {
		if l < each {
			l = each
		}
		r += each
	}

	for l < r {
		mid := l + (r-l)/2
		temp, need := 0, 1
		for _, each := range weights {
			if temp+each > mid {
				need++
				temp = each
			} else {
				temp += each
			}
		}
		if need > D {
			l = mid + 1
		} else {
			r = mid
		}
	}
	return l
}
