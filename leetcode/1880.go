package leetcode

func isSumEqual(firstWord string, secondWord string, targetWord string) bool {
	decode := func(s string) int {
		res := 0
		for i, _ := range s {
			res += (int)(s[i] - 'a')
			res *= 10
		}
		return res
	}

	return decode(firstWord)+decode(secondWord) == decode(targetWord)
}
