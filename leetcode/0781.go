package leetcode

func numRabbits(answers []int) int {
	var count [1001]int
	for _, i := range answers {
		count[i+1]++
	}
	ans := 0
	for i := 1; i < 1001; i++ {
		ans += (count[i] + i - 1) / i * i
	}
	return ans
}
