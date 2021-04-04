func longestCommonSubsequence(text1 string, text2 string) int {
	// if len(text1) < len(text2) {
	//     text1, text2 = text2, text1
	// }
	m, n := len(text1), len(text2)
	ans := make([][]int, 2)
	for i := 0; i < 2; i++ {
		ans[i] = make([]int, n+1)
	}
	for i, ch1 := range text1 {
		for j, ch2 := range text2 {
			if ch1 == ch2 {
				ans[(i+1)&1][j+1] = ans[i&1][j] + 1
			} else if ans[i&1][j+1] < ans[(i+1)&1][j] {
				ans[(i+1)&1][j+1] = ans[(i+1)&1][j]
			} else {
				ans[(i+1)&1][j+1] = ans[i&1][j+1]
			}
		}
	}
	return ans[m&1][n]
}