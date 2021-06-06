package leetcode

import "strings"

func sortSentence(s string) string {
	sslince := strings.Split(s, " ")
	n := len(sslince)
	ret := make([]string, n+1)
	for i := range sslince {
		ret[sslince[i][len(sslince[i])-1]-'0'] = string(sslince[i][:len(sslince[i])-1])
	}
	ans := ""
	for i := 1; i < n; i++ {
		ans = ans + ret[i] + " "
	}
	ans += string(ret[n])
	return ans
}
