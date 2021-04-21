package leetcode

func myPow(x float64, n int) float64 {
	q_pow := func(x float64, n int) (ans float64) {
		ans = 1.0
		for n > 0 {
			if n&0x1 == 1 {
				ans *= x
			}
			x *= x
			n >>= 1
		}
		return
	}
	if n == 0 {
		return 1.0
	} else if n < 0 {
		return 1.0 / q_pow(x, -n)
	}
	return q_pow(x, n)

}
