package leetcode

func checkZeroOnes(s string) bool {
	len1, len0, max1, max0 := 0, 0, 0, 0
	for i := range s {
		if s[i] == '0' {
			len0++
			len1 = 0
			if max0 < len0 {
				max0 = len0
			}
		} else {
			len1++
			len0 = 0
			if max1 < len1 {
				max1 = len1
			}
		}
	}
	return max1 > max0
}
