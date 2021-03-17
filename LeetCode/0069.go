func mySqrt(x int) int {
	if x < 0 {
		return -1
	}
	var l, r, tmp, mid int64 = 0, int64(x) + 1, 0, 0
	for l < r {
		mid = l + (r-l)/2
		tmp = mid * mid
		if tmp <= int64(x) {
			l = mid + 1
		} else {
			r = mid
		}
	}
	return int(l - 1)
}