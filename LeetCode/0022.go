package leetcode

func generateParenthesis(n int) []string {
	ans := make([]string, 0)

	var dfs func(string, int, int)

	dfs = func(temp string, l, r int) {
		if l == 0 && r == 0 {
			ans = append(ans, temp)
			return
		}
		if l > 0 {
			dfs(temp+"(", l-1, r)
		}
		if l < r {
			dfs(temp+")", l, r-1)
		}
	}
	dfs("", n, n)
	return ans
}
