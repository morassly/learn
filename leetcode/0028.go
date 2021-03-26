package leetcode

func strStr(haystack string, needle string) int {
	m, n := len(haystack), len(needle)
	next := make([]int, n+1)
	getnext := func() {
		j, k := 0, -1
		next[0] = k
		for j < n-1 {
			for k != -1 && needle[j] != needle[k] {
				k = next[k]
			}
			j, k = j+1, k+1
			next[j] = k
			if needle[j] == needle[k] {
				next[j] = next[k]
			}
		}
	}
	getnext()
	i, j := 0, 0
	for i < m && j < n {
		for j != -1 && haystack[i] != needle[j] {
			j = next[j]
		}
		i++
		j++
	}
	if j >= n {
		return i - n
	}
	return -1

}
