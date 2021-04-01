package leetcode

func clumsy(N int) int {
	ans := []int{0, 1, 2, 6, 7}
	if N <= 4 {
		return ans[N]
	}
	if N%4 == 0 {
		return N + 1
	} else if N%4 <= 2 {
		return N + 2
	} else {
		return N - 1
	}
	return -1
}
