package leetcode

import "strconv"

func evalRPN(tokens []string) int {
	s, index := make([]int, (len(tokens)+1)/2), -1
	for _, token := range tokens {
		number, err := strconv.Atoi(token)
		if err == nil {
			index++
			s[index] = number
		} else {
			index--
			switch token {
			case "+":
				s[index] += s[index+1]
			case "-":
				s[index] -= s[index+1]
			case "*":
				s[index] *= s[index+1]
			case "/":
				s[index] /= s[index+1]
			}
		}
	}
	return s[0]
}
