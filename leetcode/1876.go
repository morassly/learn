package leetcode

func countGoodSubstrings(s string) int {
	ret, n := 0, len(s)

	for i := 0; i < n-2; i++ {
		if s[i] != s[i+1] && s[i+1] != s[i+2] && s[i] != s[i+2] {
			ret++
		}
	}
	return ret
}
