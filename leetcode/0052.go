package leetcode

func totalNQueens(n int) int {
	ans := 0
	var dfs func(row, col, l, r int)
	dfs = func(row, col, l, r int) {
		if row == n {
			ans++
			return
		}
		for cur := ((1 << n) - 1) &^ (col | l | r); cur > 0; cur &= (cur - 1) {
			pos := cur & -cur
			dfs(row+1, col|pos, (l|pos)>>1, (r|pos)<<1)
		}
	}
	dfs(0, 0, 0, 0)
	return ans
}
