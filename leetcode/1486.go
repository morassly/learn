package leetcode

func xorOperation(n int, start int) int {
	sumXor := func(x int) int {
		switch x % 4 {
		case 0:
			return x
		case 1:
			return 1
		case 2:
			return x + 1
		default:
			return 0
		}
	}
	s, e := start>>1, start&n&1
	ret := sumXor(s-1) ^ sumXor(s+n-1)
	return ret<<1 | e
}
