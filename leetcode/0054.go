package leetcode

func spiralOrder(matrix [][]int) []int {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return nil
	}
	t, b, left, right, tol := 0, len(matrix)-1, 0, len(matrix[0])-1, len(matrix)*len(matrix[0])
	ans := make([]int, tol)

	for num := 0; num < tol; {
		for j := left; j <= right; j++ {
			ans[num] = matrix[t][j]
			num++
		}
		t++
		for i := t; i <= b; i++ {
			ans[num] = matrix[i][right]
			num++
		}
		right--
		for j := right; j >= left && num < tol; j-- {
			ans[num] = matrix[b][j]
			num++
		}
		b--
		for i := b; i >= t && num < tol; i-- {
			ans[num] = matrix[i][left]
			num++
		}
		left++
	}
	return ans
}
