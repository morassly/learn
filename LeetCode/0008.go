package leetcode

import "math"

func myAtoi(s string) int {

	i := 0
	for i < len(s) && s[i] == ' ' {
		i++
	}
	if i >= len(s) {
		return 0
	}
	sign := 1
	if s[i] == '-' {
		sign = -1
		i++
	} else if s[i] == '+' {
		sign = 1
		i++
	}
	if i >= len(s) {
		return 0
	}
	var ans int64 = 0
	for ; i < len(s) && s[i] >= '0' && s[i] <= '9'; i++ {
		ans *= 10
		ans += int64(s[i] - '0')
		if ans > math.MaxInt32 {
			if sign == 1 {
				return math.MaxInt32
			} else {
				return math.MinInt32
			}
		}
	}
	return int(ans) * sign
}
