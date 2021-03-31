package leetcode

import "sort"

func findContentChildren(g []int, s []int) int {
	sort.Ints(g)
	sort.Ints(s)
	i := 0
	for j := 0; i < len(g) && j < len(s); {
		if g[i] <= s[j] {
			i++
		}
		j++
	}
	return i
}
