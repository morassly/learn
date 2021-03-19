package leetcode

func romanToInt(s string) int {
	num := map[byte]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}
	ans := 0
	for i := 0; i < len(s)-1; i++ {
		if num[s[i]] >= num[s[i+1]] {
			ans += num[s[i]]
		} else {
			ans -= num[s[i]]
		}
	}
	return ans + num[s[len(s)-1]]
}
