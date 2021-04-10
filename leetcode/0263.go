package leetcode

func isUgly(n int) bool {
	if n < 1 {
		return false
	}
	var nums = [3]int{2, 3, 5}
	for _, num := range nums {
		for n%num == 0 {
			n /= num
		}
	}
	return n == 1
}
