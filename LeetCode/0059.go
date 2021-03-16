package leetcode

func generateMatrix(n int) [][]int {
	ans := make([][]int, n)
	for i := range ans {
		ans[i] = make([]int, n)
	}
	t, b, left, right, tol := 0, n-1, 0, n-1, n*n

	for num := 0; num < tol; {
		for j := left; j <= right; j++ {
			ans[t][j] = num + 1
			num++
		}
		t++
		for i := t; i <= b; i++ {
			ans[i][right] = num + 1
			num++
		}
		right--
		for j := right; j >= left && num < tol; j-- {
			ans[b][j] = num + 1
			num++
		}
		b--
		for i := b; i >= t && num < tol; i-- {
			ans[i][left] = num + 1
			num++
		}
		left++
	}
	return ans
}
