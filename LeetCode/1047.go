package leetcode

func removeDuplicates(S string) string {
	s := []byte(S)
	num := 0
	for _, i := range S {
		if num == 0 || s[num-1] != byte(i) {
			s[num] = byte(i)
			num++
		} else {
			num--
		}
	}
	return string(s[:num])
}
