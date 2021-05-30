package leetcode

func minSwaps(s string) int {
	s0n0, s0n1, s1n0, s1n1 := 0, 0, 0, 0
	min := func(x, y int) int {
		if x < y {
			return x
		}
		return y
	}
	for i := range s {
		if i%2 == 0 {
			if s[i] == '0' {
				s1n1++
			} else {
				s0n0++
			}
		} else {
			if s[i] == '1' {
				s1n0++
			} else {
				s0n1++
			}
		}
	}
	if s0n0 == s0n1 {
		if s1n0 == s1n1 {
			return min(s0n0, s1n0)
		} else {
			return s0n0
		}
	} else {
		if s1n0 == s1n1 {
			return s1n0
		} else {
			return -1
		}
	}
	return -1
}
