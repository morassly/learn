package leetcode

func numDecodings(s string) int {
	a, b, c := 0, 1, 0
	for i := 1; i <= len(s); i++ {
		c = 0
		if s[i-1] != '0' {
			c += b
		}
		if i > 1 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7')) {
			c += a
		}
		a, b = b, c
	}
	return c
}
