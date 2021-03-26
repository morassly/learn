package leetcode

func convert(s string, numRows int) string {
	if len(s) <= 2 || numRows == 1 {
		return s
	}
	tmp := make([]string, numRows)
	curRow, next := 0, 1
	for _, val := range s {
		tmp[curRow] += string(val)
		curRow += next
		if curRow == 0 || curRow == numRows-1 {
			next = -next
		}
	}
	ans := ""
	for _, val := range tmp {
		ans += val
	}
	return ans
}

func convert1(s string, numRows int) string {
	if len(s) <= 2 || numRows == 1 {
		return s
	}
	ans, ceycle := "", 2*numRows-2
	for i := 0; i < numRows; i++ {
		for j := 0; j+i < len(s); j += ceycle {
			ans += string(s[j+i])
			if i != 0 && i != numRows-1 && j+ceycle-i < len(s) {
				ans += string(s[j+ceycle-i])
			}
		}
	}
	return ans
}
