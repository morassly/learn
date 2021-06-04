package leetcode

func maxValue(n string, x int) string {
	X := byte('0' + x)
	i, lens := 0, len(n)
	if n[i] == '-' {
		for ; i < lens && n[i] <= X; i++ {
		}
	} else {
		for ; i < lens && n[i] >= X; i++ {
		}
	}
	return n[:i] + string(X) + n[i:]
}
