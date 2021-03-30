func hasAlternatingBits(n int) bool {
	tmp := uint32(n ^ (n >> 1))
	return (tmp & (tmp + 1)) == 0
}