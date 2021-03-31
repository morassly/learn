package leetcode

func findComplement(num int) int {
	temp, c := num, 0
	for ; temp > 0; temp = temp >> 1 {
		c = (c << 1) + 1
	}
	return num ^ c
}
