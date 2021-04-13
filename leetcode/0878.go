package leetcode

func nthMagicalNumber(n int, a int, b int) int {
	var gcd func(int, int) int
	gcd = func(x, y int) int {
		if x == 0 {
			return y
		}
		return gcd(y%x, x)
	}
	L := int64(a) / int64(gcd(a, b)) * int64(b)
	var l, r int64 = int64(0), int64(1e15)
	for l < r {
		mid := (r-l)/2 + l
		tmp := mid/int64(a) + mid/int64(b) - mid/L
		if tmp < int64(n) {
			l = mid + 1
		} else {
			r = mid
		}
	}
	return int(l) % (1e9 + 7)
}
