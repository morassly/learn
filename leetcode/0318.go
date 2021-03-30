package leetcode

func maxProduct(words []string) int {
	hash, ans := make(map[int]int), 0
	for _, word := range words {
		mask, length := 0, len(word)
		for _, ch := range word {
			mask |= 1 << (ch - 'a')
		}
		if length > hash[mask] {
			hash[mask] = length
		}
		for h_mask, h_len := range hash {
			if h_mask&mask == 0 {
				if ans < h_len*length {
					ans = h_len * length
				}
			}
		}
	}
	return ans
}
