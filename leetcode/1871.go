package leetcode

func canReach(s string, minJump int, maxJump int) bool {
	n, cnt := len(s), 1
	dp := make([]bool, n)
	if s[n-1] != '0' {
		return false
	}
	dp[0] = true
	for i := minJump; i < n; i++ {
		if cnt > 0 && s[i] == '0' {
			dp[i] = true
		}
		if i >= maxJump && dp[i-maxJump] {
			cnt--
		}
		if dp[i-minJump+1] {
			cnt++
		}
	}
	return dp[n-1]
}
