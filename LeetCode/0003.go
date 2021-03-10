package leetcode

func lengthOfLongestSubstring(s string) int {
	var m [256]int
	ans := 0
	for i, j := 0, 0; j < len(s); j++ {
		if k := m[s[j]]; k != 0 && k > i {
			i = k
		}
		if ans < j-i+1 {
			ans = j - i + 1
		}
		m[s[j]] = j + 1
	}
	return ans
}
