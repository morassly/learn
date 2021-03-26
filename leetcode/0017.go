package leetcode

func letterCombinations(digits string) []string {
	ans := make([]string, 0)
	if digits == "" {
		return ans
	}
	n := len(digits)
	table := map[byte]string{
		'2': "abc",
		'3': "def",
		'4': "ghi",
		'5': "jkl",
		'6': "mno",
		'7': "pqrs",
		'8': "tuv",
		'9': "wxyz",
	}
	var dfs func(int, string)
	dfs = func(index int, temp string) {
		if index == n {
			ans = append(ans, string(temp))
			return
		}
		for _, i := range table[digits[index]] {
			dfs(index+1, temp+string(i))
		}
	}
	dfs(0, "")
	return ans
}
