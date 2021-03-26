package leetcode

func findSubstring(s string, words []string) []int {
	slen, wnum := len(s), len(words)
	if slen <= 0 || wnum <= 0 {
		return []int{}
	}
	wlen := len(words[0])
	if wlen*wnum > slen {
		return []int{}
	}

	wmap, ans := make(map[string]int), make([]int, 0)
	for _, word := range words {
		wmap[word]++
	}

	for i := 0; i < wlen; i++ {
		smap, count := make(map[string]int), 0
		for l, r := i, i; l <= slen-wlen*wnum && r <= slen-wlen; r += wlen {
			temp := s[r : r+wlen]
			if num, ok := wmap[temp]; ok {
				smap[temp]++
				count++
				for smap[temp] > num {
					smap[s[l:l+wlen]]--
					l += wlen
					count--
				}
				if count == wnum {
					ans = append(ans, l)
					smap[s[l:l+wlen]]--
					count--
					l += wlen
				}
			} else {
				l = r + wlen
				count = 0
				smap = make(map[string]int)
			}
		}
	}
	return ans
}
