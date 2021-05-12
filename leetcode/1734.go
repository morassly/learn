package leetcode

func decode(encoded []int) []int {
	n := len(encoded) + 1
	ans := make([]int, n)
	for i := 1; i <= n; i++ {
		ans[0] ^= i
	}
	for i := 1; i < n-1; i += 2 {
		ans[0] ^= encoded[i]
	}
	for i, v := range encoded {
		ans[i+1] = ans[i] ^ v
	}
	return ans
}
