package leetcode

func kthLargestValue(matrix [][]int, k int) int {
	m, n := len(matrix), len(matrix[0])
	pre, result := make([][]int, m+1), make([]int, 0, m*n)
	pre[0] = make([]int, n+1)
	for i, row := range matrix {
		pre[i+1] = make([]int, n+1)
		for j, val := range row {
			pre[i+1][j+1] = pre[i+1][j] ^ pre[i][j+1] ^ pre[i][j] ^ val
			result = append(result, pre[i+1][j+1])
		}
	}
	quickSelect := func(a []int, k int) int {
		for l, r := 0, len(a)-1; l < r; {
			i, j := l, r+1
			for {
				for i++; i < r && a[i] < a[l]; i++ {
				}
				for j--; j > l && a[j] > a[l]; j-- {
				}
				if i >= j {
					break
				}
				a[i], a[j] = a[j], a[i]
			}
			a[l], a[j] = a[j], a[l]
			if j == k {
				break
			} else if j < k {
				l = j + 1
			} else {
				r = j - 1
			}
		}
		return a[k]
	}
	return quickSelect(result, m*n-k)
}
