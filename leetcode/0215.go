package leetcode

import "math/rand"

func findKthLargest(a []int, k int) int {
	rand.Shuffle(len(a), func(i, j int) { a[i], a[j] = a[j], a[i] })
	k = len(a) - k
	for l, r := 0, len(a)-1; l < r; {
		i, j := l, r+1
		for {
			for i++; i < r && a[i] < a[l]; i++ {
			}
			for j--; j > l && a[j] > a[l]; j-- {
			}
			if i >= j {
				break
			}
			a[i], a[j] = a[j], a[i]
		}
		a[l], a[j] = a[j], a[l]
		if j == k {
			break
		} else if j < k {
			l = j + 1
		} else {
			r = j - 1
		}
	}
	return a[k]
}
