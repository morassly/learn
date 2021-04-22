package leetcode

func solveNQueens(n int) [][]string {
	ans := [][]string{}
	queens := make([][]byte, n)
	for i := range queens {
		queens[i] = make([]byte, n)
		for j := range queens[i] {
			queens[i][j] = '.'
		}
	}
	var dfs func(row, col, l, r int)
	dfs = func(row, col, l, r int) {
		if row == n {
			tmp := []string{}
			for i := range queens {
				tmp = append(tmp, string(queens[i]))
			}
			ans = append(ans, tmp)
			return
		}
		for cur := ((1 << n) - 1) &^ (col | l | r); cur > 0; cur &= (cur - 1) {
			pos := cur & -cur
			j := bits.TrailingZeros(uint(pos))
			queens[row][j] = 'Q'
			dfs(row+1, col|pos, (l|pos)>>1, (r|pos)<<1)
			queens[row][j] = '.'
		}
	}
	dfs(0, 0, 0, 0)
	return ans
}
