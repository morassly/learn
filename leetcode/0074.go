package leetcode

import "sort"

func searchMatrix(matrix [][]int, target int) bool {
	m, n := len(matrix), len(matrix[0])
	ans := sort.Search(m*n, func(i int) bool { return matrix[i/n][i%n] >= target })
	return ans < m*n && matrix[ans/n][ans%n] == target
}
