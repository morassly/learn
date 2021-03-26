package leetcode

func longestPalindrome(s string) string {
	if len(s) < 2 {
		return s
	}

	str := make([]rune, 0)
	str = append(str, '@')
	str = append(str, '#')
	for _, i := range s {
		str = append(str, i)
		str = append(str, '#')
	}
	str = append(str, '$')
	dp, center, right, maxlen, left := make([]int, len(str)), 0, 0, 0, 0
	for i := 1; i < len(str)-1; i++ {
		if i < right {
			dp[i] = min(right-i, dp[center*2-i])
		}
		for str[i+1+dp[i]] == str[i-dp[i]-1] {
			dp[i]++
		}
		if i+dp[i] > right {
			center = i
			right = i + dp[i]
		}
		if dp[i] > maxlen {
			maxlen = dp[i]
			left = (i - dp[i]) >> 1
		}
	}
	return s[left : left+maxlen]
}
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
