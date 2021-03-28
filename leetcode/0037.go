package leetcode

import "math/bits"

func solveSudoku(board [][]byte) {
	var (
		col, row [9]int
		box      [3][3]int
		space    [][2]int
	)
	change := func(i, j int, d byte) {
		row[i] ^= 1 << d
		col[j] ^= 1 << d
		box[i/3][j/3] ^= 1 << d
	}
	for i, r := range board {
		for j, c := range r {
			if c != '.' {
				change(i, j, c-'1')
			} else {
				space = append(space, [2]int{i, j})
			}
		}
	}

	var dfs func(int) bool
	dfs = func(pos int) bool {
		if pos == len(space) {
			return true
		}
		i, j := space[pos][0], space[pos][1]
		mask := 0x1ff &^ uint(row[i]|col[j]|box[i/3][j/3])
		for ; mask > 0; mask &= mask - 1 { // 最右侧的 1 置为 0
			digit := byte(bits.TrailingZeros(mask))
			change(i, j, digit)
			board[i][j] = digit + '1'
			if dfs(pos + 1) {
				return true
			}
			change(i, j, digit)
		}
		return false
	}
	dfs(0)
}
