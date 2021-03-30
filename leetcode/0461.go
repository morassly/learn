package leetcode

func hammingDistance(x int, y int) int {
	ans := 0
	for temp := x ^ y; temp > 0; ans++ {
		temp &= (temp - 1)
	}
	return ans
}
