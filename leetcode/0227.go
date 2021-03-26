package leetcode

func calculate(s string) int {
	stack := []int{}
	num := 0
	op := '+'
	for i, ch := range s {
		isDigit := '0' <= ch && ch <= '9'
		if isDigit {
			num = 10*num + int(ch-'0')
		}
		if !isDigit && ch != ' ' || i == len(s)-1 {
			switch op {
			case '+':
				stack = append(stack, num)
			case '-':
				stack = append(stack, -num)
			case '*':
				stack[len(stack)-1] *= num
			default:
				stack[len(stack)-1] /= num
			}
			op, num = ch, 0
		}
	}

	for _, v := range stack {
		num += v
	}
	return num
}
