package leetcode

func countAndSay(n int) string {
	str := "1"
	for i := 1; i < n; i++ {
		tmp := make([]byte, 0)
		l, r := 0, 1
		for ; r < len(str); r++ {
			if str[l] != str[r] {
				num := byte((r - l) + '0')
				tmp = append(tmp, num)
				tmp = append(tmp, str[l])
				l = r
			}
		}
		num := byte((r - l) + '0')
		tmp = append(tmp, num)
		tmp = append(tmp, str[l])
		str = string(tmp)
	}
	return str
}
