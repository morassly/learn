package leetcode

func isValidSudoku(board [][]byte) bool {
	flag := make([]int, 9)

	for i, row := range board {
		for j, col := range row {
			if col == '.' {
				continue
			}
			r := 1 << (col - '0')
			c := 1 << (9 + (col - '0'))
			w := 1 << (18 + (col - '0'))
			if flag[i]&r == 0 && flag[j]&c == 0 && flag[(i/3)*3+j/3]&w == 0 {
				flag[i] |= r
				flag[j] |= c
				flag[(i/3)*3+j/3] |= w
			} else {
				return false
			}
		}
	}
	return true
}
